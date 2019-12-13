#ifndef GERER_UMBULANCE_H
#define GERER_UMBULANCE_H

#include <QDialog>
#include "ambulance.h"
#include "appel_urgence.h"
#include<QMediaPlayer>
#include <QTextBrowser>

namespace Ui {
class gerer_umbulance;
}

class gerer_umbulance : public QDialog
{
    Q_OBJECT

public:
    explicit gerer_umbulance(QWidget *parent = nullptr);
    ~gerer_umbulance();
void set_table_id(int i);
private slots:
    void on_date_dernier_ent_userDateChanged(const QDate &date);

    void on_ajouter_clicked();

    void on_supprimer_clicked();


    void on_modifier_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);
    void refresh();


    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);


    void on_ajouter_2_clicked();

    void on_supprimer_2_clicked();

    void on_comboBox_4_activated(const QString &arg1);

    void on_modifier_2_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_pushButton_clicked();

   // void on_textBrowser_anchorClicked(const QUrl &arg1);


   // void on_mess_cursorPositionChanged(int arg1, int arg2);

  //  void on_mess_editingFinished();

   // void on_mess_returnPressed();

    void on_send_clicked();

    //void on_print_clicked();

   // void on_pushButton_2_clicked();

    void on_rechercher_clicked();

   //void on_affiche_clicked();
    void aff(QString);//boxchattab2
    void aff2();//
    void aff3();//boxchattab1

    void on_send_2_clicked();
    //void reclamation();
    void sendMail();
    void mailSent(QString);

    //void on_sendBtn_clicked();
    void fekra(QString);
    void fekra2(QString);
    void fekra3(QString);

    void on_pushButton_3_clicked();

    //void on_pushButton_4_clicked();

    void on_pushButton_4_clicked();

   // void on_pushButton_5_clicked();//click ex mailling






    //void on_ajouter_3_clicked();

    void on_send_3_clicked();





    void on_pushButton_2_clicked();

    void on_add_clicked();

    void on_rechercher_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();


private:
    Ui::gerer_umbulance *ui;
    ambulance tmpambulance;
    Appel_urgence tmpappel;
    int ok=0;

};

#endif // GERER_UMBULANCE_H
