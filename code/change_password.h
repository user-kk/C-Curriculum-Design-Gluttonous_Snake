#ifndef CHANGE_PASSWORD_H
#define CHANGE_PASSWORD_H

#include <QDialog>

namespace Ui {
class change_password;
}

class change_password : public QDialog
{
    Q_OBJECT

public:
    explicit change_password(QWidget *parent = 0);
    ~change_password();
signals:
    void setting_show();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::change_password *ui;
};

#endif // CHANGE_PASSWORD_H
