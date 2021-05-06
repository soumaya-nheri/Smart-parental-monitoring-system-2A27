#ifndef TEMPS_H
#define TEMPS_H
#include <QString>
#include<iostream>
#include<QSqlQueryModel>
class Temps
{
public:
    Temps();
    Temps(QString,QString,QString);
    QString getemploi();
    QString getdateh();
       QString getrendez_vous();
      void setemploi(QString);
      void setdateh(QString);
      void setrendez_vous(QString);
      bool ajouter();
      QSqlQueryModel* afficher();
       QSqlQueryModel* affichertd();
       QSqlQueryModel* affichertr();
       QSqlQueryModel* afficherte();
      bool modifier();
      bool supprimer(QString);
    private:
   QString emploi,dateh,rendez_vous;
};
#endif // TEMPS_H
