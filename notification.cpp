#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{
num=0;
}

void notification::notification_ajout_patient(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/user/Desktop/1.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un nouveau patient a été ajouté !",QSystemTrayIcon::Information,15000);
//num++;
}

void notification::notification_ajout_rdv(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/user/Desktop/1.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un nouveau rendez-vous a été ajoutée !",QSystemTrayIcon::Information,15000);
//num++;
}


void notification::notification_Ouverture(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/user/Desktop/1.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Gestion d'agence de voyage","Nouvelle instance ouverte",QSystemTrayIcon::Information,15000);
//num++;
}
