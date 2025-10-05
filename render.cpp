#include<iostream>
#include<SDL3/SDL.h>
#include"graph.hpp"

int main(){
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_CreateWindowAndRenderer("First window",800,600,SDL_WINDOW_RESIZABLE,&window,&renderer);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);
}
