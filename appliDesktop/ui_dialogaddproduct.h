/********************************************************************************
** Form generated from reading UI file 'dialogaddproduct.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADDPRODUCT_H
#define UI_DIALOGADDPRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogAddProduct
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *labelEnteredProduct;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditPrice;
    QLineEdit *lineEditQty;
    QLabel *labelDialogErrorMessage;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogAddProduct)
    {
        if (DialogAddProduct->objectName().isEmpty())
            DialogAddProduct->setObjectName(QStringLiteral("DialogAddProduct"));
        DialogAddProduct->resize(398, 247);
        verticalLayout_5 = new QVBoxLayout(DialogAddProduct);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(DialogAddProduct);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(13);
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        labelEnteredProduct = new QLabel(DialogAddProduct);
        labelEnteredProduct->setObjectName(QStringLiteral("labelEnteredProduct"));

        horizontalLayout_2->addWidget(labelEnteredProduct);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalSpacer = new QSpacerItem(28, 168, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(DialogAddProduct);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(DialogAddProduct);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEditPrice = new QLineEdit(DialogAddProduct);
        lineEditPrice->setObjectName(QStringLiteral("lineEditPrice"));

        verticalLayout->addWidget(lineEditPrice);

        lineEditQty = new QLineEdit(DialogAddProduct);
        lineEditQty->setObjectName(QStringLiteral("lineEditQty"));

        verticalLayout->addWidget(lineEditQty);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        labelDialogErrorMessage = new QLabel(DialogAddProduct);
        labelDialogErrorMessage->setObjectName(QStringLiteral("labelDialogErrorMessage"));

        verticalLayout_3->addWidget(labelDialogErrorMessage);

        buttonBox = new QDialogButtonBox(DialogAddProduct);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(DialogAddProduct);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogAddProduct, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogAddProduct, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAddProduct);
    } // setupUi

    void retranslateUi(QDialog *DialogAddProduct)
    {
        DialogAddProduct->setWindowTitle(QApplication::translate("DialogAddProduct", "Product", 0));
        label_3->setText(QApplication::translate("DialogAddProduct", "You have just added the product:", 0));
        labelEnteredProduct->setText(QString());
        label->setText(QApplication::translate("DialogAddProduct", "Unit price  ", 0));
        label_2->setText(QApplication::translate("DialogAddProduct", "Quantity", 0));
        labelDialogErrorMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogAddProduct: public Ui_DialogAddProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADDPRODUCT_H
