#include "secretaire.h"
#include <QSqlQuery>
secretaire::secretaire()
{

}
secretaire::secretaire(QString id ,QString mot_de_passe)
{ this->id=id;
    this->mot_de_passe=mot_de_passe;
}
bool secretaire:: authentification()
{
    QSqlQuery q;
    q.prepare("select * from secretaire where (id=:id) and (mot_de_passe=:mot_de_passe)");
    q.bindValue(":id",id);
    q.bindValue(":mot_de_passe",mot_de_passe);
    q.exec();
    return q.first();

}
