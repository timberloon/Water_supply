#pragma once
#include"object.hpp"
#include"text.hpp"

class house : public object{
private: 
    int h_no;
public:
    int in;
    house(int num,std::string str,int x,int y);
    void update() override;
};
