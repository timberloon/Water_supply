#pragma once
#include"program.hpp"

const float house_scale = 2.0;

class texmanager{
public:
    static SDL_Texture* load_texture(const char* tex);
    static void draw(SDL_Texture* tex,SDL_FRect rect);
};