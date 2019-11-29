#include "fournisseur.h"
#include <QDebug>
fournisseur::fournisseur()
{
id="";
nom="";
prenom="";
telephone="";
adresse="";
domaine="";
}
fournisseur::fournisseur(QString id ,QString nom ,QString prenom , QString telephone , QString adresse ,QString domaine)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->telephone=telephone;
  this->adresse=adresse;
  this->domaine=domaine;
}
QString fournisseur::get_id(){return  id;}
QString fournisseur::get_nom(){return nom;}
QString fournisseur::get_prenom(){return prenom;}
QString fournisseur::get_telephone(){return telephone;}
QString fournisseur::get_adresse(){return  adresse;}
QString fournisseur::get_domaine(){return  domaine;}
void fournisseur::set_id(QString id){this->id=id;}
void fournisseur::set_nom(QString nom){this->nom=nom;}
void fournisseur::set_prenom(QString prenom){this->prenom=prenom;}
void fournisseur::set_telephone(QString telephone){this->telephone=telephone;}
void fournisseur::set_adresse(QString adresse){this->adresse=adresse;}
void fournisseur::set_domaine(QString domaine){this->domaine=domaine;}
bool fournisseur::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO FOURNISSEUR (id,nom,prenom,telephone,adresse,domaine) "
                    "VALUES (:id,:nom,:prenom,:telephone,:adresse,:domaine)");
query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":telephone", telephone);
query.bindValue(":adresse", adresse);
query.bindValue(":domaine", domaine);
return    query.exec();
}
QSqlQueryModel * fournisseur::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNISSEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("domaine"));
    return model;
}
QSqlQueryModel * fournisseur::afficherlist()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNISSEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

    return model;
}
bool fournisseur::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from FOURNISSEUR where ID = :id ");
query.bindValue(":id", id);
return    query.exec();
}
void fournisseur::chercher(){
QSqlQuery query1;
query1.prepare("SELECT nom,prenom,telephone,adresse,domaine FROM FOURNISSEUR WHERE ID=:id");
query1.bindValue(":id",id);
query1.exec();
while(query1.next())
{
nom = query1.value(0).toString();
prenom = query1.value(1).toString();
telephone = query1.value(2).toString();
adresse = query1.value(3).toString();
domaine = query1.value(4).toString();
}
}
bool fournisseur::modifier(){
    QSqlQuery query1;
    query1.prepare("UPDATE FOURNISSEUR set nom=:nom,prenom=:prenom,telephone=:telephone,adresse=:adresse,domaine=:domaine WHERE ID=:id");
    query1.bindValue(":id",id);
    query1.bindValue(":nom",nom);
    query1.bindValue(":prenom",prenom);
    query1.bindValue(":telephone",telephone);
    query1.bindValue(":adresse",adresse);
    query1.bindValue(":domaine",domaine);

    return (query1.exec());
}
QSqlQueryModel * fournisseur::recherche(QString valeur)
{
 QSqlQueryModel * model = new QSqlQueryModel() ;
 QSqlQuery query;
 query.prepare("SELECT * FROM FOURNISSEUR WHERE ID like :valeur order by ID ");
 valeur="%"+valeur+"%";
 query.bindValue(":valeur",valeur);
 query.exec();
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("domaine"));
 return  model;
}

QSqlQueryModel * fournisseur::GetIdModelFournisseur()
{
QSqlQueryModel *model = new QSqlQueryModel();
QSqlQuery *query= new QSqlQuery() ;
query->prepare("select ID from fournisseur");
query->exec();
model->setQuery(*query);
return model;
}
