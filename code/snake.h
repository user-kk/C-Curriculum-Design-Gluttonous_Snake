#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include<vector>
#include<QObject>

using namespace std;


class Snake : public QObject
{
    Q_OBJECT

public:
     Snake();
    ~Snake();
    vector< vector<int> >getbody();
    int gethx();
    int gethy();
    void setdirection1(char c);
    void clear();
    int getscore();
signals:
   void die(int score);
   void eat();
public slots:
    void move();
private:
    int hx;
    int hy;
    vector< vector<int> > body;
    char direction;
    char direction1;

};

#endif // SNAKE_H
