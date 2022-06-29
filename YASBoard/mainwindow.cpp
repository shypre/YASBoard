#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QCoreApplication>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionQuit_triggered()
{
    this->close();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, QCoreApplication::applicationName(), "TODO");
}


void MainWindow::on_actionMeme_1_triggered()
{
    auto player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("/home/shypre/Downloads/mixkit-classic-alarm-995.wav"));
    player->setVolume(100);
    player->play();
}


void MainWindow::on_actionMeme_2_triggered()
{

}
