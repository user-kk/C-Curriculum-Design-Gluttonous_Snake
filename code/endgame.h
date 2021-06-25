#ifndef ENDGAME_H
#define ENDGAME_H

#include <QDialog>

namespace Ui {
class EndGame;
}

class EndGame : public QDialog
{
    Q_OBJECT

public:
    explicit EndGame(QWidget *parent = 0);
    ~EndGame();
    void time_show(int a);
public slots:
    void endgame_show(int score);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
signals:
    void again();
    void return_menu();
private:
    Ui::EndGame *ui;
};

#endif // ENDGAME_H
