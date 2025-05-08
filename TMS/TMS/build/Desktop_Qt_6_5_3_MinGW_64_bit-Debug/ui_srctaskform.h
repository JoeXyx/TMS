/********************************************************************************
** Form generated from reading UI file 'srctaskform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SRCTASKFORM_H
#define UI_SRCTASKFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SrcTaskForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *opt_pushButton;
    QPushButton *opt_pushButton_2;
    QPushButton *opt_pushButton_3;
    QPushButton *opt_pushButton_4;
    QPushButton *opt_pushButton_5;
    QPushButton *opt_pushButton_6;
    QPushButton *opt_pushButton_7;
    QPushButton *opt_pushButton_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *SrcTaskForm)
    {
        if (SrcTaskForm->objectName().isEmpty())
            SrcTaskForm->setObjectName("SrcTaskForm");
        SrcTaskForm->resize(391, 367);
        SrcTaskForm->setStyleSheet(QString::fromUtf8("\n"
"    QWidget {\n"
"        font-family: \"Microsoft YaHei\";\n"
"        font-size: 14px;\n"
"        color: #333333;\n"
"        background-color: #f7f9fb;\n"
"    }\n"
"\n"
"    QPushButton {\n"
"        background-color: #e6f1ff;\n"
"        color: #000000;\n"
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
        verticalLayoutWidget = new QWidget(SrcTaskForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 371, 352));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setBold(false);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        opt_pushButton = new QPushButton(verticalLayoutWidget);
        opt_pushButton->setObjectName("opt_pushButton");
        opt_pushButton->setFont(font);

        verticalLayout->addWidget(opt_pushButton);

        opt_pushButton_2 = new QPushButton(verticalLayoutWidget);
        opt_pushButton_2->setObjectName("opt_pushButton_2");
        opt_pushButton_2->setFont(font);

        verticalLayout->addWidget(opt_pushButton_2);

        opt_pushButton_3 = new QPushButton(verticalLayoutWidget);
        opt_pushButton_3->setObjectName("opt_pushButton_3");
        opt_pushButton_3->setFont(font);

        verticalLayout->addWidget(opt_pushButton_3);

        opt_pushButton_4 = new QPushButton(verticalLayoutWidget);
        opt_pushButton_4->setObjectName("opt_pushButton_4");
        opt_pushButton_4->setFont(font);

        verticalLayout->addWidget(opt_pushButton_4);

        opt_pushButton_5 = new QPushButton(verticalLayoutWidget);
        opt_pushButton_5->setObjectName("opt_pushButton_5");
        opt_pushButton_5->setFont(font);

        verticalLayout->addWidget(opt_pushButton_5);

        opt_pushButton_6 = new QPushButton(verticalLayoutWidget);
        opt_pushButton_6->setObjectName("opt_pushButton_6");
        opt_pushButton_6->setFont(font);

        verticalLayout->addWidget(opt_pushButton_6);

        opt_pushButton_7 = new QPushButton(verticalLayoutWidget);
        opt_pushButton_7->setObjectName("opt_pushButton_7");
        opt_pushButton_7->setFont(font);

        verticalLayout->addWidget(opt_pushButton_7);

        opt_pushButton_8 = new QPushButton(verticalLayoutWidget);
        opt_pushButton_8->setObjectName("opt_pushButton_8");
        opt_pushButton_8->setFont(font);

        verticalLayout->addWidget(opt_pushButton_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SrcTaskForm);

        QMetaObject::connectSlotsByName(SrcTaskForm);
    } // setupUi

    void retranslateUi(QWidget *SrcTaskForm)
    {
        SrcTaskForm->setWindowTitle(QCoreApplication::translate("SrcTaskForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("SrcTaskForm", "\350\257\267\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\344\272\213\345\212\241\346\240\207\351\242\230\357\274\232", nullptr));
        opt_pushButton->setText(QString());
        opt_pushButton_2->setText(QString());
        opt_pushButton_3->setText(QString());
        opt_pushButton_4->setText(QString());
        opt_pushButton_5->setText(QString());
        opt_pushButton_6->setText(QString());
        opt_pushButton_7->setText(QString());
        opt_pushButton_8->setText(QString());
        pushButton->setText(QCoreApplication::translate("SrcTaskForm", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SrcTaskForm", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SrcTaskForm: public Ui_SrcTaskForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SRCTASKFORM_H
