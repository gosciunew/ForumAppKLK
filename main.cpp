#include <QApplication>
#include <QDebug>

#include "mainwindow.h"
#include "ForumHandler/Include/htmlprovider.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.presentIntro();
    ForumHandler::IHtmlProvider* htmlProvider = new ForumHandler::HtmlProvider();
    htmlProvider->initConnection();
    qDebug() << htmlProvider->getWebPage("http://www.krakowlacrosse.fora.pl/treningi,6/dodatkowy-trening-04-01-2014,98.html");

    //delete htmlProvider;
    return a.exec();
}
