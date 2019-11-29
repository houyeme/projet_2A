#ifndef MEDECIN_H
#define MEDECIN_H
#include "personnel.h"

class medecin : public personnel
{
public:
    medecin();

 medecin(QString id, QString specialite , int Num_cabinet ,QString mot_de_passe ,QString New_Mat,QString New_Nom, QString New_Prenom);
bool ajouter();
QSqlQueryModel * afficher();
QSqlQueryModel * afficher_liste_mat();
void chercher(QString);
bool mise_ajour(QString,QString,QString,int,QString,QString,QString);
QSqlQueryModel *recherche(QString champ,QString valeur,int etat);

QString get_id(){
    return id;
}
QString get_specilite(){
    return specialite;
}
int get_numcabinet(){
    return Num_cabinet;
}
QString get_mot_passe(){
    return mot_de_passe;
}
void Set_id(QString id){
    this->id=id;
}
private:
    QString id;
    QString mot_de_passe;
    QString specialite;
    int Num_cabinet;


};

#endif // MEDECIN_H
