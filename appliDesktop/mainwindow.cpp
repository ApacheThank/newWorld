#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QDebug>
#include <QSqlQuery>
#include <QInputDialog>
#include <QSqlDatabase>
#include <string>
#include <QString>
#include <QMessageBox>
#include "dialogconnect.h"
#include <QDate>
#include <QTableWidgetItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadControllers();
    loadProducers();
    loadRayons();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::loadControllers()
{
    qDebug()<<"MainWindow::loadControllers()";
    QSqlQuery maRequete("select idPersonnel,nom,prenom,adresse,codePostal,ville,email,tel,dateEmbauche from personnel where typePersonnel='control';");
    //nb de colonne
    int noLigne=0;
    QSqlRecord fields = maRequete.record();
    // création des lignes et colonnes
    ui->tableWidgetListControllers->setColumnCount(fields.count());
    ui->tableWidgetListControllers->setRowCount(maRequete.size());
    //placement des headers
    for(int noField=0;noField<fields.count();noField++)
    {
        // on donne le nom de colonne
        ui->tableWidgetListControllers->setHorizontalHeaderItem(noField,new QTableWidgetItem(fields.fieldName(noField)));
    }
    while(maRequete.next())//pour chaque controleur
    {
        for(int noField=0;noField<fields.count();noField++)
        {
            QString valeur=maRequete.value(noField).toString();
            QTableWidgetItem * cellule = new QTableWidgetItem(valeur);
            ui->tableWidgetListControllers->setItem(noLigne,noField,cellule);
        }
        // on enregistre l'id
        QString id = maRequete.value("idPersonnel").toString();
        ui->tableWidgetListControllers->item(noLigne,0)->setData(32,id);
        //on passe à la ligne suivante
        noLigne++;
    }

}



void MainWindow::on_pushButtonAddController_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonAddController_clicked()";
    QString firstName = ui->lineEditFirstName->text();
    QString lastName = ui->lineEditLastName->text();
    QString street = ui->lineEditStreet->text();
    QString city = ui->lineEditCity->text();
    QString zipCode = ui->lineEditZipCode->text();
    QString phoneNumber = ui->lineEditPhoneNumber->text();
    QString email = ui->lineEditEmail->text();
    QString SSN = ui->lineEditSSN->text();
    // concatenation de nom et prenom
    QString login=firstName[0]+lastName;
    login = login.toLower();
    // mdp reçois le mot de passe genere par la fonction
    QString mdp = generatePassword();
    // recuperation du date actuel
    QDate date(QDate::currentDate());
    qDebug()<<date;
    // id reçois l'id max
    int id = getId();
    QString control="control";
    qDebug()<<mdp;
    QSqlQuery laRequete;
    QString texteRequete="insert into personnel(idPersonnel,nom,prenom,login,mdp,adresse,ville,codePostal,tel,email,typePersonnel,SSNumber) values(";
    texteRequete+=QString::number(id)+",'"+lastName+"','"+firstName+"','"+login+"',password('"+mdp+"'),'"+street+"','"+city+"','"+zipCode+"',"+phoneNumber+",'"+email+"','"+control+"','"+SSN+"');";
    qDebug()<<texteRequete;
    laRequete.exec(texteRequete);
    loadControllers();

}

void MainWindow::loadProducers()
{
    qDebug()<<"MainWindow::loadProducers()";
    QSqlQuery maRequete("select nom,prenom,adresse,codePostal,ville,email,tel,dateInscription,verifie from utilisateur where typeUtilisateur=2;");
    // récuperation des colonnes
    QSqlRecord fields = maRequete.record();
    // création des lignes et colonnes
    ui->tableWidgetListProducers->setColumnCount(fields.count());
    ui->tableWidgetListProducers->setRowCount(maRequete.size());
    int noLigne=0;
    //placement des headers
    for(int noField=0;noField<fields.count();noField++)
    {
        // on donne le nom de colonne
        ui->tableWidgetListProducers->setHorizontalHeaderItem(noField,new QTableWidgetItem(fields.fieldName(noField)));
    }
    while(maRequete.next())
    {
            for(int noField=0;noField<fields.count();noField++)
            {
                QString valeur=maRequete.value(noField).toString();
                QTableWidgetItem *cellule = new QTableWidgetItem(valeur);
                ui->tableWidgetListProducers->setItem(noLigne,noField,cellule);
            }
            //on passe à la ligne suivante
            noLigne++;
    }
}


int MainWindow::getId()
{
    QSqlQuery getLastId("select ifnull(max(idPersonnel),0)+1 from personnel;");
    getLastId.exec();
    getLastId.first();
    int id=getLastId.value(0).toInt();
    qDebug()<<id;
    return id;
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

QString MainWindow::generatePassword()
{
    qDebug()<<"MainWindow::generatePassword()";
    QString caracts = "aAbBcCdDeEfFgGhHjJiIkKlLmMnNoOpPqQrRsStTuUwWvVxXyYzZ0123456789";
    QString code;
    //a changer la condition
    for(int i=0; i < 6; i++)
    {
        int nb = rand()%(caracts.size());
        code.append(caracts[nb]);
    }
    return code;
}

void MainWindow::on_pushButtonEraseController_clicked()
{    qDebug()<<"MainWindow::on_pushButtonEraseController_clicked()";
     QSqlQuery reqSupprimer;
     qDebug()<<idController;
     QString texteSupprimer="delete from utilisateur where type_user='control' and id='"+idController+"';";
     qDebug()<<texteSupprimer;
     reqSupprimer.exec(texteSupprimer);
     ui->tableWidgetListControllers->removeRow(ui->tableWidgetListControllers->currentRow());
}

void MainWindow::on_tableWidgetListControllers_cellClicked(int row, int column)
{
    qDebug()<<"MainWindow::on_tableWidgetListControllers_cellClicked(int row, int column)";
    idController=ui->tableWidgetListControllers->item(row,0)->data(32).toString();
    // désactivation des boutons
    qDebug()<<idController;
    ui->pushButtonModifyController->setEnabled(true);
    ui->pushButtonEraseController->setEnabled(true);
}


void MainWindow::loadRayons()
{
    qDebug()<<"MainWindow::loadRayons()";
    QSqlQuery reqRayons("select libelle from rayon;");
    int noLigne=0;
    ui->tableWidgetRayonList->setColumnCount(1);
    ui->tableWidgetRayonList->setRowCount(reqRayons.size());
    while(reqRayons.next())
    {
        QString rayon=reqRayons.value(0).toString();
        qDebug()<<rayon;
        QTableWidgetItem *Rayon= new QTableWidgetItem(rayon);
        qDebug()<<Rayon;
        ui->tableWidgetRayonList->setItem(0,0,Rayon);
        noLigne++;
    }


}

void MainWindow::loadCategories()
{
    qDebug()<<"MainWindow::loadCategories()";
    QTableWidgetItem *unRayon= ui->tableWidgetRayonList->currentItem();
    // conversion la variable en string
    QString leRayon= unRayon->data(Qt::DisplayRole).toString();
    QSqlQuery query;
    QString queryLoadCat="select c.libelle from categorie c inner join rayon r on c.idRayon=r.idRayon where r.libelle='"+leRayon+"';";
    qDebug()<<queryLoadCat;
    query.exec(queryLoadCat);
    int noLigne=0;
    ui->tableWidgetCategoryList->setColumnCount(1);
    ui->tableWidgetCategoryList->setRowCount(query.size());
    while(query.next())
    {

        QString nameCategorie=query.value(0).toString();
        qDebug()<<nameCategorie;
        QTableWidgetItem *NameCategorie= new QTableWidgetItem(nameCategorie);
        qDebug()<<NameCategorie;
        ui->tableWidgetCategoryList->setItem(noLigne,0,NameCategorie);
        noLigne++;
    }

}

void MainWindow::loadProducts()
{
    qDebug()<<"MainWindow::loadProducts()";
    QTableWidgetItem *uneCategorie=ui->tableWidgetCategoryList->currentItem();
    QString laCategorie=uneCategorie->data(Qt::DisplayRole).toString();
    QSqlQuery query;
    QString queryLoadProd="select p.libelle,p.qte,p.pU from produit p inner join categorie c on p.idCategorie=c.idCategorie where c.libelle='"+laCategorie+"';";
    qDebug()<<queryLoadProd;
    query.exec(queryLoadProd);
    QSqlRecord fields = query.record();
    int noLigne=0;
    ui->tableWidgetProductList->setColumnCount(fields.count());
    ui->tableWidgetProductList->setRowCount(query.size());

    //placement des headers
    for(int noField=0;noField<fields.count();noField++)
    {
        // on donne le nom de colonne
        ui->tableWidgetProductList->setHorizontalHeaderItem(noField,new QTableWidgetItem(fields.fieldName(noField)));
    }
    while(query.next())
    {

        for(int noField=0;noField<fields.count();noField++)
        {
            QString cell=query.value(noField).toString();
            QTableWidgetItem * Cell = new QTableWidgetItem(cell);
            ui->tableWidgetProductList->setItem(noLigne,noField,Cell);
        }
        noLigne++;
    }
}

void MainWindow::on_tableWidgetRayonList_clicked(const QModelIndex &index)
{
    qDebug()<<"MainWindow::on_tableWidgetRayonList_clicked(const QModelIndex &index)";
    loadCategories();
}

void MainWindow::on_tableWidgetCategoryList_clicked(const QModelIndex &index)
{
    qDebug()<<"MainWindow::on_tableWidgetCategoryList_clicked(const QModelIndex &index)";
    loadProducts();
}
