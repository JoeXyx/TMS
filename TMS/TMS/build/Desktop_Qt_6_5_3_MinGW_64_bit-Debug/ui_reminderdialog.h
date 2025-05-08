/********************************************************************************
** Form generated from reading UI file 'reminderdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDERDIALOG_H
#define UI_REMINDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReminderDialog
{
public:
    QListWidget *listReminders;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btnConfirm;
    QPushButton *btnCancel;
    QPushButton *btnAddReminder;
    QPushButton *btnRemoveReminder;
    QLabel *label;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkRemindStart;
    QCheckBox *checkRemindEnd;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinMinutesBefore;
    QLabel *label_2;

    void setupUi(QDialog *ReminderDialog)
    {
        if (ReminderDialog->objectName().isEmpty())
            ReminderDialog->setObjectName("ReminderDialog");
        ReminderDialog->resize(383, 290);
        ReminderDialog->setStyleSheet(QString::fromUtf8("\n"
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
        listReminders = new QListWidget(ReminderDialog);
        listReminders->setObjectName("listReminders");
        listReminders->setGeometry(QRect(70, 120, 221, 91));
        widget = new QWidget(ReminderDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 217, 191, 71));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        btnConfirm = new QPushButton(widget);
        btnConfirm->setObjectName("btnConfirm");

        gridLayout->addWidget(btnConfirm, 0, 0, 1, 1);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 0, 1, 1, 1);

        btnAddReminder = new QPushButton(widget);
        btnAddReminder->setObjectName("btnAddReminder");

        gridLayout->addWidget(btnAddReminder, 1, 0, 1, 1);

        btnRemoveReminder = new QPushButton(widget);
        btnRemoveReminder->setObjectName("btnRemoveReminder");

        gridLayout->addWidget(btnRemoveReminder, 1, 1, 1, 1);

        label = new QLabel(ReminderDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 0, 81, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        label->setFont(font);
        widget_2 = new QWidget(ReminderDialog);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(100, 70, 191, 41));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        checkRemindStart = new QCheckBox(widget_2);
        checkRemindStart->setObjectName("checkRemindStart");

        horizontalLayout->addWidget(checkRemindStart);

        checkRemindEnd = new QCheckBox(widget_2);
        checkRemindEnd->setObjectName("checkRemindEnd");

        horizontalLayout->addWidget(checkRemindEnd);

        widget_3 = new QWidget(ReminderDialog);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(120, 40, 119, 31));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        spinMinutesBefore = new QSpinBox(widget_3);
        spinMinutesBefore->setObjectName("spinMinutesBefore");
        spinMinutesBefore->setMinimum(1);
        spinMinutesBefore->setMaximum(100000);

        horizontalLayout_2->addWidget(spinMinutesBefore);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);


        retranslateUi(ReminderDialog);

        QMetaObject::connectSlotsByName(ReminderDialog);
    } // setupUi

    void retranslateUi(QDialog *ReminderDialog)
    {
        ReminderDialog->setWindowTitle(QCoreApplication::translate("ReminderDialog", "Dialog", nullptr));
        btnConfirm->setText(QCoreApplication::translate("ReminderDialog", "\347\241\256\350\256\244", nullptr));
        btnCancel->setText(QCoreApplication::translate("ReminderDialog", "\345\217\226\346\266\210", nullptr));
        btnAddReminder->setText(QCoreApplication::translate("ReminderDialog", "\346\267\273\345\212\240\346\217\220\351\206\222", nullptr));
        btnRemoveReminder->setText(QCoreApplication::translate("ReminderDialog", "\345\210\240\351\231\244\346\217\220\351\206\222", nullptr));
        label->setText(QCoreApplication::translate("ReminderDialog", "\350\256\276\347\275\256\346\217\220\351\206\222", nullptr));
        checkRemindStart->setText(QCoreApplication::translate("ReminderDialog", "\345\274\200\345\247\213\346\217\220\351\206\222", nullptr));
        checkRemindEnd->setText(QCoreApplication::translate("ReminderDialog", "\347\273\223\346\235\237\346\217\220\351\206\222", nullptr));
        label_2->setText(QCoreApplication::translate("ReminderDialog", "\345\210\206\351\222\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReminderDialog: public Ui_ReminderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDERDIALOG_H
