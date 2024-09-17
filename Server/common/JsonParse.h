//
// Created by yyds on 2024/9/15.
//

#ifndef SERVER_JSONPARSE_H
#define SERVER_JSONPARSE_H

#include <iostream>
#include <string>
#include <json/value.h>
#include <json/json.h>
#include <memory>

using namespace std;

// 定义存储数据的结构体
struct DBInfo
{
    string ip;
    unsigned short port;
    string user;
    string passwd;
    string dbname;
};

class JsonParse {
public:
    enum DBType{Mysql, Redis};
    // 这里不知道为什么相对路径用不了，暂时先使用绝对路径先代替
    JsonParse(string fileName = "/mnt/s/Online_LandlordGame/Server/config/config.json");
    // 获取数据
    shared_ptr<DBInfo> getDatabaseInfo(DBType type);
private:
    Json::Value m_root;
};


#endif //SERVER_JSONPARSE_H
