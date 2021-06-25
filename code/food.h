#ifndef FOOD_H
#define FOOD_H
#include<vector>
using namespace std;
class Food
{
public:
    Food();
    static void f5(vector< vector<int> > body); //刷新食物
    static int getfx(void)
    {
        return fx;
    }
    static int getfy(void)
    {
        return fy;
    }

private:
    static int fx,fy;


};

#endif // FOOD_H
