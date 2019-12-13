#ifndef NOTIFCATION_H
#define NOTIFCATION_H
#include <QSystemTrayIcon>
#include <QString>
class notifcation
{
public:
    notifcation();
    notifcation(QString titre,QString text);
 void afficher();


private:
    QString text;
    QString titre;

};

#endif // NOTIFCATION_H
