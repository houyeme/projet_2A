#include "login.h"
#include "ui_login.h"
#include "gestion_des_patients.h"
#include "secretaire.h"
LOGIN::LOGIN(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LOGIN)
{
    ui->setupUi(this);
    QPixmap pix3("C:/Users/user/Downloads/bg.png");
    ui->label->setPixmap(pix3);
}

LOGIN::~LOGIN()
{
    delete ui;
}


void LOGIN::on_connecter_clicked()
{secretaire sec(ui->id_edit->text(),ui->mdp_edit->text());
    switch(espace){
    case -1: {  QMessageBox::critical(this, "PAS D'ERREUR", "merci de selectionne un espace "); break;}
    case 0:   {QMessageBox::critical(this, "PAS D'ERREUR", "merci de selectionne un espace "); break;}
    case 2:         {
        if(sec.authentification()){
            gestion_des_patients p;
            // hide();
            p.exec();
        }else{
            QMessageBox::information(this, "ERREUR", "ID ou MOT_DE_PASSE incorrect ");

        }
        break;       }
    default:{ QMessageBox::information(this, "PAS D'ERREUR", "espace invalide "); break;}
    }


}

void LOGIN::on_comboBox_currentIndexChanged(int index)
{

    if(ui->comboBox->currentText() == "secretaire")
    {espace=2;}
    else {
        espace=0;
    }
}

void LOGIN::on_quitter_clicked()
{
    close();
}

void LOGIN::on_checkBox_clicked(bool checked)
{
    if(checked)
       {

           ui->mdp_edit->setEchoMode(QLineEdit::EchoMode(0));
       }
       else
       {
           ui->mdp_edit->setEchoMode(QLineEdit::EchoMode(2));
       }

}
