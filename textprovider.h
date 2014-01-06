#ifndef TEXTPROVIDER_H
#define TEXTPROVIDER_H

#include "nameswitcher.h"

class TextProvider
{
public:
    TextProvider(NameSwitcher *p_nameSwitcher);
    virtual ~TextProvider();

    std::string getText();
private:
    NameSwitcher *nameSwitcher;
    std::string constPart;
};

class TextProviderFactory
{
public:
    TextProvider* create();
};

#endif // TEXTPROVIDER_H
