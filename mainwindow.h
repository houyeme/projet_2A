#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QDateTime>
#include <QMainWindow>
#include <QMediaPlayer>
#include "arduino.h"
#include "gestion_de_mediacament.h"
#include "gestion_de_mediacament1.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool verif_formulaire();
void dark_mode();
void par_defaut();
void showTime();

private slots:

    void on_pushButton_6_clicked();


    void on_comboBox_activated(int index);

    void on_pushButton_clicked();





    void on_actionDark_triggered();

    void on_actionnormale_triggered();


    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    int espace=-1;
    QString mode="par_defaut";

QString langue;
QMediaPlayer *player;
};
#endif // MAINWINDOW_H
