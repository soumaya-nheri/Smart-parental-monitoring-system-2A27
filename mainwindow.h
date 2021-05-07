#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "parents.h"
#include <QMainWindow>
#include "temps.h"
#include "nutrition.h"
#include <QMediaPlayer>
#include "site.h"
#include "ecran.h"
#include<QtCharts>
#include<QChartView>
#include<QLineSeries>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkReply>
#include<QtNetwork/QNetworkRequest>


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


    void on_ajoutparents_clicked();

    void on_modifierparents_clicked();

    void on_affichage_clicked();

   void on_pushButton_supprimer_clicked();

   void on_ajouter_enfants_clicked();

   void on_modifier_enfants_clicked();

   void on_suppression_enf_clicked();

   void on_quitter_clicked();

   void on_trier_clicked();

   void on_recherche_clicked();

   void on_lineEdit_3_textChanged(const QString &arg1);

   void on_pdf_clicked();

   void on_trier_2_clicked();

   void on_recherche_3_clicked();

   void on_pdf_2_clicked();

   void on_browse_triggered(QAction *arg1);

   void on_browse_clicked();

   void on_trier_3_clicked();

   void on_trier_4_clicked();

   void on_pushButton_clicked();

   void on_pushButton_Mail_2_clicked();

   void on_ajouter_clicked();

   void on_imprimer_clicked();

   void on_lineEdit_4_textChanged(const QString &arg1);

   void on_modifier_clicked();

   void on_supprimer_clicked();

   void on_tridate_clicked();

   void on_trirendez_clicked();

   void on_triemp_clicked();

   void on_ajoutm_clicked();

   void on_modifiern_clicked();

   void on_supprimern_clicked();

   void on_tout_supp_clicked();

   void on_port_clicked();

   void on_pushButton_2_clicked();

   void on_pb_ajouter_clicked();

       void on_pb_supprimer_clicked();

       void on_pb_ajouter_2_clicked();

       void on_pb_supprimer_2_clicked();

       void on_pb_ajouter_3_clicked();

       void on_pb_ajouter_4_clicked();

       void on_recherche_textChanged(const QString &arg1);

     //  void on_pb_supprimer_4_clicked();

       void on_recherche_2_textChanged(const QString &arg1);

       void on_pushButton1_clicked();


private:
    Ui::MainWindow *ui;
    parents p ;
    Temps t;
    Temps t2;
    nutrition n;
    QBarSeries *series = new QBarSeries();
    QChart *chart = new QChart();
    QChartView *chartView = new QChartView(chart);
    QBarSet *set0 = new QBarSet("100-500");
   QBarSet *set1 = new QBarSet("500-1000");
   QBarSet *set2 = new QBarSet("1000-2000");
   QBarSet *set3 = new QBarSet("+2000");
    QMediaPlayer * sound;
    Site S;
    ecran E;
  //QNetworkAccessManager *manager;
  //QNetworkRequest request;

};



#endif // MAINWINDOW_H
