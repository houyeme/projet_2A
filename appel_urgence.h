#ifndef APPEL_URGENCE_H
#define APPEL_URGENCE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Appel_urgence
{
public:
    Appel_urgence();
     Appel_urgence(QString,QString,QString,QString);
     bool ajouter2();
     bool supprimer2(QString);
     bool modifier2();
    QSqlQueryModel* afficher2();
    QSqlQueryModel* afficher_list2();
    void setfichier(QString);
    void setNom(QString);
    void setadresse(QString);
    void setblessure(QString);
    void chercher2();
    QSqlQueryModel *  recherche2(QString,bool *);


    QString getfichier();
    QString getNom();
    QString getAdresse();
    QString getblessure();
private:
     QString Num_fichier;
     QString Nom_Prenom;
    QString Adresse;
    QString Blessure;



};

#endif // APPEL_URGENCE_H
