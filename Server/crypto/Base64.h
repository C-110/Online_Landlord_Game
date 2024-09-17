//
// Created by yyds on 2024/9/5.
//

#ifndef SERVER_BASE64_H
#define SERVER_BASE64_H


#include <string>
using namespace std;

class Base64
{
public:
    explicit Base64() = default;

    // 编码
    string encode(string data);
    string encode(const char* data, int length);
    // 解码
    string decode(string data);
    string decode(const char* data, int length);
};


#endif //SERVER_BASE64_H
