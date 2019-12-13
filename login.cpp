#include "login.h"
#include "ui_login.h"
#include "gestion_de_mediacament.h"
#include "pharmacien.h"
login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_connecter_clicked()
{ pharmacien ph(ui->id_edit->text(),ui->mdp_edit->text());
  switch(espace){
  case -1: {  QMessageBox::critical(this, "ERREUR", "merci de selectionne un espace "); break;}
  case 0:   {QMessageBox::critical(this, "ERREUR", "merci de selectionne un espace "); break;}
  case 2:  {
      if(ph.authentification()){
          gestion_de_mediacament x;
          x.exec();
     }else{
      QMessageBox::critical(this, "ERREUR", "ID ou MOT_DE_PASSE incorrect ");

      }
             break;}
  default:{ QMessageBox::critical(this, "ERREUR", "espace invalide ");
           break;}
  }


}

void login::on_comboBox_activated(int index)
{
  espace=index;
}

void login::on_pushButton_clicked()
{
    close();
}

