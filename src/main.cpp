#include "connection.h"
#include "connectionPool.h"
#include <iostream>
using namespace std;

int main() {
    // 插入测试
    // Connection conn;
    // char sql[1024]{};
    // sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')", "zhang san", 20, "male");
    // conn.connect("127.0.0.1", 3306, "root", "990324", "chat");
    // conn.update(sql);

    ConnectionPool* cp = ConnectionPool::getConnectionPool();
    cp->loadConfigFile();

    return 0;
}
