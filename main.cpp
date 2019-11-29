#include "login.h"
#include "connexions.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile stylefile(":/image/a.qss");
    stylefile.open(QFile::ReadOnly);
    QString style(stylefile.readAll());
    a.setStyleSheet(style);

    LOGIN w;
    Connexions c;
    if(c.ouvrirConnexion()){
    w.show();
    }
    return a.exec();
}
