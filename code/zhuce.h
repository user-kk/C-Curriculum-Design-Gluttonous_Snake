#ifndef ZHUCE_H
#define ZHUCE_H

#include <QDialog>

namespace Ui {
class ZhuCe;
}

class ZhuCe : public QDialog
{
    Q_OBJECT

public:
    explicit ZhuCe(QWidget *parent = 0);
    ~ZhuCe();



private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ZhuCe *ui;
};

#endif // ZHUCE_H
