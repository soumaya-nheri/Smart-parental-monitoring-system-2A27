#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parents.h"
#include "enfants.h"
#include "smtp.h"
#include "temps.h"
#include "nutrition.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QString>
#include <QUrl>
#include <QDebug>
#include <QTextBrowser>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QStatusBar>
#include <QMainWindow>
#include <QPdfWriter>
#include <QPainter>
#include <QPlainTextDocumentLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QMessageBox>
#include <QDate>
#include <QDateEdit>
#include <QLineEdit>
#include "smtp.h"
#include <QDebug>
#include<QComboBox>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QPlainTextEdit>
#include <QPlainTextDocumentLayout>
#include "portes.h"
#include "electomenage.h"

#define Email_RX "\\b[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}\\b"
#define Name_RX "^[a-zA-Z][a-zA-Z\\s]+$"
#define Number_RX "^[0-9]*$"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabemploi->setModel(t.afficher());
     ui->tabnutrition->setModel(n.afficher());
     sound = new QMediaPlayer();
     sound->setMedia(QUrl("qrc:/sounds/click.mp3"));
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_ajoutparents_clicked()
{
    sound->play();
    QString NOM_DE_FAMILLE=ui->lineEdit->text();
    QString PRENOM_RES= ui->lineEdit_2->text();
    int CIN=ui->lineEdit_3->text().toInt();
    QString EMAIL_RESP=ui->email->text();
    QString PASSWORD =ui->lineEdit_6->text();
     QString PAYS=ui->lineEdit_8->text();


   parents p (NOM_DE_FAMILLE,PRENOM_RES,CIN,EMAIL_RESP,PASSWORD,PAYS);
    bool test=p.ajouter();

        if(test)
            {
            ui->comboBox_mail_2->setModel(p.afficher_email());
            bool test2=false;
            QString mail_reverse ;
                        for (QString::iterator it = EMAIL_RESP.begin(); it != EMAIL_RESP.end(); ++it)
                            mail_reverse.push_front(*it);

                if(mail_reverse.startsWith( "moc.liamg@" ))
                        test2=true ;
                else
                    test2=false ;

                if(test2==false)
                {
                    QMessageBox::critical(nullptr, QObject::tr("email de la carte"),
                                QObject::tr("il faut @gmail.com !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
            else if(test)
          {
          ui->tableaffiche->setModel(p.afficher());//refresh
          QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                            QObject::tr("client ajouté.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
          ;
                }
                ui->lineEdit->clear();
                ui->lineEdit_2->clear() ;
                ui->lineEdit_3->clear() ;
                ui->email->clear() ;
                ui->lineEdit_6->clear() ;
                ui->lineEdit_8->clear() ;



            }


    else
        {
            QMessageBox msgBox ;
            msgBox.setText("parents non ajouté ");;
        }
}





void MainWindow::on_affichage_clicked()
{
    sound->play();
    parents p ;
    ui->tableaffiche->setModel(p.afficher());


}
void MainWindow::on_modifierparents_clicked()

{
    sound->play();

        QString NOM_DE_FAMILLE=ui->lineEdit->text();
            QString PRENOM_RES= ui->lineEdit_2->text();
            int CIN=ui->lineEdit_3->text().toInt();
            QString EMAIL_RESP=ui->email->text();
            QString PASSWORD =ui->lineEdit_6->text();
            QString PAYS=ui->lineEdit_8->text();
        parents p (NOM_DE_FAMILLE,PRENOM_RES,CIN,EMAIL_RESP,PASSWORD,PAYS);



        bool test=p.modifier(NOM_DE_FAMILLE,PRENOM_RES,CIN,EMAIL_RESP,PASSWORD,PAYS);

            if(test)
                {
                    QMessageBox msgBox ;
                    QMessageBox::information(this,"information"," parents modifier");;

                    ui->tableaffiche->setModel(p.afficher());//refresh
                    QMessageBox::information(nullptr, QObject::tr("modification de parents "),
                                      QObject::tr("parents modifier .\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                    ;
            }
            else
            {  QMessageBox msgBox ;
                QMessageBox::information(this,"information"," parents nom modifier");;}


     ui->lineEdit->clear();
        ui->lineEdit_2->clear() ;
        ui->lineEdit_3->clear() ;
        ui->email->clear() ;
        ui->lineEdit_6->clear() ;
        ui->lineEdit_8->clear() ;
}
















void MainWindow::on_pushButton_supprimer_clicked()
{
    sound->play();
    parents p ;
    int cin = ui->le_id_sup->text().toInt();
    bool test=p.supprimer(cin);
    if(test)
        {
            QMessageBox msgBox ;
            QMessageBox::information(this,"information"," parents supprimer");;
           ui->tableaffiche->setModel(p.afficher());

          }


else
    {
        QMessageBox msgBox ;
        msgBox.setText("parents non supprimer ");;
        msgBox.exec();
    }
}

void MainWindow::on_ajouter_enfants_clicked()
{
    sound->play();
    int ID=ui->id_line->text().toInt();
    QString NOM_ENF=ui->linenom->text();
    QString PRENOM_ENF=ui->lineprenom->text();
    enfants Enf (ID,NOM_ENF,PRENOM_ENF);

    bool test=Enf.ajouter();

        if(test)
            {
            QMessageBox msgBox ;
            QMessageBox::information(this,"information"," parents ajouté");;

            ui->tableaffichage_enfants->setModel(Enf.afficher());
            QMessageBox::information(nullptr, QObject::tr("Ajouter un enfants"),
                              QObject::tr("enfants ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel) ;;
            ui->id_line->clear();
            ui->linenom->clear() ;
            ui->lineprenom->clear() ;

               }


        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un enfants"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier_enfants_clicked()
{
    sound->play();
    int ID=ui->id_line->text().toInt();
    QString NOM_ENF=ui->linenom->text();
    QString PRENOM_ENF=ui->lineprenom->text();
    enfants Enf (ID,NOM_ENF,PRENOM_ENF);

 bool test=Enf.modifier(ID,NOM_ENF,PRENOM_ENF);

        if(test)
            {
                QMessageBox msgBox ;
                QMessageBox::information(this,"information"," enfants modifier");;

                ui->tableaffichage_enfants->setModel(Enf.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("modification de enfants "),
                                  QObject::tr("enfants modifier .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                ;
        }
        else
        {  QMessageBox msgBox ;
            QMessageBox::information(this,"information"," enfants nom modifier");;}

        ui->id_line->clear();
        ui->linenom->clear() ;
        ui->lineprenom->clear() ;
}

void MainWindow::on_suppression_enf_clicked()
{
    sound->play();
    enfants Enf ;
    int ID = ui->line_ID_sup_enf->text().toInt();
    bool test=Enf.supprimer(ID);
    if(test)
        {
            QMessageBox msgBox ;
            QMessageBox::information(this,"information"," enfants supprimer");;
           ui->tableaffichage_enfants->setModel(Enf.afficher());

          }


else
    {
        QMessageBox msgBox ;
        msgBox.setText("enfants non supprimer ");;
        msgBox.exec();
    }
}

void MainWindow::on_quitter_clicked()
{
    sound->play();
 this->close();
}



void MainWindow::on_trier_clicked()
{
sound->play();
    QSqlQueryModel * model=p.trier();
    ui->tableaffiche->setModel(model);
}

void MainWindow::on_recherche_clicked()
{
    sound->play();
    int iidc = ui->recherche_2->text().toInt();
        QSqlQueryModel * model= new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery();
        qry->prepare("SELECT * from parents where CIN like concat (:iidc,'%')");
        qry->bindValue(":iidc",iidc);
        qry->exec();
        model->setQuery(*qry);
        ui->tableaffiche->setModel(model) ;
}




void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    sound->play();
    int CIN=ui->lineEdit_3->text().toInt();
        if (CIN>10000000 && CIN <99999999)
        {
            QPalette *palette = new QPalette();
            palette->setColor(QPalette::Text,Qt::green);
            ui->lineEdit_3->setPalette(*palette);

        }
        else
        {
            QPalette *palette = new QPalette();
            palette->setColor(QPalette::Text,Qt::red);
            ui->lineEdit_3->setPalette(*palette);

        }
}

void MainWindow::on_pdf_clicked()
{
    sound->play();
    QPdfWriter pdf("C:/Users/user/Desktop/secure family/Atelier_Connexion/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1100,1200,"Liste Des parents ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(100,100,7300,2600);

        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"NOM_DE_FAMILLE");
        painter.drawText(1700,3300,"PRENOM_RES");
        painter.drawText(3200,3300,"CIN");
        painter.drawText(6600,3300,"EMAIL_RESP");
        painter.drawText(4900,3300,"PAYS");

        QSqlQuery query;
        query.prepare("select * from parents");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1700,i,query.value(1).toString());
            painter.drawText(3200,i,query.value(2).toString());
            painter.drawText(4900,i,query.value(3).toString());
            painter.drawText(6600,i,query.value(4).toString());

           i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/user/Desktop/secure family/Atelier_Connexion/Pdf.pdf"));
                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}

void MainWindow::on_trier_2_clicked()
{
    sound->play();
    enfants Enf ;

    QSqlQueryModel * model=Enf.trier();
    ui->tableaffichage_enfants->setModel(model);
}

void MainWindow::on_recherche_3_clicked()
{
    sound->play();
    int iidc = ui->idrecherche->text().toInt();
        QSqlQueryModel * model= new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery();
        qry->prepare("SELECT * from enfants where ID like concat (:iidc,'%')");
        qry->bindValue(":iidc",iidc);
        qry->exec();
        model->setQuery(*qry);
        ui->tableaffichage_enfants->setModel(model);
}

void MainWindow::on_pdf_2_clicked()
{
    sound->play();
    QPdfWriter pdf("C:/Users/user/Desktop/secure family/Atelier_Connexion/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1100,1200,"Liste Des enfants ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(100,100,7300,2600);

        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"ID");
        painter.drawText(1700,3300,"NOM_ENF");
        painter.drawText(3200,3300,"PRENOM_ENF");





        QSqlQuery query;
        query.prepare("select * from enfants");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1700,i,query.value(1).toString());
            painter.drawText(3200,i,query.value(2).toString());
           i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/user/Desktop/secure family/Atelier_Connexion/Pdf.pdf"));
                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}



void MainWindow::on_pushButton_Mail_2_clicked()
{
    sound->play();
    Smtp* smtp = new Smtp("eyadhaouadi51@gmail.com","191JFT0072","smtp.gmail.com",465);
           connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

           smtp->sendMail("eyadhaouadi51@gmail.com",ui->comboBox_mail_2->currentText(),ui->subject_2->text(),ui->msg_2->toPlainText());
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

void MainWindow::on_imprimer_clicked()
{
    sound->play();
    QPrinter *imprimante;
       QPrintDialog pd(ui->tabemploi);
       if(pd.exec()== QDialog::Accepted) return;
       imprimante=pd.printer();
       imprimante->setOutputFormat(QPrinter::PdfFormat);
       imprimante->setOutputFileName("Bureau/doc.pdf");
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    sound->play();
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

         ui->lineEdit_4->clear();}
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

void MainWindow::on_tout_supp_clicked()
{
    QSqlQuery query;
  query.prepare("DELETE FROM NUTRITION");
    query.exec();
    if(query.exec())
    {
        QMessageBox::critical(nullptr, QObject::tr("DELETE DB "),
                        QObject::tr("tout est supprimer !.\n"
                                    "Click Ok to exit."), QMessageBox::Ok);
         ui->tabnutrition->setModel(n.afficher());
}
    }

void MainWindow::on_port_clicked()
{
    portes *m = new portes();
    m->show();
}



void MainWindow::on_pushButton_2_clicked()
{
    ELECTOMENAGE *m = new ELECTOMENAGE();
    m->show();
}
