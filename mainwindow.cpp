#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "site.h"
#include "ecran.h"
#include <QIntValidator>
#include <QSqlQuery>
#include<QUrl>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_id_2->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_site->setModel(S.afficher());
    ui->tab_site_2->setModel(E.afficher());
//manager = new QNetworkAccessManager();
       // QObject::connect(manager, &QNetworkAccessManager::finished,
            //this, [=](QNetworkReply *reply) {
                //if (reply->error()) {
                    //qDebug() << reply->errorString();
                    //return;
                //}

                //QString answer = reply->readAll();

              //  qDebug() << answer;
          //  }
    // );

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString adresse=ui->le_adresse->text();
     QString type=ui->le_type->text();
    Site S(id,nom,adresse,type);
    bool test=S.ajouter();

     QMessageBox msgBox;

     if(test)
       {  msgBox.setText("ajout avec succes.");
         ui->tab_site->setModel(S.afficher());
     }
     else
         msgBox.setText("Echec de l'ajout");

         msgBox.exec();
         ui->tab_site->setModel(S.afficher());;
    }




void MainWindow::on_pb_supprimer_clicked()
{

    Site S1; S1.setid(ui->leid_supp->text().toUInt());
    bool test=S1.supprimer(S1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprion avec succes");
    ui->tab_site->setModel(S.afficher());
    }
     else
         msgBox.setText("Echec de suppression");

         msgBox.exec();
         ui->tab_site->setModel(S.afficher());;


}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QString type=ui->le_id_3 ->text();
    QString etat=ui->le_id_4->text();
    ecran E(id,type,etat);
    bool test=E.ajouter();

     QMessageBox msgBox;

     if(test)
       {  msgBox.setText("ajout avec succes.");
         ui->tab_site_2->setModel(E.afficher());
     }
     else
         msgBox.setText("Echec de l'ajout");

         msgBox.exec();
         ui->tab_site_2->setModel(E.afficher());;

}

void MainWindow::on_pb_supprimer_2_clicked()
{

    ecran E1; E1.setid(ui->leid_supp_2->text().toUInt());
    bool test=E1.supprimer(E1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprion avec succes");
    ui->tab_site_2->setModel(E.afficher());
    }
     else
         msgBox.setText("Echec de suppression");

         msgBox.exec();
         ui->tab_site_2->setModel(E.afficher());;

}

void MainWindow::on_pb_ajouter_3_clicked()
{
    int id=ui->le_id_5->text().toInt();
    QString nom=ui->le_id_7->text();
     QString adresse=ui->le_id_6->text();
      QString type=ui->le_id_8->text();
 Site S(id,nom,adresse,type);
 bool test=S.modifier();

 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("modifier avec succes.");
     ui->tab_site->setModel(S.afficher());

 }
 else
     msgBox.setText("Echec de modification");

     msgBox.exec();
     ui->tab_site->setModel(S.afficher());
}


void MainWindow::on_pb_ajouter_4_clicked()
{
    int id=ui->le_id_9->text().toInt();
     QString type=ui->le_id_10->text();
    QString etat=ui->le_id_11->text();

 ecran E(id,type,etat);
 bool test=E.modifier();

 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("modifier avec succes.");
     ui->tab_site_2->setModel(E.afficher());

 }
 else
     msgBox.setText("Echec de modification");

     msgBox.exec();
     ui->tab_site_2->setModel(E.afficher());
}


void MainWindow::on_recherche_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM Site WHERE ID  LIKE'"+arg1+"%' or NOM  LIKE'"+arg1+"%' or ADRESSE  LIKE'"+arg1+"%'  or TYPE  LIKE'"+arg1+"%' ");
     query->exec();
     if (query->next())
     {
     model->setQuery(*query);
     ui->tab_site->setModel(model);
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         ui->recherche->clear();}
}

//void MainWindow::on_pb_supprimer_4_clicked()
//{

//    QMessageBox msgBox;
//    QString destinataire=ui->leid_supp_4->text();
//    QString objet=ui->leid_supp_6->text();
//    QString msg=ui->leid_supp_5->text();
//        if(destinataire.contains(QRegExp("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$")))
//        {request.setUrl(QUrl("http://playpals.io/mailerkhalilsecret.php?email="+destinataire+"&subject="+objet+"&content="+msg+"&psw=testttesttttaztatga"));
//             manager->get(request);
//              msgBox.setText("mail envoyer");
//        }
//        else
//          msgBox.setText("adresse  mail incorrect");
//         msgBox.exec();
//}

void MainWindow::on_recherche_2_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM ECRAN WHERE ID  LIKE'"+arg1+"%' or ETAT  LIKE'"+arg1+"%'  or TYPE  LIKE'"+arg1+"%' ");
     query->exec();
     if (query->next())
     {
     model->setQuery(*query);
     ui->tab_site_2->setModel(model);
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         ui->recherche_2->clear();}
}

void MainWindow::on_pushButton_clicked()
{
        Site cat ;
       cat.telecharger();

       QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);



    }


