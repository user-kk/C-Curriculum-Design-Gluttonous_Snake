#include "food.h"
#include "time.h"
#include <vector>
#include"mainwindow.h"
using namespace std;
int Food::fx=0;int Food::fy=0;
Food::Food()
{

}
void Food::f5(vector< vector<int> > body)
{
    srand((unsigned)time(NULL));
    while(1)
    {
        int tempx=rand()%MainWindow::size;
        int tempy=rand()%MainWindow::size;
        for(int i=0;i<body.size();i++)
        {
            if(tempx!=body[i][0]||tempy!=body[i][1])
            {
                Food::fx=tempx;
                Food::fy=tempy;
                return;
            }
        }
    }
}
