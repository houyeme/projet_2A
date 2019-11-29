#include "ambulance.h"
#include<QDebug>
#include <QSqlQueryModel>
ambulance::ambulance()
{ matricule_v="";
    etat="";
    date_dernier_entretient="";

}
ambulance::ambulance(QString matricule_v , QString etat , QString date_dernier_entretient)
{

    this->matricule_v=matricule_v;
    this->etat=etat;
    this->date_dernier_entretient=date_dernier_entretient;


}
QString ambulance::getmatricule(){return  matricule_v;}
QString ambulance::getetat(){return  etat;}
QString ambulance::getdateentretient(){return  date_dernier_entretient;}
void ambulance::setdateentretient(QString date_dernie_enretient){
    this->date_dernier_entretient=date_dernie_enretient;
}
void ambulance::setetat(QString etat){
    this->etat=etat;
}
void ambulance::setmatricule(QString matricule_v){
    this->matricule_v=matricule_v;
}


bool ambulance::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO AMBULANCE (MATRICULE_V,ETAT,DATE_DERNIER_ENTRETIENT) "
                            "VALUES (:MATRICULE_V,:ETAT,:DATE_DERNIER_ENTRETIENT) ");
        query.bindValue(":MATRICULE_V",matricule_v);
        query.bindValue(":ETAT",etat);
query.bindValue(":DATE_DERNIER_ENTRETIENT", date_dernier_entretient);
return query.exec();
}
QSqlQueryModel * ambulance:: recherche(QString mat)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from AMBULANCE where MATRICULE_V='"+mat+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE_V"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_dernier_entretient"));

    return model;

}
QSqlQueryModel * ambulance::afficher(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from ambulance");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Matricule_v"));
model->setHeaderData(1,Qt::Horizontal, QObject::tr("ETAT"));
model->setHeaderData(2,Qt::Horizontal, QObject::tr("DATE_DERNIER_ENTRETIENT"));
return model;
}
void ambulance::chercher()
{
    QSqlQuery query1;
    query1.prepare("SELECT ETAT,DATE_DERNIER_ENTRETIENT FROM AMBULANCE WHERE MATRICULE_V=:MATRICULE_V");
    query1.bindValue(":MATRICULE_V",matricule_v);
    query1.exec();
    while(query1.next())
    {
    etat = query1.value(0).toString();
    date_dernier_entretient = query1.value(1).toString();

    }
}
QSqlQueryModel * ambulance::afficher_list(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select matricule_v from ambulance");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Matricule_v"));
return model;
}
bool ambulance::supprimer(QString mat){
    QSqlQuery query;
    query.prepare("delete from ambulance where matricule_v=:mat");
    query.bindValue(":mat",mat);
    return query.exec();

}
bool ambulance::modifier()
{
    QSqlQuery query;
    query.prepare("update ambulance set etat=:ETAT,DATE_DERNIER_ENTRETIENT=:DATE_DERNIER_ENTRETIENT where MATRICULE_V=:MATRICULE_V");
    query.bindValue(":MATRICULE_V",matricule_v);
    query.bindValue(":ETAT",etat);
   query.bindValue(":DATE_DERNIER_ENTRETIENT", date_dernier_entretient);
    return    query.exec();
}

