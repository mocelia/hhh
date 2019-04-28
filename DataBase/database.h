#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDriver>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlResult>
#include <INI/ini.h>

class Database
{
public:
    Database();
    Database(QString connName);

    bool connectLogInfoDb();//刘维球：连接OQC的用户
    void createLogTable(QString connName);//创建表格
    bool execSql(QString sqlstatment);//执行sql语句
    void disconnDb();
    QString getConnname();
    QSqlDatabase getDBName();
private:
    QSqlDatabase db;//数据库名
    QString connName;//连接名
    QStringList logInfo ;//刘维球，OQC登录信息
};

#endif // DATABASE_H
