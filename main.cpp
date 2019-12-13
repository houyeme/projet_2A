#include "mainwindow.h"

#include <QApplication>
#include "connexion.h"
#include <iostream>
#include <qdebug.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
Connexion c;
w.setWindowTitle("");
    w.setWindowIcon(QIcon ("C:/Users/ASUS/Desktop/icon.png"));
    if(c.ouvrirConnexion()){
    w.show();

    }
    return a.exec();
}
