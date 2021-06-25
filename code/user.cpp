#include "user.h"
#include<QFile>
#include<QDataStream>
#include<QString>
#include<QDebug>
User::User()
{
for(int i=0;i<=9;i++)
    score[i]=0;
}
int User::find_same_username()
{
    int i=1;
    QFile file("userinfo.txt");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    User user;
    for(;!(in.atEnd());i++)
        {
            in>>user;
            if(username==user.username)
            {
                file.close();
                return i;
            }
        }
    file.close();
    return 0;
}

QDataStream& operator<<(QDataStream &out, const User &t)
{
    out<<t.username<<t.userpassword;
    for(int i=0;i<=9;i++)
        out<<t.score[i];
}
QDataStream& operator>>(QDataStream &in,User &t)
{
    in>>t.username>>t.userpassword;
    for(int i=0;i<=9;i++)
        in>>t.score[i];
}
int User::dengLu()
{
    QFile file("userinfo.txt");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    if(username == "\0" && userpassword == "\0")
    {
        return 5;
    }

    if(username == "\0")    //用户名为空
    {
        return 3;
    }
    if(userpassword == "\0")    //密码为空
    {
        return 4;
    }


    int x = this->find_same_username();

    User memo;

    if(x == 0)
        return 1; //用户名不存在
    else
    {
        for(int i = 0; i <x ; i++)
        {
            in >> memo;
        }
        if(memo.userpassword == userpassword)
        {
            return 0; //登录成功
        }
        else
        {
            return 2;//密码错误
        }
    }

}
void User::rank()
{
    int i=0,j=0,t;
    for(i;i<=9;i++)
        for(j=0;j<9-i;j++)
        {
            if(score[j]<score[j+1])
            {
                t=score[j];
                score[j]=score[j+1];
                score[j+1]=t;
            }
        }

}
