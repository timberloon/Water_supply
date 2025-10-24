#include"algorithms.hpp"

vec2 get_image_dimensions(const char* str){
    SDL_Surface* surf = IMG_Load(str);
    vec2 result(surf->w*house_scale,surf->h*house_scale);
    SDL_DestroySurface(surf);

    return result;
}

int house_clicked(vec2 coords,std::vector<house*>& houses){
    vec2 h_dimenstion = get_image_dimensions(house_texture);
    for(int i=0;i<houses.size();i++){
        if(coords.x > houses[i]->position.x && coords.x < houses[i]->position.x + h_dimenstion.x){
            if(coords.y > houses[i]->position.y && coords.y < houses[i]->position.y + h_dimenstion.y) return i;
        }
    }
    return -1;
}

bool pathfind(std::vector<std::vector<int>>& map,int start_x,int start_y,int target_x,int target_y){
    return false;
}