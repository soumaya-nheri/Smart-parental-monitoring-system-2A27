#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parents.h"
#include "enfants.h"
#include "smtp.h"
#include <QMessageBox>
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

#define Email_RX "\\b[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}\\b"
#define Name_RX "^[a-zA-Z][a-zA-Z\\s]+$"
#define Number_RX "^[0-9]*$"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_ajoutparents_clicked()
{
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
    parents p ;
    ui->tableaffiche->setModel(p.afficher());


}
void MainWindow::on_modifierparents_clicked()

{

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
 this->close();
}



void MainWindow::on_trier_clicked()
{

    QSqlQueryModel * model=p.trier();
    ui->tableaffiche->setModel(model);
}

void MainWindow::on_recherche_clicked()
{
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
    enfants Enf ;

    QSqlQueryModel * model=Enf.trier();
    ui->tableaffichage_enfants->setModel(model);
}

void MainWindow::on_recherche_3_clicked()
{
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
    Smtp* smtp = new Smtp("eyadhaouadi51@gmail.com","191JFT0072","smtp.gmail.com",465);
           connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

           smtp->sendMail("eyadhaouadi51@gmail.com",ui->comboBox_mail_2->currentText(),ui->subject_2->text(),ui->msg_2->toPlainText());
}
