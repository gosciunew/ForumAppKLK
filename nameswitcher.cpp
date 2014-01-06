#include "nameswitcher.h"

NameSwitcher::NameSwitcher() : id(0)
{}

std::string NameSwitcher::getNextName()
{
    std::string result;
    switch(id)
    {
        case 0:
            result = "Rybak";
            break;
        case 1:
            result = "Wrona";
            break;
        case 2:
            result = "Cyrek";
            break;
        default:
            result = "Oops default";
    }

    id++;
    if(id > 2)
        id = 0;

    return result;
}
