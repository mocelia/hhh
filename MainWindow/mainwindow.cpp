#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QLineEdit>
#include <QScreen>
#include "Setting/qwdialogconfig.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QScreen * screen  =  QGuiApplication::primaryScreen();//刘维球，获取屏幕的大小，2019年4月28日16:20:09
    QRect rect =  screen->availableGeometry();
    this->setGeometry(50 ,50 ,rect.width()-100, rect.height()-100); //刘维球，设置界面的大小，2019年4月28日08:24:29


}

MainWindow::~MainWindow()
{
    delete ui;
}


/*********************************************************************
作者：刘维球
时间：2019年4月28日17:26:04
功能：获取订单配置
参数1：
参数2：
***********************************************************************/


void MainWindow::on_actionsetting_triggered()
{
    QString dlgTitle="输入密码对话框";
    QString txtLabel="请输入密码";
    QString defaultInput="";
    QLineEdit::EchoMode echoMode=QLineEdit::Password;//正常文字输入

    bool ok=false;
    QString text = QInputDialog::getText(this, dlgTitle,txtLabel, echoMode, defaultInput, &ok);//刘维球：自定义窗体，2019年4月28日18:02:07

    if (ok && text == "JIMI")
    {
        QWDialogConfig *configDialog = new QWDialogConfig(this);
        Qt::WindowFlags    flags=configDialog->windowFlags();
        configDialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint); //设置对话框固定大小

        int ret=configDialog->exec();
        if(ret== QDialog::Accepted )
        {

        }

        delete configDialog ;
    }
    else {
        QMessageBox::warning(this, "错误提示", "密码不能为空"); ;
    }
}
