#pragma once
#include"program.hpp"

class map{
private:
    vector<SDL_Texture*> textures;
    SDL_FRect destR;
    int mp[20][25];
public:
    map();
    ~map();
    void load_map(vector<vector<int>> arr);
    void draw_map();
};
