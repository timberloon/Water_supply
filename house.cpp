#include"house.hpp"
#include"algorithms.hpp"

std::string h_tex[8] = {"assets/houses/1.png",
                                "assets/houses/2.png",
                                "assets/houses/3.png",
                                "assets/houses/4.png",
                                "assets/houses/5.png",
                                "assets/houses/6.png",
                                "assets/houses/7.png",
                                "assets/houses/8.png"};

house::house(int num,std::string str,int x,int y) : object(str,x,y){
    this->h_no = num;
    int r = rand()%8;
    this->Sprite = new sprite(h_tex[r].c_str());
}

void house::update(){
    this->txt->update();
    this->txt->change_text(std::to_string(in));
}
