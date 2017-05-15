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
    explicit MainWindow2(QWidget *parent = 0);
    ~MainWindow2();
    /**
     * @brief loadProducers
     * load all producers from database
     */
    void loadProducers();
private slots:
    /**
     * @brief on_pushButtonExit_clicked
     * close the program
     */
    void on_pushButtonExit_clicked();

private:
    Ui::MainWindow2 *ui;
};

#endif // MAINWINDOW2_H
