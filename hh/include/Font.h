#ifndef FONT_H
#define FONT_H


#include <cdk.h>

class Font
{
    public:
        Font()
        {
        };
        virtual ~Font()
        {

        };

       void test()
       {
            char         *mesg[4];
            cdkscreen = initCDKScreen (NULL);

          /* Start CDK Colors */
          initCDKColor();

          /* Set the labels up.  */
          mesg[0] = "</B/31>Bold text            yellow foreground / blue background.<!31>";
          mesg[1] = "</U/05>Underlined text      white  foreground / blue background.<!05>";
          mesg[2] = "</K/26>Blinking text        yellow foreground / red  background.<!26>";
          mesg[3] = "<C>This line uses the screen default colors.";

          /* Declare the labels.  */
          demo = newCDKLabel (cdkscreen, CENTER, CENTER, mesg, 4, TRUE, TRUE);

          /* Draw the label */
          drawCDKLabel (demo, TRUE);
          waitCDKLabel (demo, ' ');

          /* Clean up */
          destroyCDKLabel (demo);
          destroyCDKScreen (cdkscreen);
          endCDK();
       }
    private:
        CDKSCREEN * cdkscreen;
        CDKLABEL * demo;
};
#endif // FONT_H
