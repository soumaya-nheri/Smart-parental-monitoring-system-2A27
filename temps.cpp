#include "temps.h"
#include <QSqlQuery >
#include <QtDebug>
#include <QObject>
Temps::Temps()
{
emploi=" ";dateh=" "; rendez_vous=" ";
}
Temps::Temps(QString emploi,QString dateh,QString rendez_vous)
{this->emploi=emploi; this->dateh=dateh; this->rendez_vous=rendez_vous;}
        QString Temps::getemploi(){return emploi;}
 QString Temps::getdateh(){return dateh;}
  QString Temps::getrendez_vous() {return rendez_vous;}
  void Temps::setemploi(QString emploi){ this->emploi=emploi;}
  void Temps::setdateh(QString dateh){ this-> dateh=dateh;}
  void Temps::setrendez_vous(QString rendez_vous){ this->rendez_vous=rendez_vous;}
  bool Temps::ajouter()
  {
      QSqlQuery query;
           query.prepare("INSERT INTO TEMPS (emploi,rendez_vous, dateh) "
                         "VALUES (:emploi,:rendez_vous, :dateh)");
           query.bindValue(":emploi", emploi);
           query.bindValue(":rendez_vous",rendez_vous);
           query.bindValue(":dateh", dateh);
          return query.exec();

  }
  QSqlQueryModel* Temps::afficher()
  {
      QSqlQueryModel* model =new QSqlQueryModel();
           model->setQuery("SELECT* FROM TEMPS");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("emploi du temps"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("vos notes "));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("pour le : "));
          return model;

  }
  QSqlQueryModel* Temps::affichertd()
  {
      QSqlQueryModel *model = new QSqlQueryModel();

      model->setQuery("SELECT * FROM TEMPS order by dateh desc ");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("emploi du temps"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("vos notes "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("pour le : "));

      return  model;
  }
  QSqlQueryModel* Temps::affichertr()
  {
      QSqlQueryModel *model = new QSqlQueryModel();

      model->setQuery("SELECT * FROM TEMPS order by rendez_vous desc ");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("emploi du temps"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("vos notes "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("pour le : "));

      return  model;
  }
  QSqlQueryModel* Temps::afficherte()
  {
      QSqlQueryModel *model = new QSqlQueryModel();

      model->setQuery("SELECT * FROM TEMPS order by emploi desc ");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("emploi du temps"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("vos notes "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("pour le : "));

      return  model;
  }
  bool Temps::supprimer(QString dateh)
  {
      QSqlQuery query;
      query.prepare("Delete from TEMPS where dateh = :dateh");
      query.bindValue(":dateh", dateh);
      return query.exec();
  }
  bool Temps::modifier()
  {
      QSqlQuery query;
      query.prepare("UPDATE TEMPS SET emploi=:emploi, rendez_vous=:rendez_vous, dateh=:dateh where dateh=:dateh");
      query.bindValue(":emploi", emploi);
      query.bindValue(":rendez_vous", rendez_vous);
      query.bindValue(":dateh", dateh);
      return query.exec();

  }

