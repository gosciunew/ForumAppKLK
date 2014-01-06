#include "textprovider.h"

TextProvider::TextProvider(NameSwitcher *p_nameSwitcher)
{
    nameSwitcher = p_nameSwitcher;
    constPart = " Jest Gruby";
}

TextProvider::~TextProvider()
{
    delete nameSwitcher;
}

std::string TextProvider::getText()
{
    return nameSwitcher->getNextName() + constPart;
}

TextProvider* TextProviderFactory::create()
{
    NameSwitcher *nameSwitcher = new NameSwitcher();

    return  new TextProvider(nameSwitcher);
}
