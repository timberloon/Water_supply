#pragma once
#include"program.hpp"
#include"vector2.hpp"

vec2 get_image_dimensions(const char* str){
    SDL_Surface* surf = IMG_Load(str);
    vec2 result(surf->w*house_scale,surf->h*house_scale);
    SDL_DestroySurface(surf);

    return result;
}

bool pathfind(vector<vector<int>>& map,int start_x,int start_y,int target_x,int target_y){
    if(start_x < 0 || start_x >= 25 || start_y < 0 || start_y >= 20) return false;
    if(map[start_x][start_y] != 0 && map[start_x][start_y] != 1) return false;
    if(start_x == target_x && start_y == target_y) return true;

    if(pathfind(map,start_x+1,start_y,target_x,target_y)){
        map[start_x+1][start_y] = 1;
        return true;
    }
    else if(pathfind(map,start_x-1,start_y,target_x,target_y)){
        map[start_x-1][start_y] = 1;
        return true;
    }
    else if(pathfind(map,start_x,start_y+1,target_x,target_y)){
        map[start_x][start_y+1] = 1;
        return true;
    }
    else if(pathfind(map,start_x,start_y-1,target_x,target_y)){
        map[start_x][start_y-1] = 1;
        return true;
    }
    return false;
}