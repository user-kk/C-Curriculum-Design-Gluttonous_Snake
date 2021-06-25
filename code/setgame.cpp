#include "setgame.h"
#include "ui_setgame.h"
#include<QButtonGroup>
#include"mainwindow.h"
Setgame::Setgame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Setgame)
{
    ui->setupUi(this);
    bg=new QButtonGroup(this);
    bg->addButton(ui->radioButton,0);
    bg->addButton(ui->radioButton_2,1);
    bg->addButton(ui->radioButton_3,2);
}

Setgame::~Setgame()
{
    delete ui;
}

void Setgame::on_pushButton_2_clicked()
{
    this->hide();
    emit setting_show();
}

void Setgame::on_pushButton_clicked()
{
    int a=bg->checkedId();

    switch(a)
    {
    case 0:
    MainWindow::interval=150;
      break;
    case 1:
    MainWindow::interval=100;
      break;
    case 2:
    MainWindow::interval=75;
    break;
    }
    this->hide();
    emit setting_show();
}
