#ifndef FRAME_H
#define FRAME_H

#include <ncurses.h>
#include "Buffer.h"

#include"Graphics.h"
#include "Caret.h"

#define CED_TITLE "Lexi editor"
#define CED_VERSION "v0.1"

class Frame
{
    private:
        char mode;
        string status;
        string cmd;
        string filename;

        string tos(int);

        bool execCmd();

        void saveFile();

        Caret * caret;
    public:
        bool upstatus;

        Frame(WINDOW * win);
        Frame(WINDOW * win,string);

        char getMode() {return mode;}

        void handleInput(int);
        void printBuff();
        void printStatusLine();
        void updateStatus();

};


#endif // FRAME_H
