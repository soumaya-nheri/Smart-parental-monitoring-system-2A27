#include<enfants.h>
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
#include<QSqlQuery>


enfants::enfants()
{
ID=0;
NOM_ENF="";
PRENOM_ENF="";
}

enfants::enfants(int ID ,QString NOM_ENF,QString PRENOM_ENF)
{

  this->ID=ID;
  this->NOM_ENF=NOM_ENF;
  this->PRENOM_ENF=PRENOM_ENF ;
}
int enfants::get_ID(){return  ID;}
QString enfants::get_NOM_ENF(){return NOM_ENF;}
QString enfants::get_PRENOM_ENF(){return PRENOM_ENF;}

bool enfants::ajouter()
{
QSqlQuery query;
QString res =QString::number(ID);

query.prepare("INSERT INTO enfants (ID, NOM_ENF,PRENOM_ENF)"
                    "VALUES (:ID,:NOM_ENF,:PRENOM_ENF)");
query.bindValue(":ID", res);
query.bindValue(":NOM_ENF", NOM_ENF);
query.bindValue(":PRENOM_ENF", PRENOM_ENF);

return    query.exec();
}
bool enfants::modifier(int ID ,QString NOM_ENF,QString PRENOM_ENF)
{
    QSqlQuery query;
    query.prepare("UPDATE enfants set  NOM_ENF = :NOM_ENF, PRENOM_ENF = :PRENOM_ENF WHere ID = :ID");

    query.bindValue(":NOM_ENF", NOM_ENF);
    query.bindValue(":PRENOM_ENF", PRENOM_ENF);
    query.bindValue(":ID",ID);
    return    query.exec();
}
bool enfants::supprimer(int ID )
{
    QSqlQuery query;
    query.prepare("delete from enfants where ID=:ID");

    query.bindValue(":ID", ID);

    return    query.exec();
}
QSqlQueryModel * enfants::afficher()
{ QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from enfants");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_ENF "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_ENF"));

return model;
}
QSqlQueryModel * enfants::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from enfants order by ID asc;");



model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_ENF "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_ENF"));
return model;

}
QSqlQueryModel * enfants::recherche(QString var)
{
               QSqlQueryModel * model= new QSqlQueryModel();
               QSqlQuery *query=new QSqlQuery();

               QString str="select * from enfants where ID LIKE :ID ";
               query->prepare(str);
               query->bindValue(":ID","%"+var+"%");
               qDebug()<<query->lastError();
               query->exec();
               model->setQuery(*query);

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_ENF "));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_ENF"));
                return model;

}






