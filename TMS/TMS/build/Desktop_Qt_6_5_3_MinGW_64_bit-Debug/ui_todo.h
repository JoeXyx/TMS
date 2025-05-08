/********************************************************************************
** Form generated from reading UI file 'todo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODO_H
#define UI_TODO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_todo
{
public:
    QPushButton *todo_show;
    QWidget *widget;
    QGridLayout *gridLayout;
    QTableWidget *quicktodo;
    QTableWidget *slowtodo;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *quick_doing;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *slow_doing;

    void setupUi(QWidget *todo)
    {
        if (todo->objectName().isEmpty())
            todo->setObjectName("todo");
        todo->resize(643, 410);
        todo->setStyleSheet(QString::fromUtf8("\n"
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
        todo_show = new QPushButton(todo);
        todo_show->setObjectName("todo_show");
        todo_show->setGeometry(QRect(290, 380, 56, 21));
        widget = new QWidget(todo);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 70, 601, 301));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        quicktodo = new QTableWidget(widget);
        quicktodo->setObjectName("quicktodo");
        quicktodo->horizontalHeader()->setVisible(false);

        gridLayout->addWidget(quicktodo, 0, 0, 1, 1);

        slowtodo = new QTableWidget(widget);
        slowtodo->setObjectName("slowtodo");
        slowtodo->horizontalHeader()->setVisible(false);
        slowtodo->verticalHeader()->setVisible(false);

        gridLayout->addWidget(slowtodo, 0, 1, 1, 1);

        widget_2 = new QWidget(todo);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(20, 20, 591, 47));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        quick_doing = new QLineEdit(widget_2);
        quick_doing->setObjectName("quick_doing");

        gridLayout_2->addWidget(quick_doing, 1, 1, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 2, 1, 2);

        label = new QLabel(widget_2);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        slow_doing = new QLineEdit(widget_2);
        slow_doing->setObjectName("slow_doing");

        gridLayout_2->addWidget(slow_doing, 1, 4, 1, 1);


        retranslateUi(todo);

        QMetaObject::connectSlotsByName(todo);
    } // setupUi

    void retranslateUi(QWidget *todo)
    {
        todo->setWindowTitle(QCoreApplication::translate("todo", "Form", nullptr));
        todo_show->setText(QCoreApplication::translate("todo", "\346\230\276\347\244\272", nullptr));
        label_2->setText(QCoreApplication::translate("todo", "\344\270\215\351\202\243\344\271\210\347\264\247\346\200\245\347\232\204\344\273\273\345\212\241\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("todo", "\351\234\200\350\246\201\345\260\275\345\277\253\345\256\214\346\210\220\347\232\204\344\273\273\345\212\241\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class todo: public Ui_todo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODO_H
