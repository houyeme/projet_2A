#include "pharmacien.h"


pharmacien::pharmacien()
{

}
pharmacien::pharmacien(QString id ,QString mot_de_passe)
{ this->id=id;
    this->mot_de_passe=mot_de_passe;
}
bool pharmacien:: authentification()
{
    QSqlQuery q;
    q.prepare("select * from pharmacien where (id=:id) and (mot_de_passe=:mot_de_passe)");
    q.bindValue(":id",id);
    q.bindValue(":mot_de_passe",mot_de_passe);
    q.exec();
    return q.first();

}
