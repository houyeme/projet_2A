#include "login.h"
#include "connexion.h"
#include "gestion_de_mediacament.h"
#include <QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login w;
    w.show();
    connexion c;
    bool test=c.ouvrirConnexion();
    return a.exec();
}
