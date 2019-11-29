#include "connexions.h"
#include <QSqlError>
Connexions::Connexions(){
                      }
bool Connexions::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("mybas");
                           db.setUserName("rayen");//inserer nom de l'utilisateur
                           db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connexions::fermerConnexion()
{db.close();}
