#ifndef DIALOG_H
#define DIALOG_H
#include <QMessageBox>
#include <QDialog>
#include "medicament.h"
#include "equipement.h"
#include "qcustomplot.h"
#include <QMediaPlayer>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
     void refresh();

private:
    Ui::Dialog *ui;
    medicament tmpmedicament;
    equipement tmpequipement;
    int etat=0;
    QString valeur;
    QString champ="";
      QMediaPlayer *music =new QMediaPlayer();
};

#endif // DIALOG_H
