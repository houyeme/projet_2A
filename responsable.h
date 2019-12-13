#ifndef RESPONSABLE_H
#define RESPONSABLE_H
#include "personnel.h"

class responsable : public personnel
{
public:
    responsable();
    responsable(QString id,QString mot_de_passe);
    responsable(QString id,QString mot_de_passe ,QString domaine,QString New_Mat,QString New_Nom, QString New_Prenom);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_liste_res();
    void chercher();
    bool mise_ajour(QString MAT,QString ID,QString MOT_DE_PASSE ,QString domaine,QString NOM, QString PRENOM) ;
QString get_id(){
        return id;
    }
    QString get_mot_de_passe(){
        return mot_de_passe;
    }

    QString get_domaine(){
        return domaine;
    }
     bool authentification(QString *domaine);
private: QString id,mot_de_passe,domaine;
};

#endif // RESPONSABLE_H
