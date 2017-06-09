#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQuery>
#include <QVector>
#include <QDebug>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QSqlRecord>
 #include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * @brief idProducteur
     * public variable
     */
    QString idProducteur;
    /**
     * @brief idController
     * public variable
     */
    QString idController;
    /**
     * @brief idRayon
     * public variable
     */
    QString idRayon;
    /**
     * @brief idCategorie
     * public variable
     */
    QString idCategorie;
    /**
     * @brief idLot
     * public variable
     */
    QString idLot;
    /**
     * @brief idProduit
     * public variable
     */
    QString idProduit;
    /**
     * @brief getId
     * @return max id +1 from database
     */
    int getId();
    /**
     * @brief loadControllers
     * load all controllers from database
     */
    void loadControllers();
    /**
     * @brief loadProducers
     * load all producers from database
     */
    void loadProducers();
    /**
     * @brief generatePassword
     * @return the generate password for new controller
     */
    QString generatePassword();
    /**
     * @brief loadRayons
     * load all rayons from database
     */
    void loadRayons();
    /**
     * @brief loadCategories
     * load all categories from rayon
     */
    void loadCategories();
    /**
     * @brief loadProducts
     * load all products from category
     */
    void loadProducts();
    /**
     * @brief loadProductionBatch
     * load all production batches from database
     */
    void loadProductionBatches();
    /**
     * @brief loadBatchInformation
     * load all information about clicked batch
     */
    void loadBatchInformation();
    /**
     * @brief loadNewProducts
     * load all new products
     */
    void loadNewProducts();
    /**
     * @brief loadAllProducts
     * load all products
     */
    void loadAllProducts();
    /**
     * @brief loadCategoriesComboBox
     * load categories and put into combobox
     */
    void loadCategoriesComboBox();
    /**
     * @brief loadProductInformation
     * load the product information
     */
    void loadProductInformation();
    /**
     * @brief loadControllersComboBox
     * load all controllers and put into comboBox
     */
    void loadControllersComboBox();
private slots:
    /**
     * @brief on_pushButtonAddController_clicked
     * allows to create a new controller and insert him in database
     */
    void on_pushButtonAddController_clicked();
    /**
     * @brief on_pushButton_clicked
     * close the program
     */
    void on_pushButton_clicked();
    /**
     * @brief on_pushButtonEraseController_clicked
     * delete controller from database
     */
    void on_pushButtonEraseController_clicked();
    /**
     * @brief on_tableWidgetListControllers_cellClicked
     * @param row return the row of clicked cell
     * @param column return the column of clicked column
     */
    void on_tableWidgetListControllers_cellClicked(int row, int column);
    /**
     * @brief on_tableWidgetRayonList_cellClicked
     * @param row
     * @param column
     */
    void on_tableWidgetRayonList_cellClicked(int row, int column);
    /**
     * @brief on_tableWidgetCategoryList_cellClicked
     * @param row
     * @param column
     */
    void on_tableWidgetCategoryList_cellClicked(int row, int column);
    /**
     * @brief on_pushButtonCreateRayon_clicked
     * create the rayon
     */
    void on_pushButtonCreateRayon_clicked();
    /**
     * @brief on_pushButtonAddCategory_clicked
     * add category into the rayon
     */
    void on_pushButtonAddCategory_clicked();
    /**
     * @brief on_pushButtonAddProduct_clicked
     * add the product into the category
     */
    void on_pushButtonAddProduct_clicked();
    /**
     * @brief on_tableWidgetListOfBatchPropositions_cellClicked
     * @param row
     * @param column
     */
    void on_tableWidgetListOfBatchPropositions_cellClicked(int row, int column);
    /**
     * @brief on_pushButtonAcceptNewProduct_clicked
     * accept the new proposed product
     */
    void on_pushButtonAcceptNewProduct_clicked();
    /**
     * @brief on_tableWidgetProductPropositions_cellClicked
     * @param row
     * @param column
     */
    void on_tableWidgetProductPropositions_cellClicked(int row, int column);
    /**
     * @brief on_comboBoxShelf_activated
     * @param arg1
     * load the categories while activated
     */
    void on_comboBoxShelf_activated(const QString &arg1);
    /**
     * @brief on_pushButtonSaveProduct_clicked
     * save the modified product
     */
    void on_pushButtonSaveProduct_clicked();
    /**
     * @brief on_pushButtonModifyNewProduct_clicked
     */
    void on_pushButtonModifyNewProduct_clicked();
    /**
     * @brief on_tableWidgetListProducers_cellClicked
     * @param row
     * @param column
     */
    void on_tableWidgetListProducers_cellClicked(int row, int column);
    /**
     * @brief on_pushButtonAcceptVisit_clicked
     * update fixed visit
     */
    void on_pushButtonAcceptVisit_clicked();
    /**
     * @brief on_tableWidgetListControllers_itemChanged
     * @param item
     * save the modification after text changed
     */
    void on_tableWidgetListControllers_itemChanged(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
