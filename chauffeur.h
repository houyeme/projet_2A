#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H

#include "personnel.h"
class chauffeur:public personnel
{
public:
    chauffeur();
    chauffeur(QString id,QString mot_de_passe ,QString New_Mat,QString New_Nom, QString New_Prenom);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_liste_res();
    void chercher();
    bool mise_ajour(QString MAT,QString ID,QString MOT_DE_PASSE ,QString NOM, QString PRENOM) ;
QString get_id(){
        return id;
    }
    QString get_mot_de_passe(){
        return mot_de_passe;
    }

private:
    QString id,mot_de_passe;

};

#endif // CHAUFFEUR_H
