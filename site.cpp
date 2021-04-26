#include "site.h"
#include <QSqlQuery>
#include <QtDebug>
Site::Site()
{
id=0; type="";nom="";adresse="";

}
Site::Site(int id ,QString type,QString nom ,QString adresse)
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
    QString id_strings=QString::number(id);
    query.prepare("INSERT INTO site (id, type, nom,adresse) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(0, id_strings);
    query.bindValue(1, type);
    query.bindValue(2, nom);
    query.bindValue(3, adresse);
    return query.exec();


}
QSqlQueryModel* Site::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
             model->setQuery("SELECT* FROM site");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr( "identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));



    return model;
}
bool Site::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from site id=:id");
    query.bindValue(0, id);

    return query.exec();

}
