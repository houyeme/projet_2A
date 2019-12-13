#include "equipement_paramedicale.h"

equipement_paramedicale::equipement_paramedicale()
{

}

equipement_paramedicale::equipement_paramedicale(QString r,QString n,QString t,QString i)
{ reference=r;
  nom=n;
  type=t;
  id_fournisseur=i;
}
void equipement_paramedicale:: setrefrence(QString r)
{
 reference=r;
}
void equipement_paramedicale:: setnom(QString n)
{
  nom=n;
}
void equipement_paramedicale::settype(QString t)
{
    type=t;
}
void equipement_paramedicale::setid_fournisseur(QString i)
{
    id_fournisseur=i;
}
QString equipement_paramedicale:: get_reference()
{
  return reference;
}
QString equipement_paramedicale:: get_nom()
{
    return nom;
}
QString equipement_paramedicale:: get_type()
{
    return type;
}
QString equipement_paramedicale:: get_id_fournisseur()
{
  return id_fournisseur;
}

bool equipement_paramedicale:: ajouter_equipement_paramedicale()
{
    QSqlQuery query;

    query.prepare("INSERT INTO equipement_paramedicale (reference,nom,type,id_fournisseur) " "VALUES (:reference,:nom,:type,:id_fournisseur)");
    query.bindValue(":reference",reference);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
  query.bindValue(":id_fournisseur",id_fournisseur);

    return    query.exec();
}
bool equipement_paramedicale:: modifier_equipement_paramedicale()
{
    QSqlQuery query;
    query.prepare("update equipement_paramedicale set nom=:nom,type=:type,id_fournisseur=:id_fournisseur where reference=:reference");
    query.bindValue(":reference",reference);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":id_fournisseur",id_fournisseur);
    return    query.exec();
}
bool equipement_paramedicale:: supprimer_equipement_paramedicale()
{
    QSqlQuery query;
    query.prepare("Delete from equipement_paramedicale where reference = :reference ");
    query.bindValue(":reference", reference);
    return    query.exec();
}
QSqlQueryModel * equipement_paramedicale:: afficher_equipement_paramedicale()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from equipement_paramedicale");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));

        return model;

}
QSqlQueryModel * equipement_paramedicale::afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select reference from equipement_paramedicale");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));


            return model;
}
void equipement_paramedicale:: chercher()
{    QSqlQuery query1;
     query1.prepare("SELECT nom,type,id_fournisseur FROM equipement_paramedicale WHERE reference =:reference");
     query1.bindValue(":reference",reference);
     query1.exec();
     while(query1.next())
     {
     nom = query1.value(0).toString();
     type = query1.value(1).toString();
     id_fournisseur= query1.value(2).toString();
     }}
QSqlQueryModel * equipement_paramedicale::recherche(QString champ,QString valeur,int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
   { query.prepare("SELECT * FROM equipement_paramedicale WHERE ("+champ+" LIKE :valeur) order by reference");}
    else   { query.prepare("SELECT * FROM equipement_paramedicale WHERE ("+champ+" LIKE :valeur) order by reference desc");}
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
