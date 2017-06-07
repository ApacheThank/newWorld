#ifndef DIALOGADDPRODUCT_H
#define DIALOGADDPRODUCT_H

#include <QDialog>

namespace Ui {
class DialogAddProduct;
}

class DialogAddProduct : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddProduct(QWidget *parent = 0);
    ~DialogAddProduct();
    /**
     * @brief getQty
     * @return the quantity of product added
     */
    QString getQty();
    /**
     * @brief getUnitPrice
     * @return the price of product added
     */
    QString getUnitPrice();
    /**
     * @brief setMessage
     * allows to set the message to show
     */
    void setMessage();
    /**
     * @brief setSelectedProduct
     * @param product
     */
    void setSelectedProduct(QString product);
private:
    Ui::DialogAddProduct *ui;
};

#endif // DIALOGADDPRODUCT_H
