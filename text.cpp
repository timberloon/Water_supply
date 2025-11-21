#include"text.hpp"

text::text(std::string words,int x,int y){
    this->text_size = letter_size;
    this->text_color = font_color;
    
    this->font = nullptr;
    this->font = TTF_OpenFont(font_path,text_size);
    if(!font) std::cout<< "Failed to open font\n";

    this->texture = nullptr;
    this->rect.x = x;
    this->rect.y = y;
    this->writeup = words;

    position.x = x;
    position.y = y;

    create_tex();
}

void text::create_tex(){
    SDL_Surface* surf = TTF_RenderText_Blended(font,writeup.c_str(),writeup.length(),text_color);
    if(!surf) std::cout<< "Failed to load surface\n";
    this->rect.h = surf->h;
    this->rect.w = surf->w;
    this->texture = texmanager::load_texture_from_surface(surf);
    if(!this->texture) std::cout<< "Failed to lead texture\n";
}

void text::draw(){
    texmanager::draw(this->texture,this->rect);
}

void text::update(){
    draw();
}

void text::change_text(std::string str){
    this->writeup = str;
}