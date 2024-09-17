//
// Created by yyds on 2024/9/15.
//

#include <fstream>
#include <cassert>
#include "JsonParse.h"

JsonParse::JsonParse(string fileName) {
    // 打开文件
    cout<<fileName<<endl;
    ifstream ifs(fileName);
    if (!ifs.is_open()) {
        perror("无法打开文件");
    }
    assert(ifs.is_open());
    // 解析数据
    Json::Reader rd;

    rd.parse(ifs,m_root);
    assert(m_root.isObject());

}

shared_ptr<DBInfo> JsonParse::getDatabaseInfo(JsonParse::DBType type) {
    string dbName = type == Mysql ? "mysql" : "redis";
    Json::Value node = m_root[dbName];
    DBInfo* info = new DBInfo();
    info->ip = node["ip"].asString();
    info->port = node["port"].asInt();
    if(type == Mysql)
    {
        info->user = node["user"].asString();
        info->passwd = node["password"].asString();
        info->dbname = node["dbname"].asString();
    }

    return shared_ptr<DBInfo>(info);
}
