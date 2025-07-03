/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *labelDistance;
    QPushButton *buttonFindPath;
    QTextBrowser *textBrowserLength;
    QTextBrowser *textBrowserPath;
    QGraphicsView *graphicsView;
    QComboBox *comboBoxStart;
    QLabel *labelStart;
    QComboBox *comboBoxEnd;
    QLabel *labelEnd;
    QLabel *labelPath;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1364, 679);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        labelDistance = new QLabel(centralwidget);
        labelDistance->setObjectName("labelDistance");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(11);
        labelDistance->setFont(font);

        gridLayout->addWidget(labelDistance, 4, 0, 1, 1);

        buttonFindPath = new QPushButton(centralwidget);
        buttonFindPath->setObjectName("buttonFindPath");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        buttonFindPath->setFont(font1);
        buttonFindPath->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e0e0e0;\n"
"    border: 1px solid #a0a0a0;\n"
"    padding: 5px 10px;\n"
"    font-size: 17px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #d0d0d0;\n"
"}\n"
""));

        gridLayout->addWidget(buttonFindPath, 2, 0, 1, 2);

        textBrowserLength = new QTextBrowser(centralwidget);
        textBrowserLength->setObjectName("textBrowserLength");
        textBrowserLength->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #b0b0b0;\n"
"    padding: 6px;\n"
"    font-size: 13px;\n"
"}\n"
""));

        gridLayout->addWidget(textBrowserLength, 4, 1, 1, 1);

        textBrowserPath = new QTextBrowser(centralwidget);
        textBrowserPath->setObjectName("textBrowserPath");
        textBrowserPath->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #b0b0b0;\n"
"    padding: 6px;\n"
"    font-size: 13px;\n"
"}\n"
""));

        gridLayout->addWidget(textBrowserPath, 3, 1, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 2, 5, 1);

        comboBoxStart = new QComboBox(centralwidget);
        comboBoxStart->setObjectName("comboBoxStart");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Titillium Web")});
        comboBoxStart->setFont(font2);
        comboBoxStart->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #e0e0e0;     \n"
"    border: 1px solid #a0a0a0;   \n"
"    padding: 4px;\n"
"    font-size: 13px;\n"
"}\n"
""));

        gridLayout->addWidget(comboBoxStart, 0, 1, 1, 1);

        labelStart = new QLabel(centralwidget);
        labelStart->setObjectName("labelStart");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setItalic(false);
        labelStart->setFont(font3);

        gridLayout->addWidget(labelStart, 0, 0, 1, 1);

        comboBoxEnd = new QComboBox(centralwidget);
        comboBoxEnd->setObjectName("comboBoxEnd");
        comboBoxEnd->setFont(font2);
        comboBoxEnd->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #e0e0e0;     \n"
"    border: 1px solid #a0a0a0;   \n"
"    padding: 4px;\n"
"    font-size: 13px;\n"
"}\n"
""));

        gridLayout->addWidget(comboBoxEnd, 1, 1, 1, 1);

        labelEnd = new QLabel(centralwidget);
        labelEnd->setObjectName("labelEnd");
        labelEnd->setFont(font3);

        gridLayout->addWidget(labelEnd, 1, 0, 1, 1);

        labelPath = new QLabel(centralwidget);
        labelPath->setObjectName("labelPath");
        labelPath->setFont(font);

        gridLayout->addWidget(labelPath, 3, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setFont(font1);
        label->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        gridLayout->addWidget(label, 5, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1364, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Aplikacj Miasta Trasa", nullptr));
        labelDistance->setText(QCoreApplication::translate("MainWindow", "D\305\202ugo\305\233\304\207 trasy:", nullptr));
        buttonFindPath->setText(QCoreApplication::translate("MainWindow", "Znajd\305\272 tras\304\231", nullptr));
        labelStart->setText(QCoreApplication::translate("MainWindow", "Miasto pocz\304\205tkowe:", nullptr));
        labelEnd->setText(QCoreApplication::translate("MainWindow", "Miasto ko\305\204cowe:", nullptr));
        labelPath->setText(QCoreApplication::translate("MainWindow", "Najkr\303\263tsza trasa:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Autor: Aleksandra Konopelska", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
