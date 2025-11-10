#include"object.hpp"
#include"algorithms.hpp"

object::object(std::string str,std::string txt,int x,int y){
    this->Sprite = new sprite(str.c_str());
    destR.x = x;
    destR.y = y;
    position.x = x;
    position.y = y;
    vec2 dim = get_image_dimensions(str.c_str());
    this->txt = new text(txt,dim.x/2,dim.x/2);
    map_pos = coord_to_idx(x,y);
}

object::object(std::string str,int x,int y){
    this->txt = new text(str,x,y);
    position.x = x;
    position.y = y;
    destR.x = x;
    destR.y = y;
    map_pos = coord_to_idx(x,y);
}

object::object(int x,int y){
    position.x = x;
    position.y = y;
    destR.x = x;
    destR.y = y;
    map_pos = coord_to_idx(x,y);
}

void object::render(){
    SDL_Texture* temptex = Sprite->load_texture();

    float w = Sprite->tex_dimensions.x,h = Sprite->tex_dimensions.y;
    float ratio = (float) w/h;
    destR.w = w;
    destR.h = h;

    texmanager::draw(temptex,destR);
    txt->draw();
}

vec2 object::get_texture_dimensions(){
    SDL_Texture* temptex = Sprite->load_texture();
    float w,h;
    SDL_GetTextureSize(temptex,&w,&h);

    vec2 tempvec(w,h);
    return tempvec;
}
