#ifndef ENFANTS_H
#define ENFANTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class enfants
{
public:
   enfants();
   enfants(int,QString,QString);
   int get_ID();
   QString get_NOM_ENF();
   QString get_PRENOM_ENF();
   bool ajouter();
   bool modifier(int,QString,QString);
    QSqlQueryModel * afficher();
    bool supprimer(int);

    QSqlQueryModel * trier();
    QSqlQueryModel * recherche(QString var);






private:
   int ID;
   QString NOM_ENF,PRENOM_ENF;
};

#endif // ENFANTS_H

