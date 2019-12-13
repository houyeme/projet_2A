#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "admin_panal.h"
#include "cadmin.h"
#include <QMessageBox>
#include "gestion_equipement.h"
#include "pharmacien.h"
#include "gestion_de_mediacament.h"
#include "gestion_de_mediacament1.h"
#include "gerer_umbulance.h"
#include <QStyle>
#include "gestion_des_patients.h"
#include <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
            player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Downloads/bienenu2.mp3"));
            player->setVolume(1000);
            player->play();
            QTimer *timer3 = new QTimer(this);
                timer3->start();
               showTime();
               QDateTime datetime3=QDateTime::currentDateTime();
               QString datetimetext2=datetime3.toString();
               ui->datetime_2->setText(datetimetext2);
}

MainWindow::~MainWindow()
{
    delete ui;

}




bool MainWindow::verif_formulaire(){
    if(ui->id->text()==""){
        QMessageBox::warning(this, tr("ERREUR"), tr("merci de saisir votre id .\n"));
    }else if(ui->mot_de_passe->text()==""){
        QMessageBox::warning(this, tr("ERREUR"), tr("merci de saisir votre mot_de_passe \n"));

    }


    return((ui->id->text()!="")&&(ui->mot_de_passe->text()!=""));

}
void MainWindow::on_pushButton_6_clicked()
{
if(verif_formulaire()){

    switch (espace) {
    case -1:{
        QMessageBox::warning(this, tr("ERREUR"), tr("merci de selectionné une espace .\n"));
    break;}
    case 0:{
        QMessageBox::warning(this, tr("ERREUR"), tr("merci de selectionné une espace .\n"));
   break;}
    case 1: {
        admin_panal ap;
        cadmin ca(ui->id->text(),ui->mot_de_passe->text());
         if(ca.authentification()){
         hide();

         if(mode=="dark"){
         ap.dark_mode();
             }else{
             ap.par_defaut();
             }
         ap.exec();
         }else{
           QMessageBox::warning(this, tr("ERREUR"), tr("id ou mot de passe incorrect .\n"));
         }
        break;}
    case 2:{
        pharmacien ph(ui->id->text(),ui->mot_de_passe->text());
        if(ph.authentification()&&(langue=="français")){
            gestion_de_mediacament g;
            g.exec();
        }
       else if(ph.authentification()&&(langue=="english")){
          gestion_de_mediacament1 g;
          g.exec();
        }
        else{
        QMessageBox::critical(this, "ERREUR", "ID ou MOT_DE_PASSE incorrect ");
        }
   break;}
    case 3:{
        QString domaine;
        responsable r(ui->id->text(),ui->mot_de_passe->text());
        if ((r.authentification(&domaine))&&(domaine=="equipement"))
        {gestion_equipement ge;
        ge.par_defaut();
            ge.exec();
        }
        else if((r.authentification(&domaine))&&(domaine=="service_urgence")){
            gerer_umbulance g;
            g.exec();}
        else{
                QMessageBox::critical(this, "ERREUR", "ID ou MOT_DE_PASSE ou DOMAINE incorrect ");

                }
    break;
    }
    case 4:{
        secretaire s(ui->id->text(),ui->mot_de_passe->text());
        if(s.authentification()){
         gestion_des_patients gp;
         gp.exec();
            }
        else{
            QMessageBox::critical(this, "ERREUR", "ID ou MOT_DE_PASSE incorrect ");

        }
        break;

         }
    }
}
}


void MainWindow::on_comboBox_activated(int index)
{espace= index;
}

void MainWindow::on_pushButton_clicked()
{  admin_panal *ap=new admin_panal();
    ap->exec();
}



void MainWindow::dark_mode(){
    ui->centralwidget->setStyleSheet("");
    ui->centralwidget->setStyleSheet("#centralwidget{background-image: url(:/bakground/dark_bg.png);}"
                                     "#icon{"
                                     "background-image: url(:/bakground/dark_icon.png);"
                                     "}"
                                     "#label{"
                                     "font: 15pt Arial;"
                                     "color:white;"
                                     "background-color :#602080;"
                                     "border-top-right-radius: 5px 5px;"
                                     "border-bottom-right-radius: 5px 5px;"
                                     "}"
                                     "#label_2{"
                                     "font: 15pt Arial;"
                                     "color:white;"
                                     "background-color :#602080;"
                                     "border-top-right-radius: 5px 5px;"
                                     "border-bottom-right-radius: 5px 5px;"
                                     "}"
                                     "QLineEdit {"
                                     "background:transparent;"
                                     "border:none;"
                                     "border-bottom:1px solid #602080;"
                                     "font: 15pt Arial;"
                                     "color: #602080;"

                                     "}"
                                     "#pushButton_6{"
                                     "font: 15pt Arial;"
                                     "color:white;"
                                     "background-color :#602080;"
                                     "border-bottom-left-radius: 10px 10px;"
                                     "border-bottom-right-radius: 10px 10px;"
                                     "}"
                                     "#pushButton_6:hover{"
                                     "background-color:rgba(96,32,128,0.8);}"
                                     "#comboBox{"
                                     "font: 15pt Arial;"
                                     "color:white;"
                                     "background-color :#602080;"
                                     "border-top-right-radius: 5px 5px;"
                                     "border-bottom-right-radius: 5px 5px;"
                                      "}"
                                      "#comboBox:drop-down {"
                                      "border:none;}"
                                      "#comboBox QAbstractItemView {"
                                      "font: 15pt Arial;"
                                      "color:white;"
                                      "background-color :#602080;"
                                      "selection-background-color:rgba(0,0,0,0.2);} "

);
}
void MainWindow::on_actionDark_triggered()
{dark_mode();
mode="dark";
}
void MainWindow::par_defaut(){
ui->centralwidget->setStyleSheet("");
ui->centralwidget->setStyleSheet("#centralwidget{background-image: url(:/bakground/bg.png);}"
"#icon{"
"background-image: url(:/bakground/icon-authentification.png);"
"}"
"#label{"
"font: 15pt Arial;"
"color:white;"
"background-color :#2da5d5;"
"border-top-right-radius: 5px 5px;"
"border-bottom-right-radius: 5px 5px;"
"}"
"#label_2{"
"font: 15pt Arial;"
"color:white;"
"background-color :#2da5d5;"
"border-top-right-radius: 5px 5px;"
"border-bottom-right-radius: 5px 5px;"
"}"
"QLineEdit {"
"background:transparent;"
"border:none;"
"border-bottom:1px solid #2da5d5;"
"font: 12pt Arial;"
"color: #2da5d5;"
"}"
"#pushButton_6{"
"font: 15pt Arial ;"
"color:white;"
"background-color :#2da5d5;"
"border-bottom-left-radius: 10px 10px;"
"border-bottom-right-radius: 10px 10px;"
"}"
"#pushButton_6:hover{"
"background-color:rgba(126,214,216,0.8);}"
"#comboBox{"
"font: 15pt Arial;"
"color:white;"
"background-color :#2da5d5;"
"border-top-right-radius: 5px 5px;"
"border-bottom-right-radius: 5px 5px;"
"}"

"#comboBox:drop-down {"

"  border:none;} "
"#comboBox QAbstractItemView {"
" font: 15pt Arial;"
"color:white;"
"background-color :#2da5d5;"
"selection-background-color: rgb(254, 120, 126);}" );
}

void MainWindow::on_actionnormale_triggered()
{
par_defaut();
mode="par_defaut";
}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    langue=arg1;
}

void MainWindow :: showTime()
{
    {
        QTime time2=time2.currentTime();
        QString time_text2=time2.toString("hh : mm : ss");
       if((time2.second() % 2)==0)
        {
            time_text2[3]=' ';
            time_text2[8]=' ';
        }
       qDebug()<<time2;
       ui->time_2->clear();
        ui->time_2->setText(time_text2);
    }

}
