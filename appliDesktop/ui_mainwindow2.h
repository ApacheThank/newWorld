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
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelProducteurs;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *tableWidgetListProducers;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelProducteursAController;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidgetListToControl;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidgetListToValid;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButtonValiderProducteur;
    QPushButton *pushButtonRefuserProducteur;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButtonExit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName(QStringLiteral("MainWindow2"));
        MainWindow2->resize(798, 799);
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_10 = new QVBoxLayout(centralwidget);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelProducteurs = new QLabel(centralwidget);
        labelProducteurs->setObjectName(QStringLiteral("labelProducteurs"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelProducteurs->setFont(font);

        horizontalLayout_2->addWidget(labelProducteurs);

        horizontalSpacer_3 = new QSpacerItem(498, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

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

        verticalLayout_2->addWidget(tableWidgetListProducers);


        verticalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(618, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelProducteursAController = new QLabel(centralwidget);
        labelProducteursAController->setObjectName(QStringLiteral("labelProducteursAController"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        labelProducteursAController->setFont(font1);

        horizontalLayout_3->addWidget(labelProducteursAController);

        horizontalSpacer_2 = new QSpacerItem(418, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tableWidgetListToControl = new QTableWidget(centralwidget);
        if (tableWidgetListToControl->columnCount() < 7)
            tableWidgetListToControl->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetListToControl->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetListToControl->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetListToControl->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetListToControl->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetListToControl->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetListToControl->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetListToControl->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        tableWidgetListToControl->setObjectName(QStringLiteral("tableWidgetListToControl"));

        verticalLayout_3->addWidget(tableWidgetListToControl);


        verticalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_4->addWidget(comboBox);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(278, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_5->addWidget(pushButton);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setFamily(QStringLiteral("STIXGeneral"));
        font2.setItalic(true);
        label_3->setFont(font2);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAutoFillBackground(false);

        horizontalLayout_6->addWidget(label_3);

        horizontalSpacer_6 = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_6->addLayout(horizontalLayout_6);


        verticalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(218, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableWidgetListToValid = new QTableWidget(centralwidget);
        if (tableWidgetListToValid->columnCount() < 7)
            tableWidgetListToValid->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetListToValid->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidgetListToValid->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidgetListToValid->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidgetListToValid->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidgetListToValid->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidgetListToValid->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidgetListToValid->setHorizontalHeaderItem(6, __qtablewidgetitem20);
        tableWidgetListToValid->setObjectName(QStringLiteral("tableWidgetListToValid"));

        verticalLayout->addWidget(tableWidgetListToValid);


        verticalLayout_7->addLayout(verticalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_7 = new QSpacerItem(398, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButtonValiderProducteur = new QPushButton(centralwidget);
        pushButtonValiderProducteur->setObjectName(QStringLiteral("pushButtonValiderProducteur"));

        horizontalLayout_7->addWidget(pushButtonValiderProducteur);

        pushButtonRefuserProducteur = new QPushButton(centralwidget);
        pushButtonRefuserProducteur->setObjectName(QStringLiteral("pushButtonRefuserProducteur"));

        horizontalLayout_7->addWidget(pushButtonRefuserProducteur);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_7->addLayout(horizontalLayout_8);


        verticalLayout_8->addLayout(verticalLayout_7);


        verticalLayout_9->addLayout(verticalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_8 = new QSpacerItem(518, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        pushButtonExit = new QPushButton(centralwidget);
        pushButtonExit->setObjectName(QStringLiteral("pushButtonExit"));

        horizontalLayout_9->addWidget(pushButtonExit);


        verticalLayout_9->addLayout(horizontalLayout_9);


        verticalLayout_10->addLayout(verticalLayout_9);

        MainWindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 798, 29));
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
        labelProducteurs->setText(QApplication::translate("MainWindow2", "Producteurs", 0));
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
        labelProducteursAController->setText(QApplication::translate("MainWindow2", "Producteur(s) \303\240 controller", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetListToControl->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow2", "Nom", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetListToControl->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow2", "Prenom", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetListToControl->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow2", "Rue", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetListToControl->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow2", "Ville", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetListToControl->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow2", "Code postal", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetListToControl->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow2", "Tel", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetListToControl->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow2", "Visite pr\303\251vu", 0));
        label->setText(QApplication::translate("MainWindow2", "Les dates propos\303\251es", 0));
        pushButton->setText(QApplication::translate("MainWindow2", "Accepter", 0));
        label_3->setText(QApplication::translate("MainWindow2", "lors d'acceptation, le producteur sera pr\303\251venu de votre visite", 0));
        label_2->setText(QApplication::translate("MainWindow2", "Producteur(s) \303\240 valider", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetListToValid->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow2", "Nom", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetListToValid->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow2", "Prenom", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetListToValid->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow2", "Rue ", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetListToValid->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow2", "Ville", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetListToValid->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow2", "Code postal", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetListToValid->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow2", "Tel", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetListToValid->horizontalHeaderItem(6);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow2", "Derni\303\250re visite", 0));
        pushButtonValiderProducteur->setText(QApplication::translate("MainWindow2", "Valider", 0));
        pushButtonRefuserProducteur->setText(QApplication::translate("MainWindow2", "Refuser", 0));
        pushButtonExit->setText(QApplication::translate("MainWindow2", "Quitter", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
