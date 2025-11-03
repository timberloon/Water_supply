#include"house.hpp"
#include"algorithms.hpp"

house::house(int num,int x,int y) : object(x,y){
    this->h_no = num;
    sprite temp(house_texture);
    this->Sprite = temp;
    map_pos = coord_to_idx(x,y);
}

void house::update(){
    //stay there
}
