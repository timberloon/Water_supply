#include"mux.hpp"

mux::mux(float multiplier,std::string write,int x,int y) : mult(multiplier), object(write,x,y){
    this->Sprite = new sprite(mux_texture);
}

void mux::update(){}