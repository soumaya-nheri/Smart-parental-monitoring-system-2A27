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
  QVector<float> nutrition::stat()
  {
      QSqlQuery q1,q2,q3,q4,q5;
  double rows,s1,s2,s3,s4;
  rows=0;s2=0;s3=0;s4=0;s1=0;

     q1.prepare("SELECT count (*)  from NUTRITION  " );

                     q1.exec();
                      if (q1.next()) {
                      rows= q1.value(0).toInt();}
        q2.prepare("SELECT count (*)  from NUTRITION where CALORIES  between 0 and 500 " );

                                      q2.exec();
                                       if (q2.next()) {
                                      s1= q2.value(0).toInt();}
    q3.prepare("SELECT count (*)  from NUTRITION where CALORIES between 500 and 1000 " );

                                            q3.exec();
                                               if (q3.next()) {
                                              s2= q3.value(0).toInt();}
     q4.prepare("SELECT count (*)  from NUTRITION where CALORIES between 1000 and 2000 " );

                                                                                       q4.exec();
                                                                                          if (q4.next()) {
                                                                                         s3= q4.value(0).toInt();}
     q5.prepare("SELECT count (*)  from NUTRITION where CALORIES > 2000  " );

                                         q5.exec();
                               if (q5.next()) {
                             s4= q5.value(0).toInt();}

  QVector<float>stats;
  float a1 = (s1/rows)*100;
  float a2 = (s2/rows)*100;
  float a3 = (s3/rows)*100;
  float a4 =  (s4/rows)*100;

  stats.push_back(a1);
  stats.push_back(a2);
  stats.push_back(a3);
  stats.push_back(a4);

  return stats;
  }


