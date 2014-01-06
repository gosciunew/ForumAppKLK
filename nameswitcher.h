#ifndef NAMESWITCHER_H
#define NAMESWITCHER_H

#include <string>

class NameSwitcher
{
public:
    NameSwitcher();

    std::string getNextName();
private:
    int id;
};

#endif // NAMESWITCHER_H
