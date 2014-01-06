#ifndef INTROSCREEN_H
#define INTROSCREEN_H

#include <QFrame>

namespace Ui {
class IntroScreen;
}

class IntroScreen : public QFrame
{
    Q_OBJECT

public:
    explicit IntroScreen(QWidget *parent = 0);
    ~IntroScreen();

private:
    Ui::IntroScreen *ui;
};

#endif // INTROSCREEN_H
