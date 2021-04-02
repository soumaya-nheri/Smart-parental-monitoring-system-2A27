#include "nutrition.h"
#include <QSqlQuery >
#include <QtDebug>
#include <QObject>
nutrition::nutrition()
{
pttdej=" ";dej=" "; diner=" ";calories=0;dater=" ";emp=" ";
}
nutrition::nutrition(QString pttdej,QString dej,QString diner,int calories,QString dater,QString emp)
{this->pttdej=pttdej; this->dej=dej; this->diner=diner;this->calories=calories;this->dater=dater;this->emp=emp;}
        QString nutrition::getpttdej(){return pttdej;}
 QString nutrition::getdej(){return dej;}
  QString nutrition::getdiner() {return diner;}
  int nutrition::getcalories() {return calories;}
  QString nutrition::getdater() {return dater;}
  QString nutrition::getemp() {return emp;}
  void nutrition::setpttdej(QString pttdej){ this->pttdej=pttdej;}
  void nutrition::setdej(QString dej){ this->dej=dej;}
  void nutrition::setdiner(QString diner){ this->diner=diner;}
  void nutrition::setcalories(int calories){ this->calories=calories;}
  void nutrition::setdater(QString dater){ this->dater=dater;}
  void nutrition::setemp(QString emp){ this->emp=emp;}
  bool nutrition::ajouter()
  {
      QSqlQuery query;
           query.prepare("INSERT INTO NUTRITION (DEJEUNER,DINER,PTT_DEJ,CALORIES,DATER,EMPREINTE) "
                         "VALUES (:dej,:diner, :pttdej ,:calories,:dater,:emp)");
           query.bindValue(":dej", dej);
           query.bindValue(":diner",diner);
           query.bindValue(":pttdej", pttdej);
           query.bindValue(":calories", calories);
           query.bindValue(":dater", dater);
           query.bindValue(":emp", emp);
          return query.exec();

  }
  QSqlQueryModel* nutrition::afficher()
  {
      QSqlQueryModel* model =new QSqlQueryModel();
           model->setQuery("SELECT* FROM NUTRITION");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("le dejeuner"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("le diner "));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("le petit dej "));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("calories "));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("pour le : "));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("menu de: "));
          return model;

  }
  bool nutrition::supprimer(QString dater)
  {
      QSqlQuery query;
      query.prepare("Delete from NUTRITION where DATER =:dater");
      query.bindValue(":dater", dater);
      return query.exec();
  }
  bool nutrition::modifier()
  {
      QSqlQuery query;
      query.prepare("UPDATE NUTRITION SET DEJEUNER=:dej,DINER=:diner,PTT_DEJ=:pttdej,CALORIES=:calories,DATER=:dater,EMPREINTE=:emp where DATER=:dater");
      query.bindValue(":dej", dej);
      query.bindValue(":diner",diner);
      query.bindValue(":pttdej", pttdej);
      query.bindValue(":calories", calories);
      query.bindValue(":dater", dater);
      query.bindValue(":emp", emp);
      return query.exec();

  }

