#ifndef QDLGLOGIN_H
#define QDLGLOGIN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QString>
#include  "DataBase/database.h"
#include "INI/ini.h"

namespace Ui {
class dlgLogin;
}

class QDlgLogin : public QDialog
{
    Q_OBJECT
private:
    int m_tryCount=0; //试错次数
    QString encrypt(const QString& str);//字符串加密
    Database *logDB;
protected:

public:
    explicit QDlgLogin(QWidget *parent = 0);

    ~QDlgLogin();
    QString logName();//返回测试工程师的姓名

private slots:
    void on_btnOK_clicked(); //OK按键
    void on_btnCancel_clicked();    
private:
    Ui::dlgLogin *ui;
    QString pwd;
    QString username;
    


};

#endif // DLGLOGIN_H
