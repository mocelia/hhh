#include "INI/ini.h"
#include <QCoreApplication>
#include <QApplication>
#include <QSettings>
#include <QDebug>
#include <QMessageBox>



INISETTINGS::INISETTINGS()
{

}

/*************************************************************
作者：刘维球
时间：2019年4月28日08:46:35
功能：获取连接数据库的消息, 服务器名(IP + port)，登录名，密码，数据库名
参数1：
参数2：
***********************************************************************/

QStringList INISETTINGS::getConnLogInfo()
{

    QStringList connInfo;

    QString SERVER = "";
    QString PORT = "";
    QString SERVER_PORT ;//刘维球，服务器名 ，2019年4月28日09:52:34
    QString DATABASE  = "";
    QString UID = "";
    QString PWD = "";//刘维球，登录名，密码


    QString appDir = QApplication::applicationDirPath(); ////刘维球：当前程序路径，2019年4月28日09:21:02
    const QString  configFile = appDir + "/config.ini" ; ////刘维球，config.ini路径


    QVariant strConfigValue;
    QString strConfigGroup = "";
    QString strConfigKey = "";

    QSettings user_cfg(configFile,QSettings::IniFormat);

    user_cfg.setIniCodec("UTF-8");


    strConfigGroup = "DB";//根
    user_cfg.beginGroup(strConfigGroup);

    strConfigKey = "IP"; //刘维球：server服务器
    strConfigValue = user_cfg.value(strConfigKey);
    SERVER = strConfigValue.toString();


    strConfigKey = "PORT"; //刘维球：server服务器
    strConfigValue = user_cfg.value(strConfigKey);
    PORT = strConfigValue.toString();

    SERVER_PORT = SERVER + "," + PORT ;

    strConfigKey = "DATABASE"; //刘维球：server服务器
    strConfigValue = user_cfg.value(strConfigKey);
    DATABASE = strConfigValue.toString();

    strConfigKey = "UID"; //刘维球：server服务器
    strConfigValue = user_cfg.value(strConfigKey);
    UID = strConfigValue.toString();

    strConfigKey = "PWD"; //刘维球：server服务器
    strConfigValue = user_cfg.value(strConfigKey);
    PWD = strConfigValue.toString();


    user_cfg.endGroup();
    connInfo << SERVER_PORT  << DATABASE  << UID << PWD ;


    return  connInfo ;

}
