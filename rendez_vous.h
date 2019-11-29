#ifndef RENDEZ_VOUS_H
#define RENDEZ_VOUS_H
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDate>
#include <QSqlQuery>
#include <QSound>

class rendez_vous
{
public:
    rendez_vous();
    rendez_vous(QString,QString,QDate,int,QString);
    void setid_sec(QString);
    void setreference(QString);
    void setdate_rendez_vous(QDate);
    void setnum_rendez_vous(int);
    void setid_med(QString);
    void settime_rendez_vous(QTime);

    QString get_id_sec();
    QString get_reference();
    QDate get_date_rendez_vous();
    QTime get_time_rendez_vous();

    int get_num_rendez_vous();
    QString get_id_med();
    bool ajouter_rendez_vous();
    bool modifier_rendez_vous();
    bool archiver_rendez_vous();
    QSqlQueryModel * afficher_rendez_vous();
    QSqlQueryModel * afficher_liste_rendez_vous();
    QSqlQueryModel * recherche(QString,int);
    QString generate_date(int j,int m, int a);
    QString generate_time(int h,int s,int m);
    QSqlQueryModel * recherche(QString,QString,int);
bool recherche_rendez_vous();
    void chercher();
    private:
    QString id_sec;
    QString reference;
    QDate date_rendez_vous;
    int num_rendez_vous;
    QString id_med;
    QTime time_rendez_vous;
};

#endif // RENDEZ_VOUS_H
