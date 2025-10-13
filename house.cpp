#include"house.hpp"

house::house(int num,int x,int y) : object(x,y){
    this->h_no = num;
    this->texture = "assets/house3.png";
}

void house::update(){
    //stay there
}
