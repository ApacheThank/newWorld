/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditFirstName;
    QLabel *label_4;
    QLineEdit *lineEditCity;
    QLabel *label_5;
    QLineEdit *lineEditZipCode;
    QLabel *label_6;
    QLineEdit *lineEditPhoneNumber;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditLastName;
    QLineEdit *lineEditStreet;
    QLineEdit *lineEditEmail;
    QPushButton *pushButtonAddController;
    QLineEdit *lineEditSSN;
    QLabel *label_12;
    QLabel *label_8;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidgetListControllers;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonModifyController;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonEraseController;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelProducers;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableWidgetListProducers;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *verticalLayout_15;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_9;
    QTableWidget *tableWidgetRayonList;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButtonCreateRayon;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_10;
    QTableWidget *tableWidgetCategoryList;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButtonAddCategory;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_11;
    QTableWidget *tableWidgetProductList;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButtonAddProduct;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1049, 759);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalSpacer = new QSpacerItem(13, 568, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(998, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        formLayoutWidget = new QWidget(tab);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 321, 351));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditFirstName = new QLineEdit(formLayoutWidget);
        lineEditFirstName->setObjectName(QStringLiteral("lineEditFirstName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditFirstName);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEditCity = new QLineEdit(formLayoutWidget);
        lineEditCity->setObjectName(QStringLiteral("lineEditCity"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditCity);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lineEditZipCode = new QLineEdit(formLayoutWidget);
        lineEditZipCode->setObjectName(QStringLiteral("lineEditZipCode"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditZipCode);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        lineEditPhoneNumber = new QLineEdit(formLayoutWidget);
        lineEditPhoneNumber->setObjectName(QStringLiteral("lineEditPhoneNumber"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEditPhoneNumber);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEditLastName = new QLineEdit(formLayoutWidget);
        lineEditLastName->setObjectName(QStringLiteral("lineEditLastName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditLastName);

        lineEditStreet = new QLineEdit(formLayoutWidget);
        lineEditStreet->setObjectName(QStringLiteral("lineEditStreet"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditStreet);

        lineEditEmail = new QLineEdit(formLayoutWidget);
        lineEditEmail->setObjectName(QStringLiteral("lineEditEmail"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEditEmail);

        pushButtonAddController = new QPushButton(formLayoutWidget);
        pushButtonAddController->setObjectName(QStringLiteral("pushButtonAddController"));

        formLayout->setWidget(8, QFormLayout::FieldRole, pushButtonAddController);

        lineEditSSN = new QLineEdit(formLayoutWidget);
        lineEditSSN->setObjectName(QStringLiteral("lineEditSSN"));

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEditSSN);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_12);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(120, 190, 67, 21));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(380, 10, 601, 451));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableWidgetListControllers = new QTableWidget(layoutWidget);
        tableWidgetListControllers->setObjectName(QStringLiteral("tableWidgetListControllers"));

        verticalLayout_3->addWidget(tableWidgetListControllers);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonModifyController = new QPushButton(layoutWidget);
        pushButtonModifyController->setObjectName(QStringLiteral("pushButtonModifyController"));
        pushButtonModifyController->setEnabled(false);

        horizontalLayout_2->addWidget(pushButtonModifyController);

        horizontalSpacer_3 = new QSpacerItem(408, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButtonEraseController = new QPushButton(layoutWidget);
        pushButtonEraseController->setObjectName(QStringLiteral("pushButtonEraseController"));
        pushButtonEraseController->setEnabled(false);

        horizontalLayout_2->addWidget(pushButtonEraseController);


        verticalLayout_3->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_7 = new QVBoxLayout(tab_3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelProducers = new QLabel(tab_3);
        labelProducers->setObjectName(QStringLiteral("labelProducers"));

        horizontalLayout_5->addWidget(labelProducers);

        horizontalSpacer_6 = new QSpacerItem(648, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        tableWidgetListProducers = new QTableWidget(tab_3);
        tableWidgetListProducers->setObjectName(QStringLiteral("tableWidgetListProducers"));

        horizontalLayout_4->addWidget(tableWidgetListProducers);

        verticalSpacer_2 = new QSpacerItem(158, 328, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_4->addItem(verticalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_5 = new QSpacerItem(898, 58, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_6);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_16 = new QVBoxLayout(tab_2);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        horizontalSpacer_12 = new QSpacerItem(928, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_15->addItem(horizontalSpacer_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_8->addWidget(label_9);

        tableWidgetRayonList = new QTableWidget(tab_2);
        if (tableWidgetRayonList->columnCount() < 1)
            tableWidgetRayonList->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetRayonList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetRayonList->setObjectName(QStringLiteral("tableWidgetRayonList"));

        verticalLayout_8->addWidget(tableWidgetRayonList);


        verticalLayout_11->addLayout(verticalLayout_8);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_7 = new QSpacerItem(78, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        pushButtonCreateRayon = new QPushButton(tab_2);
        pushButtonCreateRayon->setObjectName(QStringLiteral("pushButtonCreateRayon"));

        horizontalLayout_8->addWidget(pushButtonCreateRayon);


        verticalLayout_11->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_11);

        verticalSpacer_3 = new QSpacerItem(38, 188, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_9->addItem(verticalSpacer_3);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_9->addWidget(label_10);

        tableWidgetCategoryList = new QTableWidget(tab_2);
        if (tableWidgetCategoryList->columnCount() < 1)
            tableWidgetCategoryList->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetCategoryList->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        tableWidgetCategoryList->setObjectName(QStringLiteral("tableWidgetCategoryList"));

        verticalLayout_9->addWidget(tableWidgetCategoryList);


        verticalLayout_12->addLayout(verticalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_8 = new QSpacerItem(78, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        pushButtonAddCategory = new QPushButton(tab_2);
        pushButtonAddCategory->setObjectName(QStringLiteral("pushButtonAddCategory"));

        horizontalLayout_7->addWidget(pushButtonAddCategory);


        verticalLayout_12->addLayout(horizontalLayout_7);


        horizontalLayout_9->addLayout(verticalLayout_12);

        verticalSpacer_4 = new QSpacerItem(38, 188, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_9->addItem(verticalSpacer_4);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_10->addWidget(label_11);

        tableWidgetProductList = new QTableWidget(tab_2);
        tableWidgetProductList->setObjectName(QStringLiteral("tableWidgetProductList"));

        verticalLayout_10->addWidget(tableWidgetProductList);


        verticalLayout_13->addLayout(verticalLayout_10);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(78, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        pushButtonAddProduct = new QPushButton(tab_2);
        pushButtonAddProduct->setObjectName(QStringLiteral("pushButtonAddProduct"));

        horizontalLayout_6->addWidget(pushButtonAddProduct);


        verticalLayout_13->addLayout(horizontalLayout_6);


        horizontalLayout_9->addLayout(verticalLayout_13);


        verticalLayout_14->addLayout(horizontalLayout_9);

        horizontalSpacer_10 = new QSpacerItem(898, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_14->addItem(horizontalSpacer_10);


        horizontalLayout_10->addLayout(verticalLayout_14);

        verticalSpacer_5 = new QSpacerItem(38, 338, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_10->addItem(verticalSpacer_5);


        verticalLayout_15->addLayout(horizontalLayout_10);

        horizontalSpacer_11 = new QSpacerItem(918, 98, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_15->addItem(horizontalSpacer_11);


        verticalLayout_16->addLayout(verticalLayout_15);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalSpacer_2 = new QSpacerItem(988, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(838, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1049, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "First name", 0));
        label_4->setText(QApplication::translate("MainWindow", "City", 0));
        label_5->setText(QApplication::translate("MainWindow", "ZIP code", 0));
        label_6->setText(QApplication::translate("MainWindow", "N\302\260 phone         ", 0));
        label_7->setText(QApplication::translate("MainWindow", "Email", 0));
        label_2->setText(QApplication::translate("MainWindow", "Last name", 0));
        label_3->setText(QApplication::translate("MainWindow", "Street", 0));
        pushButtonAddController->setText(QApplication::translate("MainWindow", "Add", 0));
        label_12->setText(QApplication::translate("MainWindow", "Social Security number", 0));
        label_8->setText(QString());
        pushButtonModifyController->setText(QApplication::translate("MainWindow", "Modify", 0));
        pushButtonEraseController->setText(QApplication::translate("MainWindow", "Erase", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Controlleurs", 0));
        labelProducers->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">Producers</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Producteurs", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Rayons</span></p></body></html>", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetRayonList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Nom", 0));
        pushButtonCreateRayon->setText(QApplication::translate("MainWindow", "Cr\303\251er un rayon", 0));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Categories</span></p></body></html>", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetCategoryList->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Nom", 0));
        pushButtonAddCategory->setText(QApplication::translate("MainWindow", "Ajouter", 0));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Produits</span></p></body></html>", 0));
        pushButtonAddProduct->setText(QApplication::translate("MainWindow", "Ajouter", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Produits", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
