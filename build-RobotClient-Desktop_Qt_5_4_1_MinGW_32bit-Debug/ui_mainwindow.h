/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *editLocalID;
    QLineEdit *editServerIP;
    QLineEdit *editPort;
    QPushButton *btnConnect;
    QGroupBox *groupBox_2;
    QTextBrowser *txtData;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(349, 477);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/Welcome.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 321, 161));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 81, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 91, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 100, 54, 12));
        editLocalID = new QLineEdit(groupBox);
        editLocalID->setObjectName(QStringLiteral("editLocalID"));
        editLocalID->setGeometry(QRect(120, 30, 181, 20));
        editServerIP = new QLineEdit(groupBox);
        editServerIP->setObjectName(QStringLiteral("editServerIP"));
        editServerIP->setGeometry(QRect(120, 60, 181, 20));
        editPort = new QLineEdit(groupBox);
        editPort->setObjectName(QStringLiteral("editPort"));
        editPort->setGeometry(QRect(120, 90, 181, 20));
        editPort->setAlignment(Qt::AlignCenter);
        btnConnect = new QPushButton(groupBox);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(60, 120, 181, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 170, 321, 231));
        txtData = new QTextBrowser(groupBox_2);
        txtData->setObjectName(QStringLiteral("txtData"));
        txtData->setGeometry(QRect(10, 20, 301, 201));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 349, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\351\200\201\351\244\220\347\263\273\347\273\237\345\256\242\346\210\267\347\253\257", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\275\221\347\273\234\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("MainWindow", "\346\234\254\346\234\272\347\274\226\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\357\274\232", 0));
        editPort->setText(QApplication::translate("MainWindow", "8010", 0));
        btnConnect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\351\242\204\350\247\210", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
