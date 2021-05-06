#ifndef NUTRITION_H
#define NUTRITION_H
#include <QString>
#include<iostream>
#include<QSqlQueryModel>
class nutrition
{
public:
    nutrition();
    nutrition(QString,QString,QString,int,QString,QString);
    QString getpttdej();
    QString getdej();
       QString getdiner();
       int getcalories();
       QString getdater();
       QString getemp();
      void setpttdej(QString);
      void setdej(QString);
      void setdiner(QString);
      void setcalories(int);
      void setdater(QString);
      void setemp(QString);
      bool ajouter();
      QSqlQueryModel* afficher();
      bool modifier();
      bool supprimer(QString);
    private:
   QString pttdej,dej,diner,dater,emp;
   int calories;
};
#endif // NUTRITION_H
