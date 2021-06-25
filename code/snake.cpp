#include "snake.h"
#include <QDebug>
#include <food.h>
#include<vector>
#include<QObject>
#include"mainwindow.h"
using namespace std;
Snake::Snake()
{

    hx=3;
    hy=0;
    vector<int>a1={0,0};
    vector<int>a2={1,0};
    vector<int>a3={2,0};
    vector<int>a4={3,0};
    body.push_back(a1);
    body.push_back(a2);
    body.push_back(a3);
    body.push_back(a4);
    direction='d';
    direction1='d';
    Food::f5(body);
}

Snake::~Snake()
{

}
void Snake::move()
{
   int x=Food::getfx();
   int y=Food::getfy();
   if((direction=='a'&&direction1=='w')||(direction=='a'&&direction1=='s')||(direction=='d'&&direction1=='w')||(direction=='d'&&direction1=='s')||(direction=='w'&&direction1=='a')||(direction=='w'&&direction1=='d')||(direction=='s'&&direction1=='a')||(direction=='s'&&direction1=='d'))
       direction=direction1;
    switch (direction) {
    case 'd':hx++;break;
    case 'a':hx--;break;
    case 'w':hy--;break;
    case 's':hy++;break;
    }
    vector<int>a={hx,hy};
    body.push_back(a);
    if(hx==x&&hy==y)
    {
        Food::f5(body);
        emit eat();
    }
    else
    {
        body.erase(body.begin());
    }
    if(hx<0||hx>=MainWindow::size||hy<0||hy>=MainWindow::size)
    {
        emit die(this->getscore());

    }
    for(int i=0;i<body.size()-1;i++)
    {
        if(hx==body[i][0]&&hy==body[i][1])
        {
            emit die(this->getscore());
        }
    }
}
vector< vector<int> >Snake::getbody()
{
    return body;
}
int Snake::gethx()
{
    return hx;
}
int Snake::gethy()
{
    return hy;
}

void Snake::setdirection1(char c)
{
    direction1=c;
}
void Snake::clear()
{
    body.clear();
    hx=3;
    hy=0;
    vector<int>a1={0,0};
    vector<int>a2={1,0};
    vector<int>a3={2,0};
    vector<int>a4={3,0};
    body.push_back(a1);
    body.push_back(a2);
    body.push_back(a3);
    body.push_back(a4);
    direction='d';
    direction1='d';
    Food::f5(body);
}
int Snake::getscore()
{
    return body.size()-4;
}
