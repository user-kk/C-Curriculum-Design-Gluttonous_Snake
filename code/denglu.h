#ifndef DENGLU_H
#define DENGLU_H

#include <QWidget>

namespace Ui {
class DengLu;
}

class DengLu : public QWidget
{
    Q_OBJECT

public:
    explicit DengLu(QWidget *parent = 0);
    ~DengLu();


signals:
    void start_log_in();
private slots:
    void on_btn_denglu_clicked();

    void on_btn_zhuce_clicked();

private:
    Ui::DengLu *ui;
};

#endif // DENGLU_H
