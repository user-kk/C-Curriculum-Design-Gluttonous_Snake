#include "setting.h"
#include "ui_setting.h"
#include"userlist.h"
#include<QDebug>
#include<QFile>
#include<QDataStream>
#include"change_password.h"
#include <QButtonGroup>
Setting::Setting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    connect(&change,&change_password::setting_show,this,&Setting::show);
    connect(&setgame,&Setgame::setting_show,[=](){
        this->show();
    });
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_pushButton_clicked()
{
    this->hide();
    change.show();
//    Userlist a;
//  a[0].userpassword="103";
//  a.save();
}

void Setting::on_pushButton_2_clicked()
{
    this->hide();
    emit menu_show();
}

void Setting::on_pushButton_3_clicked()
{
    this->hide();
    setgame.show();
}
