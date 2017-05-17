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

    void on_tableWidgetListControllers_cellEntered(int row, int column);

    void on_tableWidgetRayonList_cellClicked(int row, int column);

    void on_tableWidgetCategoryList_cellClicked(int row, int column);

    void on_pushButtonCreateRayon_clicked();

    void on_pushButtonAddCategory_clicked();

    void on_pushButtonAddProduct_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
