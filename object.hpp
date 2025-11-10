#pragma once
#include"program.hpp"
#include"sprite.hpp"
#include"text.hpp"

class object{
private:
    SDL_Renderer* renderer;

protected:
    SDL_FRect destR;
    sprite* Sprite;
    text* txt;
    
public:
    vec2 map_pos;
    vec2 position;
    object(std::string str,std::string txt,int x ,int y);
    object(std::string str,int x,int y);
    object(int x,int y);
    virtual void update() = 0;
    void render();
    vec2 get_texture_dimensions();
};