/********************************************************************************
** Form generated from reading UI file 'dialogconnect.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONNECT_H
#define UI_DIALOGCONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogConnect
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *labelID;
    QLineEdit *lineEditLogin;
    QLabel *labelMDP;
    QLineEdit *lineEditMDP;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogConnect)
    {
        if (DialogConnect->objectName().isEmpty())
            DialogConnect->setObjectName(QStringLiteral("DialogConnect"));
        DialogConnect->resize(391, 204);
        verticalLayout_4 = new QVBoxLayout(DialogConnect);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalSpacer = new QSpacerItem(38, 128, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        labelID = new QLabel(DialogConnect);
        labelID->setObjectName(QStringLiteral("labelID"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelID);

        lineEditLogin = new QLineEdit(DialogConnect);
        lineEditLogin->setObjectName(QStringLiteral("lineEditLogin"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditLogin);

        labelMDP = new QLabel(DialogConnect);
        labelMDP->setObjectName(QStringLiteral("labelMDP"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelMDP);

        lineEditMDP = new QLineEdit(DialogConnect);
        lineEditMDP->setObjectName(QStringLiteral("lineEditMDP"));
        lineEditMDP->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditMDP);


        verticalLayout->addLayout(formLayout);


        verticalLayout_2->addLayout(verticalLayout);

        label = new QLabel(DialogConnect);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(48, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(DialogConnect);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(DialogConnect);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogConnect, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogConnect, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogConnect);
    } // setupUi

    void retranslateUi(QDialog *DialogConnect)
    {
        DialogConnect->setWindowTitle(QApplication::translate("DialogConnect", "Connection", 0));
        labelID->setText(QApplication::translate("DialogConnect", "Login", 0));
        lineEditLogin->setText(QString());
        labelMDP->setText(QApplication::translate("DialogConnect", "Password", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogConnect: public Ui_DialogConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONNECT_H
