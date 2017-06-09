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
MainWindow2::MainWindow2(QString idConnect,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    idConnected = idConnect;
    ui->setupUi(this);
    loadProducers("All");
    ui->labelIfVisitToken->hide();

}

MainWindow2::~MainWindow2()
{

    delete ui;
}

// charger les producteurs selon le paramètre reçu
void MainWindow2::loadProducers(QString trier)
{
    qDebug()<<"MainWindow2::loadProducers()";
    QSqlQuery maRequete;
    // on charge que les producteurs qui ont activé leur compte
    QString texte= "select nom,prenom,adresse,codePostal,ville,email,tel,dateInscription,verifie,idUtilisateur from utilisateur where typeUtilisateur=2 and active=1 ";
            if(trier==(tr("Accepted"))){
                texte+="and verifie=1;";
            } else { if(trier==(tr("Waiting"))) {
                    texte+="and verifie=0";
                    }
                    texte+";";
                }
    maRequete.exec(texte);

    int noLigne=0;
    QSqlRecord fields = maRequete.record();
    // -1 pour idUtilisateur
    ui->tableWidgetListProducers->setColumnCount(fields.count()-1);
    ui->tableWidgetListProducers->setRowCount(maRequete.size());
    for(int noField=0;noField<fields.count()-1;noField++)
    {
        // on donne le nom de colonne
        ui->tableWidgetListProducers->setHorizontalHeaderItem(noField,new QTableWidgetItem(fields.fieldName(noField)));
    }

    while(maRequete.next())
    {
        for(int noField=0;noField<fields.count()-1;noField++)
        {
            // on donne le nom de colonne
            QString producteur=maRequete.value(noField).toString();
            qDebug()<<producteur;
            QTableWidgetItem *Producteur = new QTableWidgetItem(producteur);
            ui->tableWidgetListProducers->setItem(noLigne,noField,Producteur);
        }
            // enregistrement de l'idUtilisateur dans data
            QString id=maRequete.value("idUtilisateur").toString();
            ui->tableWidgetListProducers->item(noLigne,0)->setData(32,id);
            // on passe à la ligne suivante
            noLigne++;
   }
}

// quitter le programme
void MainWindow2::on_pushButtonExit_clicked()
{
    close();
}

// trier les producteurs selon le paramètre reçu
void MainWindow2::on_comboBoxSort_activated(const QString &arg1)
{
    qDebug()<<"MainWindow2::on_comboBoxSort_activated(const QString &arg1)";
    QString sortList = ui->comboBoxSort->currentText();
    loadProducers(sortList);
}

// lors d'un click sur la liste des producteurs
void MainWindow2::on_tableWidgetListProducers_cellClicked(int row, int column)
{
     ui->labelActionMessage->clear();
    qDebug()<<"MainWindow2::on_tableWidgetListProducers_cellClicked(int row, int column)";
    idProducteur=ui->tableWidgetListProducers->item(row,0)->data(32).toString();
    qDebug()<<idProducteur;
    QSqlQuery verif;
    QString texte="select * from utilisateur where verifie=1 and idUtilisateur="+idProducteur+";";
    verif.exec(texte);
    if(verif.size()==0){
        ui->pushButtonValidProducer->setEnabled(true);
        ui->pushButtonRefuseProducer->setEnabled(true);
    } else { ui->labelActionMessage->setText(tr("The producer is already validated"));
        ui->pushButtonValidProducer->setEnabled(false);
        ui->pushButtonRefuseProducer->setEnabled(false);
    }
    loadProducers("All");

    loadVisitInformation();
}


void MainWindow2::loadVisitInformation(){
    qDebug()<<"MainWindow2::loadVisitInformation()";
    QSqlQuery query;
    QString texte ="select v.idVisite, concat(p.nom,' ',p.prenom) as controleur,v.libelle,v.dateVisite from personnel p ";
            texte+="inner join visite v on p.idPersonnel=v.idRole ";
            texte+="inner join ControleProducteur cp on v.idVisite=cp.idVisite ";
            texte+="where idUtilisateur="+idProducteur+";";
    qDebug()<<texte;
    query.exec(texte);
    if(query.size()!=0){
        while(query.next()) {
        ui->labelIfVisitToken->show();
        ui->labelVisitLabel->show();
        ui->labelControllerLabel->show();
        ui->labelVisitLabel->setEnabled(true);
        ui->labelControllerLabel->setEnabled(true);
        ui->labelVisitNumber->setText(query.value(0).toString());
        ui->labelVisitController->setText(query.value(1).toString());
        ui->labelVisitDescription->setText(query.value(2).toString());
        ui->dateEditVisit2->setDate(query.value(3).toDate());
        }
    } else {
        clearVisitInformation();
        ui->labelVisitLabel->hide();
        ui->labelControllerLabel->hide();
        ui->labelIfVisitToken->hide();
    }

}

void MainWindow2::clearVisitInformation(){
    qDebug()<<"MainWindow2::clearVisitInformation()";
    // on vide les informations saisies precedemment
    ui->labelVisitLabel->hide();
    ui->labelControllerLabel->hide();
    ui->labelVisitNumber->clear();
    ui->labelVisitController->clear();
    ui->labelVisitDescription->clear();

}

// le bouton pour la validation de producteur
void MainWindow2::on_pushButtonValidProducer_clicked()
{
    qDebug()<<"MainWindow2::on_pushButtonValidProducer_clicked()";
    QSqlQuery query;
    QString texte="update utilisateur set verifie=1 where idUtilisateur="+idProducteur+";";
    query.exec(texte);
}

// le bouton pour refuser le producteur
void MainWindow2::on_pushButtonRefuseProducer_clicked()
{
    qDebug()<<"MainWindow2::on_pushButtonRefuseProducer_clicked()";
}


void MainWindow2::on_pushButtonAcceptVisit2_clicked()
{
    qDebug()<<"MainWindow2::on_pushButtonAcceptVisit2_clicked()";
    QSqlQuery query;

    QSqlQuery reqId("select ifnull(max(idVisite),0)+1 from visite;");
    reqId.first();
    QString idVisite=reqId.value(0).toString();
    QString dateVisit = ui->dateEditVisit2->text();
    //QString visitDescription = ui->lineEditDesciption->text();
    //QString texte="update visite set ";

}
