#ifndef DIALOGCONNECT_H
#define DIALOGCONNECT_H
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
class DialogConnect;
}

class DialogConnect : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogConnect(QWidget *parent = 0);
    ~DialogConnect();
    QString getMdp();
    QString getLogin();
    void setMessage();
    
private:
    Ui::DialogConnect *ui;
};

#endif // DIALOGCONNECT_H
