#pragma once
#include"program.hpp"
#include"object.hpp"

class pipe : public object{
public:
    int multiplier;
    int in;
    int out;

    pipe(std::string str,int x,int y,int mult);
    void update() override;
};