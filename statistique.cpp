#include "statistique.h"
#include "ui_statistique.h"
#include "connexion.h"
#include <QMap>
#include <QVector>
#include <QString>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
#include <QSqlQuery>
#include <QDebug>
QT_CHARTS_USE_NAMESPACE
statistique::statistique(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
    QVector <QPieSlice *> tab;
        QPieSeries *series = new QPieSeries();
        QSqlQuery qry;
        int tous=0;
        int male=0;
        int female=0;

        qry.prepare("select * from patient ");
        if (qry.exec())
        {

            while (qry.next())
            {

    tous++;
    if (qry.value(4)=="male")
    {
        male++;
    }
    else if(qry.value(4)=="female")
    {
        female++;
    }


            }
        }


        qDebug () << "male " << male;
            qDebug () << "female " << female;


float testing1 =(male*100)/tous;
QString pleasework = QString::number(testing1);
float testing2 =(male*100)/tous;
QString pleasework1 = QString::number(testing2);
    series ->append("male "+pleasework+"%",(male));
        series ->append("female "+pleasework1+"%",(female));


QPieSlice * slice0= series->slices().at(0);
slice0->setLabelVisible();
QPieSlice * slice1= series->slices().at(1);
slice1->setLabelVisible();

    if (male>female)
    {

       slice0->setExploded();
        slice0->setPen(QPen(Qt::darkGreen,2));
       slice0->setBrush(Qt::red);

    }
    else
    {

 slice1->setExploded();
  slice1->setPen(QPen(Qt::darkGreen,2));
 slice1->setBrush(Qt::red);
    }





    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("produit  : ");
    chart->legend()->hide();



                QChartView *chartview = new QChartView (chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        QGridLayout *mainLayout = new QGridLayout;
            mainLayout->addWidget(chartview, 1, 1);
            setLayout(mainLayout);


}

statistique::~statistique()
{
    delete ui;
}
