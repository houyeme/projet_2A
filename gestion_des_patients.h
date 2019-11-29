#ifndef GESTION_DES_PATIENTS_H
#define GESTION_DES_PATIENTS_H
#include <QMessageBox>
#include "rendez_vous.h"
#include "patient.h"
#include <QDialog>

namespace Ui {
class gestion_des_patients;
}

class gestion_des_patients : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_des_patients(QWidget *parent = nullptr);
    ~gestion_des_patients();

private slots:
    void on_dateEdit_userDateChanged(const QDate &date);

    void on_ajouter_clicked();
    void on_archiver_clicked();

    void on_modifier_p_clicked();
void refresh();
void on_comboBox_activated(const QString &arg1);

void on_comboBox_2_activated(const QString &arg1);

void on_dateEdit_3_userDateChanged(const QDate &date);

void on_recherche_tri_textChanged(const QString &arg1);

void on_checkBox_stateChanged(int arg1);


void on_ajouter_2_clicked();

void on_references_patient_activated(const QString &arg1);

void on_dateEdit_4_userDateChanged(const QDate &date);

void on_timeEdit_userTimeChanged(const QTime &time);



void on_radioButton_clicked(bool checked);

void on_radioButton_2_clicked(bool checked);

void on_pushButton_clicked();

void on_modifier_p_2_clicked();

void on_comboBox_3_activated(const QString &arg1);

void on_dateEdit_5_userDateChanged(const QDate &date);

void on_comboBox_4_activated(const QString &arg1);

void on_archiver_2_clicked();



void on_recherche_tri_cursorPositionChanged(int arg1, int arg2);


void on_comboBox_5_activated(const QString &arg1);

void on_champ_activated(const QString &arg1);

void on_champ_currentIndexChanged(const QString &arg1);

void on_checkBox_2_stateChanged(int arg1);

void on_recherche_tri_2_cursorPositionChanged(int arg1, int arg2);

void on_recherche_tri_2_textChanged(const QString &arg1);

private:
    Ui::gestion_des_patients *ui;
    patient tmppatient;
    int etat=0;
    QString valeur,sexe;
    rendez_vous tmprend;
    QString champ="";
};

#endif // GESTION_DES_PATIENTS_H
