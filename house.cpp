#include"house.hpp"

house::house(int num,std::string tex,int x,int y,int width,int height) : object(tex,x,y,width,height){
    this->h_no = num;
}

void house::update(){
    //stay there
}
