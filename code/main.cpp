#include "mainwindow.h"
#include <QApplication>
#include "denglu.h"
#include "menu.h"
#include "endgame.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DengLu d;
    d.show();
    Menu m;
    DengLu::connect(&d,&DengLu::start_log_in,&m,&Menu::menu_show);
    QObject::connect(&m,&Menu::game_start,&w,&MainWindow::start);
    QObject::connect(&w.endgame,&EndGame::return_menu,&m,&Menu::menu_show);
    return a.exec();
}
