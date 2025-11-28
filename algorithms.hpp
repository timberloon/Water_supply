#pragma once
#include"program.hpp"
#include"object.hpp"
#include"graph.hpp"
#include"pipe.hpp"
#include"mux.hpp"

int house_clicked(vec2 coords,std::vector<object*>& houses);
void connect(u_graph& game,const std::vector<int>& chosen,std::vector<std::vector<int>>& map,std::vector<object*>& objects,std::vector<pipe*>& pipes);
vec2 coord_to_idx(int x,int y);
vec2 get_image_dimensions(const char* str);
bool isValid(int x, int y,int start_x, int start_y,int target_x, int target_y,const vector<vector<int>> &maze,const vector<vector<bool>> &visited);
void pathfind(vector<vector<int>> &maze, int start_x, int start_y, int target_x, int target_y,int mark);
void addmult(int pipeid,float mult,const std::vector<object*>& houses,const std::vector<pipe*>& pipes);