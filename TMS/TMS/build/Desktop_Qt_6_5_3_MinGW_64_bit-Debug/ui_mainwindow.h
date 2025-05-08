/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *delTaskButton;
    QPushButton *delTaskButton_2;
    QPushButton *srcTaskButton;
    QPushButton *srcChgButton;
    QPushButton *addTaskButton;
    QPushButton *tdlistButton;
    QPushButton *chgTaskButton;
    QPushButton *concentrateBtn;
    QLabel *label;
    QCalendarWidget *calendarWidget;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(490, 600);
        MainWindow->setMinimumSize(QSize(490, 600));
        MainWindow->setMaximumSize(QSize(490, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/C:/Users/13677/Downloads/20250506_2335_\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237\345\233\276\346\240\207_simple_compose_01jtk3rb2reex8ecbp5vwkpme8.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QWidget {\n"
"    font-family: \"Microsoft YaHei\";\n"
"    font-size: 12pt;\n"
"    font-weight: normal;\n"
"background-color: rgb(223, 230, 233);\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 481, 91));
        widget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #f3f3f3;\n"
"    color: black;\n"
"    border: none;\n"
"      border-radius: 10px;\n"
"     padding: 8px 16px;\n"
"      font-size: 14px;\n"
"    }\n"
"    QPushButton:hover {\n"
"     background-color: #bababa;\n"
"    }\n"
"    QPushButton:pressed {\n"
"      background-color: #858585;\n"
"    }"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        delTaskButton = new QPushButton(widget);
        delTaskButton->setObjectName("delTaskButton");

        gridLayout->addWidget(delTaskButton, 0, 3, 1, 1);

        delTaskButton_2 = new QPushButton(widget);
        delTaskButton_2->setObjectName("delTaskButton_2");

        gridLayout->addWidget(delTaskButton_2, 2, 3, 1, 1);

        srcTaskButton = new QPushButton(widget);
        srcTaskButton->setObjectName("srcTaskButton");

        gridLayout->addWidget(srcTaskButton, 2, 1, 1, 1);

        srcChgButton = new QPushButton(widget);
        srcChgButton->setObjectName("srcChgButton");

        gridLayout->addWidget(srcChgButton, 2, 4, 1, 1);

        addTaskButton = new QPushButton(widget);
        addTaskButton->setObjectName("addTaskButton");

        gridLayout->addWidget(addTaskButton, 0, 1, 1, 1);

        tdlistButton = new QPushButton(widget);
        tdlistButton->setObjectName("tdlistButton");

        gridLayout->addWidget(tdlistButton, 0, 0, 1, 1);

        chgTaskButton = new QPushButton(widget);
        chgTaskButton->setObjectName("chgTaskButton");

        gridLayout->addWidget(chgTaskButton, 0, 4, 1, 1);

        concentrateBtn = new QPushButton(widget);
        concentrateBtn->setObjectName("concentrateBtn");

        gridLayout->addWidget(concentrateBtn, 0, 5, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font-size:10px;"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 5, 1, 1);

        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(10, 100, 469, 261));
        calendarWidget->setStyleSheet(QString::fromUtf8("\n"
"/* \346\225\264\344\275\223\345\244\226\350\247\202 */\n"
"QCalendarWidget {\n"
"    background-color: #fefefe;\n"
"    border: 10px solid #8e8e8e;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"/* \351\241\266\351\203\250\345\257\274\350\210\252\346\240\217\350\203\214\346\231\257 */\n"
"QWidget#qt_calendar_navigationbar {\n"
"    background-color: #2c3e50;\n"
"    border-top-left-radius: 10px;\n"
"    border-top-right-radius: 10px;\n"
"}\n"
"\n"
"/* \345\271\264\346\234\210\345\210\207\346\215\242\346\214\211\351\222\256 */\n"
"QCalendarWidget QToolButton {\n"
"    font-size: 18px;\n"
"    color: #ffffff;\n"
"    background-color:#2c3e50;\n"
"    border-radius: 6px;\n"
"    padding: 5px;\n"
"}\n"
"QCalendarWidget QAbstractItemView {\n"
"    font-size: 16px;\n"
"    selection-background-color: #6BBE92;\n"
"}\n"
"\n"
"\n"
"QCalendarWidget QToolButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\350\217\234\345\215\225\357\274\210\351\200\211\346\213\251\346\234\210\344"
                        "\273\275\345\222\214\345\271\264\344\273\275\357\274\211 */\n"
"QCalendarWidget QMenu {\n"
"    background-color: white;\n"
"    border: 1px solid #bbb;\n"
"    padding: 5px;\n"
"}\n"
"\n"
" \346\227\245\346\234\237\350\241\250\346\240\274\345\255\227\344\275\223\344\270\216\351\242\234\350\211\262 \n"
"QCalendarWidget QAbstractItemView {\n"
"    selection-background-color: #3498db;\n"
"    selection-color: white;\n"
"    font-size: 14px;\n"
"    gridline-color: #e0e0e0;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"QCalendarWidget QAbstractItemView::item:hover {\n"
"    background-color: #ecf0f1;\n"
"}\n"
"\n"
"/* \346\227\240\346\225\210\346\227\245\346\234\237\357\274\210\344\270\212\346\234\210/\344\270\213\346\234\210\347\232\204\347\201\260\350\211\262\346\225\260\345\255\227\357\274\211 */\n"
"QCalendarWidget QAbstractItemView::item:disabled {\n"
"    color: #bdc3c7;\n"
"}\n"
"\n"
"/* \345\275\223\345\211\215\351\200\211\344\270\255\347\232\204\346\227"
                        "\245\346\234\237 */\n"
"QCalendarWidget QAbstractItemView::item:selected {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* \344\273\212\346\227\245\351\253\230\344\272\256\357\274\210\351\200\232\350\277\207 QTextCharFormat \346\233\264\347\262\276\347\273\206\346\216\247\345\210\266\357\274\211 *"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 20)
            tableWidget->setRowCount(20);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 370, 469, 221));
        tableWidget->setStyleSheet(QString::fromUtf8("\n"
"/* \346\225\264\344\275\223\350\276\271\346\241\206\344\270\216\350\203\214\346\231\257 */\n"
"QTableWidget {\n"
"    background-color:#ffffff;\n"
"    border: 5px solid #dcdcdc;\n"
"    gridline-color: #e0e0e0;\n"
"    font-size: 14px;\n"
"    selection-background-color: #3498db;\n"
"    selection-color: #ffffff;\n"
"}\n"
"\n"
"/* \350\241\250\345\244\264\357\274\210horizontalHeader\357\274\211 */\n"
"QHeaderView::section {\n"
"    background-color: #2c3e50;\n"
"    color: white;\n"
"    padding: 6px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234\345\215\225\345\205\203\346\240\274\357\274\210\346\227\240\351\200\211\344\270\255\346\227\266\357\274\211 */\n"
"QTableWidget::item:hover {\n"
"    background-color: #f1f1f1;\n"
"}\n"
"\n"
"/* \345\215\225\345\205\203\346\240\274\351\200\211\344\270\255\346\240\267\345\274\217 */\n"
"QTableWidget::item:selected {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"}\n"
"\n"
"/* \345"
                        "\216\273\346\216\211\347\204\246\347\202\271\350\231\232\347\272\277\350\276\271\346\241\206 */\n"
"QTableWidget::focus {\n"
"    outline: none;\n"
"}\n"
"\n"
"/* \346\273\232\345\212\250\346\235\241\350\203\214\346\231\257 */\n"
"QScrollBar:vertical {\n"
"    background: #f0f0f0;\n"
"    width: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"/* \346\273\232\345\212\250\346\235\241\346\273\221\345\235\227 */\n"
"QScrollBar::handle:vertical {\n"
"    background: #b1b1b1;\n"
"    min-height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/* \346\273\232\345\212\250\346\235\241\346\273\221\345\235\227\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #2980b9;\n"
"}\n"
"\n"
"/* \344\270\212\347\256\255\345\244\264 */\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"/* \344\270\213\347\256\255\345\244\264 */\n"
"QScrollBar::add-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"/* \345\211\251\344\275\231\345\214\272\345\237"
                        "\237 */\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"/* \346\250\252\345\220\221\346\273\232\345\212\250\346\235\241\345\220\214\347\220\206 */\n"
"QScrollBar:horizontal {\n"
"    background: #f0f0f0;\n"
"    height: 10px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #b1b1b1;\n"
"    min-width: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #2980b9;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal,\n"
"QScrollBar::add-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}"));
        tableWidget->setRowCount(20);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\244\247\345\255\246\347\224\237\346\227\266\351\227\264\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "TO-DO", nullptr));
        delTaskButton->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\345\210\240\351\231\244", nullptr));
        delTaskButton_2->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\345\210\240\351\231\244", nullptr));
        srcTaskButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\344\272\213\345\212\241", nullptr));
        srcChgButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\344\277\256\346\224\271", nullptr));
        addTaskButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\272\213\345\212\241", nullptr));
        tdlistButton->setText(QCoreApplication::translate("MainWindow", "TDLIst", nullptr));
        chgTaskButton->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\344\277\256\346\224\271", nullptr));
        concentrateBtn->setText(QCoreApplication::translate("MainWindow", "\344\270\223\346\263\250\346\250\241\345\274\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\217\214\345\207\273\344\272\213\344\273\266\n"
"\346\267\273\345\212\240\346\217\220\351\206\222", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\344\272\213\345\212\241\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\344\272\213\345\212\241\346\240\207\351\242\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\344\274\230\345\205\210\347\272\247", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\344\272\213\345\212\241\347\212\266\346\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\344\272\213\345\212\241\346\217\217\350\277\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
