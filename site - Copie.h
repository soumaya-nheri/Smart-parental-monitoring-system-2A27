#ifndef SITE_H
#define SITE_H
#include <QString>
#include <QSqlQueryModel>
class Site
{
public:
    Site();
    Site(int,QString,QString,QString);
    int getid();
    QString gettype();
    QString getnom();
    QString getadresse();
    void setid(int);
    void settype(QString);
    void setnom(QString);
    void setadresse(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    void telecharger();



private:
  int id;
  QString type,nom,adresse;


};

#endif // SITE_H
