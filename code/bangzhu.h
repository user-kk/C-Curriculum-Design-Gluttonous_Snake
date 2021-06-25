#ifndef BANGZHU_H
#define BANGZHU_H

#include <QWidget>

namespace Ui {
class BangZhu;
}

class BangZhu : public QWidget
{
    Q_OBJECT

public:
    explicit BangZhu(QWidget *parent = 0);
    ~BangZhu();

private slots:
    void on_fanhui_clicked();

signals:
    void menu_show();
private:
    Ui::BangZhu *ui;
};

#endif // BANGZHU_H
