#include "contrat.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
contrat::contrat()
{

}
bool contrat::ajouter(){
QSqlQuery query2;
QSqlQuery query1;
query1.prepare("UPDATE PERSONNEL SET NUM_CONTRAT=:NUM_CONTRAT where matricule=:matricule");
query1.bindValue(":matricule",matricule);
query1.bindValue(":NUM_CONTRAT",num_contrat);
query2.prepare("INSERT INTO CONTRAT (NUM_CONTRAT,DATE_DEBUT,DATE_FIN,SALAIRE,MATRICULE)" "VALUES(:NUM_CONTRAT,:date_debut,:date_fin,:SALAIRE,:MATRICULE)");
query2.bindValue(":NUM_CONTRAT",num_contrat);
query2.bindValue(":SALAIRE",salaire);
query2.bindValue(":MATRICULE",matricule);
query2.bindValue(":date_debut",generate_date(date_debut.j,date_debut.m,date_debut.a));
query2.bindValue(":date_fin",generate_date(date_fin.j,date_fin.m,date_fin.a));

return  (query2.exec())&&(query1.exec());
}
QSqlQueryModel * contrat:: afficher(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM CONTRAT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_CONTRAT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_FIN"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("SALAIRE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("MATRICULE"));
return  model;
}
QSqlQueryModel * contrat:: afficher_list(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT NUM_CONTRAT FROM CONTRAT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_CONTRAT"));
return  model;
}

void contrat::chercher (){

QSqlQuery query1;
query1.prepare("SELECT date_debut,date_fin,salaire FROM CONTRAT WHERE NUM_CONTRAT=:NUM_CONTRAT");
query1.bindValue(":NUM_CONTRAT",num_contrat);
query1.exec();
while(query1.next())
{   date_debut.j=QString::number(query1.value(0).toDate().day());
    date_debut.m=QString::number(query1.value(0).toDate().month());
    date_debut.a=QString::number(query1.value(0).toDate().year());

   date_fin.j=QString::number(query1.value(1).toDate().day());
   date_fin.m=QString::number(query1.value(1).toDate().month());
    date_fin.a=QString::number(query1.value(1).toDate().year());
    salaire= query1.value(2).toInt();
}

}
bool contrat::mise_ajour()
{
    QSqlQuery query2;
        query2.prepare("UPDATE CONTRAT SET DATE_DEBUT=:DATE_DEBUT,DATE_FIN=:DATE_FIN,SALAIRE=:SALAIRE WHERE NUM_CONTRAT=:NUM_CONTRAT");
        query2.bindValue(":SALAIRE",salaire);
        query2.bindValue(":NUM_CONTRAT",num_contrat);
        query2.bindValue(":DATE_DEBUT",generate_date(date_debut.j,date_debut.m,date_debut.a));
        query2.bindValue(":DATE_FIN",generate_date(date_fin.j,date_fin.m,date_fin.a));
         return(query2.exec());

}
bool contrat::supprimer(){
    QSqlQuery query2;

    query2.prepare("DELETE FROM CONTRAT WHERE NUM_CONTRAT=:NUM_CONTRAT");
    query2.bindValue(":NUM_CONTRAT",num_contrat);

    return query2.exec();
}

QSqlQueryModel * contrat::afficher_list_fin(bool *test){
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    QDate q;
    q.setDate(q.currentDate().year(),q.currentDate().month(),q.currentDate().day());
    q=q.addDays(7);
    query.prepare("SELECT 'le contrat numero : '| | NUM_CONTRAT|| ' de l''employe numero : '||MATRICULE||' se termine en '||DATE_FIN FROM CONTRAT where DATE_FIN<=:d");
    query.bindValue(":d",generate_date(QString::number(q.day()),QString::number(q.month()),QString::number(q.year())));
    query.exec();
    model->setQuery(query);
    *test=query.first();
    return  model;
}
