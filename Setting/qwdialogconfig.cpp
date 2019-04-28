#include "qwdialogconfig.h"
#include "ui_qwdialogconfig.h"

#include <QMessageBox>
#include <QComboBox>
#include <QDebug>
#include <QSqlQuery>
QWDialogConfig::QWDialogConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogConfig)
{
    ui->setupUi(this);
    this->setWindowTitle("订单配置");

    //this->setStyleSheet("border:1px solid #ff9800;border-radius:0px;background: #FFFFFF");
}

QWDialogConfig::~QWDialogConfig()
{
    //    QMessageBox::information(this,"提示","设置表格行列数对话框被删除");
    delete ui;
}




