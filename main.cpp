#include "mainwindow.h"

#include <QApplication>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    if(c.ouvrirconnexion()){
    w.show();}
    return a.exec();
}
