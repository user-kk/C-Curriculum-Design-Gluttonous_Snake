#include "endgame.h"
#include "ui_endgame.h"
#include<QDebug>
#include<QString>
#include<QFont>
#include"userlist.h"
#include"user.h"
#include"menu.h"
#include<QLabel>
EndGame::EndGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndGame)
{
    ui->setupUi(this);
}

EndGame::~EndGame()
{
    delete ui;
}

void EndGame::on_pushButton_clicked()
{
    emit again();
   this->hide();

}

void EndGame::on_pushButton_2_clicked()
{
    emit return_menu();
    this->hide();
}
void EndGame::endgame_show(int score)
{
    QString a=QString::number(score);
    QFont ft;
    ft.setPointSize(14);
    ui->label->setFont(ft);
    ui->label->setText(a);
    Userlist userlist1;
    User user=userlist1[Menu::user];
    int min=user.score[0];
    int max=user.score[0];
    int k=0;
    for(int i=0;i<=9;i++)
    {
        if(min>user.score[i])
        {
           min=user.score[i];
           k=i;
        }
    }
    //QDebug()<<score;

    if(score>min)
    {
        userlist1[Menu::user].score[k]=score;
    }
    userlist1.save();
    Userlist userlist2;
    user=userlist2[Menu::user];
    for(int i=0;i<=9;i++)
    {
        if(max<user.score[i])
        {
           max=user.score[i];
        }
    }
    a=QString::number(max);
    ui->label_4->setFont(ft);
    ui->label_4->setText(a);
    this->show();
}
void EndGame::time_show(int a)
{
    QFont ft;
    ft.setPointSize(14);
    ui->label_6->setFont(ft);
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

   ui->label_6->setText(b);
}
