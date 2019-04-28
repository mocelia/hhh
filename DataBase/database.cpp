#include "DataBase/database.h"
#include <QApplication>
#include <QSettings>
#include <QVector>
#include <qiterator.h>
#include <QList>
#include <QDebug>
#include <QMessageBox>

Database::Database()
{

}

Database::Database(QString connName)
{
    this->connName =  connName ;
    this->db =  QSqlDatabase::addDatabase("QODBC",connName);
}


bool Database::connectLogInfoDb()
{

    QString appDir = QApplication::applicationDirPath(); ////刘维球：当前程序路径，2019年4月28日09:21:02
    const QString  configFile = appDir + "/config.ini" ; ////刘维球，config.ini路径
    QFile IniFile(configFile) ;//刘维球；读取配置路径,2019年4月28日10:52:01
    INISETTINGS  iniSettings; //刘维球，初始化设置，2019年4月28日11:07:50

    if(!IniFile.exists())
    {
        qDebug() << "初始化文件不存在" << endl ;
    }
    else{


        logInfo = iniSettings.getConnLogInfo();

        db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                                    "SERVER=%1;"
                                    "DATABASE=%2;"
                                    "UID=%3;"
                                    "PWD=%4;").arg(logInfo[0])
                            .arg(logInfo[1])
                            .arg(logInfo[2])
                            .arg(logInfo[3]));
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
}


void Database::createLogTable(QString tablename)
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






