#include "TestFile.h"
#include <cdk.h>

TestFile::TestFile()
{
    win = initscr();
}

TestFile::~TestFile()
{
    getch();
    endwin();

}

void TestFile::testGraphics()
{
    refresh();
    Graphics *gc = new Graphics(win);
    //gc->draw_Hline(100,100,10,10);
    gc->drawRectangle(40,20);
    noecho();
    while(1)
    {
        char ch = getch();
        if(ch == 27)
        {
            ch = getch();
            if(ch == 'r')
            {
                gc->setForeColor(1);
                noecho();
            }else
            if(ch == 'b')
            {
                gc->setForeColor(2);
                noecho();
            }else
            break;
        }
        gc->draw_char(ch);
    }
    gc->draw_string(" ko no dio da!");

}

void TestFile::testColors()
{
      CDKSCREEN   *cdkscreen;
      CDKLABEL    *demo;
      char        *mesg[4];

      cdkscreen = initCDKScreen (NULL);

      /* Start CDK Colors */
      initCDKColor();

      /* Set the labels up.      */
      mesg[0] = "</31>This line should have a yellow foreground and a cyan background.<!31>";
      mesg[1] = "</05>This line should have a white  foreground and a blue background.<!05>";
      mesg[2] = "</26>This line should have a yellow foreground and a red  background.<!26>";
      mesg[3] = "<C>This line should be set to whatever the screen default is.";

      /* Declare the labels.     */
      demo   = newCDKLabel (cdkscreen, CENTER, CENTER, mesg, 4, TRUE, TRUE);

      /* Draw the label          */
      drawCDKLabel (demo, TRUE);
      waitCDKLabel (demo, ' ');

      /* Clean up           */
      destroyCDKLabel (demo);
      destroyCDKScreen (cdkscreen);
      endCDK();
      exit (0);

}
