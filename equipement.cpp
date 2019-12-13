#include "equipement.h"

equipement::equipement()
{

}

equipement::equipement(QString r,QString n,QString t,QString i)
{ reference=r;
  nom=n;
  type=t;
  id_fournisseur=i;
}
void equipement:: setrefrence(QString r)
{
 reference=r;
}
void equipement:: setnom(QString n)
{
  nom=n;
}
void equipement::settype(QString t)
{
    type=t;
}
void equipement::setid_fournisseur(QString i)
{
    id_fournisseur=i;
}
QString equipement:: get_reference()
{
  return reference;
}
QString equipement:: get_nom()
{
    return nom;
}
QString equipement:: get_type()
{
    return type;
}
QString equipement:: get_id_fournisseur()
{
  return id_fournisseur;
}

bool equipement:: ajouter_equipement()
{
    QSqlQuery query;

    query.prepare("INSERT INTO equipement (reference,nom,type,id_fournisseur) " "VALUES (:reference,:nom,:type,:id_fournisseur)");
    query.bindValue(":reference",reference);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
  query.bindValue(":id_fournisseur",id_fournisseur);

    return    query.exec();
}
bool equipement:: modifier_equipement()
{
    QSqlQuery query;
    query.prepare("update equipement set nom=:nom,type=:type,id_fournisseur=:id_fournisseur where reference=:reference");
    query.bindValue(":reference",reference);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":id_fournisseur",id_fournisseur);
    return    query.exec();
}
bool equipement:: supprimer_equipement()
{
    QSqlQuery query;
    query.prepare("Delete from equipement where reference = :reference ");
    query.bindValue(":reference", reference);
    return    query.exec();
}
QSqlQueryModel * equipement:: afficher_equipement()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from equipement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));

        return model;

}
QSqlQueryModel * equipement::afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select reference from equipement");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));


            return model;
}
void equipement:: chercher()
{    QSqlQuery query1;
     query1.prepare("SELECT nom,type,id_fournisseur FROM equipement WHERE reference =:reference");
     query1.bindValue(":reference",reference);
     query1.exec();
     while(query1.next())
     {
     nom = query1.value(0).toString();
     type = query1.value(1).toString();
     id_fournisseur= query1.value(2).toString();
     }}
QSqlQueryModel * equipement::recherche(QString champ,QString valeur,int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
   { query.prepare("SELECT * FROM equipement WHERE ("+champ+" LIKE :valeur) order by reference");}
    else   { query.prepare("SELECT * FROM equipement WHERE ("+champ+" LIKE :valeur) order by reference desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_fournisseur"));
    return model;
}
