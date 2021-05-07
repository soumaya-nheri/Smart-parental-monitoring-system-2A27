#include "parents.h"
#include <QDebug>
#include "connection.h"
#include <QMainWindow>
#include <QDialog>
#include <QObject>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QMessageBox>
parents::parents()
{

NOM_DE_FAMILLE="";
PRENOM_RES="";
CIN=0;
EMAIL_RESP="";
PASSWORD="";
PAYS="";

}
parents::parents(QString NOM_DE_FAMILLE,QString PRENOM_RES,int CIN,QString EMAIL_RESP,QString PASSWORD,QString PAYS)
{

  this->NOM_DE_FAMILLE=NOM_DE_FAMILLE;
  this->PRENOM_RES=PRENOM_RES;
  this->CIN=CIN ;
  this->EMAIL_RESP=EMAIL_RESP ;
  this->PASSWORD=PASSWORD ;
  this->PAYS=PAYS ;

}
QString parents::get_NOM_DE_FAMILLE(){return NOM_DE_FAMILLE;}
QString parents::get_PRENOM_RES(){return PRENOM_RES;}
int parents::get_CIN(){return  CIN;}
QString parents::get_EMAIL_RESP(){return EMAIL_RESP; }
QString parents::get_PASSWORD(){return PASSWORD; }
QString parents::get_PAYS(){return PAYS; }


bool parents::ajouter()
{
QSqlQuery query;


query.prepare("INSERT INTO parents (NOM_DE_FAMILLE, PRENOM_RES,  CIN, EMAIL_RESP ,PASSWORD,PAYS)"
                    "VALUES ( :NOM_DE_FAMILLE, :PRENOM_RES,  :CIN, :EMAIL_RESP , :PASSWORD, :PAYS)");
query.bindValue(":NOM_DE_FAMILLE", NOM_DE_FAMILLE);
query.bindValue(":PRENOM_RES", PRENOM_RES);
query.bindValue(":CIN", CIN);
query.bindValue(":EMAIL_RESP", EMAIL_RESP);
query.bindValue(":PASSWORD", PASSWORD);
query.bindValue(":PAYS", PAYS);

return    query.exec();
}
bool parents::modifier(QString NOM_DE_FAMILLE,QString PRENOM_RES,int CIN,QString EMAIL_RESP,QString PASSWORD,QString PAYS)
{
    QSqlQuery query;
    query.prepare("UPDATE parents set NOM_DE_FAMILLE = :NOM_DE_FAMILLE, PRENOM_RES = :PRENOM_RES, EMAIL_RESP = :EMAIL_RESP, PASSWORD = :PASSWORD , PAYS = :PAYS WHere CIN = :CIN");

    query.bindValue(":NOM_DE_FAMILLE", NOM_DE_FAMILLE);
    query.bindValue(":PRENOM_RES", PRENOM_RES);
    query.bindValue(":CIN",CIN);
    query.bindValue(":EMAIL_RESP", EMAIL_RESP);
    query.bindValue(":PASSWORD", PASSWORD);
    query.bindValue(":PAYS", PAYS);
    return    query.exec();
}
bool parents::supprimer(int CIN )
{
    QSqlQuery query;
    query.prepare("delete from parents where CIN=:CIN");

    query.bindValue(":CIN", CIN);

    return    query.exec();
}
QSqlQueryModel * parents::afficher()
{ QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from parents");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_DE_FAMILLE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM_RES "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMAIL_RESP"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PASSWORD"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("PAYS"));

return model;
}
QSqlQueryModel * parents::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from parents order by NOM_DE_FAMILLE asc;");


model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_DE_FAMILLE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM_RES "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMAIL_RESP"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PASSWORD"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("PAYS"));
return model;

}
QSqlQueryModel * parents::recherche(QString var)
{
               QSqlQueryModel * model= new QSqlQueryModel();
               QSqlQuery *query=new QSqlQuery();

               QString str="select * from parents where CIN LIKE :CIN or NOM_DE_FAMILLE like :NOM_DE_FAMILLE or PRENOM_RES like :PRENOM_RES ";
               query->prepare(str);
               query->bindValue(":CIN","%"+var+"%");
               query->bindValue(":NOM_DE_FAMILLE","%"+var+"%");
               query->bindValue(":PRENOM_RES","%"+var+"%");
               qDebug()<<query->lastError();
               query->exec();
               model->setQuery(*query);

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_DE_FAMILLE"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM_RES "));
               model->setHeaderData(5, Qt::Horizontal, QObject::tr("CIN"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMAIL_RESP"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("PASSWORD"));
               model->setHeaderData(6, Qt::Horizontal, QObject::tr("PAYS"));
                return model;

}
QSqlQueryModel * parents::afficher_email()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select EMAIL_RESP from PARENTS   ");
    return model;
}
bool parents::login(QString user, QString pass){

    QSqlQuery query;

        QString select ="SELECT  CIN from parents where PRENOM_RES=? and PASSWORD=?";

        query.prepare(select);
        query.addBindValue(user);
         query.addBindValue(pass);
           query.exec();

         if (query.next()){
             return  true;
         }
         return  false;

}


