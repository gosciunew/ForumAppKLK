#include "introscreen.h"
#include "ui_introscreen.h"

IntroScreen::IntroScreen(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::IntroScreen)
{
    ui->setupUi(this);
}

IntroScreen::~IntroScreen()
{
    delete ui;
}
