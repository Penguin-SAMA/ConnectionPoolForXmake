#include "connectionPool.h"
#include "public.h"
#include <cstdio>
#include <iostream>

// 连接池的构造
ConnectionPool::ConnectionPool() {
    // 加载配置项了
    if (!loadConfigFile()) {
        return;
    }

    // 创建初始数量的连接
    for (int i = 0; i < _initSize; ++i) {
        Connection* p = new Connection();
        p->connect(_ip, _port, _username, _password, _dbname);
        _connectionQue.push(p);
        _connectionCnt++;
    }

    // 启动一个新的线程，作为连接的生产者
}

// 线程安全的懒汉单例函数结构
ConnectionPool* ConnectionPool::getConnectionPool() {
    static ConnectionPool pool; // lock和unlock
    return &pool;
}

bool ConnectionPool::loadConfigFile() {
    FILE* pf = fopen("mysql.cnf", "r");
    if (pf == nullptr) {
        LOG("mysql.cnf file is not exist!");
        return false;
    }

    while (!feof(pf)) {
        char line[1024] = {0};
        fgets(line, 1024, pf);
        string str = line;
        int idx = str.find('=', 0);
        // 无效配置项
        if (idx == -1) {
            continue;
        }

        int endidx = str.find('\n', idx);
        string key = str.substr(0, idx);
        string value = str.substr(idx + 1, endidx - idx - 1);

        if (key == "ip") {
            _ip = value;

        } else if (key == "port") {
            _port = atoi(value.c_str());

        } else if (key == "username") {
            _username = value;

        } else if (key == "password") {
            _password = value;

        } else if (key == "dbname") {
            _dbname = value;

        } else if (key == "initSize") {
            _initSize = atoi(value.c_str());

        } else if (key == "maxSize") {
            _maxSize = atoi(value.c_str());

        } else if (key == "maxIdleTime") {
            _maxIdleTime = atoi(value.c_str());

        } else if (key == "connectionTimeOut") {
            _connectionTimeout = atoi(value.c_str());
        }
    }

    return true;
}
