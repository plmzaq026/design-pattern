#ifndef FONTFACTORY_H
#define FONTFACTORY_H

#include "Font.h"

class FontFactory
{
private:
    // store all fonts that is used now:
    map<string,Font *> fonts;
    // store all fonts' name:
    vector<string> fontNames;
public:
    //Create new font with FontFactory
    Font* createFont(string name, int size, bool bold, bool italic, bool underlined)
    {
        Font tmp;
        string key = tmp.toKey(name, size, bold, italic, underlined);
        Font * _font = fonts[key];
        if(_font!=NULL)
        {
            // found it!
            _font->addRef();
            return _font;
        }

        Font* font = new Font(name, size, bold, italic, underlined);
        // cache it:
        fonts.insert(make_pair(font->tostring(), font));
        return font;
    }

    // enumerate all fonts installed in the system:
    vector<string> enumerateFonts()
    {
        // TODO Auto-generated method stub
        if(fontNames.empty()) {
            fontNames.push_back("Arial");
            fontNames.push_back("System");
            fontNames.push_back("Tahoma");
        }
        return fontNames;
    }

    // dispose all fonts it used now.
    void clearAllFonts()
    {
        map<string,Font*>::iterator it;
        for(it = fonts.begin();it != fonts.end();it ++)
        {
            Font font = *(it->second);
            while(font.getRefCount() > 0)
            {
                cout<<"WARNING: Some fonts are not released.";
                font.dispose();
            }
            cout<<it->first<<": "<<it->second->getName()<<endl;
        }
        // clear hash table:
        fonts.clear();
    }
    //Remove the font from the cache.
    void remove(Font *font) {
        fonts.erase(font->tostring());
    }

    int fontCount()
    {
        return fonts.size();
    }
    Font * createDefaultEnglishFont()
    {
        return createFont("Times New Roman", 14, false, false, false);
    }
    void debug()
    {
        cout<<"\n[FontFactory] fonts=" + fonts.size();
        map<string,Font*>::iterator it;
        for(it = fonts.begin();it != fonts.end();it ++)
        {
            cout<<it->first<<": "<<it->second->getName()<<endl;
        }
    }
};


#endif // FONTFACTORY_H
