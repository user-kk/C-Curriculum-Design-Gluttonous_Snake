#ifndef USERLIST_H
#define USERLIST_H
#include"user.h"
#include"usernode.h"
#include<QDataStream>
class Userlist
{
public:
    Userlist();
    Usernode*usernode_head;
    int number;
    ~Userlist();
    User&operator[](int i);
    friend QDataStream& operator<<(QDataStream &out,  Userlist&t);
    void save();
private:


};

#endif // USERLIST_H
