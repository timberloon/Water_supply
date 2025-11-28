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

house::house(int num,int tx,int x,int y) : object(std::to_string(tx),x,y){
    this->h_no = num;
    int r = rand()%8;
    this->Sprite = new sprite(h_tex[r].c_str());
    this->req = tx;
    this->in = 0;
}

void house::update(){
    this->txt->update();
    this->getting->change_text(std::to_string(in));
    this->getting->update();
}
