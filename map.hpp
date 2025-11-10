#pragma once
#include"program.hpp"

class map{
private:
    std::vector<SDL_Texture*> textures;
    SDL_FRect destR;
    public:
    std::vector<std::vector<int>> mp;
    SDL_Texture* green;
    SDL_Texture* blue;
    SDL_Texture* brown;

    map();
    ~map();
    void load_map(int arr[20][25]);
    void draw_map();
    void update_map(int x,int y,int z);
    void update_map(int x, int y, int house_w, int house_h);
    void update_map(vec2 coords);
    void show_map();
};
