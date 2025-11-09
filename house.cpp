#include"house.hpp"
#include"algorithms.hpp"

house::house(int num,std::string str,int x,int y) : object(str,x,y){
    this->h_no = num;
    this->Sprite = new sprite(house_texture);
    map_pos = coord_to_idx(x,y);
}

void house::update(){
    //stay there
}
