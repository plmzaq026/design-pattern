#ifndef PAGE_H
#define PAGE_H

#include "Graphics.h"
class Page
{
    public:
        Page();
        virtual ~Page();
        void draw(Graphics * g)
        {
            int org_x = getcurx(g->getWindow());
            int org_y = getcury(g->getWindow());

            int x = org_x + PAGE_SPACE / 2;
            int y = org_y + PAGE_SPACE / 2;

        }
    protected:
        int PAGE_SPACE = 16;
    private:
};

#endif // PAGE_H
