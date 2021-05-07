#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "site.h"
#include "ecran.h"
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

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_ajouter_4_clicked();

    void on_recherche_textChanged(const QString &arg1);

  //  void on_pb_supprimer_4_clicked();

    void on_recherche_2_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Site S;
    ecran E;
  //QNetworkAccessManager *manager;
  //QNetworkRequest request;

};

#endif // MAINWINDOW_H
