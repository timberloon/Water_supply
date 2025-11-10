#include"pipe.hpp"

pipe::pipe(std::string str,int x,int y,int mult) : object(str,x,y){
    this->multiplier = mult;
    this->Sprite = new sprite(pump_texture);
}

void pipe::update(){}
