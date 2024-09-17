//
// Created by yyds on 2024/8/18.
//

#include "myTest.h"
#include "Person.pb.h"

using namespace MyPerson;
using namespace MyAddress;

void myTest::test() {
    Person p;
    p.set_id(10);
    p.set_age(28);
    p.set_sex("man");
    p.add_name();
    p.set_name(0,"路飞");
    p.add_name("艾斯");
    p.add_name("萨博");
    p.mutable_addr()->set_addr("广东省广州市白云区嘉禾八一科技园");
    p.mutable_addr()->set_num(1001);
    p.set_color(Color::Blue);

    // 序列化对象 p,最终得到一个字符串
    std::string output;
    p.SerializeToString(&output);

    // 反序列化数据
    Person pp;
    pp.ParseFromString(output);
    std::cout<<pp.id()<<" "<<pp.sex()<<" "<<pp.age()<<std::endl;
    std::cout<<pp.addr().addr()<<" "<<pp.addr().num()<<std::endl;
    int size = pp.name_size();
    for(int i=0;i<size;i++)
    {
        std::cout<<pp.name(i)<<std::endl;
    }
    std::cout<<pp.color()<<std::endl;
}
