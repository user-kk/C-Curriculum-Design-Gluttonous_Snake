#include "userlist.h"
#include"user.h"
#include"usernode.h"
#include<QFile>
#include<QDataStream>
#include<QDebug>
Userlist::Userlist()
{
number=0;
Usernode*node;
Usernode*node2;
QFile file("userinfo.txt");
file.open(QIODevice::ReadOnly);
QDataStream in(&file);
User user;
for(;!(in.atEnd());number++)
    {
        in>>user;
        if(number==0)
        {
            usernode_head=new Usernode;
            usernode_head->user=user;
        }
        else if(number==1)
        {
            node=new Usernode;
            node->user=user;
            usernode_head->next=node;
            node2=node;
        }
        else
        {
            node=new Usernode;
            node->user=user;
            node2->next=node;
            node2=node;
        }
}

if(number==1)usernode_head->next=NULL;
if(number>1) node2->next=NULL;
file.close();
}
Userlist::~Userlist()
{
    if(number==1)
        delete usernode_head;
    if(number>1)
    {
        Usernode*node;
        for(int i=0;i<=number-1;i++)
        {
          node=usernode_head;
          for(int j=1;j<=number-i-1;j++)
          {
              node=node->next;
          }
          delete node;

        }
    }
}
User&Userlist::operator[](int i)
{
     Usernode*node=usernode_head;
     if(i<number)
     {
         for(int j=1;j<=i;j++)
            node=node->next;
         return node->user;
     }
}
QDataStream& operator<<(QDataStream &out,  Userlist&t)
{
    for(int i=0;i<=t.number-1;i++)
    {
        out<<t[i];
    }
}
void Userlist::save()
{
    QFile file("userinfo.txt");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out<<(*this);
    file.close();
}
