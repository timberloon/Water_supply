#include"object.hpp"
#include"algorithms.hpp"

object::object(std::string asset,std::string txt,int x,int y){
    this->Sprite = new sprite(asset.c_str());
    destR.x = x;
    destR.y = y;
    position.x = x;
    position.y = y;
    vec2 dim = get_image_dimensions(asset.c_str());
    this->txt = new text(txt,dim.x/2,dim.x/2,font_color);
    this->getting = new text("0",x+25,y+25,green);
    map_pos = coord_to_idx(x,y);
}

object::object(std::string write,int x,int y){
    this->txt = new text(write,x,y,font_color);
    this->getting = new text("0",x+25,y+25,green);
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
    if(getting)getting->draw();
}

vec2 object::get_texture_dimensions(){
    SDL_Texture* temptex = Sprite->load_texture();
    float w,h;
    SDL_GetTextureSize(temptex,&w,&h);

    vec2 tempvec(w,h);
    return tempvec;
}
