#pragma once
#include<iostream>
#include<memory>
#include<math.h>
#include<SDL3/SDL.h>
#include<SDL3_image/SDL_image.h>
#include<SDL3_ttf/SDL_ttf.h>
#include<ctime>
#include<vector>
#include<utility>
#include"texmanager.hpp"
#include"vector2.hpp"
#include"globals.hpp"

class program{
private:
    SDL_Window* window;
    bool running;
public:
    static SDL_Renderer* renderer;

    void init(std::string title,int width,int height,SDL_WindowFlags flag);
    void start();
    void update();
    void render();
    void clean();
    void handle_events();
    void clear();
    bool is_running(){return running;}
};
