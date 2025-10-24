#pragma once
#include"program.hpp"
#include"house.hpp"

vec2 get_image_dimensions(const char* str);
int house_clicked(vec2 coords,std::vector<house*>& houses);
bool pathfind(std::vector<std::vector<int>>& map,int start_x,int start_y,int target_x,int target_y);