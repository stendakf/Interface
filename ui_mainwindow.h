/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QFormLayout *formLayout;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_10;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_24;
    QLineEdit *lineEdit_26;
    QLabel *label_2;
    QFormLayout *formLayout_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_8;
    QPushButton *pushButton_9;
    QLineEdit *lineEdit_9;
    QLabel *label_3;
    QFormLayout *formLayout_3;
    QPushButton *pushButton_11;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLabel *label_4;
    QFormLayout *formLayout_4;
    QPushButton *pushButton_17;
    QLineEdit *lineEdit_14;
    QPushButton *pushButton_18;
    QLineEdit *lineEdit_15;
    QLabel *label_6;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_22;
    QLineEdit *lineEdit_22;
    QLineEdit *lineEdit_23;
    QPushButton *pushButton_23;
    QLineEdit *lineEdit_24;
    QLineEdit *lineEdit_25;
    QLabel *label_5;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_17;
    QPushButton *pushButton_20;
    QLineEdit *lineEdit_16;
    QPushButton *pushButton_19;
    QLineEdit *lineEdit_19;
    QPushButton *pushButton_21;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_21;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout_5;
    QPushButton *pushButton_25;
    QLineEdit *lineEdit_27;
    QPushButton *pushButton_16;
    QPushButton *pushButton_26;
    QPushButton *pushButton;
    QPushButton *pushButton_12;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 995);
        MainWindow->setMaximumSize(QSize(1000, 16777215));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);

        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(160, 16777215));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(87, 0));
        pushButton_5->setMaximumSize(QSize(87, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, pushButton_5);

        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMaximumSize(QSize(80, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_4);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(87, 0));
        pushButton_6->setMaximumSize(QSize(87, 16777215));

        formLayout->setWidget(1, QFormLayout::LabelRole, pushButton_6);

        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setMaximumSize(QSize(80, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_5);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(87, 0));
        pushButton_3->setMaximumSize(QSize(87, 16777215));

        formLayout->setWidget(2, QFormLayout::LabelRole, pushButton_3);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(80, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_2);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(87, 0));
        pushButton_4->setMaximumSize(QSize(87, 16777215));

        formLayout->setWidget(3, QFormLayout::LabelRole, pushButton_4);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(80, 16777215));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_3);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(87, 0));
        pushButton_10->setMaximumSize(QSize(87, 16777215));

        formLayout->setWidget(4, QFormLayout::LabelRole, pushButton_10);

        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setMaximumSize(QSize(80, 16777215));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_6);

        pushButton_24 = new QPushButton(centralWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setMinimumSize(QSize(87, 0));
        pushButton_24->setMaximumSize(QSize(87, 16777215));

        formLayout->setWidget(5, QFormLayout::LabelRole, pushButton_24);

        lineEdit_26 = new QLineEdit(centralWidget);
        lineEdit_26->setObjectName(QStringLiteral("lineEdit_26"));
        lineEdit_26->setMaximumSize(QSize(80, 16777215));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_26);


        verticalLayout_4->addLayout(formLayout);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(160, 16777215));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        formLayout_2->setHorizontalSpacing(6);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(87, 0));
        pushButton_2->setMaximumSize(QSize(87, 16777215));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, pushButton_2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(80, 16777215));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(87, 0));
        pushButton_7->setMaximumSize(QSize(87, 16777215));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, pushButton_7);

        lineEdit_7 = new QLineEdit(centralWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setMaximumSize(QSize(80, 16777215));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_7);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(87, 0));
        pushButton_8->setMaximumSize(QSize(87, 16777215));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, pushButton_8);

        lineEdit_8 = new QLineEdit(centralWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setMaximumSize(QSize(80, 16777215));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEdit_8);

        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(87, 0));
        pushButton_9->setMaximumSize(QSize(87, 16777215));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, pushButton_9);

        lineEdit_9 = new QLineEdit(centralWidget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setMaximumSize(QSize(80, 16777215));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineEdit_9);


        verticalLayout_4->addLayout(formLayout_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(160, 16777215));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(87, 0));
        pushButton_11->setMaximumSize(QSize(87, 16777215));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, pushButton_11);

        lineEdit_10 = new QLineEdit(centralWidget);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setMaximumSize(QSize(80, 16777215));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lineEdit_10);

        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(87, 0));
        pushButton_13->setMaximumSize(QSize(87, 16777215));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, pushButton_13);

        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(87, 0));
        pushButton_14->setMaximumSize(QSize(87, 16777215));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, pushButton_14);

        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(87, 0));
        pushButton_15->setMaximumSize(QSize(87, 16777215));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, pushButton_15);

        lineEdit_11 = new QLineEdit(centralWidget);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setMaximumSize(QSize(80, 16777215));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lineEdit_11);

        lineEdit_12 = new QLineEdit(centralWidget);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setMaximumSize(QSize(80, 16777215));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, lineEdit_12);

        lineEdit_13 = new QLineEdit(centralWidget);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        lineEdit_13->setMaximumSize(QSize(80, 16777215));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, lineEdit_13);


        verticalLayout_4->addLayout(formLayout_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(160, 16777215));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        pushButton_17 = new QPushButton(centralWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setMinimumSize(QSize(87, 0));
        pushButton_17->setMaximumSize(QSize(87, 16777215));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, pushButton_17);

        lineEdit_14 = new QLineEdit(centralWidget);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setMaximumSize(QSize(80, 16777215));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEdit_14);

        pushButton_18 = new QPushButton(centralWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setMinimumSize(QSize(87, 0));
        pushButton_18->setMaximumSize(QSize(87, 16777215));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, pushButton_18);

        lineEdit_15 = new QLineEdit(centralWidget);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setMaximumSize(QSize(80, 16777215));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, lineEdit_15);


        verticalLayout_4->addLayout(formLayout_4);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(160, 16777215));
        QFont font2;
        font2.setPointSize(10);
        label_6->setFont(font2);

        verticalLayout_4->addWidget(label_6);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_22 = new QPushButton(centralWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(pushButton_22, 0, 0, 1, 1);

        lineEdit_22 = new QLineEdit(centralWidget);
        lineEdit_22->setObjectName(QStringLiteral("lineEdit_22"));
        lineEdit_22->setMaximumSize(QSize(40, 16777215));

        gridLayout_2->addWidget(lineEdit_22, 0, 1, 1, 1);

        lineEdit_23 = new QLineEdit(centralWidget);
        lineEdit_23->setObjectName(QStringLiteral("lineEdit_23"));
        lineEdit_23->setMaximumSize(QSize(40, 16777215));

        gridLayout_2->addWidget(lineEdit_23, 0, 2, 1, 1);

        pushButton_23 = new QPushButton(centralWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));

        gridLayout_2->addWidget(pushButton_23, 1, 0, 1, 1);

        lineEdit_24 = new QLineEdit(centralWidget);
        lineEdit_24->setObjectName(QStringLiteral("lineEdit_24"));
        lineEdit_24->setMaximumSize(QSize(40, 16777215));

        gridLayout_2->addWidget(lineEdit_24, 1, 1, 1, 1);

        lineEdit_25 = new QLineEdit(centralWidget);
        lineEdit_25->setObjectName(QStringLiteral("lineEdit_25"));
        lineEdit_25->setMaximumSize(QSize(40, 16777215));

        gridLayout_2->addWidget(lineEdit_25, 1, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(160, 16777215));
        label_5->setFont(font2);

        verticalLayout_4->addWidget(label_5);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        lineEdit_18 = new QLineEdit(centralWidget);
        lineEdit_18->setObjectName(QStringLiteral("lineEdit_18"));
        lineEdit_18->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(lineEdit_18, 1, 1, 1, 1);

        lineEdit_17 = new QLineEdit(centralWidget);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));
        lineEdit_17->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(lineEdit_17, 0, 2, 1, 1);

        pushButton_20 = new QPushButton(centralWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));

        gridLayout->addWidget(pushButton_20, 1, 0, 1, 1);

        lineEdit_16 = new QLineEdit(centralWidget);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(lineEdit_16, 0, 1, 1, 1);

        pushButton_19 = new QPushButton(centralWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(pushButton_19, 0, 0, 1, 1);

        lineEdit_19 = new QLineEdit(centralWidget);
        lineEdit_19->setObjectName(QStringLiteral("lineEdit_19"));
        lineEdit_19->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(lineEdit_19, 1, 2, 1, 1);

        pushButton_21 = new QPushButton(centralWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));

        gridLayout->addWidget(pushButton_21, 2, 0, 1, 1);

        lineEdit_20 = new QLineEdit(centralWidget);
        lineEdit_20->setObjectName(QStringLiteral("lineEdit_20"));
        lineEdit_20->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(lineEdit_20, 2, 1, 1, 1);

        lineEdit_21 = new QLineEdit(centralWidget);
        lineEdit_21->setObjectName(QStringLiteral("lineEdit_21"));
        lineEdit_21->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(lineEdit_21, 2, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalSpacer = new QSpacerItem(190, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer);

        formLayout_5 = new QFormLayout();
        formLayout_5->setSpacing(6);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        pushButton_25 = new QPushButton(centralWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setMaximumSize(QSize(80, 16777215));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, pushButton_25);

        lineEdit_27 = new QLineEdit(centralWidget);
        lineEdit_27->setObjectName(QStringLiteral("lineEdit_27"));
        lineEdit_27->setMaximumSize(QSize(93, 16777215));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, lineEdit_27);


        verticalLayout_4->addLayout(formLayout_5);

        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setMaximumSize(QSize(180, 16777215));

        verticalLayout_4->addWidget(pushButton_16);

        pushButton_26 = new QPushButton(centralWidget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        pushButton_26->setMaximumSize(QSize(180, 16777215));

        verticalLayout_4->addWidget(pushButton_26);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(180, 16777215));

        verticalLayout_4->addWidget(pushButton);

        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMaximumSize(QSize(180, 16777215));

        verticalLayout_4->addWidget(pushButton_12);


        horizontalLayout->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 20));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\262\320\272\320\270", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\321\200\320\265\320\266\320\270\320\274", nullptr));
        lineEdit_4->setText(QApplication::translate("MainWindow", "10", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "w0", nullptr));
        lineEdit_5->setText(QApplication::translate("MainWindow", "55", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\321\203\321\201\321\202. \320\272\321\200\321\203\321\202. \320\274\320\276\320\274.", nullptr));
        lineEdit_2->setText(QApplication::translate("MainWindow", "55", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "t \320\277\320\265\321\200\320\265\320\272\320\273.", nullptr));
        lineEdit_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "t \320\276\321\202\320\272\320\273.", nullptr));
        lineEdit_6->setText(QApplication::translate("MainWindow", "30", nullptr));
        pushButton_24->setText(QApplication::translate("MainWindow", "\320\222\320\275. \320\274\320\276\320\274\320\265\320\275\321\202", nullptr));
        lineEdit_26->setText(QApplication::translate("MainWindow", "255", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 1", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "alpha 1", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "20", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "h1", nullptr));
        lineEdit_7->setText(QApplication::translate("MainWindow", "5", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "k1", nullptr));
        lineEdit_8->setText(QApplication::translate("MainWindow", "1.5", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "x01", nullptr));
        lineEdit_9->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 2", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "alpha 2", nullptr));
        lineEdit_10->setText(QApplication::translate("MainWindow", "30", nullptr));
        pushButton_13->setText(QApplication::translate("MainWindow", "h2", nullptr));
        pushButton_14->setText(QApplication::translate("MainWindow", "k2", nullptr));
        pushButton_15->setText(QApplication::translate("MainWindow", " x02", nullptr));
        lineEdit_11->setText(QApplication::translate("MainWindow", "5", nullptr));
        lineEdit_12->setText(QApplication::translate("MainWindow", "1.5", nullptr));
        lineEdit_13->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\222\320\236\320\241", nullptr));
        pushButton_17->setText(QApplication::translate("MainWindow", "K", nullptr));
        lineEdit_14->setText(QApplication::translate("MainWindow", "150", nullptr));
        pushButton_18->setText(QApplication::translate("MainWindow", "T", nullptr));
        lineEdit_15->setText(QApplication::translate("MainWindow", "2", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\267\320\276\320\262\321\213\320\271 \320\277\320\276\321\200\321\202\321\200\320\265\321\202", nullptr));
        pushButton_22->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\214 \321\205", nullptr));
        lineEdit_22->setText(QApplication::translate("MainWindow", "-100", nullptr));
        lineEdit_23->setText(QApplication::translate("MainWindow", "100", nullptr));
        pushButton_23->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\214 \321\203", nullptr));
        lineEdit_24->setText(QApplication::translate("MainWindow", "-100", nullptr));
        lineEdit_25->setText(QApplication::translate("MainWindow", "100", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\206\320\270\320\273\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
        lineEdit_18->setText(QApplication::translate("MainWindow", "-120", nullptr));
        lineEdit_17->setText(QApplication::translate("MainWindow", "2000", nullptr));
        pushButton_20->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\214 x,y", nullptr));
        lineEdit_16->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButton_19->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\214 t", nullptr));
        lineEdit_19->setText(QApplication::translate("MainWindow", "120", nullptr));
        pushButton_21->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\214 \320\261, F", nullptr));
        lineEdit_20->setText(QApplication::translate("MainWindow", "-120", nullptr));
        lineEdit_21->setText(QApplication::translate("MainWindow", "120", nullptr));
        pushButton_25->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 x0", nullptr));
        pushButton_16->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272\320\270", nullptr));
        pushButton_26->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\241\320\242\320\220\320\240\320\242", nullptr));
        pushButton_12->setText(QApplication::translate("MainWindow", "\320\241\320\242\320\236\320\237", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
