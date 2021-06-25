#include "bangzhu.h"
#include "ui_bangzhu.h"

BangZhu::BangZhu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BangZhu)
{
    ui->setupUi(this);
    ui->label->setText("游戏说明：\n控制蛇移动用游戏把子上下左右控制蛇的方向，\n寻找吃的东西，每吃一口就能得到一定的积分，\n而且蛇的身子会越吃越长，身子越长\n玩的难度就越大，\n不能碰墙，不能咬到自己的身体，更不能咬自己的尾巴。\n贪吃蛇的唯一的目标就是长成最长的一条蛇！\n吃掉地图上彩色的小圆点，就会变长。\n\n按键说明：\n使用w a s d控制蛇移动");

}

BangZhu::~BangZhu()
{
    delete ui;
}

void BangZhu::on_fanhui_clicked()
{
    this->hide();
    emit menu_show();
}
