#pragma once
#include"program.hpp"
#include"sprite.hpp"

class object{
private:
    SDL_Renderer* renderer;

protected:
    SDL_FRect destR;
    sprite Sprite;

public:
    vec2 position;
    object(std::string str,int x ,int y);
    object(int x,int y);
    virtual void update() = 0;
    void render();
    vec2 get_texture_dimensions();
};