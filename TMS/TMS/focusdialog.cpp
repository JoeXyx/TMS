#include "focusdialog.h"
#include "ui_focusdialog.h"
#include <QRandomGenerator>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

FocusDialog::FocusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FocusDialog),
    m_circularProgress(new CircularProgressBar(this)) ,
    circuit(0)
{
    ui->setupUi(this);
    m_circularProgress->hide();  // 初始隐藏

    QStringList bgImages = {
        ":/assets/concentrate_1.jpg",
        ":/assets/concentrate_2.jpg",
        ":/assets/concentrate_3.jpg",
        ":/assets/concentrate_4.jpg"
    };
    QString bgImage = bgImages.at(QRandomGenerator::global()->bounded(bgImages.size()));
    QPixmap pixmap(bgImage);
    if (!pixmap.isNull()) {
        // 使用窗口实际大小或固定尺寸（避免构造函数中size()为0）
        pixmap = pixmap.scaled(420, 630, Qt::KeepAspectRatio, Qt::SmoothTransformation); // 假设窗口默认大小
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(pixmap));
        this->setPalette(palette);
        this->setAutoFillBackground(true); // 必须调用！
    }

    QString styleSheet = R"(
        #FocusDialog {
            border: 1px solid #DEE2E6;
            border-radius: 12px;
        }
        QLabel#sloganLabel, QLabel#authorLabel {
            background-color: rgba(0, 0, 0, 180);
            color: white;
            padding: 5px 10px;
            border-radius: 8px;
            font-size: 16px;
        }
        QPushButton {
            background-color: rgba(255, 255, 255, 220);
            border: 1px solid #ccc;
            padding: 5px 15px;
            border-radius: 4px;
        }
        QSpinBox {
            padding: 5px;
            border: 1px solid #CED4DA;
            border-radius: 6px;
            min-width: 80px;
            background: rgba(255, 255, 255, 200);  // 避免透明背景覆盖
        }
    )";
    this->setStyleSheet(styleSheet);

    scrollTimer = new QTimer(this);
    connect(scrollTimer, &QTimer::timeout, this, &FocusDialog::scrollText);
    scrollPos = 0;


    // 在构造函数中添加
    ui->progressContainer->setLayout(new QVBoxLayout());
    ui->progressContainer->layout()->addWidget(m_circularProgress);
    ui->progressContainer->layout()->setAlignment(Qt::AlignCenter);


    // 设置按钮样式
    QString btnStyle = R"(
        QPushButton {
            background-color: %1;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 8px 16px;
            font-size: 14px;
        }
        QPushButton:hover {
            background-color: %2;
        }
        QPushButton:pressed {
            background-color: %3;
        }
    )";

    ui->beginBtn->setStyleSheet(btnStyle.arg("#2B5F8E").arg("#1E4A7B").arg("#0D3A6B"));
    ui->cancelBtn->setStyleSheet(btnStyle.arg("#6C757D").arg("#5A6268").arg("#495056"));

    setWindowIcon(QIcon(":/assets/tomato.jpg"));
    setWindowTitle("专注模式");

    ui->spinBox->setRange(1, 60);
    ui->spinBox->setValue(25);

    ui->sloganLabel->setVisible(false);
    ui->authorLabel->setVisible(false);

    slogans << "“成功不是终点，失败也并非末日，重要的是继续前进的勇气。” —— 温斯顿·丘吉尔"
            << "“生命中最美好的东西，往往是在你最不期待的时候出现的。” —— 保罗·科埃略"
            << "“不要等待机会，而要创造机会。” —— 乔治·伯纳德·萧"
            << "“你的人生由你自己书写，别让他人替你执笔。” —— 约翰·列侬"
            << "“困难越大，克服它时的荣耀就越大。” —— 西塞罗"
            << "“今天的努力，是为了明天的不后悔。” —— 佚名"
            << "“相信自己，你已经赢了一半。” —— 西奥多·罗斯福"
            << "“即使走得慢，也绝不后退。” —— 亚伯拉罕·林肯"
            << "“世界会为有目标和远见的人让路。” —— 冯·歌德"
            << "“你的时间有限，别浪费在活成别人的样子上。” —— 史蒂夫·乔布斯"
            << "“天行健，君子以自强不息。” ——《周易》"
            << "“路漫漫其修远兮，吾将上下而求索。” —— 屈原"
            << "“不积跬步，无以至千里；不积小流，无以成江海。” —— 荀子"
            << "“老骥伏枥，志在千里；烈士暮年，壮心不已。” —— 曹操"
            << "“长风破浪会有时，直挂云帆济沧海。” —— 李白"
            << "“世上无难事，只要肯登攀。” —— 毛泽东"
            << "“为中华之崛起而读书。” —— 周恩来"
            << "“人生最大的光荣，不在于永不失败，而在于能屡仆屡起。” —— 梁启超"
            << "“时间就像海绵里的水，只要愿挤，总还是有的。” —— 鲁迅"
            << "“真正的强者，不是没有眼泪，而是含着眼泪依然奔跑。” —— 马云"
            << "“梦想还是要有的，万一实现了呢？” —— 马云"
            << "“不是因为看到希望才坚持，而是因为坚持才能看到希望。” —— 俞敏洪"
            << "“人生没有白走的路，每一步都算数。” —— 李宗盛"
            << "“你只管努力，剩下的交给时间。” —— 张艺谋"
            << "“成功的路上并不拥挤，因为坚持的人不多。” —— 雷军";
}

FocusDialog::~FocusDialog()
{
    if (m_circularProgress) {
        delete m_circularProgress;
    }
    delete ui;
}

int FocusDialog::getFocusMinutes() const {
    return ui->spinBox->value();
}

void FocusDialog::changeSlogan()
{
    int randomInt = QRandomGenerator::global()->bounded(slogans.size());
    QString fullText = slogans[randomInt];
    int index = fullText.indexOf("——");

    QString slogan = index > 0 ? fullText.left(index) : fullText;
    QString author = index > 0 ? fullText.mid(index) : "";

    ui->sloganLabel->setText(slogan.trimmed());
    ui->authorLabel->setText(author.trimmed());

    QFontMetrics fm(ui->sloganLabel->font());
    if (fm.horizontalAdvance(slogan.trimmed()) > ui->sloganLabel->width()) {
        scrollPos = 0;
        scrollTimer->start(1500);  // 每3s滚动一次
    } else {
        scrollTimer->stop();
    }
}

void FocusDialog::on_beginBtn_clicked()
{
    if (ui->beginBtn->text() == "开始") {
        ui->sloganLabel->setVisible(true);
        ui->authorLabel->setVisible(true);
        ui->setTimeLabel->setVisible(false);
        ui->spinBox->setVisible(false);

        changeSlogan();

        remainingTime = getFocusMinutes() * 60;

        if(remainingTime==0||remainingTime>3600)
        {
            QMessageBox::information(this,"提醒","选择时间非法。");
            return;
        }

        countdownTimer = new QTimer(this);
        connect(countdownTimer, &QTimer::timeout, this, &FocusDialog::updateTimer);
        countdownTimer->setTimerType(Qt::PreciseTimer); // 更精确的计时器
        countdownTimer->start(1000);

        ui->beginBtn->setText("暂停");
        ui->cancelBtn->setText("结束");
        setWindowTitle("正在专注");




        if (!m_circularProgress) {
            m_circularProgress = new CircularProgressBar(this);
        } else {
            m_circularProgress->show();  // 重新显示它
        }


        m_circularProgress->show();  // 确保显示
        m_circularProgress->setRange(0, getFocusMinutes() * 60);
        setValueWithAnimation(remainingTime);

        updateTimer();
    }
    else if (ui->beginBtn->text() == "暂停") {
        if (countdownTimer) countdownTimer->stop();
        ui->beginBtn->setText("继续");
        setWindowTitle("暂停中");
    }
    else if (ui->beginBtn->text() == "继续") {
        if (countdownTimer) countdownTimer->start(1000);
        ui->beginBtn->setText("暂停");
        setWindowTitle("正在专注");
    }
}

void FocusDialog::on_cancelBtn_clicked()
{
    if (ui->cancelBtn->text() == "取消") {
        close();
    }
    else {
        auto reply = QMessageBox::question(this, "确认操作", "确认结束专注模式吗？", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            resetUI();
        }
    }
}

void FocusDialog::updateTimer()
{
    if (remainingTime <= 0) {
        countdownTimer->stop();
        countdownTimer->deleteLater();
        countdownTimer = nullptr;

        QMessageBox::information(this, "完成", "恭喜你完成了一次专注！");
        resetUI();
        return;
    }


    if (m_circularProgress) {
        setValueWithAnimation(remainingTime);  // 使用封装好的动画方法
    }

    remainingTime--;
    circuit++;
    if (circuit >= 20) {
        changeSlogan();
        circuit = 0;
    }


}

void FocusDialog::resetUI()
{
    setWindowTitle("欢迎进入专注模式");
    ui->sloganLabel->setVisible(false);
    ui->authorLabel->setVisible(false);
    ui->setTimeLabel->setVisible(true);
    ui->spinBox->setVisible(true);
    ui->beginBtn->setText("开始");
    ui->cancelBtn->setText("取消");


    if (m_circularProgress) {
        m_circularProgress->hide();
        m_circularProgress->setValue(ui->spinBox->value() * 60);
    }

    if (countdownTimer) {
        countdownTimer->stop();
        countdownTimer->deleteLater();
        countdownTimer = nullptr;
    }
}

void FocusDialog::setValueWithAnimation(int value) {
    QPropertyAnimation *anim = new QPropertyAnimation(m_circularProgress, "value");
    anim->setDuration(500);
    anim->setEasingCurve(QEasingCurve::OutQuad);
    anim->setStartValue(m_circularProgress->value());
    anim->setEndValue(value);
    anim->start(QAbstractAnimation::DeleteWhenStopped); // 关键修复
}

// 添加滚动方法
void FocusDialog::scrollText() {
    scrollPos++;
    QString elidedText = ui->sloganLabel->fontMetrics().elidedText(
        ui->sloganLabel->text(),
        Qt::ElideNone,
        ui->sloganLabel->width(),
        Qt::TextShowMnemonic
        );

    if (scrollPos > elidedText.length()) {
        scrollPos = 0;
    }

    QString displayedText = elidedText.mid(scrollPos) + " " + elidedText.left(scrollPos);
    ui->sloganLabel->setText(displayedText);
}
