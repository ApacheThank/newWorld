#include "dialogaddproduct.h"
#include "ui_dialogaddproduct.h"

DialogAddProduct::DialogAddProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddProduct)
{
    ui->setupUi(this);
}

DialogAddProduct::~DialogAddProduct()
{
    delete ui;
}

QString DialogAddProduct::getUnitPrice()
{
    return ui->lineEditPrice->text();
}

QString DialogAddProduct::getQty()
{
    return ui->lineEditQty->text();
}

void DialogAddProduct::setMessage()
{
    ui->labelDialogErrorMessage->setText("Please enter the price and the quantity of product");
}

void DialogAddProduct::setSelectedProduct(QString product)
{
    ui->labelEnteredProduct->setText(product);
}

void DialogAddProduct::closeDialog()
{
    close();
}
