#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "admin_panal.h"
#include "cadmin.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    music->setMedia(QUrl("C:/Users/ASUS/Desktop/Nouveau dossier (2)/Ash - Mosaïque.mp3"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::verif_formulaire(){
    if(ui->id->text()==""){
ui->message->setText("merci de saisir votre id");
    }else if(ui->mot_de_passe->text()==""){
ui->message->setText("merci de saisir votre mot_de_passe");
    }


    return((ui->id->text()!="")&&(ui->mot_de_passe->text()!=""));

}
void MainWindow::on_pushButton_6_clicked()
{
if(verif_formulaire()){

    switch (espace) {
    case -1:{
         ui->message->setText("merci de selectionner un espace");
    break;
    }
    case 0:{
        ui->message->setText("merci de selectionner un espace");
   break;
   }
    case 1: {
        admin_panal ap;
        cadmin ca(ui->id->text(),ui->mot_de_passe->text());

       if(ca.authentification()){
hide();

           ap.exec();
       }else{
           ui->message->setText("id ou mot_de_passe incorrect");
       }

        break;}
    }
}
}


void MainWindow::on_comboBox_activated(int index)
{espace= index;
}

void MainWindow::on_pushButton_clicked()
{
    admin_panal ap;
    ap.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    music->play();
}

void MainWindow::on_pushButton_3_clicked()
{
    music->pause();
}
void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    music->setVolume(position);
}
