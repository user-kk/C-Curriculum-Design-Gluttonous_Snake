#ifndef USER_H
#define USER_H
#include<QString>
#include<QDataStream>
class User
{
public:
    User();
    QString username;
    QString userpassword;
    int score[10];
    int find_same_username();
    friend QDataStream& operator<<(QDataStream &out, const User &t);
    friend QDataStream& operator>>(QDataStream &in, User &t);
    int dengLu();
    void rank();
};

#endif // USER_H
