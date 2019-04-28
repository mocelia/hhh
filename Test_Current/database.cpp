#include "database.h"
#include <QApplication>
#include <QSettings>
#include <QVector>
#include <qiterator.h>
#include <QList>
#include <QDebug>

Database::Database()
{

}

Database::Database(QString connName)
{
    this->connName =  connName ;
    this->db =  QSqlDatabase::addDatabase("QODBC",connName);
}

bool Database::connectDb()
{

    QString appDir = QApplication::applicationDirPath(); //当前运行程序地址
    QString configFile = appDir + "/config.ini" ;

    QVariant strConfigValue;
    QString strConfigGroup = "";
    QString strConfigKey = "";

    QString SERVER = "";
    QString DATABASE  = "";
    QString UID = "";
    QString pwd = "";

    QSettings user_cfg(configFile,QSettings::IniFormat);
    user_cfg.setIniCodec("UTF-8");

    strConfigGroup = "DB";//根
    user_cfg.beginGroup(strConfigGroup);

    strConfigKey = "SERVER"; //刘维球：server服务器
    strConfigValue = user_cfg.value(strConfigKey);
    SERVER = strConfigValue.toString();

    strConfigKey = "DATABASE"; //刘维球：server服务器
    strConfigValue = user_cfg.value(strConfigKey);
    DATABASE = strConfigValue.toString();

    strConfigKey = "UID"; //刘维球：server服务器
    strConfigValue = user_cfg.value(strConfigKey);
    UID = strConfigValue.toString();

    strConfigKey = "pwd"; //刘维球：server服务器
    strConfigValue = user_cfg.value(strConfigKey);
    pwd = strConfigValue.toString();

    user_cfg.endGroup();

    qDebug() << "SERVER:" <<SERVER << endl;
    qDebug() << "DATABASE:" <<DATABASE << endl;
    qDebug() << "UID:" <<UID << endl;
    qDebug() << "pwd:" <<pwd << endl;

    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                               "SERVER=%1;"
                               "DATABASE=%2;"
                               "UID=%3;"
                               "PWD=%4;").arg(SERVER)
                       .arg(DATABASE)
                       .arg(UID)
                       .arg(pwd));
    if (!db.open())
    {
        qDebug("数据库连接失败"); //
        return false;
    }
    else
    {
        return  true;
    }

}

void Database::createTable(QString tablename)
{
    //tablename = "GPSTest.dbo.Test_Engineers2";
    QSqlQuery query(db);
    QString sqlstatement(QString("if not exists (select * from sysobjects where id = object_id('\"%1\"') "
                                 "and OBJECTPROPERTY(id, 'IsUserTable') = 1)"
                                 "create table %2"
                                 "(id int primary key identity(1,1),  username nvarchar(200) not null"
                                 "unique,Grade int default 1,  pwd nvarchar(32) not null,createTime datetime)").arg(tablename).arg(tablename));

}

bool Database::execSql(QString sqlstatment)
{
    QSqlQuery query(db);

    if(query.exec(sqlstatment))
    {
        return true; //执行是否成功
    }
    else
    {
        return  false;//执行失败
    }
}

void Database::disconnDb()
{
    if(db.open())
    {
        db.close();
    }
}

QString Database::getConnname()
{
    return  this->connName;
}

QSqlDatabase Database::getDBName()
{

    return  this->db;
    //添加数据库
}






