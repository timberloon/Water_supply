#include"object.hpp"
#include"texmanager.hpp"

object::object(std::string str,int x,int y,int width,int height){
    texture = str.c_str();
    xpos = x,ypos = y;
    destR->w = width;
    destR->h = height;
}

void object::render(){
    SDL_Texture* temptex = texmanager::load_texture(this->texture);
    texmanager::draw(temptex,this->destR);
}