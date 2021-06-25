#include "denglu.h"
#include "ui_denglu.h"
#include <QMessageBox>
#include <fstream>
#include<qdialog.h>
#include"zhuce.h"
#include <user.h>
#include<QDebug>
#include"menu.h"
DengLu::DengLu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DengLu)
{
    ui->setupUi(this);
}

DengLu::~DengLu()
{
    delete ui;
}

void DengLu::on_btn_denglu_clicked()
{
    User currentUser;
    currentUser.username = ui->edit_name->text();
    currentUser.userpassword = ui->edit_password->text();
    if(currentUser.dengLu() == 0)   //登录成功
    {
        this->hide();
        Menu::user=currentUser.find_same_username()-1;
        emit start_log_in();

    }
    if(currentUser.dengLu() == 1)   //用户名不存在
    {
        ui->edit_name->clear();
        ui->edit_password->clear();
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label_3->setPalette(pa);
        ui->label_3->setText("用户名不存在");
        connect(ui->edit_name,&QLineEdit::editingFinished,[=](){
            ui->label_3->setText(" ");
        });

    }
    if(currentUser.dengLu() == 2)   //密码错误
    {
        ui->edit_password->clear();
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label_4->setPalette(pa);
        ui->label_4->setText("密码错误");
        connect(ui->edit_password,&QLineEdit::editingFinished,[=](){
            ui->label_4->setText(" ");
        });
    }
    if(currentUser.dengLu() == 3)
    {
        ui->edit_password->clear();
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label_3->setPalette(pa);
        ui->label_3->setText("请输入用户名");
        connect(ui->edit_password,&QLineEdit::editingFinished,[=](){
            ui->label_3->setText(" ");
        });
    }
    if(currentUser.dengLu() == 4)
    {
        ui->edit_password->clear();
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label_4->setPalette(pa);
        ui->label_4->setText("请输入密码");
        connect(ui->edit_password,&QLineEdit::editingFinished,[=](){
            ui->label_4->setText(" ");
        });
    }
    if(currentUser.dengLu() == 5)
    {
        ui->edit_password->clear();
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->label_3->setPalette(pa);
        ui->label_3->setText("请输入用户名");
        ui->label_4->setPalette(pa);
        ui->label_4->setText("请输入密码");
        connect(ui->edit_password,&QLineEdit::editingFinished,[=](){
            ui->label_3->setText(" ");
            ui->label_4->setText(" ");
        });
    }
}
void DengLu::on_btn_zhuce_clicked()
{
    ZhuCe zhuce(this);
    zhuce.exec();
}
