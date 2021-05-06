#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include "parents.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_connecter_clicked()
{

    QSqlQuery query;
        parents P1;
          bool login;

          QString user= ui->nom->text();
           QString   pass=ui->pass->text();

        login=P1.login(user,pass);
             if (login==true){
               mainwindow = new MainWindow(this);

               mainwindow->setWindowTitle("Gestion des Clients" );
                     mainwindow->show(); //showMaximized()

        }
             else
                 ui->label_3->setText("mot de passe incorrecte");
}
