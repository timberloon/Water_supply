#pragma once
#include"object.hpp"
#include"text.hpp"

class house : public object{
private: 
    int h_no;
public:
    int req;
    int in;
    house(int num,int text,int x,int y);
    void update() override;
};
