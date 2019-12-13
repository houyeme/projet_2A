#ifndef SECRETAIRE_H
#define SECRETAIRE_H

#include "personnel.h"
class secretaire: public personnel
{
public:
    secretaire();
    secretaire(QString id,QString mot_de_passe ,QString New_Mat,QString New_Nom, QString New_Prenom);
    secretaire(QString id,QString mot_de_passe);
    bool authentification();
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

#endif // SECRETAIRE_H
