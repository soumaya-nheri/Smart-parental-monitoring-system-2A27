#include "site.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QPdfWriter>
#include<QPainter>
#include <QString>
#include<QSystemTrayIcon>
#include <QTableView>
Site::Site()
{
id=0; nom="";adresse="";type="";

}
Site::Site(int id ,QString nom,QString adresse ,QString type)
{this->id=id; this->type=type; this->nom=nom; this->adresse=adresse;}
int Site::getid(){return id;}
QString Site::gettype(){return type;}
QString Site::getnom(){return nom;}
QString Site::getadresse(){return adresse;}
void Site::setid(int id){this->id=id;}
void Site::settype(QString type){this->type=type;}
void Site::setnom(QString nom){this->nom=nom;}
void Site::setadresse(QString){this->adresse=adresse;}


bool Site::ajouter()
{


    QSqlQuery query;
    query.prepare("INSERT INTO Site (ID, NOM, ADRESSE,TYPE) "
                  "VALUES (:id, :nom, :adresse ,:type)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":type", type);

    return query.exec();




}
QSqlQueryModel* Site::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
             model->setQuery("SELECT* FROM Site");
         model->setHeaderData(id, Qt::Horizontal, QObject::tr( "identifiant"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));



    return model;
}
bool Site::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from Site where ID=:id");
    query.bindValue(":id", id);

    return query.exec();

}

bool Site::modifier()
{
QSqlQuery query;
      query.prepare("UPDATE Site SET ID=:id, NOM=:nom, ADRESSE=:adresse, TYPE=:type where ID=:id");
      query.bindValue(":id", id);
      query.bindValue(":nom", nom);
      query.bindValue(":adresse", adresse);
      query.bindValue(":type", type);
      return query.exec();
}
void  Site::telecharger()
{

                         QPdfWriter pdf("C:\\Users\\Desktop\\Atelier_Connexion\\Commande.pdf");
                         QPainter painter(&pdf);
                         int i = 4000;
                             painter.setPen(Qt::blue);
                             painter.setFont(QFont("Arial", 64));
                             painter.drawText(1100,1200,"Commande");
                             painter.setPen(Qt::black);
                             painter.setFont(QFont("Arial", 20));
                             painter.drawRect(100,100,7300,2600);
                             painter.drawRect(0,3000,9600,500);
                             painter.setFont(QFont("Arial", 15));
                             painter.drawText(200,3300,"ID");
                             painter.drawText(1300,3300,"NOM");
                             painter.drawText(6000,3300,"ADRESSE");
                             painter.drawText(7500,3300,"TYPE");
                             QSqlQuery query;
                             query.prepare("select * from SITE");
                             query.exec();
                             while (query.next())
                                                      {
                                                          painter.drawText(200,i,query.value(0).toString());
                                                          painter.drawText(1300,i,query.value(1).toString());
                                                          painter.drawText(6000,i,query.value(2).toString());
                                                          painter.drawText(7500,i,query.value(3).toString());
                                                          i = i + 500;
                                                      }
                            }
