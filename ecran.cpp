#include "ecran.h"
#include <QSqlQuery>
#include <QtDebug>
#include "notifications.h"
ecran::ecran()
{
    id=0; type="";etat="";

    }
    ecran::ecran(int id ,QString type,QString etat )
    {this->id=id; this->type=type; this->etat=etat;}
    int ecran::getid(){return id;}
    QString ecran::gettype(){return type;}
    QString ecran::getetat(){return etat;}
    void ecran::setid(int id){this->id=id;}
    void ecran::settype(QString type){this->type=type;}
    void ecran::setetat(QString etat){this->etat=etat;}


    bool ecran::ajouter()
    {


        QSqlQuery query;
        query.prepare("INSERT INTO ECRAN (ID, TYPE, ETAT) "
                      "VALUES (:id, :type, :etat)");
        query.bindValue(":id", id);
        query.bindValue(":type", type);
        query.bindValue(":etat", etat);
        return query.exec();




    }
    QSqlQueryModel* ecran::afficher()
    {
        QSqlQueryModel* model=new QSqlQueryModel();
                 model->setQuery("SELECT* FROM ECRAN");
             model->setHeaderData(id, Qt::Horizontal, QObject::tr( "identifiant"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));




        return model;
    }
    bool ecran::supprimer(int id)
    {
        QSqlQuery query;
        query.prepare("Delete from ECRAN  where ID=:id");
        query.bindValue(":id", id);

        return query.exec();

    }
    bool ecran::modifier()
    {
    QSqlQuery query;
          query.prepare("UPDATE ECRAN SET ID=:id, ETAT=:etat, TYPE=:type where ID=:id");
          query.bindValue(":id", id);
          query.bindValue(":etat", etat);
          query.bindValue(":type", type);
          return query.exec();
    }
    void ecran::verifier()
     {
         QSqlQuery qry;

      if (qry.exec("select * from ECRAN "))
      {

           int n=0;
          while (qry.next())
          {
              qDebug () <<n;


                n= qry.value(3).toInt();
                if(n==1)
                {  Notifications N;
                      N.notifications_ecran();


                }

          }

      }


     }
