#ifndef RANKING_H
#define RANKING_H

#include <QMainWindow>
#include<QListWidgetItem>
namespace Ui {
class Ranking;
}

class Ranking : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ranking(QWidget *parent = 0);
    ~Ranking();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_clicked();
signals:
    void menu_show();
private:
    Ui::Ranking *ui;
    QListWidgetItem*item;
    QListWidgetItem*item1;
};

#endif // RANKING_H
