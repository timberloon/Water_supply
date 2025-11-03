#include"object.hpp"

object::object(std::string str,int x,int y){
    sprite temp(str.c_str());
    this->Sprite = temp;
    destR.x = x;
    destR.y = y;
    position.x = x;
    position.y = y;
}

object::object(int x,int y){
    position.x = x;
    position.y = y;
    destR.x = x;
    destR.y = y;
}

void object::render(){
    SDL_Texture* temptex = Sprite.load_texture();

    float w = Sprite.tex_dimensions.x,h = Sprite.tex_dimensions.y;
    float ratio = (float) w/h;
    destR.w = w;
    destR.h = h;

    texmanager::draw(temptex,destR);
}

vec2 object::get_texture_dimensions(){
    SDL_Texture* temptex = Sprite.load_texture();
    float w,h;
    SDL_GetTextureSize(temptex,&w,&h);

    vec2 tempvec(w,h);
    return tempvec;
}