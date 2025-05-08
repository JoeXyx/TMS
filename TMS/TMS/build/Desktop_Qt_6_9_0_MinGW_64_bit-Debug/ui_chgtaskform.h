/********************************************************************************
** Form generated from reading UI file 'chgtaskform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHGTASKFORM_H
#define UI_CHGTASKFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chgTaskForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *title_lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *label_11;
    QSpinBox *st_spinBox;
    QLabel *label_3;
    QSpinBox *st_spinBox_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *label_12;
    QSpinBox *et_spinBox;
    QLabel *label_13;
    QSpinBox *et_spinBox_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QRadioButton *low_radioButton;
    QRadioButton *medium_radioButton;
    QRadioButton *high_radioButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QRadioButton *pending_radioButton;
    QRadioButton *in_progress_radioButton;
    QRadioButton *completed_radioButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLabel *label_14;
    QSpinBox *year_spinBox;
    QLabel *label_15;
    QSpinBox *month_spinBox;
    QLabel *label_16;
    QSpinBox *day_spinBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QWidget *chgTaskForm)
    {
        if (chgTaskForm->objectName().isEmpty())
            chgTaskForm->setObjectName("chgTaskForm");
        chgTaskForm->resize(698, 541);
        verticalLayoutWidget = new QWidget(chgTaskForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 681, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout_10->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        title_lineEdit = new QLineEdit(verticalLayoutWidget);
        title_lineEdit->setObjectName("title_lineEdit");

        horizontalLayout_4->addWidget(title_lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName("label_11");

        horizontalLayout_5->addWidget(label_11);

        st_spinBox = new QSpinBox(verticalLayoutWidget);
        st_spinBox->setObjectName("st_spinBox");
        st_spinBox->setMinimum(0);
        st_spinBox->setMaximum(23);

        horizontalLayout_5->addWidget(st_spinBox);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        st_spinBox_2 = new QSpinBox(verticalLayoutWidget);
        st_spinBox_2->setObjectName("st_spinBox_2");
        st_spinBox_2->setMaximum(59);

        horizontalLayout_5->addWidget(st_spinBox_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName("label_12");

        horizontalLayout_6->addWidget(label_12);

        et_spinBox = new QSpinBox(verticalLayoutWidget);
        et_spinBox->setObjectName("et_spinBox");
        et_spinBox->setMinimum(0);
        et_spinBox->setMaximum(23);

        horizontalLayout_6->addWidget(et_spinBox);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName("label_13");

        horizontalLayout_6->addWidget(label_13);

        et_spinBox_2 = new QSpinBox(verticalLayoutWidget);
        et_spinBox_2->setObjectName("et_spinBox_2");
        et_spinBox_2->setMaximum(59);

        horizontalLayout_6->addWidget(et_spinBox_2);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_8->addWidget(label_7);

        low_radioButton = new QRadioButton(verticalLayoutWidget);
        buttonGroup = new QButtonGroup(chgTaskForm);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(low_radioButton);
        low_radioButton->setObjectName("low_radioButton");

        horizontalLayout_8->addWidget(low_radioButton);

        medium_radioButton = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(medium_radioButton);
        medium_radioButton->setObjectName("medium_radioButton");

        horizontalLayout_8->addWidget(medium_radioButton);

        high_radioButton = new QRadioButton(verticalLayoutWidget);
        buttonGroup->addButton(high_radioButton);
        high_radioButton->setObjectName("high_radioButton");

        horizontalLayout_8->addWidget(high_radioButton);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");

        horizontalLayout_7->addWidget(label_8);

        pending_radioButton = new QRadioButton(verticalLayoutWidget);
        buttonGroup_2 = new QButtonGroup(chgTaskForm);
        buttonGroup_2->setObjectName("buttonGroup_2");
        buttonGroup_2->addButton(pending_radioButton);
        pending_radioButton->setObjectName("pending_radioButton");

        horizontalLayout_7->addWidget(pending_radioButton);

        in_progress_radioButton = new QRadioButton(verticalLayoutWidget);
        buttonGroup_2->addButton(in_progress_radioButton);
        in_progress_radioButton->setObjectName("in_progress_radioButton");

        horizontalLayout_7->addWidget(in_progress_radioButton);

        completed_radioButton = new QRadioButton(verticalLayoutWidget);
        buttonGroup_2->addButton(completed_radioButton);
        completed_radioButton->setObjectName("completed_radioButton");

        horizontalLayout_7->addWidget(completed_radioButton);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName("label_10");

        horizontalLayout_2->addWidget(label_10);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName("label_14");

        horizontalLayout_2->addWidget(label_14);

        year_spinBox = new QSpinBox(verticalLayoutWidget);
        year_spinBox->setObjectName("year_spinBox");
        year_spinBox->setMinimum(2025);
        year_spinBox->setMaximum(2075);

        horizontalLayout_2->addWidget(year_spinBox);

        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName("label_15");

        horizontalLayout_2->addWidget(label_15);

        month_spinBox = new QSpinBox(verticalLayoutWidget);
        month_spinBox->setObjectName("month_spinBox");
        month_spinBox->setMinimum(1);
        month_spinBox->setMaximum(12);

        horizontalLayout_2->addWidget(month_spinBox);

        label_16 = new QLabel(verticalLayoutWidget);
        label_16->setObjectName("label_16");

        horizontalLayout_2->addWidget(label_16);

        day_spinBox = new QSpinBox(verticalLayoutWidget);
        day_spinBox->setObjectName("day_spinBox");
        day_spinBox->setMinimum(1);
        day_spinBox->setMaximum(31);

        horizontalLayout_2->addWidget(day_spinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");

        horizontalLayout_9->addWidget(label_9);


        verticalLayout->addLayout(horizontalLayout_9);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(chgTaskForm);

        QMetaObject::connectSlotsByName(chgTaskForm);
    } // setupUi

    void retranslateUi(QWidget *chgTaskForm)
    {
        chgTaskForm->setWindowTitle(QCoreApplication::translate("chgTaskForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("chgTaskForm", "\350\257\267\350\276\223\345\205\245\350\246\201\346\267\273\345\212\240\344\272\213\344\273\266\347\232\204\344\277\241\346\201\257\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("chgTaskForm", "title:", nullptr));
        label_5->setText(QCoreApplication::translate("chgTaskForm", "start_time:", nullptr));
        label_11->setText(QCoreApplication::translate("chgTaskForm", "hour:", nullptr));
        label_3->setText(QCoreApplication::translate("chgTaskForm", "minute:", nullptr));
        label_6->setText(QCoreApplication::translate("chgTaskForm", "end_time:", nullptr));
        label_12->setText(QCoreApplication::translate("chgTaskForm", "hour:", nullptr));
        label_13->setText(QCoreApplication::translate("chgTaskForm", "minute:", nullptr));
        label_7->setText(QCoreApplication::translate("chgTaskForm", "priority:", nullptr));
        low_radioButton->setText(QCoreApplication::translate("chgTaskForm", "low", nullptr));
        medium_radioButton->setText(QCoreApplication::translate("chgTaskForm", "medium", nullptr));
        high_radioButton->setText(QCoreApplication::translate("chgTaskForm", "high", nullptr));
        label_8->setText(QCoreApplication::translate("chgTaskForm", "status:", nullptr));
        pending_radioButton->setText(QCoreApplication::translate("chgTaskForm", "pending", nullptr));
        in_progress_radioButton->setText(QCoreApplication::translate("chgTaskForm", "in progress", nullptr));
        completed_radioButton->setText(QCoreApplication::translate("chgTaskForm", "completed", nullptr));
        label_10->setText(QCoreApplication::translate("chgTaskForm", "date:", nullptr));
        label_14->setText(QCoreApplication::translate("chgTaskForm", "year:", nullptr));
        label_15->setText(QCoreApplication::translate("chgTaskForm", "month:", nullptr));
        label_16->setText(QCoreApplication::translate("chgTaskForm", "day:", nullptr));
        label_9->setText(QCoreApplication::translate("chgTaskForm", "description:", nullptr));
        pushButton->setText(QCoreApplication::translate("chgTaskForm", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("chgTaskForm", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chgTaskForm: public Ui_chgTaskForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHGTASKFORM_H
