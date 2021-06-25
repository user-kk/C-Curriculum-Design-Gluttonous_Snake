#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"snake.h"
#include <QPainter>
#include <QKeyEvent>
#include "endgame.h"
#include<QTimer>
#include<QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
    EndGame endgame;
    static int interval;
static const int size=40;
public slots:
    void start(); //从单人游戏进入
private:
    Ui::MainWindow *ui;
    Snake snake;
    QTimer timer;
    QTimer timer2;
    QMediaPlayer *startsound;
};
#endif // MAINWINDOW_H
