#include "ranking.h"
#include "ui_ranking.h"
#include<QListWidget>
#include<QListWidgetItem>
#include"userlist.h"
#include"user.h"
#include<QStringList>
#include<QDebug>
#include"menu.h"
Ranking::Ranking(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ranking)
{
    ui->setupUi(this);  
    Userlist userlist;
    int n=userlist.number;
    User user[n];
    for(int a=0;a<=n-1;a++)
    {
        user[a]=userlist[a];
    }
    for(int a=0;a<=n-1;a++)
    {
        user[a].rank();
    }
    int i=0,j=0;
    User u;
    for(;i<=n;i++)
        for(j=0;j<=n-i-1;j++)
        {
            if(user[j].score[0]<user[j+1].score[0])
            {
                u=user[j];
                user[j]=user[j+1];
                user[j+1]=u;
            }
        }
    item=new QListWidgetItem[n];
    int p;
    for(int a=0;a<=n-1;a++)
    {
       item[a]=QListWidgetItem("第"+QString::number(a+1)+"名为："+user[a].username+"\t\t  最高分："+QString::number(user[a].score[0]));
       if(userlist[Menu::user].username==user[a].username)
       {
           p=a+1;
       }
    }
    for(int a=0;a<=n-1;a++)
    {
       ui->listWidget_2->addItem(item+a);
    }
    ui->label_3->setText("您的当前排名为："+QString::number(p));
    item1=new QListWidgetItem[10];
    userlist[Menu::user].rank();
    for(int a=0;a<=9;a++)
    {
       if(a!=9)
           item1[a]=QListWidgetItem("第"+QString::number(a+1)+"名为：                     "+QString::number(userlist[Menu::user].score[a])+"分");
       else
           item1[a]=QListWidgetItem("第"+QString::number(a+1)+"名为：                   "+QString::number(userlist[Menu::user].score[a])+"分");
    }
    for(int a=0;a<=9;a++)
    {
       ui->listWidget->addItem(item1+a);
    }
    ui->label_4->setText("您的最高分为："+QString::number(userlist[Menu::user].score[0]));
}

Ranking::~Ranking()
{
    delete ui;
    delete[]item;
    delete[]item1;
}

void Ranking::on_toolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Ranking::on_toolButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);

}

void Ranking::on_pushButton_clicked()
{
    this->hide();
    emit menu_show();
}
