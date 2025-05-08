/********************************************************************************
** Form generated from reading UI file 'focusdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOCUSDIALOG_H
#define UI_FOCUSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FocusDialog
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *progressVBox;
    QWidget *progressContainer;
    QHBoxLayout *quoteLayout;
    QLabel *sloganLabel;
    QSpacerItem *quoteSpacer;
    QLabel *authorLabel;
    QHBoxLayout *controlLayout;
    QLabel *setTimeLabel;
    QSpinBox *spinBox;
    QSpacerItem *timeSpacer;
    QPushButton *beginBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *FocusDialog)
    {
        if (FocusDialog->objectName().isEmpty())
            FocusDialog->setObjectName("FocusDialog");
        FocusDialog->resize(420, 630);
        FocusDialog->setMinimumSize(QSize(420, 630));
        FocusDialog->setMaximumSize(QSize(420, 630));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/assets/tomato.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FocusDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(FocusDialog);
        verticalLayout->setObjectName("verticalLayout");
        progressVBox = new QVBoxLayout();
        progressVBox->setObjectName("progressVBox");
        progressContainer = new QWidget(FocusDialog);
        progressContainer->setObjectName("progressContainer");
        progressContainer->setMinimumSize(QSize(200, 200));

        progressVBox->addWidget(progressContainer);


        verticalLayout->addLayout(progressVBox);

        quoteLayout = new QHBoxLayout();
        quoteLayout->setObjectName("quoteLayout");
        sloganLabel = new QLabel(FocusDialog);
        sloganLabel->setObjectName("sloganLabel");

        quoteLayout->addWidget(sloganLabel);

        quoteSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        quoteLayout->addItem(quoteSpacer);

        authorLabel = new QLabel(FocusDialog);
        authorLabel->setObjectName("authorLabel");

        quoteLayout->addWidget(authorLabel);


        verticalLayout->addLayout(quoteLayout);

        controlLayout = new QHBoxLayout();
        controlLayout->setObjectName("controlLayout");
        setTimeLabel = new QLabel(FocusDialog);
        setTimeLabel->setObjectName("setTimeLabel");

        controlLayout->addWidget(setTimeLabel);

        spinBox = new QSpinBox(FocusDialog);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimum(1);
        spinBox->setMaximum(60);

        controlLayout->addWidget(spinBox);

        timeSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        controlLayout->addItem(timeSpacer);

        beginBtn = new QPushButton(FocusDialog);
        beginBtn->setObjectName("beginBtn");

        controlLayout->addWidget(beginBtn);

        cancelBtn = new QPushButton(FocusDialog);
        cancelBtn->setObjectName("cancelBtn");

        controlLayout->addWidget(cancelBtn);

        controlLayout->setStretch(2, 1);

        verticalLayout->addLayout(controlLayout);

        verticalLayout->setStretch(0, 1);

        retranslateUi(FocusDialog);

        QMetaObject::connectSlotsByName(FocusDialog);
    } // setupUi

    void retranslateUi(QDialog *FocusDialog)
    {
        FocusDialog->setWindowTitle(QCoreApplication::translate("FocusDialog", "\346\254\242\350\277\216\344\275\277\347\224\250\344\270\223\346\263\250\346\250\241\345\274\217", nullptr));
        sloganLabel->setText(QCoreApplication::translate("FocusDialog", "\345\220\215\344\272\272\345\220\215\350\250\200", nullptr));
        authorLabel->setText(QCoreApplication::translate("FocusDialog", "\342\200\224\342\200\224 \344\275\234\350\200\205", nullptr));
        setTimeLabel->setText(QCoreApplication::translate("FocusDialog", "\344\270\223\346\263\250\345\210\206\351\222\237\346\225\260\357\274\232", nullptr));
        beginBtn->setText(QCoreApplication::translate("FocusDialog", "\345\274\200\345\247\213", nullptr));
        cancelBtn->setText(QCoreApplication::translate("FocusDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FocusDialog: public Ui_FocusDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOCUSDIALOG_H
