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

    clock_t begin = clock();

    // 多线程测试
    thread t1([]() {
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        for (int i = 0; i < 2500; ++i) {
            // 未用连接池
            // Connection conn;
            // char sql[1024]{};
            // sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')", "zhang san", 20, "male");
            // conn.connect("127.0.0.1", 3306, "root", "990324", "chat");
            // conn.update(sql);

            // 使用连接池
            char sql[1024]{};
            sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')", "zhang san", 20, "male");
            shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
        }
    });

    thread t2([]() {
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        for (int i = 0; i < 2500; ++i) {
            // 未用连接池
            // Connection conn;
            // char sql[1024]{};
            // sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')", "zhang san", 20, "male");
            // conn.connect("127.0.0.1", 3306, "root", "990324", "chat");
            // conn.update(sql);

            // 使用连接池
            char sql[1024]{};
            sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')", "zhang san", 20, "male");
            shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
        }
    });

    thread t3([]() {
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        for (int i = 0; i < 2500; ++i) {
            // 未用连接池
            // Connection conn;
            // char sql[1024]{};
            // sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')", "zhang san", 20, "male");
            // conn.connect("127.0.0.1", 3306, "root", "990324", "chat");
            // conn.update(sql);

            // 使用连接池
            char sql[1024]{};
            sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')", "zhang san", 20, "male");
            shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
        }
    });

    thread t4([]() {
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        for (int i = 0; i < 2500; ++i) {
            // 未用连接池
            // Connection conn;
            // char sql[1024]{};
            // sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')", "zhang san", 20, "male");
            // conn.connect("127.0.0.1", 3306, "root", "990324", "chat");
            // conn.update(sql);

            // 使用连接池
            char sql[1024]{};
            sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')", "zhang san", 20, "male");
            shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
        }
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    clock_t end = clock();
    cout << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
#if 0

 // 单线程测试
    // for (int i = 0; i < 10000; ++i) {
    //     // 未用连接池
    //     // Connection conn;
    //     // char sql[1024]{};
    //     // sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')", "zhang san", 20, "male");
    //     // conn.connect("127.0.0.1", 3306, "root", "990324", "chat");
    //     // conn.update(sql);

    //     // 使用连接池
    //     shared_ptr<Connection> sp = cp->getConnection();
    //     char sql[1024]{};
    //     sprintf(sql, "insert into user(name, age, sex) values('%s', %d, '%s')", "zhang san", 20, "male");
    //     sp->update(sql);
    // }
#endif

    return 0;
}
