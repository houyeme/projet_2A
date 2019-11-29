#include "equipement.h"
#include <QDebug>
equipement::equipement()
{
id="";
type="";
nom="";
reference="";

}
equipement::equipement(QString id ,QString type ,QString nom ,QString reference,QString pays  )
{
  this->id=id;
  this->type=type;
  this->nom=nom;
    this->reference=reference;
this->pays=pays;
}
QString equipement::get_type(){return  type;}
QString equipement::get_nom(){return nom;}
QString equipement::get_id(){return id;}
QString equipement::get_reference(){return  reference;}
QString equipement::get_pays(){return  pays;}
void equipement::set_pays(QString pays){
    this->pays=pays;
}

void equipement::set_reference(QString reference){
    this->reference=reference;
}
void equipement::set_nom(QString nom) {
    this->nom=nom;}
void equipement::set_type(QString type) {
    this->type=type;}
void equipement::set_id(QString id )
{ this->id=id ; }
bool equipement::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO EQUIPEMENT (reference,nom,type,id_fournisseur,pays) "
                    "VALUES (:reference,:nom,:type,:id_fournisseur,:pays)");
query.bindValue(":reference", reference);
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":id_fournisseur", id );
query.bindValue(":pays",pays);

return    query.exec();
}

QSqlQueryModel * equipement::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from EQUIPEMENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PAYS"));
return model;
}
QSqlQueryModel * equipement::afficherlist()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select reference from EQUIPEMENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
return model;
}

bool equipement::supprimer(QString reference)
{
QSqlQuery query;
query.prepare("Delete from EQUIPEMENT where reference=:N ");
query.bindValue(":N",reference);
return query.exec();
}
void equipement::chercher(){
QSqlQuery query1;
query1.prepare("SELECT nom,type,id_fournisseur FROM EQUIPEMENT WHERE REFERENCE=:reference");
query1.bindValue(":reference",reference);
query1.exec();
while(query1.next())
{ nom = query1.value(0).toString();
 type = query1.value(1).toString();
 id = query1.value(2).toString(); }
}
bool equipement::modifier(){
    QSqlQuery query1;
    query1.prepare("UPDATE EQUIPEMENT set nom=:nom,type=:type,id_fournisseur=:id_fournisseur,pays=:pays WHERE REFERENCE=:reference");
    query1.bindValue(":reference",reference);
    query1.bindValue(":nom",nom);
    query1.bindValue(":type",type);
    query1.bindValue(":id_fournisseur",id);
    query1.bindValue(":pays",pays);
    return (query1.exec());
}
QSqlQueryModel * equipement::recherche(QString valeur,int etat)
{
 QSqlQueryModel * model = new QSqlQueryModel() ;
 QSqlQuery query;
 if(etat==0){query.prepare("SELECT * FROM EQUIPEMENT WHERE REFERENCE like :valeur order by REFERENCE ");
 }else {
     query.prepare("SELECT * FROM EQUIPEMENT WHERE REFERENCE like :valeur order by REFERENCE desc");
 }valeur="%"+valeur+"%";
 query.bindValue(":valeur",valeur);
 query.exec();
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
 return  model;
}





