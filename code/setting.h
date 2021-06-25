#ifndef SETTING_H
#define SETTING_H

#include <QMainWindow>
#include"change_password.h"
#include"setgame.h"
namespace Ui {
class Setting;
}

class Setting : public QMainWindow
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();
signals:
    void menu_show();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Setting *ui;
    change_password change;
    Setgame setgame;
};

#endif // SETTING_H
