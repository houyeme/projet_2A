#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog:: refresh()
{ ui->tabmedicament_5->setModel(tmpmedicament.afficher_medicament());
ui->tabequipement_5->setModel(tmpequipement.afficher_equipement());
ui->comboBox_17->setModel(tmpmedicament.afficher_list());
ui->comboBox_18->setModel(tmpmedicament.afficher_list());
ui->comboBox_19->setModel(tmpequipement.afficher_list());
ui->comboBox_20->setModel(tmpequipement.afficher_list());
}
