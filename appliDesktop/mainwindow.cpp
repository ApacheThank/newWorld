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
    loadProductionBatches();
    loadAllProducts();
    loadNewProducts();
    ui->widgetProductInformation->hide();
    ui->widgetBatchInformation->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 *
 * Onglet controlleurs
 *
 */
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

// ajout un controleur
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

// on genere le mot de passe pour envoyer au controleur
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

// pour la suppression du controleur
void MainWindow::on_pushButtonEraseController_clicked()
{    qDebug()<<"MainWindow::on_pushButtonEraseController_clicked()";
     QSqlQuery reqSupprimer;
     qDebug()<<idController;
     QString texteSupprimer="delete from personnel where and id='"+idController+"';";
     qDebug()<<texteSupprimer;
     reqSupprimer.exec(texteSupprimer);
     ui->tableWidgetListControllers->removeRow(ui->tableWidgetListControllers->currentRow());
}

//  lors d'un click sur la liste des controleurs
void MainWindow::on_tableWidgetListControllers_cellClicked(int row, int column)
{
    qDebug()<<"MainWindow::on_tableWidgetListControllers_cellClicked(int row, int column)";
    idController=ui->tableWidgetListControllers->item(row,0)->data(32).toString();
    // désactivation des boutons
    qDebug()<<idController;
    ui->pushButtonModifyController->setEnabled(true);
    ui->pushButtonEraseController->setEnabled(true);
}

// recuperer l'id max du personnel
int MainWindow::getId()
{
    QSqlQuery getLastId("select ifnull(max(idPersonnel),0)+1 from personnel;");
    getLastId.exec();
    getLastId.first();
    int id=getLastId.value(0).toInt();
    qDebug()<<id;
    return id;
}

// lors d'un changement de la liste des controleurs
void MainWindow::on_tableWidgetListControllers_itemChanged(QTableWidgetItem *item)
{
    qDebug()<<"MainWindow::on_tableWidgetListControllers_itemChanged(QTableWidgetItem *item)";
    QString modif = item->data(Qt::DisplayRole).toString();
    int Label = ui->tableWidgetListControllers->currentColumn();
    QTableWidgetItem * nomColonne=ui->tableWidgetListControllers->horizontalHeaderItem(Label);
    //QString NomColonne = nomColonne->data(Qt::DisplayRolee).toString();
    qDebug()<<nomColonne;
    qDebug()<<Label;
    qDebug()<<modif;
}


///////////////////// fin d'onglet controlleurs //////////////////

/**
 *
 * ongler producteurs
 *
 */
// charger des producteurs
void MainWindow::loadProducers()
{
    qDebug()<<"MainWindow::loadProducers()";
    // le champ active est pour reinitialisation de mot de passe, si le compte était activé il renvoie 1
    QSqlQuery maRequete("select nom,prenom,adresse,codePostal,ville,email,tel,dateInscription,active,idUtilisateur from utilisateur where typeUtilisateur=2;");
    // récuperation des colonnes
    QSqlRecord fields = maRequete.record();
    // création des lignes et colonnes
    ui->tableWidgetListProducers->setColumnCount(fields.count()-1);
    ui->tableWidgetListProducers->setRowCount(maRequete.size());
    int noLigne=0;
    //placement des headers
    for(int noField=0;noField<fields.count()-1;noField++)
    {
        // on donne le nom de colonne
        ui->tableWidgetListProducers->setHorizontalHeaderItem(noField,new QTableWidgetItem(fields.fieldName(noField)));
    }
    while(maRequete.next())
    {
            for(int noField=0;noField<fields.count()-1;noField++)
            {
                QString valeur=maRequete.value(noField).toString();
                QTableWidgetItem *cellule = new QTableWidgetItem(valeur);
                ui->tableWidgetListProducers->setItem(noLigne,noField,cellule);
            }
            QString idProducteur=maRequete.value("idUtilisateur").toString();
            ui->tableWidgetListProducers->item(noLigne,0)->setData(32,idProducteur);
            //on passe à la ligne suivante
            noLigne++;
    }
}

// charger les controleurs et mettre les dans combobox
void MainWindow::loadControllersComboBox(){
    qDebug()<<"MainWindow::loadControllersComboBox()";
    QSqlQuery query("select concat(nom,' ',prenom) as producteur,idPersonnel from personnel where typePersonnel='control';");
    while(query.next()){
        QString producteur = query.value("producteur").toString();
        QString id = query.value(1).toString();
        ui->comboBoxListControllers->addItem(producteur,id);
        //qDebug()<<query.value(1).toString();
    }
}

// lors d'un click sur la liste des producteurs
void MainWindow::on_tableWidgetListProducers_cellClicked(int row, int column)
{
    qDebug()<<"MainWindow::on_tableWidgetListProducers_cellClicked(int row, int column)";
    idProducteur=ui->tableWidgetListProducers->item(row,0)->data(32).toString();
    ui->pushButtonAcceptVisit->setEnabled(true);
    loadControllersComboBox();
}

// pour accepter la visite pour le producteur
void MainWindow::on_pushButtonAcceptVisit_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonAcceptVisit_clicked()";
    QString visitDescription = ui->lineEditVisitDescription->text();
    int index = ui->comboBoxListControllers->currentIndex();
    QString idControl= ui->comboBoxListControllers->itemData(index).toString();
    //QString id = ui->comboBoxListControllers->itemData();
    QString dateVisit = ui->dateEditVisit->text();
    qDebug()<<visitDescription;
    qDebug()<<idControl;
    if(!(visitDescription.isEmpty())){
        QSqlQuery reqId("select ifnull(max(idVisite),0)+1 from visite;");
        //reqId.exec();
        reqId.first();
        QString idVisite=reqId.value(0).toString();
        QSqlQuery query;
        qDebug()<<idProducteur;

        QString texte = "insert into visite values ("+idVisite+","+visitDescription+","+dateVisit+","+idControl+","+idProducteur+");";
        //query.exec(texte);
        qDebug()<<texte;

    }
}



/////////////////// fin d'onglet producteur ///////////////////

// quitter le programme
void MainWindow::on_pushButton_clicked()
{
    close();
}

/**
 *
 * Onglet catalogue
 *
 *
 */

// charger les rayons
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

// charger les catégories pour le rayon
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

// charger les produits pour la catégorie
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

// lors d'un click sur la liste des rayons, charger les catégories
void MainWindow::on_tableWidgetRayonList_cellClicked(int row, int column)
{
    qDebug()<<"MainWindow::on_tableWidgetRayonList_cellClicked(int row, int column)";
    idRayon = ui->tableWidgetRayonList->item(row,0)->data(32).toString();
    loadCategories();
}

// lors d'un click sur la liste des catégories, charger les produits
void MainWindow::on_tableWidgetCategoryList_cellClicked(int row, int column)
{
    qDebug()<<"MainWindow::on_tableWidgetCategoryList_cellClicked(int row, int column)";
    idCategorie = ui->tableWidgetCategoryList->item(row,0)->data(32).toString();
    loadProducts();

}

// créer un nouveau rayon et l'ajouter dans la liste
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

// créer une catégorie et l'ajouter dans liste
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

// ajouter un nouveau produit dans le catalogue
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
                        dialogProduct.close();
                        qDebug()<<reqText;
                    }
                }
            } else { ui->labelErrorMessage->setText("The entered product is already exists"); }

        } else { ui->labelErrorMessage->setText("The name of product is empty"); }

    } else { ui->labelErrorMessage->setText("Please select the category"); }
}

////////////////// fin d'onglet catalogue  /////////////////////////


/**
 *
 * onglet lot
 *
 */

// charger les lots
void MainWindow::loadProductionBatches(){
    qDebug()<<"MainWindow::loadProductionBatches()";
    QSqlQuery query;
    QString texte="select p.libelle,l.quantite,l.prixUnitaire,l.dateRecolte,CONCAT(u.nom,u.prenom) as producteur,l.idLot ";
            texte+=" from utilisateur u ";
            texte+="inner join lot l on u.idUtilisateur=l.idUtilisateur ";
            texte+="inner join produit p on l.idProduit=p.idProduit ;";
    qDebug()<<texte;
    query.exec(texte);
    int noLigne=0;
    QSqlRecord fields = query.record();
    qDebug()<<fields;
    ui->tableWidgetListOfBatchPropositions->setColumnCount(5);
    ui->tableWidgetListOfBatchPropositions->setRowCount(query.size());
    for(int noField=0;noField<5;noField++)
    {
        // on donne le nom de colonne
        ui->tableWidgetListOfBatchPropositions->setHorizontalHeaderItem(noField,new QTableWidgetItem(fields.fieldName(noField)));
        qDebug()<<fields.fieldName(noField);
    }

    while(query.next())
    {
        for(int noField=0;noField<5;noField++)
        {
            QString cell=query.value(noField).toString();
            QTableWidgetItem * Cell = new QTableWidgetItem(cell);
            ui->tableWidgetListOfBatchPropositions->setItem(noLigne,noField,Cell);
        }
        QString lot= query.value(5).toString();
        qDebug()<<lot;
        ui->tableWidgetListOfBatchPropositions->item(noLigne,0)->setData(32,lot);
        noLigne++;
    }
}

// charger les information pour le lot choisi
void MainWindow::loadBatchInformation(){
    qDebug()<<"MainWindow::loadBatchInformation()";
    QSqlQuery query;
    QString texte="select r.libelle,c.libelle,p.libelle,l.quantite,l.prixUnitaire,l.uniteDeVente,l.dateRecolte,CONCAT(u.nom,' ',u.prenom) as producteur, l.nbJourConservation,";
            texte+="l.nbJourConservation,l.uniteDeVente,l.modeProduction,l.ramassageManuel from utilisateur u ";
            texte+="inner join lot l on u.idUtilisateur=l.idUtilisateur ";
            texte+="inner join produit p on l.idProduit=p.idProduit ";
            texte+="inner join categorie c on p.idCategorie=c.idCategorie ";
            texte+="inner join rayon r on c.idRayon=r.idRayon where idLot="+idLot+";";
    query.exec(texte);
    qDebug()<<texte;
    while(query.next()){
        ui->labelShelf->setText(query.value(0).toString());
        ui->labelCategory->setText(query.value(1).toString());
        ui->labelProduct->setText(query.value(2).toString());
        ui->labelQuantity->setText(query.value(3).toString());
        ui->labelPrice->setText(query.value(4).toString());
        ui->labelSalesUnit->setText(query.value(5).toString());
        ui->labelHarvestDate->setText(query.value(6).toString());
        ui->labelProducer->setText(query.value(7).toString());
        ui->labelPreservation->setText(query.value(8).toString());
    }
}

// lors d'un click sur la liste des lots, afficher les informations
void MainWindow::on_tableWidgetListOfBatchPropositions_cellClicked(int row, int column)
{
    qDebug()<<"MainWindow::on_tableWidgetListOfBatchPropositions_cellClicked(int row, int column)";
    idLot = ui->tableWidgetListOfBatchPropositions->item(row,0)->data(32).toString();
    ui->widgetBatchInformation->show();
    loadBatchInformation();
}



//////////////// fin d'onglet lot ////////////////////

/**
 *
 * onglet produits
 *
 */


// charger les propositions des nouveaux produits
void MainWindow::loadNewProducts() {
    qDebug()<<"MainWindow::loadNewProducts()";
    QSqlQuery query("select libelle,idProduit from produit where accepte = 0;");
    query.exec();
    int noLigne=0;
    QSqlRecord fields= query.record();
    ui->tableWidgetProductPropositions->setColumnCount(1);
    ui->tableWidgetProductPropositions->setRowCount(query.size());
    ui->tableWidgetProductPropositions->setHorizontalHeaderItem(0,new QTableWidgetItem(fields.fieldName(0)));
    while(query.next()){
        QString cell = query.value(0).toString();
        QTableWidgetItem * Cell= new QTableWidgetItem(cell);
        ui->tableWidgetProductPropositions->setItem(noLigne,0,Cell);
        ui->tableWidgetProductPropositions->item(noLigne,0)->setData(32,query.value(1).toString());
        noLigne++;
    }

}

// charger tous les produits de la catalogue
void  MainWindow::loadAllProducts() {
    qDebug()<<"MainWindow::loadAllProducts()";
    QSqlQuery query("select libelle as nom_produit,idProduit from produit where accepte=1;");
    query.exec();
    int noLigne=0;
    QSqlRecord fields= query.record();
    ui->tableWidgetAllProducts->setColumnCount(1);
    ui->tableWidgetAllProducts->setRowCount(query.size());
    ui->tableWidgetAllProducts->setHorizontalHeaderItem(0,new QTableWidgetItem(fields.fieldName(0)));

    while(query.next()){
        QString cell = query.value(0).toString();
        QTableWidgetItem * Cell= new QTableWidgetItem(cell);
        ui->tableWidgetAllProducts->setItem(noLigne,0,Cell);
        ui->tableWidgetAllProducts->item(noLigne,0)->setData(32,query.value(1).toString());
        noLigne++;
    }
}

// charger les information concernant de produit
void MainWindow::loadProductInformation(){
    qDebug()<<"MainWindow::loadProducInformation()";
    QSqlQuery query;
    QString texte = "select p.libelle,c.libelle,r.libelle ";
    texte+="from produit p inner join categorie c on p.idCategorie=c.idCategorie ";
    texte+="inner join rayon r on c.idRayon=r.idRayon ";
    texte+="where idProduit="+idProduit+";";
    qDebug()<<texte;
    query.exec(texte);
    while(query.next()){
    ui->comboBoxShelf->addItem(query.value(2).toString());
    ui->comboBoxCategory->addItem(query.value(1).toString());
    ui->labelNewProductLabel->setText(query.value(0).toString());
    }
}

// lors d'un click sur la liste des nouveaux produits, afficher les informations
void MainWindow::on_tableWidgetProductPropositions_cellClicked(int row, int column)
{
    qDebug()<<"MainWindow::on_tableWidgetProductPropositions_cellClicked(int row, int column)";
    idProduit = ui->tableWidgetProductPropositions->item(row,0)->data(32).toString();
    ui->comboBoxShelf->clear();
    ui->comboBoxCategory->clear();
    ui->widgetProductInformation->show();
    loadProductInformation();

}

// pour acceptation des nouveaux produits
void MainWindow::on_pushButtonAcceptNewProduct_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonAcceptNewProduct_clicked()";
    QSqlQuery query;
    QString texte = "update produit set accepte=1 where idProduit="+idProduit+";";
    query.exec(texte);
    qDebug()<<texte;
    loadAllProducts();
    loadNewProducts();
}

// charger les catégories et mettre les dans combobox
void MainWindow::loadCategoriesComboBox(){
    qDebug()<<"MainWindow::loadCategoriesComboBox()";
    QString rayon=ui->comboBoxShelf->currentText();
    QSqlQuery query;
    int noLigne=0;
    QString texte = "select c.libelle from categorie c inner join rayon r on c.idRayon=r.idRayon where r.libelle='"+rayon+"';";
    qDebug()<<texte;
    query.exec(texte);
    while(query.next()){
        ui->comboBoxCategory->addItem(query.value(0).toString());
        qDebug()<<query.value(0).toString();
        noLigne++;
    }
}

// lors d'un changement de comboboxde rayon, charger ses catégories
void MainWindow::on_comboBoxShelf_activated(const QString &arg1)
{
    qDebug()<<"MainWindow::on_comboBoxShelf_activated(const QString &arg1)";
    ui->comboBoxCategory->clear();
    loadCategoriesComboBox();
}

// enregistrer les modfication de rayon/catégories
void MainWindow::on_pushButtonSaveProduct_clicked()
{
    qDebug()<<"MainWindow::on_pushButtonSaveBatch_clicked()";
    QSqlQuery query;
    QString rayon = ui->comboBoxShelf->currentText();
    QString categ = ui->comboBoxCategory->currentText();
    QString findIdCat = "select idCategorie from categorie where libelle='"+categ+"';";
    query.exec(findIdCat);
    if(query.next()){
        QString idCat = query.value(0).toString();

    QSqlQuery update;
    QString texte ="update produit set idCategorie="+idCat+" where idProduit='"+idProduit+"';";
    update.exec(texte);
    }
    ui->labelActionMessage->setText(tr("The category of product has been changed"));
}

// lors du click charger les rayons et catégories afin de donner le pouvoir de les modifier
void MainWindow::on_pushButtonModifyNewProduct_clicked()
{
    QSqlQuery query("select libelle,idRayon from rayon;");
    query.exec();
    ui->widgetProductInformation->show();
    int noLigne=0;
    ui->comboBoxShelf->clear();
    ui->comboBoxCategory->clear();
    while(query.next()){
        ui->comboBoxShelf->addItem(query.value(0).toString());
        noLigne++;
    }
    loadCategoriesComboBox();
}

