#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "site.h"
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_site->setModel(S.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString type=ui->le_type->text();
    QString nom=ui->le_nom->text();
    QString adresse=ui->le_adresse->text();
    Site S(id,type,nom,adresse);

}


void MainWindow::on_pb_supprimer_clicked()
{
    Site S1; S1.setid(ui->leid_supp->text().toUInt());
    bool test=S1.supprimer(S1.getid());
    QMessageBox msgBox;

    if(test)
        msgBox.setText("Supprion avec succes");
    ui->tab_site->setModel(S.afficher());


}
