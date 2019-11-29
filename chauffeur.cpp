#include "chauffeur.h"

chauffeur::chauffeur()
{

}
chauffeur::chauffeur(QString id,QString mot_de_passe,QString New_Mat,QString New_Nom, QString New_Prenom):personnel(New_Mat,New_Nom,New_Prenom){
    this->id=id;
    this->mot_de_passe=mot_de_passe;
    }
bool chauffeur::ajouter(){
    QSqlQuery query;
    query.prepare("INSERT INTO chauffeur (ID,MOT_DE_PASSE,MATRICULE)" "VALUES(:ID,:MOT_DE_PASSE,:MATRICULE)");
    query.bindValue(":ID",id);
    query.bindValue(":MOT_DE_PASSE",mot_de_passe);
    query.bindValue(":MATRICULE",Matricule);
    return  ((personnel::ajouter())&&(query.exec()));
}
QSqlQueryModel * chauffeur::afficher(){
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM PERSONNEL P , chauffeur S  where (P.MATRICULE=S.MATRICULE) ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_CONTRAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("REF_EQUIPE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MOT_DE_PASSE"));
    return model;
}
QSqlQueryModel * chauffeur::afficher_liste_res(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT MATRICULE FROM chauffeur");
    model->setHeaderData(0,Qt::Horizontal, QObject:: tr("MATRICULE"));
    return  model;
}
void chauffeur::chercher(){
    personnel::chercher(Matricule);
    QSqlQuery query1;
    query1.prepare("SELECT ID,MOT_DE_PASSE FROM chauffeur WHERE MATRICULE=:MAT");
    query1.bindValue(":MAT",Matricule);
    query1.exec();
    while(query1.next())
    {
    id = query1.value(0).toString();
    mot_de_passe = query1.value(1).toString();
    }
    }


bool chauffeur::mise_ajour(QString MAT, QString ID, QString MOT_DE_PASSE, QString NOM, QString PRENOM){

    QSqlQuery query2;
        query2.prepare("UPDATE CHAUFFEUR SET ID=:ID,MOT_DE_PASSE=:MOT_DE_PASSE WHERE MATRICULE=:MAT");
        query2.bindValue(":ID",ID);
        query2.bindValue(":MOT_DE_PASSE",MOT_DE_PASSE);
    return((personnel::mise_ajour(MAT,NOM,PRENOM))&&(query2.exec()));
}