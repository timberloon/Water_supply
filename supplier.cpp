#include"supplier.hpp"

supplier::supplier(int x,int y,int num) : object(std::to_string(num),x,y) {
    this->supply = num;
    this->Sprite = new sprite(supplier_texture);
}

void supplier::update(){
    this->txt->update();
}