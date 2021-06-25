#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include<Qpainter>
#include "food.h"
#include <Qt>
#include"snake.h"
#include<QDebug>
#include "endgame.h"
#include<QString>
#include <QImage>
#include<QMediaPlayer>
int MainWindow::interval=150;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startsound=new QMediaPlayer;
    startsound->setMedia(QUrl("qrc:/7895.wav"));
    startsound->setVolume(80);
    static int a=0;
    static int e=0;
    resize(10*MainWindow::size+200,10*MainWindow::size+9);
    endgame.setModal(false);
    connect(&timer,&QTimer::timeout,[=](){
        snake.move();
        update();
    });
    connect(&snake,&Snake::die,&timer,&QTimer::stop);
    connect(&snake,&Snake::die,[=](){
        this->hide();

        e=0;
        QString b=QString::number(e);
        ui->label_4->setText(b);
        b=QString::number(a);
        b=b+" "+"秒";
        ui->label->setText(b);
    });
    connect(&snake, &Snake::die, &endgame, &EndGame::endgame_show);
    connect(&endgame,&EndGame::again,[=]()mutable{
            snake.clear();
            this->show();
            a=0;
            timer.start(MainWindow::interval);
            startsound->play();
            });
    connect(&timer2,&QTimer::timeout,[=]()mutable{
        a++;
        QString b;
        if(a<60)
        {
            b=QString::number(a);
            b=b+" "+"秒";
        }
        else
        {
            b=QString::number(a/60)+"分"+QString::number(a%60)+"秒";
        }

       ui->label->setText(b);
    });
    connect(&snake,&Snake::eat,[=](){
        e++;
        QString b=QString::number(e);
        ui->label_4->setText(b);
    });
    connect(&snake, &Snake::die,[=](){
        endgame.time_show(a);

        startsound->stop();
        a=0;
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
     {
        case Qt::Key_W:snake.setdirection1('w');break;
        case Qt::Key_A:snake.setdirection1('a');break;
        case Qt::Key_S:snake.setdirection1('s');break;
        case Qt::Key_D:snake.setdirection1('d');break;
     }

}
void MainWindow::paintEvent(QPaintEvent *)
{
    vector< vector<int> > body = snake.getbody();
    QPainter *painter = new QPainter(this);

    QImage img(":/666.jpg");
    painter->drawImage(0,0,img);


    QPen pen1(QColor(255,0,0));
    pen1.setWidth(0);
    QBrush brush1(QColor(255,0,0));

    QPen pen2(QColor(0,0,255));
    pen2.setWidth(0);
    QBrush brush2(QColor(0,0,255));

    QPen pen3(QColor(255,0,255));
    pen3.setWidth(0);
    QBrush brush3(QColor(255,0,255));
    QPen pen4(QColor(0,0,0));
    pen4.setWidth(0);
    painter->setPen(pen4);
    painter->drawRect(0,0,10*MainWindow::size+6,10*MainWindow::size+7);
    for(int i=0;i<body.size()-1;i++)
    {
       painter->setPen(pen1);
       painter->setBrush(brush1);
        painter->drawEllipse(10*body[i][0] + 5,10*body[i][1] + 5,12,12);
    }

    painter->setPen(pen2);
    painter->setBrush(brush2);
    painter->drawEllipse(10*snake.gethx()+5,10*snake.gethy()+5,12,12);

    painter->setPen(pen3);
    painter->setBrush(brush3);
    painter->drawEllipse(10*Food::getfx()+5,10*Food::getfy()+5,8,8);
    delete painter;

}
void MainWindow::start()
{
    this->show();
    snake.clear();
    timer.start(MainWindow::interval);
    timer2.start(1000);
    startsound->play();
}
