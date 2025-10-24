#include"house.hpp"

house::house(int num,int x,int y) : object(x,y){
    this->h_no = num;
    sprite temp(house_texture);
    this->Sprite = temp;
}

void house::update(){
    //stay there
}
