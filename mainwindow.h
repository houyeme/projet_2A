#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
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

private slots:

    void on_pushButton_6_clicked();


    void on_comboBox_activated(int index);

    void on_pushButton_clicked();


    void on_verticalSlider_sliderMoved(int position);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    int espace=-1;
    QMediaPlayer *music =new QMediaPlayer();
};
#endif // MAINWINDOW_H
