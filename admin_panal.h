#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "medecin.h"
#include "contrat.h"
#include "pharmacien.h"
#include "responsable.h"
#include "secretaire.h"
#include "chauffeur.h"
#include <QDate>
namespace Ui {
class admin_panal;
}

class admin_panal : public QDialog
{
    Q_OBJECT

public:
    explicit admin_panal(QWidget *parent = nullptr);
    ~admin_panal();
    void initialiser_formulaire();
    void initialiser_formulaire2();
    bool verif_formulaire_m();
    bool verif_formulaire_ph();
    bool verif_formulaire_r();
    bool verif_formulaire_s();
    bool verif_formulaire_ch();
    void refresh();
    void initialiser_formulaire3();
    void initialiser_formulaire4();
    void initialiser_formulaire5();
    void initialiser_formulaire6();
    void initialiser_formulaire7();
    void initialiser_formulaire8();
    void initialiser_formulaire9();
    void initialiser_formulaire10();
    void initialiser_formulaire11();
    void initialiser_formulaire12();


private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_5_activated(const QString &arg1);

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateEdit_2_userDateChanged(const QDate &date);

    void on_pushButton_6_clicked();

    void on_dateEdit_3_userDateChanged(const QDate &date);

    void on_dateEdit_4_userDateChanged(const QDate &date);

    void on_pushButton_9_clicked();

    void on_numero_contrat_list_activated(const QString &arg1);
    void on_pushButton_10_clicked();

    void on_numero_contrat_list_2_activated(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_comboBox_4_activated(const QString &arg1);

    void on_pushButton_15_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_comboBox_6_activated(const QString &arg1);

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();



    void on_comboBox_7_activated(const QString &arg1);

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_comboBox_8_activated(const QString &arg1);

    void on_pushButton_24_clicked();

    void on_comboBox_9_activated(const QString &arg1);

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_comboBox_10_activated(const QString &arg1);

    void on_pushButton_28_clicked();

    void on_comboBox_11_activated(const QString &arg1);

    void on_pushButton_30_clicked();


    void on_champs_activated(const QString &arg1);

    void on_valeur_textChanged(const QString &arg1);

    void on_champs_activated(int index);



    void on_checkBox_stateChanged(int arg1);

    void afficher_notification(int *);

    void makePolt();
private:
    Ui::admin_panal *ui;
    medecin tmpmedecin;
    personnel tmppersonnel;
    contrat tmpcontrat;
    pharmacien tmppharmacien;
    responsable tmpresponsable;
    secretaire tmpsecretaire;
    chauffeur tmpch;
    QDate date_debut,date_fin ; //contrat
    QString champ; //order by champs
    int ordre=0; //ordre tri
    QString valeur;
    int x=0;

};

#endif // ADMIN_H
