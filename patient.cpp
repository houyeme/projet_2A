#include "patient.h"
#include<QDebug>
#include<QString>
#include<QSqlQueryModel>
patient::patient()
{}
patient::patient(QString reference, QString nom,QString prenom,QString date_de_naissance,QString sexe){
this->reference=reference;
this->nom=nom;
this->prenom=prenom;
this->date_de_naissance=date_de_naissance;
this->sexe=sexe;
}

void patient::setreference(QString reference){
  this->reference=reference;
}
void patient::setnom(QString nom){
  this->nom=nom;
}
void patient::setprenom(QString prenom){
    this->prenom=prenom;
}
void patient::setdatedenaissance(QString date_de_naissance){
    this->date_de_naissance=date_de_naissance;
}
void patient::setsexe(QString sexe){
    this->sexe=sexe;
}
QString patient::get_reference(){
    return reference;
}
QString patient::get_nom(){
    return nom;
}
QString patient::get_prenom(){
    return prenom;
}
QString patient::get_datedenaissance(){
    return date_de_naissance;
}
QString patient::get_sexe(){
    return sexe;
}
bool patient::ajouter_patient (){
    QSqlQuery query;

    query.prepare("INSERT INTO patient (reference,nom,prenom,date_de_naissance,sexe) "
                        "VALUES (:reference,:nom,:prenom,:date_de_naissance,:sexe)");
    query.bindValue(":reference",reference);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_de_naissance", date_de_naissance );
    query.bindValue(":sexe", sexe);

    return    query.exec();


};

   bool patient::archiver_patient(){

    QSqlQuery query;

    query.prepare("Delete from patient where reference = :reference ");
    query.bindValue(":reference",reference);
    return    query.exec();
    }

QSqlQueryModel * patient::afficher_patient(){

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from patient");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DE_NAISSANCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SEXE"));

        return model;

}
bool patient::modifier_patient(){

        QSqlQuery query;
        query.prepare("update patient set prenom=:prenom,nom=:nom,date_de_naissance=:date_de_naissance where reference=:reference");
        query.bindValue(":reference",reference);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":date_de_naissance",date_de_naissance);
        return    query.exec();


}
QSqlQueryModel * patient::afficher_liste_patient(){

QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select reference from patient");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));


    return model;

}
void patient::chercher (){

QSqlQuery query1;
query1.prepare("select nom,prenom,date_de_naissance from patient where REFERENCE=:reference");
query1.bindValue(":reference",reference);
query1.exec();
while(query1.next())
{
nom = query1.value(0).toString();
prenom = query1.value(1).toString();
date_de_naissance = query1.value(2).toString();
}
}
QSqlQueryModel * patient::recherche (QString champ ,QString valeur,int etat){
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    if(etat==0){
    query.prepare("SELECT * FROM PATIENT  where ("+champ+" LIKE :valeur) order by reference");}
    else
    {
         query.prepare("SELECT * FROM PATIENT  where ("+champ+" LIKE :valeur) order by reference desc");
    }
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DE_NAISSANCE"));
    return  model;

}
