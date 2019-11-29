#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "equipement.h"
#include <QMainWindow>
#include"fournisseur.h"
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QMediaPlayer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_ajouter_2_clicked();
    void on_pb_supprimer_2_clicked();
    void refresh();
    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_4_activated(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_16_textChanged(const QString &arg1);

    void on_lineEdit_20_textChanged(const QString &arg1);

    void on_checkBox_stateChanged(int arg1);
    void sendMail();
    void mailSent(QString);


    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_pushButton_3_clicked();

    void on_radioButton_3_clicked(bool checked);

    void on_radioButton_4_clicked(bool checked);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_verticalSlider_sliderMoved(int position);

    void on_envoyer_email_bott_clicked();

private:
    Ui::MainWindow *ui;
    equipement tmprdv;
    fournisseur tmprdv1;
    int etat;
    QString valeur,pays,pays1;
    QMediaPlayer *music =new QMediaPlayer();


};

#endif // MAINWINDOW_H
