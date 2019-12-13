#include "notifcation.h"

notifcation::notifcation()
{

}
notifcation::notifcation(QString titre,QString text){
    this->text=text;
    this->titre=titre;
}
void notifcation::afficher(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->setIcon(QIcon("C:/Users/ASUS/Desktop/icon.png"));
        notifyIcon->show();
        notifyIcon->showMessage(titre,text,QSystemTrayIcon::Information,15000);


}
