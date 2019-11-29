#ifndef LOGIN_H
#define LOGIN_H
#include <QSound>


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LOGIN; }
QT_END_NAMESPACE

class LOGIN : public QMainWindow
{
    Q_OBJECT

public:
    LOGIN(QWidget *parent = nullptr);
    ~LOGIN();

private slots:
    void on_connecter_clicked();
    void on_comboBox_currentIndexChanged(int index);

    void on_quitter_clicked();

    void on_checkBox_clicked(bool checked);

private:
    Ui::LOGIN *ui;
     int espace=-1;//espace login
};
#endif // LOGIN_H
