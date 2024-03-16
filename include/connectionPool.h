#pragma once
#include "connection.h"
#include <atomic>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
using namespace std;

class ConnectionPool
{
public:
    // 获取连接池对象实例
    static ConnectionPool* getConnectionPool();

private:
    ConnectionPool(); // 单例1：构造函数私有化

    bool loadConfigFile(); // 从配置文件中加载配置项

    string _ip;             // MySQL的IP地址
    unsigned short _port;   // mysql的端口号
    string _username;       // mysql登录用户名
    string _password;       // mysql登录密码
    string _dbname;         // 连接的数据库名称
    int _initSize;          // 连接池的初始连接量
    int _maxSize;           // 连接池的最大连接量
    int _maxIdleTime;       // 连接池最大空闲时间
    int _connectionTimeout; // 连接池获取连接的超时时间

    queue<Connection*> _connectionQue; // 存储mysql连接的队列
    mutex _queueMutex;                 // 维护连接队列的线程安全互斥锁
    atomic_int _connectionCnt;         // 记录连接所创建的connection连接的总数量
};
