#ifndef LOGINDATAPROVIDER_H
#define LOGINDATAPROVIDER_H

#include <QByteArray>
#include <QString>

namespace ForumHandler
{

class ILoginDataProvider
{
public:
    virtual ~ILoginDataProvider()
    {};

    virtual QByteArray getData() = 0;
    virtual void setParams(QString, QString, QString) = 0;
};

class LoginDataProvider : public ILoginDataProvider
{
public:
    LoginDataProvider();
    LoginDataProvider(QString p_username, QString p_password, QString p_login = "Zaloguj");
    virtual ~LoginDataProvider();

    virtual QByteArray getData();
    virtual void setParams(QString p_username, QString p_password, QString p_login = "Zaloguj");

private:
    QString m_username;
    QString m_password;
    QString m_login;
};

class LoginDataProviderFactory
{
public:
    LoginDataProvider* create();
};

} // namespace ForumHandler

#endif // LOGINDATAPROVIDER_H
