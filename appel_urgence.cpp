#include "appel_urgence.h"
#include<QDebug>
#include <QSqlQueryModel>

Appel_urgence::Appel_urgence()
{
  Num_fichier="";
  Nom_Prenom="";
  Adresse="";
  Blessure="";
}
Appel_urgence::Appel_urgence(QString Num,QString Non,QString adresse,QString blessure)
{
    this->Num_fichier=Num;
    this->Nom_Prenom=Non;
    this->Adresse=adresse;
    this->Blessure=blessure;
}

QString Appel_urgence::getfichier(){return Num_fichier;}
QString Appel_urgence::getNom(){return  Nom_Prenom;}
QString Appel_urgence::getAdresse(){return Adresse;}
QString Appel_urgence::getblessure(){return  Blessure;}
void Appel_urgence::setfichier(QString Num_fichier)
{
    this->Num_fichier=Num_fichier;
}
void Appel_urgence::setNom(QString Nom_Prenom)
{
    this->Nom_Prenom=Nom_Prenom;
}
void Appel_urgence::setadresse(QString adresse)
{
    this->Adresse=adresse;
}
void Appel_urgence::setblessure(QString blessure)
{
    this->Blessure=blessure;
}
bool Appel_urgence::ajouter2()
{
    QSqlQuery query;
    query.prepare("INSERT INTO SERVICEURGENCE (NUM_FICHIER,NOM_PRENOM,ADRESSE,BLESSURE) "
                            "VALUES (:Num_fichier,:Nom_Prenom,:Adresse,:Blessure) ");
        query.bindValue(":Num_fichier",Num_fichier);
        query.bindValue(":Nom_Prenom",Nom_Prenom);
query.bindValue(":Adresse", Adresse);
query.bindValue(":Blessure",Blessure);
return query.exec();
}
QSqlQueryModel * Appel_urgence::afficher2()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from serviceurgence");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Num_fichier"));
 model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom_Prenom"));
model->setHeaderData(2,Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(3,Qt::Horizontal, QObject::tr("Blessure"));
return model;
}

void Appel_urgence::chercher2()
{

    QSqlQuery query1;
    query1.prepare("SELECT NOM_PRENOM,ADRESSE,BLESSURE FROM SERVICEURGENCE WHERE NUM_FICHIER=:NUM_FICHIER");
    query1.bindValue(":NUM_FICHIER",Num_fichier);
    query1.exec();
    while(query1.next())
    {
    Nom_Prenom = query1.value(0).toString();
    Adresse= query1.value(1).toString();
    Blessure=query1.value(2).toString();


    }
}

QSqlQueryModel * Appel_urgence::afficher_list2()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select num_fichier from SERVICEURGENCE");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Num_fichier"));
  return model;
}
bool Appel_urgence::supprimer2(QString num)
{
    QSqlQuery query;
    query.prepare("delete from serviceurgence where num_fichier=:num");
    query.bindValue(":num",num);
    return query.exec();

}

bool Appel_urgence::modifier2()
{
    QSqlQuery query;
    query.prepare("update SERVICEURGENCE set NOM_PRENOM=:NOM_PRENOM,ADRESSE=:ADRESSE,BLESSURE=:BLESSURE where NUM_FICHIER=:NUM_FICHIER");
    query.bindValue(":NUM_FICHIER",Num_fichier);
    query.bindValue(":NOM_PRENOM",Nom_Prenom);
   query.bindValue(":ADRESSE", Adresse);
  query.bindValue(":BLESSURE", Blessure);
    return    query.exec();

}
QSqlQueryModel*  Appel_urgence::recherche2(QString mat,bool *test)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from SERVICEURGENCE where NUM_FICHIER='"+mat+"'");
    q.exec();
    model->setQuery(q);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_FICHIER"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("BLESSURE"));
    *test=q.first();
    return model;
}

