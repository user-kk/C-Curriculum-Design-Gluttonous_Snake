#include "change_password.h"
#include "ui_change_password.h"
#include<QLineEdit>
#include"userlist.h"
#include"menu.h"
#include"user.h"
#include<QPalette>
#include<QLabel>
#include<QDebug>
change_password::change_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_password)
{
    ui->setupUi(this);

    connect(ui->lineEdit_1,&QLineEdit::editingFinished,[=](){
        if(!(ui->lineEdit_1->text()=="\0"))
        {
           Userlist userlist;
           User user=userlist[Menu::user];
            if(user.userpassword==ui->lineEdit_1->text())
            {
                QPalette pa;
                pa.setColor(QPalette::WindowText,Qt::green);
                ui->label_4->setPalette(pa);
                ui->label_4->setText("密码正确");


            }
            else
            {
                QPalette pa;
                pa.setColor(QPalette::WindowText,Qt::red);
                ui->label_4->setPalette(pa);
                ui->label_4->setText("密码错误");
                ui->lineEdit_1->clear();
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

change_password::~change_password()
{
    delete ui;
}

void change_password::on_pushButton_2_clicked()
{
    this->close();
    emit setting_show();
}

void change_password::on_pushButton_clicked()
{
    this->close();
    Userlist userlist;
    User user=userlist[Menu::user];
    if(user.userpassword==ui->lineEdit_1->text()&&((ui->lineEdit_2->text())==(ui->lineEdit_3->text())))
    {
        userlist[Menu::user].userpassword=ui->lineEdit_2->text();
        userlist.save();
    }
    this->close();
    emit setting_show();
}
