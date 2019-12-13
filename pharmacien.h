#ifndef PHARMACIEN_H
#define PHARMACIEN_H
#include <personnel.h>
class pharmacien:public personnel
{
public:
    pharmacien();
    pharmacien(QString id,QString mot_de_passe ,QString New_Mat,QString New_Nom, QString New_Prenom);
    pharmacien(QString id,QString mot_de_passe);

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_liste_ph();
    void chercher(QString);
    bool mise_ajour(QString MAT,QString ID,QString MOT_DE_PASSE ,QString NOM, QString PRENOM) ;
QString get_id(){
        return id;
    }
    QString get_mot_de_passe(){
        return mot_de_passe;
    }
    bool authentification();

private:
    QString id,mot_de_passe;
};

#endif // PHARMACIEN_H
