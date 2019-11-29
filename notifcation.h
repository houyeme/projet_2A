#ifndef NOTIFCATION_H
#define NOTIFCATION_H
#include <QSystemTrayIcon>
#include <QString>
class notifcation
{
public:
    notifcation();
 void afficher();

private:
    QString text="un contrat se termine bientot";

};

#endif // NOTIFCATION_H
