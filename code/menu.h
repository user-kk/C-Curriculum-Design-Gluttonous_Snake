#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include"setting.h"
#include"ranking.h"
#include "bangzhu.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

    void menu_show();
    Setting setting;
    static int user;

signals:
    void game_start();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_btn_bangzhu_clicked();

private:
    Ui::Menu *ui;
    Ranking*r;
    BangZhu bangzhu;
};


#endif // MENU_H
