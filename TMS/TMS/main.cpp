#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>
#include <QSplashScreen>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建并显示启动画面
    QPixmap pixmap(":/assets/beginPicture.png"); // 使用资源文件中的图片
    pixmap = pixmap.scaled(800, 600,
                           Qt::KeepAspectRatio,
                           Qt::SmoothTransformation);
    QSplashScreen splash(pixmap);
    splash.show();

    // 模拟加载过程
    a.processEvents(); // 确保界面能及时更新
    QThread::sleep(2); // 模拟加载时间

    MainWindow w;
    w.show();
    return a.exec();
}
