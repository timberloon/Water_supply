#pragma once
#include"program.hpp"
#include"texmanager.hpp"

class text{
    SDL_Texture* texture;
    TTF_Font* font;
    SDL_Color text_color;
    float text_size;
    SDL_FRect rect;
    std::string writeup;

public:
    text(std::string words,int x,int y);
    void create_tex();
    void draw();
};