#ifndef GESTION_DE_MEDIACAMENT_H
#define GESTION_DE_MEDIACAMENT_H
#include <QMessageBox>
#include <QDialog>
#include "medicament.h"
#include "equipement_paramedicale.h"
#include "qcustomplot.h"
#include <QMediaPlayer>
#include "arduino.h"
namespace Ui {
class gestion_de_mediacament;
}

class gestion_de_mediacament : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_de_mediacament(QWidget *parent = nullptr);
    ~gestion_de_mediacament();
    bool verif_data(QByteArray data,char c);

private slots:
    //ARDUINO
    void update_label();
    // ARIJ'S WORK PLEASE NOTE HER WELL ELSE F U.

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void refresh();

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_lineEdit_16_textChanged(const QString &arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_ajouter_2_clicked();

    void on_modifier_2_clicked();

    void on_supprimer_2_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_4_activated(const QString &arg1);

    void on_lineEdit_17_textChanged(const QString &arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_envoyer_email_bott_clicked();



    void on_champ_activated(const QString &arg1);

    void on_champ_2_activated(const QString &arg1);



    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();


    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_verticalSlider_sliderMoved(int position);

    void on_pushButton_13_clicked();

private:
    Ui::gestion_de_mediacament *ui;
   medicament tmpmedicament;
   equipement_paramedicale tmpequipement_paramedicale;
   int etat=0;
   QString valeur;
   QString champ="";
     QMediaPlayer *music =new QMediaPlayer();

     //ARDUINO
     Arduino A;
     QByteArray data;

};

#endif // GESTION_DE_MEDIACAMENT_H
