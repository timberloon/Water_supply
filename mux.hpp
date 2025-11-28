#pragma once
#include"program.hpp"
#include"object.hpp"

class mux : public object{
public:
    mux(float multiplier,std::string write,int x,int y);
    float mult;
    void update()override;

};