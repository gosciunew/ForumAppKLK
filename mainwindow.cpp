#include <QThread>
#include <QtTest/QTest>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    intro = new IntroScreen(this);

    switchName = ui->MainGridSwitchButton;
    centeredText = ui->MainGridLabel;

    textProvider = TextProviderFactory().create();

    connect(switchName, SIGNAL(clicked()), this, SLOT(handleSwitchNameButton()));

//    presentIntro();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::presentIntro()
{
    intro->show();
    QTest::qWait(2000);
    intro->hide();
}

void MainWindow::handleSwitchNameButton()
{
    centeredText->setText(QString::fromStdString(textProvider->getText()));

}

