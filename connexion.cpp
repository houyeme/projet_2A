#include "connexion.h"

connexion::connexion()
{

}

bool connexion::ouvrirconnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setConnectOptions();
db.setDatabaseName("mybas");
db.setUserName("Mahdi");//inserer nom de l'utilisateur
db.setPassword("esprit19");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
else{
 throw QString("ERREUR Paramétres" + db.lastError().text()); }
  return  test;
}
