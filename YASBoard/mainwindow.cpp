#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QResizeEvent>
#include <QGridLayout>

#include "videoplayer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setupUI()
{
    // Set window background
    QPixmap bkgnd(":/images/hexagon_background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    // Add grid layout
    QGridLayout *gridLayout = new QGridLayout;
    QWidget *widget = new QWidget();
    widget->setLayout(gridLayout);
    setCentralWidget(widget);

    player = new VideoPlayer(this);
    gridLayout->addWidget(player, 0, 0);


//    QRect availableGeometry = QApplication::desktop()->availableGeometry(player);
//    player->resize(availableGeometry.width(), availableGeometry.height());
    player->show();


    player2 = new VideoPlayer(this);
    gridLayout->addWidget(player2, 1, 0);

//    availableGeometry = QApplication::desktop()->availableGeometry(player2);
//    player2->resize(availableGeometry.width(), availableGeometry.height());
    player2->show();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    player->resize(event->size()/3);
    player2->resize(event->size()/3);
}

void MainWindow::on_actionResize_triggered()
{
    QRect availableGeometry = QApplication::desktop()->availableGeometry(player);
    player->resize(availableGeometry.width(), availableGeometry.height());

    availableGeometry = QApplication::desktop()->availableGeometry(player2);
    player2->resize(availableGeometry.width(), availableGeometry.height());
}

