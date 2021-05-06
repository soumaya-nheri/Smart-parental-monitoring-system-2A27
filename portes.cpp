#include "portes.h"
#include "ui_portes.h"
#include "porte_impl.h"
#include "notifications.h"
#include <QMessageBox>
portes::portes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::portes)
{
    ui->setupUi(this);

}

portes::~portes()
{
    delete ui;
}



void portes::on_pushButton_Ajouter_clicked()
{
//controle de decésie

      int num = ui->spinBox_NUMPORT->text().toInt()   ;
      int code = ui->spinBox_CODEPORT->text().toInt()   ;
      int temp_ouvert = ui->spinBox_TEMPOUVERT->text().toInt()   ;
      int temp_ferme = ui->spinBox_TEMPFERME->text().toInt()   ;

      if (num < 1)
      {
          QMessageBox::information(nullptr, QObject::tr("Problem num"),
                      QObject::tr("Problem num."), QMessageBox::Cancel);
      }
      else if  (code <1)
      {
          QMessageBox::information(nullptr, QObject::tr("Problem code"),
                      QObject::tr("Problem code."), QMessageBox::Cancel);
      }
      else if (temp_ouvert <1)
      {
          QMessageBox::information(nullptr, QObject::tr("Problem temp_ouvert"),
                      QObject::tr("Problem temp_ouvert."), QMessageBox::Cancel);
      }
      else if  (temp_ferme < 1)
      {
          QMessageBox::information(nullptr, QObject::tr("Problem temp_ferme"),
                      QObject::tr("Problem temp_ferme."), QMessageBox::Cancel);
      }
      else
      {

          Notifications N;
          N.notifications_ajouterPortes();
          porte_impl p (num,code,temp_ouvert,temp_ferme);
          p.ajouter();
                      ui->tableView_port->setModel(p.afficher());
      }



}

void portes::on_pushButton_Afficher_clicked()
{
    QSqlTableModel *mmodel = new QSqlTableModel();
    mmodel->setTable("PORTE");
    mmodel->select();
    mmodel->setHeaderData(0, Qt::Horizontal,"num_porte");
    mmodel->setHeaderData(1, Qt::Horizontal,"code_porte");
    QSortFilterProxyModel *port = new QSortFilterProxyModel (this) ;
    port->setSourceModel(mmodel) ;
    port->setFilterCaseSensitivity(Qt::CaseInsensitive) ;
    port->setFilterKeyColumn(-1) ;
    porte_impl p;
  ui->tableView_port->setModel(port);
  ui->tableView_port->setSelectionBehavior(QAbstractItemView::SelectRows) ;
  ui->tableView_port->setSortingEnabled(true);

  ui->comboBox->setCurrentIndex(3);

  completerporte = new QCompleter(port,this) ;
  completerporte->setCaseSensitivity(Qt::CaseInsensitive) ;
  completerporte->setCompletionColumn(1);
  ui->txt_search->setCompleter(completerporte);
}

void portes::on_pushButton_supprimer_clicked()
{
    porte_impl r;
          r.supprimer()->removeRow(ui->tableView_port->currentIndex().row());

            ui->tableView_port->setModel(r.afficher());
}

void portes::on_pushButton_TRI_clicked()
{

    porte_impl r;
    ui->tableView_port->setModel(r.tri(ui->tableView_port->currentIndex().column()));
}

void portes::on_txt_search_textChanged(const QString &arg1)
{
    porte_impl c ;

    completerporte->setCompletionColumn(ui->comboBox->currentIndex()) ;

    c.cleartable(ui->tableView_port);
    int numero =ui->txt_search->text().toInt();
    c.rechercher(ui->tableView_port,numero);

    if(ui->txt_search->text().isEmpty())
    {
        ui->tableView_port->setModel(c.afficher());
    }

}
