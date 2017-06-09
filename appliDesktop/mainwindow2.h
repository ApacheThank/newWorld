#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

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
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow2(QString variable, QWidget *parent = 0);
    ~MainWindow2();
    /**
     * @brief idConnected
     * public variable passée lors de connection
     */
    QString idConnected;
    /**
     * @brief idProducteur
     * public variable
     */
    QString idProducteur;
    /**
     * @brief loadProducers
     * load all producers from database
     */
    void loadProducers(QString trier);
    /**
     * @brief loadVisitInformation
     * load information about visit token for clicked producer's
     */
    void loadVisitInformation();
    /**
     * @brief clearVisitInformation
     * clear visit information
     */
    void clearVisitInformation();
private slots:
    /**
     * @brief on_pushButtonExit_clicked
     * close the program
     */
    void on_pushButtonExit_clicked();

    /**
     * @brief on_comboBoxSort_activated
     * @param arg1 load the producers by param got
     */
    void on_comboBoxSort_activated(const QString &arg1);

    /**
     * @brief on_tableWidgetListProducers_cellClicked
     * @param row
     * @param column
     */
    void on_tableWidgetListProducers_cellClicked(int row, int column);

    /**
     * @brief on_pushButtonValidProducer_clicked
     * valid selected producer if not validated
     */
    void on_pushButtonValidProducer_clicked();

    /**
     * @brief on_pushButtonRefuseProducer_clicked
     * refuse the producer
     */
    void on_pushButtonRefuseProducer_clicked();

    /**
     * @brief on_pushButtonAcceptVisit2_clicked
     * accept the visit
     */
    void on_pushButtonAcceptVisit2_clicked();

private:
    Ui::MainWindow2 *ui;
};

#endif // MAINWINDOW2_H
