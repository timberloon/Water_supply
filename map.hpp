#pragma once
#include"program.hpp"

class map{
private:
    vector<SDL_Texture*> textures;
    SDL_FRect destR;
    public:
    int mp[20][25];
    SDL_Texture* green;
    SDL_Texture* blue;
    SDL_Texture* brown;

    map();
    ~map();
    void load_map(int arr[20][25]);
    void draw_map();
};
