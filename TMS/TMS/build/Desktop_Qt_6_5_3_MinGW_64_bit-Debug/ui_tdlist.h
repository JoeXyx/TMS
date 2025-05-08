/********************************************************************************
** Form generated from reading UI file 'tdlist.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TDLIST_H
#define UI_TDLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tdlist
{
public:
    QLabel *label_2;
    QLabel *label;
    QPushButton *td_del;
    QLineEdit *tname;
    QDateEdit *td_ddl;
    QTableWidget *tdl_weight;
    QPushButton *td_add;

    void setupUi(QWidget *tdlist)
    {
        if (tdlist->objectName().isEmpty())
            tdlist->setObjectName("tdlist");
        tdlist->resize(488, 337);
        tdlist->setStyleSheet(QString::fromUtf8("\n"
"    QWidget {\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-size: 14px;\n"
"        color: #333333;\n"
"        background-color: #f7f9fb;\n"
"    }\n"
"\n"
"    QPushButton {\n"
"        background-color: #4CAF50;\n"
"        color: white;\n"
"        padding: 6px 12px;\n"
"        border: none;\n"
"        border-radius: 4px;\n"
"    }\n"
"\n"
"    QPushButton:hover {\n"
"        background-color: #45a049;\n"
"    }\n"
"\n"
"    QLineEdit {\n"
"        border: 1px solid #ccc;\n"
"        padding: 4px;\n"
"        border-radius: 4px;\n"
"        background-color: #ffffff;\n"
"    }\n"
"\n"
"    QLabel {\n"
"        color: #2c3e50;\n"
"    }\n"
"\n"
"    QTableWidget {\n"
"        background-color: white;\n"
"        gridline-color: #dcdcdc;\n"
"        selection-background-color: #cceeff;\n"
"    }\n"
"\n"
"    QHeaderView::section {\n"
"        background-color: #e0e0e0;\n"
"        padding: 4px;\n"
"        border: 1px solid #dcdcdc;\n"
"    }"));
        label_2 = new QLabel(tdlist);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 70, 101, 16));
        label = new QLabel(tdlist);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 30, 71, 16));
        td_del = new QPushButton(tdlist);
        td_del->setObjectName("td_del");
        td_del->setGeometry(QRect(370, 110, 91, 31));
        tname = new QLineEdit(tdlist);
        tname->setObjectName("tname");
        tname->setGeometry(QRect(350, 30, 113, 20));
        td_ddl = new QDateEdit(tdlist);
        td_ddl->setObjectName("td_ddl");
        td_ddl->setGeometry(QRect(350, 70, 121, 21));
        tdl_weight = new QTableWidget(tdlist);
        tdl_weight->setObjectName("tdl_weight");
        tdl_weight->setGeometry(QRect(10, 10, 231, 311));
        td_add = new QPushButton(tdlist);
        td_add->setObjectName("td_add");
        td_add->setGeometry(QRect(250, 110, 91, 31));

        retranslateUi(tdlist);

        QMetaObject::connectSlotsByName(tdlist);
    } // setupUi

    void retranslateUi(QWidget *tdlist)
    {
        tdlist->setWindowTitle(QCoreApplication::translate("tdlist", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("tdlist", "\344\273\273\345\212\241\346\210\252\346\255\242\346\227\245\346\234\237\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("tdlist", "\344\273\273\345\212\241\345\220\215\357\274\232", nullptr));
        td_del->setText(QCoreApplication::translate("tdlist", "\345\210\240\351\231\244", nullptr));
        td_add->setText(QCoreApplication::translate("tdlist", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tdlist: public Ui_tdlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TDLIST_H
