#include"object.hpp"
#include"texmanager.hpp"

object::object(std::string str,int x,int y){
    texture = str.c_str();
    destR.x = x;
    destR.y = y;
    xpos = x;
    ypos = y;
}

object::object(int x,int y){
    xpos = x;
    ypos = y;
    destR.x = x;
    destR.y = y;
}

void object::render(){
    SDL_Texture* temptex = texmanager::load_texture(this->texture);

    float w,h;
    SDL_GetTextureSize(temptex,&w,&h);
    float ratio = (float) w/h;
    destR.w = w*house_scale;
    destR.h = h*house_scale;

    texmanager::draw(temptex,destR);
}

vec2 object::get_texture_dimensions(){
    SDL_Texture* temptex = texmanager::load_texture(this->texture);
    float w,h;
    SDL_GetTextureSize(temptex,&w,&h);

    vec2 tempvec(w,h);
    return tempvec;
}