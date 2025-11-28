#pragma once
#include"program.hpp"
#include"object.hpp"
#include"house.hpp"

class pipe : public object{
public:
    int in,out,from,to,id;
    float multiplier;
    pipe(std::string str,int x,int y,float mult,int one,int two,int pipeid,int in);
    void update(const std::vector<object*>& houses);
    void update();
    void addmux(const std::vector<object*>& houses,float mux);
};