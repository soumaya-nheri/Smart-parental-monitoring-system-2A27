#ifndef ECRAN_H
#define ECRAN_H
#include <QString>
#include <QSqlQueryModel>

class ecran
{
public:
    ecran();
    ecran(int,QString,QString);
    int getid();
    QString gettype();
    QString getetat();
    void setid(int);
    void settype(QString);
    void setetat(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
     bool modifier();
    void verifier();

private:
  int id;
  QString type,etat;


};

#endif // ECRAN_H
