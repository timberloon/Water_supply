#pragma once
#include"program.hpp"

class sprite{
private:
    const char* texture;
    SDL_FRect destR;
public:
    vec2 tex_dimensions;
    sprite();
    sprite(const char* str);
    virtual void draw();
    SDL_Texture* load_texture();
};