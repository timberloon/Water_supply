#pragma once
#include"program.hpp"
#include"house.hpp"
#include"graph.hpp"

int house_clicked(vec2 coords,std::vector<house*>& houses);
bool pathfind(std::vector<std::vector<int>>& map,int start_x,int start_y,int target_x,int target_y);
void connect(u_graph& game,std::vector<int> houses);
vec2 coord_to_idx(int x,int y);
vec2 get_image_dimensions(const char* str);