#include "personnel.h"
#include <QSqlQueryModel>
personnel::personnel()
{

}

personnel::personnel(QString New_Mat,QString New_Nom, QString New_Prenom){
    Matricule=New_Mat;
    Nom=New_Nom;
    Prenom=New_Prenom;

}
bool personnel::ajouter()
{QSqlQuery query;
query.prepare("INSERT INTO PERSONNEL (MATRICULE,NOM,PRENOM)" "VALUES(:MATRICULE,:NOM,:PRENOM)");
query.bindValue(":MATRICULE",Matricule);
query.bindValue(":NOM",Nom);
query.bindValue(":PRENOM",Prenom);
return  query.exec();
}
QSqlQueryModel * personnel:: afficher_list(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT MATRICULE FROM PERSONNEL");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
return  model;
}
bool personnel::supprimer(QString mat)
{QSqlQuery query;
query.prepare("DELETE FROM PERSONNEL WHERE MATRICULE =:MAT");
query.bindValue(":MAT",mat);
return (query.exec());
}
bool personnel::mise_ajour(QString MAT, QString NOM, QString PRENOM){
    QSqlQuery query;
    query.prepare("UPDATE PERSONNEL SET NOM=:NOM,PRENOM=:PRENOM WHERE MATRICULE=:MAT");
    query.bindValue(":MAT",MAT);
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    return (query.exec());
}
bool personnel::chercher (QString MAT){
QSqlQuery query;
query.prepare("SELECT MATRICULE, NOM, PRENOM FROM PERSONNEL WHERE MATRICULE=:MAT");
query.bindValue(":MAT",MAT);
query.exec();
while(query.next())//parcour
{
Matricule = query.value(0).toString();
Nom = query.value(1).toString();
Prenom= query.value(2).toString();
}
return query.first();
}

