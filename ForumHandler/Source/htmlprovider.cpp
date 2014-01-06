#include "ForumHandler/Include/htmlprovider.h"
#include "ForumHandler/Include/logindataprovider.h"

#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QAuthenticator>
#include <QHostAddress>
#include <QSslKey>
#include <QVariant>
#include <QNetworkCookie>
#include <QNetworkCookieJar>
#include <QSslConfiguration>



namespace ForumHandler
{

HtmlProvider::HtmlProvider()
{
    m_loginDataProvider = LoginDataProviderFactory().create();

    m_manager = new QNetworkAccessManager(this);
    m_request = new QNetworkRequest();
    m_cookieReply = NULL;
    m_pageReply = NULL;
    m_loop = new QEventLoop();

    m_initSuccessful = false;

    connect(m_manager, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)),
            this, SLOT(requestSslError(QNetworkReply*,QList<QSslError>)));
}

HtmlProvider::~HtmlProvider()
{
    delete m_loginDataProvider;

    delete m_manager;
    delete m_request;
    delete m_cookieReply;
    delete m_pageReply;
    delete m_loop;
}

int HtmlProvider::initConnection()
{
    QByteArray l_loginData = m_loginDataProvider->getData();

    m_request->setUrl(QUrl("https://krakowlacrosse.fora.pl/login.php"));
    m_request->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    m_cookieReply = m_manager->post(*m_request, l_loginData);
    connect(m_cookieReply, SIGNAL(finished()), this, SLOT(gotInitCookies()));
    connectWebPageErrorAndLoop(m_cookieReply);
    m_loop->exec();

    return 0;
}

QString HtmlProvider::getWebPage(const QString p_urlAddressPage)
{
    if(m_initSuccessful)
    {
        delete m_request;
        m_request = new QNetworkRequest();
        m_request->setUrl(p_urlAddressPage);

        m_pageReply = m_manager->get(*m_request);
        connect(m_pageReply, SIGNAL(finished()), this, SLOT(gotWebPage()));
        connectWebPageErrorAndLoop(m_pageReply);
        m_loop->exec();

        return QString(m_pageReply->readAll());
    }
    else
        return QString("");
}

void HtmlProvider::gotInitCookies()
{
    if(m_cookieReply->error() == QNetworkReply::NoError)
        m_initSuccessful = true;
}

void HtmlProvider::gotWebPage()
{
    if (m_pageReply->error() > 0)
        qDebug() << m_pageReply->errorString();
    else
    {
        if(m_pageReply->readAll().contains("gosciunew"))
            qDebug() << "Find gosciunew";
        else
            qDebug() << "Problem not find login";
//        qDebug() << m_pageReply->readAll();
    }
}

void HtmlProvider::requestSslError(QNetworkReply* p_reply,QList<QSslError> p_sslErrorList)
{
    QString result = "SSL Errors: ";
    QSslError sslerror;
    foreach (sslerror, p_sslErrorList)
    {
        result.append(sslerror.errorString()).append("\n");
    }
    qDebug() << result << p_reply->readAll();
}

void HtmlProvider::handleWebPageError(QNetworkReply::NetworkError p_errors)
{
    qDebug() << p_errors;
}

void HtmlProvider::connectWebPageErrorAndLoop(QNetworkReply* p_reply)
{
    connect(p_reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(handleWebPageError(QNetworkReply::NetworkError)));
    connect(p_reply, SIGNAL(finished()),
            m_loop, SLOT(quit()));
}

} // ForumHandler
