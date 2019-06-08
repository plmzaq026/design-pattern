#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <cctype>
#include <fstream>
using namespace std;

struct Node {
        char data;
        Node* next;
        Node* prev;
};

class Line {
    private:
        Node* head;
        Node* tail;
        Node* cursor;

    public:
    Line() {
		Node* newNode = new Node;
		newNode->data = ' ';
		newNode->next = NULL;
		newNode->prev = NULL;
		head = newNode;
		tail = newNode;
		cursor = newNode;
        }
    void add(string str) {
		for(int i = 0; i < str.length(); i++) {
			if(str[i] == '\n') {
				this->add(' '); //if newline add space. Used in open function in lineList class
			} else {
				this->add(str[i]);
			}
		}
		return;
        }

    void addToTail(Node* oldHead) {
		cursor = tail; //point cursor to end of current line. This is used in LineList remove function
		tail->next = oldHead; //point current list at other list
		oldHead->prev = tail; //point other list at current list

		Node* temp = tail;
		//loop from previous tail to the end of the new list to reposition tail
		while(temp->next != NULL) {
			temp = temp->next;
		}

		tail = temp; //repoint tail
        }

        // add the new node before the cursor
        void add(char key) {
		//create node
		Node* newNode = new Node;
		newNode->data = key;

		//adding to the front of the list
		if (head == cursor) {
			head->prev = newNode; //point first entry at the new node
			newNode->next = head; //point new node at the first entry
			newNode->prev = NULL;	//point prev to nothing
			head = newNode; //repoint head
			return;

		} else {

		//adding to the middle of the list

		newNode->next = cursor; //point newnode at the current node
		newNode->prev = cursor->prev; //point newnode at the previous node
		cursor->prev->next = newNode; // point previous node at newnode
		cursor->prev = newNode; //point current node at newnode
		}
		return;
        }

        // remove the node before the cursor
        void remove() {
		Node* temp;
		if(cursor == head) {
			return;
		} else {
			temp = cursor->prev; //mark previous node
			cursor->prev = cursor->prev->prev; //remove previous node from list
			cursor->prev->next = cursor; //point new previous node at cursor
			delete temp; //delete old  previous node
		}
		return;
        }

        // print the line
        void print(int row) {
		//vars
		Node* temp = head;
		int col = 0;

		//loop through the list and print each node
		while(temp != NULL) {

			//Highlight the cursor
			if(temp == cursor) {
				attron(COLOR_PAIR(1));
				mvaddch(row, col, temp->data);
				attroff(COLOR_PAIR(1));
				temp = temp->next;
				col++;

			} else {
				//otherwise print normally
				mvaddch(row, col, temp->data);
				temp = temp->next;
				col++;
			}
		}

		return;
        }

        // returns the whole line as a string
        string get() {
		//vars
		string str;
		Node* temp = head;
		int i = 0;

		//loop through the list and load each node into a string
		while (temp != NULL) {
			if (temp == tail) {//convert ' ' tail char to newline char. used in save function
				str[i] = '\n';
			} else {
				str[i] = temp->data;
			}
			temp = temp->next;
			i++;
		}

		return str;
        }


        // move the cursor left and right
        void moveCursor(char input) {

		if(input == 'l' && cursor->prev != NULL) { //if in bounds
			cursor = cursor->prev;	//move left
		}
		if(input == 'r' && cursor->next != NULL) { //if in bounds
			cursor = cursor->next;	//move right
		}

		return;
        }

        // set the cursor to a particular position in the line
        // (or NULL if the pos input is -1)
        void setCursor(int pos) {
		if (pos < 0) { //if less than 1
			cursor = NULL;
		} else { //otherwise move cursor to a pos number of nodes into the list
			cursor = head;
			for(int i = 0; i < pos; i++) {
				cursor = cursor->next;
			}
		}

		return;
        }

        // get the position of the cursor
        // (# of chars from the left, starting at 0)
        int getCursor() {
		//vars
		Node* temp = head;
		int i = 0;

		//loop until cursor is reached and increment i for each node
		while(temp != cursor) {
			temp = temp->next;
			i++;
		}

		return i;
        }

        // returns a pointer to the section of the list to the right of
        // and including the cursor. it also removes this part of the
        // list from the original, replacing it with a new tail char, ' '
        Node* getCursorPointer() {

		Node* temp = cursor; //mark where cursor is currently
		Node* newNode = new Node; //create node
		newNode->data = ' ';	//load tail char into it

		//insert it at end of the list
		cursor = cursor->prev;
		newNode->next = NULL;
		newNode->prev = cursor;
		cursor->next = newNode;
		tail = newNode; //repoint tail
		cursor = NULL; //delete cursor off this line
		return temp;
        }


        // destructor deletes all nodes in the list
        ~Line() {
		//set cursor to end of list
		cursor = tail;

		//loop backwards through the list removing all nodes
		while (cursor != head) {
			this->remove();
			cursor = cursor->prev;
		}
        }

};




struct LineNode {
        Line data;
        LineNode* next;
        LineNode* prev;
};


class LineList {
        private:
        LineNode* head;
        LineNode* tail;
        LineNode* curr;

        public:
        // creates a new LineList with one empty LineNode in it
        // head, tail, and curr should point at this LineNode
        LineList() {
		LineNode* newLine = new LineNode;
		newLine->next = NULL;
		newLine->prev = NULL;
		head = newLine;
		tail = newLine;
		curr = newLine;
        }

        // opens the file at path and loads all of the text in
        // it into LineList (converting \n to ' ' at line ends)
        void open(char path[100]) {
		//vars
		ifstream inFile;
		string line;

		inFile.open(path);
		if (inFile.is_open()){

		//read from file before eof check
		getline(inFile, line, '\n'); //store line as a string
		curr->data.add(line);
		curr = curr->next;

			//load each file line into each line node
			while(!inFile.eof()) {
				getline(inFile, line, '\n');
				curr->data.add(line);
				curr = curr->next;
			}
		}

		inFile.close();
		return;
        }

        // takes all of the text in LineList and prints it to a
        // file at 'path' (converting ' ' to \n at line ends)
        void save(char path[100]) {
		//vars
		LineNode* temp = head;
		ofstream outFile;

		outFile.open(path);

		//loop to access each member of the LineList
		while (temp != NULL) {
			outFile << temp->data.get();
			temp = temp->next;
		}

		outFile.close();
		return;
        }

        // add a new line to the list after the cursor and bring
        // everything to the right of the cursor down to that next line
        void add() {
		Node* temp = curr->data.getCursorPointer(); //get everything to the right of the cursor position
		LineNode* newLine = new LineNode; //create new line
		newLine->data.addToTail(temp); //put data in new line
		//place it after the current line
		newLine->prev = curr;
		newLine->next = curr->next;
		curr->next = newLine;
		curr = curr->next; //move to next line
		return;
        }

        // prints all of the lines from head to tail
        void display() {
		//vars
		LineNode* temp = head;
		int row = 0;

		//loop through each line node and print the constituent lines
		while(temp != NULL){
			temp->data.print(row);
			temp = temp->next;
			row++;
		}
		return;
        }

        // adds a string to the line 'curr'
        void add(string str) {
		curr->data.add(str);
		return;
        }

        // adds a char to the line 'curr'
        void add(char ch) {
		curr->data.add(ch);
		return;
        }

        // if the cursor isn't at the head, just remove the char
        // before the cursor.  otherwise, (when curr isn't head) bring
        // the whole line up onto the end of the line previous
        void remove() {
		//vars
		Node* temp;
		int pos;

		//if curr is at the head then dont do anything
		if (curr == head) {
			return;
		}
		//if cursor is at the head
		if (curr->data.getCursor() == 0) {
			//get pointer to this line
			temp = curr->data.getCursorPointer();
			//add this line to the end of the previous line
			curr->prev->data.addToTail(temp);
			//move curr pointer
			curr = curr->prev;

		} else { //otherwise remove char
			curr->data.remove();
		}
        }

        // move the cursor left, right, up or down
        void moveCursor(char ch) {
		//vars
		int pos;

		if (ch == 'l') {
			curr->data.moveCursor('l'); //move left
			return;
		}

		if (ch == 'r') {
			curr->data.moveCursor('r'); //move right
			return;
		}

		if (ch == 'u' && curr->prev != NULL) { //if in bounds
			pos = curr->data.getCursor();//get current cursor pos
			curr->data.setCursor(-1); //delete cursor off this line
			curr = curr->prev; //move up
			curr->data.setCursor(pos);//return cursor to original pos
			return;
		}

		if (ch == 'd' && curr->next != NULL) { //if in bounds
			pos = curr->data.getCursor();//get cursor pos
			curr->data.setCursor(-1);//delete cursor off this line
			curr = curr->next; //move down
			curr->data.setCursor(pos);//return cursor to original pos
			return;
		}
        }

};


int main() {
        // set up ncurses stuff
        initscr();
        keypad(stdscr, TRUE);   // lets the arrow keys work
        start_color();
        init_pair(1, COLOR_BLACK, COLOR_BLUE);


        // declare line list
        LineList l;
        int input = 'a';

        // open routine
        char path[100];
        clear();
        mvprintw(0, 0, "Would you like to open an existing file? (y/n) ");
        refresh();
        input = getch();
        if(input == 'y') {
                mvprintw(1, 0, "Please enter file open path: ");
                getstr(path);
                l.open(path);
        }

        clear();
        noecho();                               // makes the keystroke NOT be printed
        nodelay(stdscr, TRUE);  // makes getch NOT WAIT for input
        curs_set(0);                    // turn off the regular cursor

        // modification loop
        while(input != 27) { // 27 is the escape key
                // get input
                input = getch();

                // put it into the line or move the cursor
                if(isalpha(input) || input == ' ') {
                        l.add(input);
                } else if(input == KEY_LEFT) {
                        l.moveCursor('l');
                } else if(input == KEY_RIGHT) {
                        l.moveCursor('r');
                } else if(input == KEY_BACKSPACE) { // backspace
                        l.remove();
                } else if(input == '\n') {
                        l.add();
                } else if(input == KEY_UP) {
                        l.moveCursor('u');
                } else if(input == KEY_DOWN) {
                        l.moveCursor('d');
                }

                // display line with cursor and pause
                l.display();
                refresh();
                usleep(10000);
        }

        echo();                         // makes the keystroke NOT be printed
        nodelay(stdscr, FALSE); // makes getch NOT WAIT for input
        curs_set(1);                    // turn off the regular cursor

        // ask for save
        clear();
        mvprintw(0, 0, "Would you like to save your file? (y/n) ");
        refresh();
        input = getch();
        if(input == 'y') {
                mvprintw(1, 0, "Please enter file save path: ");
                getstr(path);
                l.save(path);
        }



        // exit
        endwin();
        return 0;
}

