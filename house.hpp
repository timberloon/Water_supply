#pragma once
#include"object.hpp"

class house : public object{
private: int h_no;
public:
    house(int num,int x,int y);
    void update() override;
};
