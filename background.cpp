#include"background.hpp"

background::background(){
    destR.h = window_height;
    destR.w = window_width;
    destR.x = 0;
    destR.y = 0;
    texture = background_image;

}

background::background(std::string str){
    destR.h = window_height;
    destR.w = window_width;
    texture = str;
}

void background::draw(){
    SDL_Texture* tx = texmanager::load_texture(texture.c_str());
    texmanager::draw(tx,destR);
}