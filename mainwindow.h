#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "arduino.h"
#include <QMainWindow>
#include "temps.h"
#include "nutrition.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QNetworkRequest>
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
    void update_label();
    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_ajoutm_clicked();

    void on_modifiern_clicked();

    void on_supprimern_clicked();

    void on_imprimer_clicked();


    void on_envoyer_clicked();

    void on_tridate_clicked();

    void on_trirendez_clicked();

    void on_triemp_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on_ttsup_clicked();

    void on_pushButton_clicked();

    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

private:
    Ui::MainWindow *ui;
    Temps t;
    Temps t2;
    nutrition n;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QMediaPlayer * sound;
    QByteArray data; // variable contenant les données reçues

    arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
