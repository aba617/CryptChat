/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed May 14 08:56:16 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listoffriends;
    QLabel *friends;
    QWidget *convowidget;
    QPushButton *addfriend;
    QPushButton *logoffbutton;
    QPushButton *helpbutton;
    QLabel *thisusr;
    QLineEdit *friendtoadd;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(497, 668);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listoffriends = new QListWidget(centralwidget);
        listoffriends->setObjectName(QString::fromUtf8("listoffriends"));
        listoffriends->setGeometry(QRect(10, 140, 101, 281));
        sizePolicy.setHeightForWidth(listoffriends->sizePolicy().hasHeightForWidth());
        listoffriends->setSizePolicy(sizePolicy);
        listoffriends->setLayoutDirection(Qt::LeftToRight);
        listoffriends->setMovement(QListView::Free);
        listoffriends->setFlow(QListView::TopToBottom);
        listoffriends->setResizeMode(QListView::Adjust);
        listoffriends->setLayoutMode(QListView::Batched);
        listoffriends->setSpacing(1);
        listoffriends->setModelColumn(0);
        friends = new QLabel(centralwidget);
        friends->setObjectName(QString::fromUtf8("friends"));
        friends->setGeometry(QRect(20, 100, 71, 20));
        sizePolicy.setHeightForWidth(friends->sizePolicy().hasHeightForWidth());
        friends->setSizePolicy(sizePolicy);
        convowidget = new QWidget(centralwidget);
        convowidget->setObjectName(QString::fromUtf8("convowidget"));
        convowidget->setGeometry(QRect(120, 60, 361, 521));
        sizePolicy.setHeightForWidth(convowidget->sizePolicy().hasHeightForWidth());
        convowidget->setSizePolicy(sizePolicy);
        convowidget->setAutoFillBackground(false);
        convowidget->setStyleSheet(QString::fromUtf8("border-color: rgb(45, 45, 45);\n"
"\n"
""));
        addfriend = new QPushButton(centralwidget);
        addfriend->setObjectName(QString::fromUtf8("addfriend"));
        addfriend->setGeometry(QRect(10, 60, 85, 27));
        sizePolicy.setHeightForWidth(addfriend->sizePolicy().hasHeightForWidth());
        addfriend->setSizePolicy(sizePolicy);
        logoffbutton = new QPushButton(centralwidget);
        logoffbutton->setObjectName(QString::fromUtf8("logoffbutton"));
        logoffbutton->setGeometry(QRect(434, 0, 51, 27));
        sizePolicy.setHeightForWidth(logoffbutton->sizePolicy().hasHeightForWidth());
        logoffbutton->setSizePolicy(sizePolicy);
        helpbutton = new QPushButton(centralwidget);
        helpbutton->setObjectName(QString::fromUtf8("helpbutton"));
        helpbutton->setGeometry(QRect(230, 0, 85, 27));
        sizePolicy.setHeightForWidth(helpbutton->sizePolicy().hasHeightForWidth());
        helpbutton->setSizePolicy(sizePolicy);
        thisusr = new QLabel(centralwidget);
        thisusr->setObjectName(QString::fromUtf8("thisusr"));
        thisusr->setGeometry(QRect(350, 0, 81, 21));
        sizePolicy.setHeightForWidth(thisusr->sizePolicy().hasHeightForWidth());
        thisusr->setSizePolicy(sizePolicy);
        thisusr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        friendtoadd = new QLineEdit(centralwidget);
        friendtoadd->setObjectName(QString::fromUtf8("friendtoadd"));
        friendtoadd->setGeometry(QRect(10, 30, 113, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 131, 16));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        friends->setText(QApplication::translate("MainWindow", "  Friend List  ", 0, QApplication::UnicodeUTF8));
        addfriend->setText(QApplication::translate("MainWindow", "+ Add Friend", 0, QApplication::UnicodeUTF8));
        logoffbutton->setText(QApplication::translate("MainWindow", "Log Off", 0, QApplication::UnicodeUTF8));
        helpbutton->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        thisusr->setText(QString());
        label->setText(QApplication::translate("MainWindow", "   Enter a New Friend!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
