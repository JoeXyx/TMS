#include "srcchgform.h"
#include "ui_srcchgform.h"
#include "bst.h"

//取得可选框中要显示的标题
void get_strlist_3(QList<QString> &strlist,BSTnode * tp,int &count)
{
    if(count==8||tp==nullptr)
    {
        return;
    }
    strlist[count]=tp->ttl;
    ++count;
    if(tp->left!=nullptr)
    {
        get_strlist_3(strlist,tp->left,count);
    }
    if(tp->right!=nullptr)
    {
        get_strlist_3(strlist,tp->right,count);
    }
}

srcChgForm::srcChgForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::srcChgForm)
{
    ui->setupUi(this);

    //伴随输入实时更新可选框
    connect(ui->lineEdit,&QLineEdit::textChanged,
            [=]()
            {
                QString temp=ui->lineEdit->text();
                BSTnode * tp=bst.Search_BST(temp,evtid);
                QList<QString>strlist(8,"");
                int count=0;
                get_strlist_3(strlist,tp,count);

                ui->opt_pushButton->setText(strlist[0]);
                ui->opt_pushButton_2->setText(strlist[1]);
                ui->opt_pushButton_3->setText(strlist[2]);
                ui->opt_pushButton_4->setText(strlist[3]);
                ui->opt_pushButton_5->setText(strlist[4]);
                ui->opt_pushButton_6->setText(strlist[5]);
                ui->opt_pushButton_7->setText(strlist[6]);
                ui->opt_pushButton_8->setText(strlist[7]);
            });

    //将子窗口与主窗口连接
    MainWindow *mainWindow= nullptr;
    foreach (QWidget *w, qApp->topLevelWidgets())
        if (MainWindow* mainWin = qobject_cast<MainWindow*>(w))
        {
            mainWindow= mainWin;
        }
    connect(this, &srcChgForm::accepted, mainWindow, &MainWindow::flushCalendar);
}

srcChgForm::~srcChgForm()
{
    delete ui;
}

//关闭按钮
void srcChgForm::on_pushButton_2_clicked()
{
    close();
}

//确认按钮
void srcChgForm::on_pushButton_clicked()
{
    if(evtid==-1)
    {
        close();
        QMessageBox::information(this,"提醒","未查找到相关事件！");
        return;
    }
    close();

    emit accepted();
    int e_id=evtid;
    chgTaskForm*ch=new chgTaskForm();
    ch->setEid(e_id);
    ch->show();
}

//点击提供选项按钮可将输入框文本设置为对应文本
void srcChgForm::on_opt_pushButton_clicked()
{
    ui->lineEdit->setText(ui->opt_pushButton->text());
}
void srcChgForm::on_opt_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->opt_pushButton_2->text());
}
void srcChgForm::on_opt_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->opt_pushButton_3->text());
}
void srcChgForm::on_opt_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->opt_pushButton_4->text());
}
void srcChgForm::on_opt_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->opt_pushButton_5->text());
}
void srcChgForm::on_opt_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->opt_pushButton_6->text());
}
void srcChgForm::on_opt_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->opt_pushButton_7->text());
}
void srcChgForm::on_opt_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->opt_pushButton_8->text());
}
