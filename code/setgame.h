#ifndef SETGAME_H
#define SETGAME_H

#include <QMainWindow>
#include<QButtonGroup>
namespace Ui {
class Setgame;
}

class Setgame : public QMainWindow
{
    Q_OBJECT

public:
    explicit Setgame(QWidget *parent = 0);
    ~Setgame();
signals:
    void setting_show();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Setgame *ui;
    QButtonGroup *bg;
};

#endif // SETGAME_H
