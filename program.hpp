#pragma once
#include<iostream>
#include<SDL3/SDL.h>
#include"graph.hpp"

class program{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
public:
    void init(std::string title,int width,int height,SDL_WindowFlags flag);
    void update();
    void render();
    void clean();
    void handle_events();
    bool is_running(){return running;}
};
