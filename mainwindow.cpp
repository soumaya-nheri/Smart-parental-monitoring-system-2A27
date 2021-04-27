#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "temps.h"
#include "nutrition.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>
#include<QUrl>
#include <QDesktopServices>
#include <QSqlQuery >



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabemploi->setModel(t.afficher());
     ui->tabnutrition->setModel(n.afficher());
     sound = new QMediaPlayer();
     sound->setMedia(QUrl("qrc:/sounds/click.mp3"));
manager = new QNetworkAccessManager();
        QObject::connect(manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply) {
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }

                QString answer = reply->readAll();

                qDebug() << answer;
            }
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    sound->play();
    QString emploi=ui->emploi->text();
    QString dateh=ui->dateh->text();
     QString rendez_vous=ui->rendez_vous->text();
 Temps t(emploi,dateh,rendez_vous);
 bool test=t.ajouter();

 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("ajout avec succes.");
     ui->tabemploi->setModel(t.afficher());
 }
 else
     msgBox.setText("Echec de l'ajout");

     msgBox.exec();
     ui->tabemploi->setModel(t.afficher());;
}

void MainWindow::on_modifier_clicked()
{
    QString emploi=ui->emploim->text();
    QString dateh=ui->datehm->text();
     QString rendez_vous=ui->rendez_vousm->text();
 Temps t(emploi,dateh,rendez_vous);
 bool test=t.modifier();

 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("modifier avec succes.");
     ui->tabemploi->setModel(t.afficher());
 }
 else
     msgBox.setText("Echec de modification");
 sound->play();
     msgBox.exec();
     ui->tabemploi->setModel(t.afficher());

}


void MainWindow::on_supprimer_clicked()
{

    Temps t1; t1.setdateh(ui->datehm->text());
    bool test=t1.supprimer(t1.getdateh());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tabemploi->setModel(t.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
sound->play();
        msgBox.exec();
}

void MainWindow::on_ajoutm_clicked()
{
    QString dej=ui->dej->text();
    QString diner=ui->diner->text();
     QString pttdej=ui->pttdej->text();
     int calories=ui->calories->text().toInt();
      QString dater=ui->dater->text();
      QString emp=ui->emp->text();
 nutrition n(pttdej,dej,diner,calories,dater,emp);
 bool test=n.ajouter();

 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("ajout avec succes.");
     ui->tabnutrition->setModel(n.afficher());
 }
 else
     msgBox.setText("Echec de l'ajout");
 sound->play();
     msgBox.exec();
     ui->tabnutrition->setModel(n.afficher());
}

void MainWindow::on_modifiern_clicked()
{
    QString dej=ui->dejm->text();
    QString diner=ui->dinerm->text();
     QString pttdej=ui->pttdejm->text();
     int calories=ui->caloriesm->text().toInt();
      QString dater=ui->daterm->text();
      QString emp=ui->empm->text();
 nutrition n(pttdej,dej,diner,calories,dater,emp);
 bool test=n.modifier();

 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("modifier avec succes.");
     ui->tabnutrition->setModel(n.afficher());

 }
 else
     msgBox.setText("Echec de modification");
 sound->play();
     msgBox.exec();
     ui->tabnutrition->setModel(n.afficher());
}

void MainWindow::on_supprimern_clicked()
{
    nutrition n; n.setdater(ui->daterm->text());
    bool test=n.supprimer(n.getdater());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tabnutrition->setModel(n.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
sound->play();
        msgBox.exec();
}




void MainWindow::on_imprimer_clicked()
{
    QPrinter *imprimante;
       QPrintDialog pd(ui->tabemploi);
       if(pd.exec()== QDialog::Accepted) return;
       imprimante=pd.printer();
       imprimante->setOutputFormat(QPrinter::PdfFormat);
       imprimante->setOutputFileName("Bureau/doc.pdf");

}

void MainWindow::on_envoyer_clicked()
{
    QMessageBox msgBox;
    QString mail=ui->le_envoyer->text();
    QString objet=ui->le_objet->text();
    QString msg=ui->te_mail->toPlainText();
        if(mail.contains(QRegExp("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$")))
        {request.setUrl(QUrl("http://playpals.io/mailerkhalilsecret.php?email="+mail+"&subject="+objet+"&content="+msg+"&psw=testttesttttaztatga"));
             manager->get(request);
              msgBox.setText("mail envoyer");
        }
        else
          msgBox.setText("adresse  mail incorrect");
sound->play();
         msgBox.exec();

}

void MainWindow::on_tridate_clicked()
{
    ui->tabemploi->setModel(t.affichertd());
}

void MainWindow::on_trirendez_clicked()
{
    ui->tabemploi->setModel(t.affichertr());
}

void MainWindow::on_triemp_clicked()
{
    ui->tabemploi->setModel(t.afficherte());
}

void MainWindow::on_recherche_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM TEmPS WHERE dateh  LIKE'"+arg1+"%' or rendez_vous  LIKE'"+arg1+"%' or emploi  LIKE'"+arg1+"%' ");
     query->exec();
     if (query->next()) {
     model->setQuery(*query);
     ui->tabemploi->setModel(model);
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                         QObject::tr("NO MATCH FOUND !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         ui->recherche->clear();}
}

void MainWindow::on_verifiermvnt_clicked()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_23->setText("mouvement detecté"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_23->setText("pas de mouvement");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}
