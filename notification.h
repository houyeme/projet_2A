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
    void notification_ajout_patient(QString);
    void notification_Ouverture(QString id);
    void notification_ajout_rdv(QString id);
};

#endif // NOTIFICATION_H
