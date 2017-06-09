#include "dialogconnect.h"
#include "ui_dialogconnect.h"

DialogConnect::DialogConnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnect)
{
    ui->setupUi(this);


}

DialogConnect::~DialogConnect()
{
    delete ui;
}


QString DialogConnect::getLogin()
{
    return ui->lineEditLogin->text();
}

QString DialogConnect::getMdp()
{
    return ui->lineEditMDP->text();
}

void DialogConnect::setMessage()
{
    ui->label->setText(tr("Login or password is incorrect"));
}
