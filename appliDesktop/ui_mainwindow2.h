/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow2
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelProducteurs_2;
    QSpacerItem *horizontalSpacer_9;
    QLabel *labelSort;
    QComboBox *comboBox_2;
    QTableWidget *tableWidgetListProducers;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonValidProducer;
    QPushButton *pushButtonRefuseProducer;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonExit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName(QStringLiteral("MainWindow2"));
        MainWindow2->resize(893, 534);
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        labelProducteurs_2 = new QLabel(centralwidget);
        labelProducteurs_2->setObjectName(QStringLiteral("labelProducteurs_2"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelProducteurs_2->setFont(font);

        horizontalLayout_10->addWidget(labelProducteurs_2);

        horizontalSpacer_9 = new QSpacerItem(498, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);

        labelSort = new QLabel(centralwidget);
        labelSort->setObjectName(QStringLiteral("labelSort"));

        horizontalLayout_10->addWidget(labelSort);

        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_10->addWidget(comboBox_2);


        verticalLayout_4->addLayout(horizontalLayout_10);

        tableWidgetListProducers = new QTableWidget(centralwidget);
        if (tableWidgetListProducers->columnCount() < 7)
            tableWidgetListProducers->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetListProducers->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetListProducers->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetListProducers->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetListProducers->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetListProducers->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetListProducers->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetListProducers->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidgetListProducers->setObjectName(QStringLiteral("tableWidgetListProducers"));

        verticalLayout_4->addWidget(tableWidgetListProducers);

        horizontalSpacer_5 = new QSpacerItem(618, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        pushButtonValidProducer = new QPushButton(centralwidget);
        pushButtonValidProducer->setObjectName(QStringLiteral("pushButtonValidProducer"));

        horizontalLayout_7->addWidget(pushButtonValidProducer);

        pushButtonRefuseProducer = new QPushButton(centralwidget);
        pushButtonRefuseProducer->setObjectName(QStringLiteral("pushButtonRefuseProducer"));

        horizontalLayout_7->addWidget(pushButtonRefuseProducer);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalSpacer_3 = new QSpacerItem(448, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));

        verticalLayout_3->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(578, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonExit = new QPushButton(centralwidget);
        pushButtonExit->setObjectName(QStringLiteral("pushButtonExit"));

        horizontalLayout->addWidget(pushButtonExit);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_2);

        MainWindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 893, 27));
        MainWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow2->setStatusBar(statusbar);

        retranslateUi(MainWindow2);

        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QApplication::translate("MainWindow2", "Control", 0));
        labelProducteurs_2->setText(QApplication::translate("MainWindow2", "Producers", 0));
        labelSort->setText(QApplication::translate("MainWindow2", "Sort", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow2", "To control", 0)
         << QApplication::translate("MainWindow2", "To valid", 0)
        );
        QTableWidgetItem *___qtablewidgetitem = tableWidgetListProducers->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow2", "Nom", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetListProducers->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow2", "Prenom", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetListProducers->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow2", "Rue", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetListProducers->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow2", "Ville", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetListProducers->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow2", "Code postal", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetListProducers->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow2", "Tel", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetListProducers->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow2", "Derni\303\250re visite", 0));
        pushButtonValidProducer->setText(QApplication::translate("MainWindow2", "Valid", 0));
        pushButtonRefuseProducer->setText(QApplication::translate("MainWindow2", "Refuse", 0));
        pushButtonExit->setText(QApplication::translate("MainWindow2", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
