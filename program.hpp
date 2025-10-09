#pragma once
#include<iostream>
#include<SDL3/SDL.h>
#include<SDL3_image/SDL_image.h>
#include"graph.hpp"
#include"texmanager.hpp"

class program{
private:
    SDL_Window* window;
    bool running;
public:
    static SDL_Renderer* renderer;

    void init(std::string title,int width,int height,SDL_WindowFlags flag);
    void update();
    void render();
    void clean();
    void handle_events();
    bool is_running(){return running;}

};
