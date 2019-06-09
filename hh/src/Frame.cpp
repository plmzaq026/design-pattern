#include "Frame.h"

#include <fstream>
#include <iostream>
#include <sstream>

Frame::Frame(WINDOW * win,string fn)
{
    mode = 'n';
    cmd = "";
    upstatus = true;
    status = "Normal Mode";

    caret = new Caret(win);
    caret->x = 0;
    caret->y = 0;
    caret->lowerbound = 0;
    caret->raiseflag = false;                  // for debugging

    filename = fn;

    /* Read from file if exists */
    ifstream infile(fn.c_str());
    if(infile.is_open())
    {
        while(!infile.eof())
        {
            string temp;
            getline(infile, temp);
            caret->buff->appendLine(temp);
        }
    }
    else
    {
        cerr << "Cannot open file: '" << fn << endl;
        caret->buff->appendLine("");
    }
    infile.close();
}

Frame::Frame(WINDOW * win)
{
    /* For a new file */
    mode = 'n';
    cmd = "";
    upstatus = true;
    status = "Normal Mode";
    filename = "";

    caret = new Caret(win);
    caret->buff->appendLine("");
    caret->x = caret->y = 0;
    caret->lowerbound = 0;
    caret->raiseflag = false;
}

void Frame::updateStatus()
{
    switch(mode)
    {
        case 'n':
            if(cmd.empty())
                status = string(CED_TITLE) + " " + string(CED_VERSION);
            else
                status = cmd;
            break;
        case 'i':
            status = "Insert Mode";
            break;
        case 'x':
            status = "Exiting";
            break;
        case 'c':
            status = "Coloring Mode";
            break;
        case 'f':
            status = "Fonting Mode";
            break;
    }
    status += "\tCOL: " + tos(caret->x) + "\tROW: " + tos(caret->lowerbound);
}

void Frame::handleInput(int c)
{    upstatus = true;
    switch(mode)
    {
        case 'n':
            switch(c)
            {
                case KEY_LEFT:
                    caret->moveLeft();
                    break;
                case KEY_RIGHT:
                    caret->moveRight();
                    break;
                case KEY_UP:
                    caret->moveUp();
                    break;
                case KEY_DOWN:
                    caret->moveDown();
                    break;
                case KEY_ENTER:
                case 10:
                    // Execute the command
                    execCmd();
                    break;
                case 27:
                    // Escape/Alt kecaret->y
                    // clears command
                    cmd.clear();
                    break;
                case 127:
                case KEY_BACKSPACE:
                case KEY_DC:
                    // Removes last character
                    if(!cmd.empty())
                        cmd.erase(cmd.length()-1, 1);
                    break;
                default:
                    // Add character to command
                    cmd += string(1, char(c));
                    break;
            }
            break;
        case 'i':
            switch(c)
            {
                case 27:
                    // Escape/Alt key
                    mode = 'n';
                    break;
                case 127:
                case KEY_BACKSPACE:
                    // The Backspace
                    if(caret->x == 0 && caret->y > 0)
                    {
                        caret->x = caret->buff->lines[caret->y-1].length();
                        // Bring line down
                        caret->buff->lines[caret->y-1] += caret->buff->lines[caret->y];
                        // Delete the line
                        caret->deleteLine();
                        caret->moveUp();
                    }
                    else if(caret->x > 0)
                    {
                        caret->buff->lines[caret->y].erase(--caret->x, 1);
                    }
                    break;
                case KEY_DC:
                    // The Delete kecaret->y
                    if(caret->x == caret->buff->lines[caret->y].length() && caret->y != caret->buff->lines.size()-1)
                    {
                        // Bring line down
                        caret->buff->lines[caret->y] += caret->buff->lines[caret->y+1];
                        // Delete the line
                        caret->deleteLine(caret->y+1);
                    }
                    else
                    {
                        caret->buff->lines[caret->y].erase(caret->x, 1);
                    }
                    break;
                case KEY_LEFT:
                    caret->moveLeft();
                    break;
                case KEY_RIGHT:
                    caret->moveRight();
                    break;
                case KEY_UP:
                    caret->moveUp();
                    break;
                case KEY_DOWN:
                    caret->moveDown();
                    break;
                case KEY_ENTER:
                case 10:
                    // \n
                    if(caret->x < caret->buff->lines[caret->y+caret->lowerbound].length()-1)
                    {
                        // Put rest of line on new line
                        caret->buff->insertLine(caret->buff->lines[caret->y+caret->lowerbound].substr(caret->x, caret->buff->lines[caret->y+caret->lowerbound].length()-caret->x), caret->y+1);
                        // Remove that part of the line
                        caret->buff->lines[caret->y+caret->lowerbound].erase(caret->x, caret->buff->lines[caret->y+caret->lowerbound].length()-caret->x);
                    }
                    else
                        caret->buff->insertLine("", caret->y+caret->lowerbound+1);
                    caret->moveDown();
                    break;
                case KEY_BTAB:
                case KEY_CTAB:
                case KEY_STAB:
                case KEY_CATAB:
                case 9:
                    // The tab
                    caret->buff->lines[caret->y+caret->lowerbound].insert(caret->x, 4, ' ');
                    caret->x+=4;
                    break;
                default:
                    caret->buff->lines[caret->y+caret->lowerbound].insert(caret->x, 1, char(c));
                    caret->x++;
                    break;
            }
            break;
        default:;
    }
}
void Frame::printBuff()
{
    int lc = 0;                     // Line count
    for(int i=caret->lowerbound; lc<LINES-1; i++)
    {
        if(i >= caret->buff->lines.size())
        {
        }
        else
        {
            mvprintw(lc, 0, caret->buff->lines[i].c_str());
        }
        clrtoeol();
        lc++;
    }
    move(caret->y, caret->x);
}

void Frame::printStatusLine()
{
    if(caret->raiseflag)
        attron(A_BOLD);
    attron(A_REVERSE);
    mvprintw(LINES-1, 0, status.c_str());
    clrtoeol();
    if(caret->raiseflag)
        attroff(A_BOLD);
    attroff(A_REVERSE);
}

void Frame::saveFile()
{
    if(filename == "")
    {
        // Set filename to untitled
        filename = "untitled";
    }

    ofstream f(filename.c_str());
    if(f.is_open())
    {
        for(int i=0; i< caret->buff->lines.size(); i++)
        {
            f << caret->buff->lines[i] << endl;
        }
        status = "Saved to file!";
    }
    else
    {
        status = "Error: Cannot open file for writing!";
    }
    f.close();
}

string Frame::tos(int n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}

bool Frame::execCmd()
{
    if(cmd == "i")
        mode = 'i';
    else if(cmd == "x")
        mode = 'x';
    else if(cmd == "s")
    {
        upstatus = false;
        saveFile();
    }

    cmd = "";                       // Reset command buffer
    return true;                    // Returns if command has executed successfullcaret->y
}
