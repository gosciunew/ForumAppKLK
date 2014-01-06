#ifndef IHTMLPROVIDER_H
#define IHTMLPROVIDER_H

#include <QString>

namespace ForumHandler
{

class IHtmlProvider
{
public:
    virtual ~IHtmlProvider()
    {}

    virtual QString getWebPage(const QString) = 0;
    virtual int initConnection() = 0;
};

} // namespace ForumHandler

#endif // IHTMLPROVIDER_H
