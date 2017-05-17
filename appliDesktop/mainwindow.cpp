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
#include "dialogaddproduct.h"
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
    QSqlQuery maRequete("select nom,prenom,adresse,codePostal,ville,email,tel,dateEmbauche,idPersonnel from personnel where typePersonnel='control';");
    //nb de colonne
    int noLigne=0;
    QSqlRecord fields = maRequete.record();
    // création des lignes et colonnes
    ui->tableWidgetListControllers->setColumnCount(fields.count()-1);
    ui->tableWidgetListControllers->setRowCount(maRequete.size());
    //placement des headers
    for(int noField=0;noField<8;noField++)
    {
        // on donne le nom de colonne
        ui->tableWidgetListControllers->setHorizontalHeaderItem(noField,new QTableWidgetItem(fields.fieldName(noField)));
    }
    while(maRequete.next())//pour chaque controleur
    {
        for(int noField=0;noField<8;noField++)
        {
            QString valeur=maRequete.value(noField).toString();
            QTableWidgetItem * cellule = new QTableWidgetItem(valeur);
            ui->tableWidgetListControllers->setItem(noLigne,noField,cellule);
        }
        // on enregistre l'idPersonnel
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
    // id reçois l'id max
    int id = getId();
    QString control="control";
    qDebug()<<mdp;
    QSqlQuery laRequete;
    QString texteRequete="insert into personnel(idPersonnel,nom,prenom,login,mdp,adresse,ville,codePostal,tel,email,typePersonnel,SSNumber,dateEmbauche) values(";
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
     QString texteSupprimer="delete from personnel where and id='"+idController+"';";
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
    QSqlQuery reqRayons("select libelle,idRayon from rayon;");
    int noLigne=0;
    ui->tableWidgetRayonList->setColumnCount(1);
    ui->tableWidgetRayonList->setRowCount(reqRayons.size());
    while(reqRayons.next())
    {
        QString rayon=reqRayons.value(0).toString();
        qDebug()<<rayon;
        QTableWidgetItem *Rayon= new QTableWidgetItem(rayon);
        qDebug()<<Rayon;
        ui->tableWidgetRayonList->setItem(noLigne,0,Rayon);
        // on enregistre l'idRayon
        QString idRayon = reqRayons.value("idRayon").toString();
        ui->tableWidgetRayonList->item(noLigne,0)->setData(32,idRayon);
        noLigne++;
    }


}

void MainWindow::loadCategories()
{
    qDebug()<<"MainWindow::loadCategories()";
    QSqlQuery query;
    QString queryLoadCat="select libelle,idCategorie from categorie where idRayon="+idRayon+";";
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
        // on enregistre l'idCategorie
        QString idCategorie = query.value("idCategorie").toString();
        ui->tableWidgetCategoryList->item(noLigne,0)->setData(32,idCategorie);
        noLigne++;
    }

}

void MainWindow::loadProducts()
{
    qDebug()<<"MainWindow::loadProducts()";
    QSqlQuery query;
    QString queryLoadProd="select libelle,qte,pU from produit where idCategorie="+idCategorie+";";
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


void MainWindow::on_tableWidgetListControllers_cellEntered(int row, int column)
{

}

void MainWindow::on_tableWidgetRayonList_cellClicked(int row, int column)
{
    qDebug()<<"MainWindow::on_tableWidgetRayonList_cellClicked(int row, int column)";
    idRayon = ui->tableWidgetRayonList->item(row,0)->data(32).toString();
    loadCategories();
}

void MainWindow::on_tableWidgetCategoryList_cellClicked(int row, int column)
{
    qDebug()<<"MainWindow::on_tableWidgetCategoryList_cellClicked(int row, int column)";
    idCategorie = ui->tableWidgetCategoryList->item(row,0)->data(32).toString();
    loadProducts();

}

void MainWindow::on_pushButtonCreateRayon_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonCreateRayon_clicked()";
    QString newShelf=ui->lineEditCreateShelf->text();
    if(newShelf.isEmpty())
    { ui->labelErrorMessage->setText("The name of shelf is empty"); }
    else {
        // on fait la recherche dans notre base pour voir s'il existe le rayon saisi
        QSqlQuery reqExistingShelf("select * from rayon where libelle='"+newShelf+"';");
        reqExistingShelf.exec();
        int resultat=reqExistingShelf.size();
        // s'il n'existe pas dans notre base on l'ajoute
            if(resultat==0)
            {
                QSqlQuery reqId("select ifnull(max(idRayon),0)+1 from rayon;");
                reqId.exec();
                reqId.first();
                int idShelf = reqId.value(0).toInt();
                qDebug()<<idShelf;
                QSqlQuery insertShelf;
                QString textRequest = "insert into rayon values(";
                textRequest+=QString::number(idShelf)+",'"+newShelf+"');";
                qDebug()<<textRequest;
                insertShelf.exec(textRequest);
                loadRayons();
            } else {  ui->labelErrorMessage->setText("The entered shelf is already exists"); }
        }
}

void MainWindow::on_pushButtonAddCategory_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonAddCategory_clicked()";
    // si un des rayons n'était pas saisi
    if(idRayon!=0)
    {
        QString newCategory=ui->lineEditAddCategory->text();
        if(!(newCategory.isEmpty()))
        {
            QSqlQuery reqExistingCategory("select * from categorie where libelle='"+newCategory+"';");
            reqExistingCategory.exec();
            int resultat = reqExistingCategory.size();
            if(resultat==0)
            {
                QSqlQuery reqId("select ifnull(max(idCategorie),0)+1 from categorie;");
                reqId.exec();
                reqId.first();
                int newIdCategory=reqId.value(0).toInt();
                qDebug()<<newIdCategory;
                QSqlQuery insertCategory;
                QString textQuery = "insert into categorie values(";
                textQuery+=QString::number(newIdCategory)+",'"+newCategory+"',"+idRayon+");";
                qDebug()<<textQuery;
                insertCategory.exec(textQuery);
                loadCategories();
            } else { ui->labelErrorMessage->setText("The entered category is already exists"); }

        } else { ui->labelErrorMessage->setText("The name of category is empty"); }

    } else { ui->labelErrorMessage->setText("Firstly, it necessary to select the shelf"); }
}

void MainWindow::on_pushButtonAddProduct_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonAddProduct_clicked()";
    // il est nécessaire d'abord selectionner la categorie sur laquelle on veut ajoute le produit
    // si la catégorie a été selectionnée
    if(idCategorie!=0)
    {
        QString newProduct=ui->lineEditAddProduct->text();
        // s'il n'est pas vide on l'ajoute si non on affiche un message d'erreur
        if(!(newProduct.isEmpty()))
        {
            // on regarde est-ce que le produit déjà existe dans notre base
            QSqlQuery reqExistingProduct("select * from produit where libelle='"+newProduct+"' and idCategorie='"+idCategorie+"';");
            reqExistingProduct.exec();
            int resultat = reqExistingProduct.size();
            // s'il n'existe pas on l'ajoute
            if(resultat == 0)
            {
                QSqlQuery reqId("select ifnull(max(idProduit),0)+1 from produit;");
                reqId.exec();
                reqId.first();
                int newIdProduct = reqId.value(0).toInt();
                DialogAddProduct dialogProduct;
                qDebug()<<newIdProduct;
                dialogProduct.setSelectedProduct(newProduct);
                while(dialogProduct.exec()==QDialog::Accepted)
                {


                    QString unitPrice=dialogProduct.getUnitPrice();
                    QString qty = dialogProduct.getQty();
                    qDebug()<<unitPrice;
                    if(unitPrice.isEmpty() || qty.isEmpty())
                    {
                        dialogProduct.setMessage();
                    }
                    else
                    {
                        QSqlQuery insertProduct;
                        QString reqText="insert into produit values (";
                        reqText+=QString::number(newIdProduct)+",'"+newProduct+"',"+unitPrice+","+qty+","+idCategorie+");";
                        insertProduct.exec(reqText);
                        loadProducts();
                        qDebug()<<reqText;           
                        dialogProduct.closeDialog();
                    }
                }
            } else { ui->labelErrorMessage->setText("The entered product is already exists"); }

        } else { ui->labelErrorMessage->setText("The name of product is empty"); }

    } else { ui->labelErrorMessage->setText("Please select the category"); }
}
