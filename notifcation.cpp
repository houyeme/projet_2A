#include "notifcation.h"

notifcation::notifcation()
{

}
void notifcation::afficher(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->setIcon(QIcon("C:/Users/ASUS/Desktop/icon.png"));
        notifyIcon->show();
        notifyIcon->showMessage("NOTICATION CONTRAT ",text,QSystemTrayIcon::Information,15000);


}
