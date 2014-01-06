#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

#include "textprovider.h"
#include "introscreen.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void presentIntro();

private slots:
    void handleSwitchNameButton();

private:
    Ui::MainWindow  *ui;
    IntroScreen     *intro;
    QPushButton     *switchName;
    QLabel          *centeredText;

    TextProvider    *textProvider;
};

#endif // MAINWINDOW_H
