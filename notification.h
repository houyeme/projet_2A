#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QSystemTrayIcon>
#include<QString>
class notification
{
private:
    int num;
public:
    notification();
    void notification_supp_med(QString);
    void notification_Ouverture(QString id);
    void notification_supp_equi(QString id);
};

#endif // NOTIFICATION_H
