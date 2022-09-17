#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "videoplayer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionResize_triggered();

private:
    Ui::MainWindow *ui;

    VideoPlayer *player;
    VideoPlayer *player2;

    void setupUI();
    void resizeEvent(QResizeEvent*);
};
#endif // MAINWINDOW_H
