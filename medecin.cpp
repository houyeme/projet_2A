#include "medecin.h"
#include "personnel.h"
#include <QDebug>
#include <QSqlRecord>
medecin::medecin()
{

}
medecin::medecin(QString id,QString specialite , int Num_cabinet ,QString mot_de_passe ,QString New_Mat,QString New_Nom, QString New_Prenom)
    :personnel(New_Mat,New_Nom,New_Prenom){
this->id=id;
    this->specialite=specialite;
    this->mot_de_passe=mot_de_passe;
    this->Num_cabinet=Num_cabinet;
}
bool medecin::ajouter(){
   QSqlQuery query2;
   QString cabinet=QString::number(Num_cabinet);
   query2.prepare("INSERT INTO MEDECIN (ID,MOT_DE_PASSE,SPECIALITE,NUM_CABINET,MATRICULE)" "VALUES(:ID,:MOT_DE_PASSE,:SPECIALITE,:NUM_CABINET,:MATRICULE)");
   query2.bindValue(":ID",id);
   query2.bindValue(":MOT_DE_PASSE",mot_de_passe);
   query2.bindValue(":SPECIALITE",specialite);
   query2.bindValue(":NUM_CABINET",cabinet);
   query2.bindValue(":SPECILITE",specialite);
   query2.bindValue(":MATRICULE",Matricule);
   return  ((personnel::ajouter())&&(query2.exec()));
}

QSqlQueryModel * medecin::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM PERSONNEL P , MEDECIN M  where (P.MATRICULE=M.MATRICULE) ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_CONTRAT"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("REF_EQUIPE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("MOT_DE_PASSE"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("SPECIALITE"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("NUM_CABINET"));
return model;
}
QSqlQueryModel * medecin::afficher_liste_mat(){
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT MATRICULE FROM MEDECIN");
    model->setHeaderData(0 ,Qt::Horizontal,QObject::tr("MATRICULE"));
    return model;
}
QSqlQueryModel * medecin::afficher_liste_id(){
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT id FROM MEDECIN");
    model->setHeaderData(0 ,Qt::Horizontal,QObject::tr("MATRICULE"));
    return model;
}
bool medecin::mise_ajour(QString MAT,QString ID,QString SPECIALITE, int NUM_CABINET, QString MOT_DE_PASSE ,QString NOM, QString PRENOM){

    QSqlQuery query2;
        query2.prepare("UPDATE MEDECIN SET ID=:ID,SPECIALITE=:SPECIALITE,NUM_CABINET=:NUM_CABINET,MOT_DE_PASSE=:MOT_DE_PASSE WHERE MATRICULE=:MAT");
        query2.bindValue(":ID",ID);
        query2.bindValue(":SPECIALITE",SPECIALITE);
        query2.bindValue(":NUM_CABINET",NUM_CABINET);
        query2.bindValue(":MOT_DE_PASSE",MOT_DE_PASSE);
        query2.bindValue(":MAT",MAT);
    return((personnel::mise_ajour(MAT,NOM,PRENOM))&&(query2.exec()));

}
void medecin::chercher (QString MAT){
personnel::chercher(MAT);
QSqlQuery query1;
query1.prepare("SELECT ID,MOT_DE_PASSE,SPECIALITE,NUM_CABINET FROM MEDECIN WHERE MATRICULE=:MAT");
query1.bindValue(":MAT",MAT);
query1.exec();
while(query1.next())
{
id = query1.value(0).toString();
mot_de_passe = query1.value(1).toString();
specialite = query1.value(2).toString();
Num_cabinet = query1.value(3).toInt();
}
}
QSqlQueryModel * medecin::recherche(QString champ,QString valeur,int etat){
    QSqlQueryModel * model= new QSqlQueryModel();
    valeur="%"+valeur+"%";
    QSqlQuery query;
    if(etat==0){
    query.prepare("SELECT * FROM PERSONNEL P , MEDECIN M where ("+champ+" like :valeur) and (P.MATRICULE=M.MATRICULE) order by "+champ);
    }else{
        query.prepare("SELECT * FROM PERSONNEL P , MEDECIN M where ("+champ+" like :valeur) and (P.MATRICULE=M.MATRICULE) order by "+champ+" desc");

    }
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    return  model;

}

