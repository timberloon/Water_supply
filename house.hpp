#pragma once
#include"object.hpp"

class house : public object{
private: 
    int h_no;
public:
    vec2 map_pos;
    house(int num,int x,int y);
    void update() override;
};
