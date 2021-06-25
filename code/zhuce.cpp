#include "zhuce.h"
#include "ui_zhuce.h"
#include <QPalette>
#include<QFile>
#include"user.h"
#include <QDebug>
#include<QDataStream>
#include<QLineEdit>
ZhuCe::ZhuCe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ZhuCe)
{
    ui->setupUi(this);

    connect(ui->lineEdit_1,&QLineEdit::editingFinished,[=](){
        if(!(ui->lineEdit_1->text()=="\0"))
        {
            User user;
            user.username=ui->lineEdit_1->text();
            if(user.find_same_username())
            {
                QPalette pa;
                pa.setColor(QPalette::WindowText,Qt::red);
                ui->label_4->setPalette(pa);
                ui->label_4->setText("用户名已存在！");
                ui->lineEdit_1->clear();


            }
            else
            {
                QPalette pa;
                pa.setColor(QPalette::WindowText,Qt::green);
                ui->label_4->setPalette(pa);
                ui->label_4->setText("符合要求");
            }
        }
    });
    connect(ui->lineEdit_3,&QLineEdit::editingFinished,[=](){
        if((ui->lineEdit_2->text())==(ui->lineEdit_3->text()))
        {
            QPalette pa;
            pa.setColor(QPalette::WindowText,Qt::green);
            ui->label_5->setPalette(pa);
            ui->label_5->setText("符合要求");
        }
        else
        {
            QPalette pa;
            pa.setColor(QPalette::WindowText,Qt::red);
            ui->label_5->setPalette(pa);
            ui->label_5->setText("两次输入的密码不一致");
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
        }
    });









}

ZhuCe::~ZhuCe()
{
    delete ui;
}


void ZhuCe::on_pushButton_2_clicked()
{
    this->hide();
}

void ZhuCe::on_pushButton_clicked()
{
    User user;
    user.username=ui->lineEdit_1->text();
    if((!(user.find_same_username()))&&((ui->lineEdit_2->text())==(ui->lineEdit_3->text())))
    {
        user.userpassword=ui->lineEdit_2->text();
        QFile file("userinfo.txt");
        file.open(QIODevice::Append);
        QDataStream out(&file);
        out<<user;
        file.close();
        this->hide();
    }
}
