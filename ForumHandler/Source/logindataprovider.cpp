#include "ForumHandler/Include/logindataprovider.h"

namespace ForumHandler
{

LoginDataProvider::LoginDataProvider()
{
    m_username = QString("");
    m_password = QString("");
    m_login    = QString("");
}

LoginDataProvider::LoginDataProvider(QString p_username,
                                     QString p_password,
                                     QString p_login)
    : m_username(p_username), m_password(p_password), m_login(p_login)
{
}

LoginDataProvider::~LoginDataProvider()
{
}

QByteArray LoginDataProvider::getData()
{
    QByteArray loginData = QString("username=%1&password=%2&login=%3")
        .arg(m_username,
             m_password,
             m_login).toLatin1();

    return loginData;
}

void LoginDataProvider::setParams(QString p_username, QString p_password, QString p_login)
{
    m_username = p_username;
    m_password = p_password;
    m_login    = p_login;
}

LoginDataProvider* LoginDataProviderFactory::create()
{
    return new LoginDataProvider("gosciunew", "dziekizajdi", "Zaloguj");
}

} // namespace ForumHandler
