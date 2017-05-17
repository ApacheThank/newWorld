#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QDebug>
#include <QSqlQuery>
#include <QInputDialog>
#include <QSqlDatabase>
#include <string>
#include <QString>
#include <QMessageBox>
#include <QDate>
#include "dialogconnect.h"
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    loadProducers();
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::loadProducers()
{
    qDebug()<<"MainWindow2::loadProducers()";
    QSqlQuery maRequete("select nom,prenom,adresse,codePostal,ville,email,tel,dateInscription from utilisateur where typeUtilisateur=2;");
    int nbLigne=0;
    int producteurAController= maRequete.value("valid").toInt();
    QSqlRecord fields = maRequete.record();
    QString producteurAValider=maRequete.value("der_vis").toString();
    while(maRequete.next())
    {

        for(int noField=0;noField<fields.count();noField++)
        {
                ui->tableWidgetListProducers->setColumnCount(fields.count());
                // on donne le nom de colonne
                ui->tableWidgetListProducers->setHorizontalHeaderItem(noField,new QTableWidgetItem(fields.fieldName(noField)));
                QString lesTables=maRequete.value(noField).toString();
                qDebug()<<lesTables;
                QTableWidgetItem *mesTables = new QTableWidgetItem(lesTables);
                ui->tableWidgetListProducers->setRowCount(nbLigne+1);
                ui->tableWidgetListProducers->setItem(nbLigne,noField,mesTables);
                qDebug()<<producteurAController;

        }
                //on passe à la ligne suivante
                nbLigne++;
   }
}

void MainWindow2::on_pushButtonExit_clicked()
{
    close();
}
