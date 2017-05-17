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
#include <QtWidgets/QComboBox>
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
    QLabel *label_8;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidgetListControllers;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonModifyController;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonEraseController;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *labelLastName;
    QLineEdit *lineEditLastName;
    QLabel *labelFirstName;
    QLineEdit *lineEditFirstName;
    QLabel *labelStreet;
    QLineEdit *lineEditStreet;
    QLabel *labelCity;
    QLineEdit *lineEditCity;
    QLabel *labelZipCode;
    QLineEdit *lineEditZipCode;
    QLabel *labelPhoneNumber;
    QLineEdit *lineEditPhoneNumber;
    QLabel *labelMail;
    QLineEdit *lineEditEmail;
    QLabel *labelSSN;
    QLineEdit *lineEditSSN;
    QPushButton *pushButtonAddController;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelProducers;
    QSpacerItem *horizontalSpacer_6;
    QTableWidget *tableWidgetListProducers;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_3;
    QComboBox *comboBoxListDate_2;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_16;
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
    QLineEdit *lineEditCreateShelf;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButtonCreateRayon;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_10;
    QTableWidget *tableWidgetCategoryList;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEditAddCategory;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButtonAddCategory;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_11;
    QTableWidget *tableWidgetProductList;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEditAddProduct;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButtonAddProduct;
    QSpacerItem *verticalSpacer_5;
    QLabel *labelErrorMessage;
    QSpacerItem *horizontalSpacer_11;
    QWidget *tab_4;
    QTableWidget *tableWidgetListOfProductPropositions;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
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

        layoutWidget_2 = new QWidget(tab);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 10, 309, 345));
        formLayout_2 = new QFormLayout(layoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        labelLastName = new QLabel(layoutWidget_2);
        labelLastName->setObjectName(QStringLiteral("labelLastName"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelLastName);

        lineEditLastName = new QLineEdit(layoutWidget_2);
        lineEditLastName->setObjectName(QStringLiteral("lineEditLastName"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditLastName);

        labelFirstName = new QLabel(layoutWidget_2);
        labelFirstName->setObjectName(QStringLiteral("labelFirstName"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelFirstName);

        lineEditFirstName = new QLineEdit(layoutWidget_2);
        lineEditFirstName->setObjectName(QStringLiteral("lineEditFirstName"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEditFirstName);

        labelStreet = new QLabel(layoutWidget_2);
        labelStreet->setObjectName(QStringLiteral("labelStreet"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelStreet);

        lineEditStreet = new QLineEdit(layoutWidget_2);
        lineEditStreet->setObjectName(QStringLiteral("lineEditStreet"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEditStreet);

        labelCity = new QLabel(layoutWidget_2);
        labelCity->setObjectName(QStringLiteral("labelCity"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, labelCity);

        lineEditCity = new QLineEdit(layoutWidget_2);
        lineEditCity->setObjectName(QStringLiteral("lineEditCity"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineEditCity);

        labelZipCode = new QLabel(layoutWidget_2);
        labelZipCode->setObjectName(QStringLiteral("labelZipCode"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, labelZipCode);

        lineEditZipCode = new QLineEdit(layoutWidget_2);
        lineEditZipCode->setObjectName(QStringLiteral("lineEditZipCode"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, lineEditZipCode);

        labelPhoneNumber = new QLabel(layoutWidget_2);
        labelPhoneNumber->setObjectName(QStringLiteral("labelPhoneNumber"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, labelPhoneNumber);

        lineEditPhoneNumber = new QLineEdit(layoutWidget_2);
        lineEditPhoneNumber->setObjectName(QStringLiteral("lineEditPhoneNumber"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, lineEditPhoneNumber);

        labelMail = new QLabel(layoutWidget_2);
        labelMail->setObjectName(QStringLiteral("labelMail"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, labelMail);

        lineEditEmail = new QLineEdit(layoutWidget_2);
        lineEditEmail->setObjectName(QStringLiteral("lineEditEmail"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, lineEditEmail);

        labelSSN = new QLabel(layoutWidget_2);
        labelSSN->setObjectName(QStringLiteral("labelSSN"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, labelSSN);

        lineEditSSN = new QLineEdit(layoutWidget_2);
        lineEditSSN->setObjectName(QStringLiteral("lineEditSSN"));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, lineEditSSN);

        pushButtonAddController = new QPushButton(layoutWidget_2);
        pushButtonAddController->setObjectName(QStringLiteral("pushButtonAddController"));

        formLayout_2->setWidget(8, QFormLayout::FieldRole, pushButtonAddController);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_6 = new QVBoxLayout(tab_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelProducers = new QLabel(tab_3);
        labelProducers->setObjectName(QStringLiteral("labelProducers"));

        horizontalLayout_5->addWidget(labelProducers);

        horizontalSpacer_6 = new QSpacerItem(648, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_5);

        tableWidgetListProducers = new QTableWidget(tab_3);
        tableWidgetListProducers->setObjectName(QStringLiteral("tableWidgetListProducers"));

        verticalLayout_5->addWidget(tableWidgetListProducers);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_17->addWidget(label_3);

        comboBoxListDate_2 = new QComboBox(tab_3);
        comboBoxListDate_2->setObjectName(QStringLiteral("comboBoxListDate_2"));

        horizontalLayout_17->addWidget(comboBoxListDate_2);


        horizontalLayout_16->addLayout(horizontalLayout_17);

        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_16->addWidget(pushButton_5);


        verticalLayout_18->addLayout(horizontalLayout_16);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setFamily(QStringLiteral("STIXGeneral"));
        font.setItalic(true);
        label_5->setFont(font);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAutoFillBackground(false);

        horizontalLayout_18->addWidget(label_5);

        horizontalSpacer_14 = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_14);


        verticalLayout_18->addLayout(horizontalLayout_18);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalSpacer_16 = new QSpacerItem(448, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_16);


        verticalLayout_18->addLayout(horizontalLayout_20);


        verticalLayout_5->addLayout(verticalLayout_18);


        verticalLayout_6->addLayout(verticalLayout_5);

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
        lineEditCreateShelf = new QLineEdit(tab_2);
        lineEditCreateShelf->setObjectName(QStringLiteral("lineEditCreateShelf"));

        horizontalLayout_8->addWidget(lineEditCreateShelf);

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
        lineEditAddCategory = new QLineEdit(tab_2);
        lineEditAddCategory->setObjectName(QStringLiteral("lineEditAddCategory"));

        horizontalLayout_7->addWidget(lineEditAddCategory);

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
        lineEditAddProduct = new QLineEdit(tab_2);
        lineEditAddProduct->setObjectName(QStringLiteral("lineEditAddProduct"));

        horizontalLayout_6->addWidget(lineEditAddProduct);

        horizontalSpacer_9 = new QSpacerItem(78, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        pushButtonAddProduct = new QPushButton(tab_2);
        pushButtonAddProduct->setObjectName(QStringLiteral("pushButtonAddProduct"));

        horizontalLayout_6->addWidget(pushButtonAddProduct);


        verticalLayout_13->addLayout(horizontalLayout_6);


        horizontalLayout_9->addLayout(verticalLayout_13);


        verticalLayout_14->addLayout(horizontalLayout_9);


        horizontalLayout_10->addLayout(verticalLayout_14);

        verticalSpacer_5 = new QSpacerItem(38, 338, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_10->addItem(verticalSpacer_5);


        verticalLayout_15->addLayout(horizontalLayout_10);

        labelErrorMessage = new QLabel(tab_2);
        labelErrorMessage->setObjectName(QStringLiteral("labelErrorMessage"));

        verticalLayout_15->addWidget(labelErrorMessage);

        horizontalSpacer_11 = new QSpacerItem(918, 98, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_15->addItem(horizontalSpacer_11);


        verticalLayout_16->addLayout(verticalLayout_15);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tableWidgetListOfProductPropositions = new QTableWidget(tab_4);
        tableWidgetListOfProductPropositions->setObjectName(QStringLiteral("tableWidgetListOfProductPropositions"));
        tableWidgetListOfProductPropositions->setGeometry(QRect(30, 50, 601, 271));
        label = new QLabel(tab_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 191, 21));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(680, 60, 95, 31));
        pushButton_3 = new QPushButton(tab_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(680, 100, 95, 31));
        tabWidget->addTab(tab_4, QString());

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

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_8->setText(QString());
        pushButtonModifyController->setText(QApplication::translate("MainWindow", "Modify", 0));
        pushButtonEraseController->setText(QApplication::translate("MainWindow", "Erase", 0));
        labelLastName->setText(QApplication::translate("MainWindow", "Last name", 0));
        labelFirstName->setText(QApplication::translate("MainWindow", "First name", 0));
        labelStreet->setText(QApplication::translate("MainWindow", "Street", 0));
        labelCity->setText(QApplication::translate("MainWindow", "City", 0));
        labelZipCode->setText(QApplication::translate("MainWindow", "ZIP code", 0));
        labelPhoneNumber->setText(QApplication::translate("MainWindow", "N\302\260 phone         ", 0));
        labelMail->setText(QApplication::translate("MainWindow", "Email", 0));
        labelSSN->setText(QApplication::translate("MainWindow", "Social Security Number", 0));
        pushButtonAddController->setText(QApplication::translate("MainWindow", "Add", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Controllers", 0));
        labelProducers->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">Producers</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "Meeting's propositions", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Accept", 0));
        label_5->setText(QApplication::translate("MainWindow", "Upon acceptance the producer will be notified of your visit  ", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Producers", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Shelves</span></p></body></html>", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetRayonList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Name", 0));
        pushButtonCreateRayon->setText(QApplication::translate("MainWindow", "Create shelf", 0));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Categories</span></p></body></html>", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetCategoryList->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Name", 0));
        pushButtonAddCategory->setText(QApplication::translate("MainWindow", "Add category", 0));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Products</span></p></body></html>", 0));
        pushButtonAddProduct->setText(QApplication::translate("MainWindow", "Add product", 0));
        labelErrorMessage->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Products", 0));
#ifndef QT_NO_WHATSTHIS
        label->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("MainWindow", "Products propositions", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Accept", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Refuse", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Propositions", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
