#include "responsable.h"

responsable::responsable()
{

}

responsable::responsable(QString id,QString mot_de_passe ,QString domaine,QString New_Mat,QString New_Nom, QString New_Prenom):personnel(New_Mat,New_Nom,New_Prenom){
    this->id=id;
    this->mot_de_passe=mot_de_passe;
    this->domaine=domaine;
}
bool responsable::ajouter(){
    QSqlQuery query;
    query.prepare("INSERT INTO RESPONSABLE (ID,MOT_DE_PASSE,DOMAINE,MATRICULE)" "VALUES(:ID,:MOT_DE_PASSE,:DOMAINE,:MATRICULE)");
    query.bindValue(":ID",id);
    query.bindValue(":MOT_DE_PASSE",mot_de_passe);
    query.bindValue(":MATRICULE",Matricule);
    query.bindValue(":DOMAINE",domaine);
    return  ((personnel::ajouter())&&(query.exec()));
}
QSqlQueryModel * responsable::afficher(){
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM PERSONNEL P , RESPONSABLE R  where (P.MATRICULE=R.MATRICULE) ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_CONTRAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("REF_EQUIPE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MOT_DE_PASSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DOMAINE"));

    return model;
}
QSqlQueryModel * responsable::afficher_liste_res(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT MATRICULE FROM RESPONSABLE");
    model->setHeaderData(0,Qt::Horizontal, QObject:: tr("MATRICULE"));
    return  model;
}
void responsable::chercher(){
    personnel::chercher(Matricule);
    QSqlQuery query1;
    query1.prepare("SELECT ID,MOT_DE_PASSE,DOMAINE FROM RESPONSABLE WHERE MATRICULE=:MAT");
    query1.bindValue(":MAT",Matricule);
    query1.exec();
    while(query1.next())
    {
    id = query1.value(0).toString();
    mot_de_passe = query1.value(1).toString();
    domaine=query1.value(2).toString();
    }
    }


bool responsable::mise_ajour(QString MAT, QString ID,QString domaine, QString MOT_DE_PASSE, QString NOM, QString PRENOM){

    QSqlQuery query2;
        query2.prepare("UPDATE RESPONSABLE SET ID=:ID,MOT_DE_PASSE=:MOT_DE_PASSE,DOMAINE=:domaine WHERE MATRICULE=:MAT");
        query2.bindValue(":ID",ID);
        query2.bindValue(":MOT_DE_PASSE",MOT_DE_PASSE);
        query2.bindValue(":DOMAINE",domaine);
        query2.bindValue(":MAT",MAT);

    return((personnel::mise_ajour(MAT,NOM,PRENOM))&&(query2.exec()));
}
