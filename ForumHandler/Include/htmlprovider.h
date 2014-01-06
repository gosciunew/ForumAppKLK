#ifndef HTMLPROVIDER_H
#define HTMLPROVIDER_H

#include "ForumHandler/Include/ihtmlprovider.h"
#include "ForumHandler/Include/logindataprovider.h"

#include <QString>
#include <QNetworkAccessManager>
#include <QList>
#include <QSslSocket>
#include <QSslError>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPointer>
#include <QEventLoop>

namespace ForumHandler
{

class HtmlProvider : public QObject, public IHtmlProvider
{
    Q_OBJECT

public:
    HtmlProvider();
    virtual ~HtmlProvider();

    virtual QString getWebPage(const QString p_urlAddressPage);
    virtual int initConnection();

public slots:
    virtual void gotInitCookies();
    virtual void gotWebPage();
    virtual void requestSslError(QNetworkReply* p_reply,QList<QSslError> p_sslErrorList);
    virtual void handleWebPageError(QNetworkReply::NetworkError p_errors);

protected:
    virtual void connectWebPageErrorAndLoop(QNetworkReply* p_reply);

private:
    ILoginDataProvider*    m_loginDataProvider;

    QNetworkAccessManager* m_manager;
    QNetworkRequest*       m_request;
    QNetworkReply*         m_cookieReply;
    QNetworkReply*         m_pageReply;
    QEventLoop*            m_loop;

    bool                   m_initSuccessful;
};

} // ForumHandler

#endif // HTMLPROVIDER_H
