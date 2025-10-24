#include"sprite.hpp"
#include"algorithms.hpp"

sprite::sprite(){}

sprite::sprite(const char* str){
    this->texture = str;
    this->tex_dimensions = get_image_dimensions(str);
    destR.h = destR.w = 32;
    destR.x = destR.y = 0;
}

SDL_Texture* sprite::load_texture(){
    return texmanager::load_texture(this->texture);
}

void sprite::draw(){
    SDL_Texture* tmp = texmanager::load_texture(this->texture);
    texmanager::draw(tmp,destR);
}
