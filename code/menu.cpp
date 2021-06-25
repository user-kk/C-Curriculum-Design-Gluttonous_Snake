#include "menu.h"
#include "ui_menu.h"
#include"setting.h"
#include"ranking.h"
#include "bangzhu.h"
int Menu::user=0;
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    setWindowTitle("菜单");
    connect(&setting,&Setting::menu_show,this,&Menu::show);
    connect(&bangzhu,&BangZhu::menu_show,this,&Menu::show);

}

Menu::~Menu()
{
    delete ui;
}
void Menu::menu_show()
{

    this->show();

}

void Menu::on_pushButton_clicked()
{
    emit game_start();
    hide();
}

void Menu::on_pushButton_3_clicked()
{
    exit(0);
}

void Menu::on_pushButton_4_clicked()
{
    this->hide();
    setting.show();
}

void Menu::on_pushButton_2_clicked()
{
    this->hide();
    Ranking *ranking=new Ranking(this);
    r=ranking;
    ranking->show();
    connect(r,&Ranking::menu_show,this,&Menu::show);
}

void Menu::on_btn_bangzhu_clicked()
{
    this->hide();
    bangzhu.show();

}
