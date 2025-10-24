#pragma once
#include"program.hpp"

class sprite{
private:
    const char* texture;
    vec2 tex_dimensions;
    SDL_FRect destR;
public:
    sprite();
    sprite(const char* str);
    virtual void draw();
    SDL_Texture* load_texture();
};