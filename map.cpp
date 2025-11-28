#include"map.hpp"
#include"texmanager.hpp"
#include"algorithms.hpp"

 int map1[20][25] = {

                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
                    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
}; 

// int map1[10][13] = {
//     { 10,11,11,11,11,11,11,11,11,11,11,11,12 },
//     { 13,14,14,14,14,14,14,14,14,14,14,14,15 },
//     { 13,14,14,14,14,14,14,14,14,14,14,14,15 },
//     { 13,14,14,14,14,14,14,14,14,14,14,14,15 },
//     { 13,14,14,14,14,14,14,14,14,14,14,14,15 },
//     { 13,14,14,14,14,14,14,14,14,14,14,14,15 },
//     { 13,14,14,14,14,14,14,14,14,14,14,14,15 },
//     { 13,14,14,14,14,14,14,14,14,14,14,14,15 },
//     { 13,14,14,14,14,14,14,14,14,14,14,14,15 },
//     { 16,17,17,17,17,17,17,17,17,17,17,17,18 },
    
// };

map::map(){
    mp = std::vector<std::vector<int>>(maprows, std::vector<int>(mc, 0));
    destR.h = destR.w = mapscale;
    load_map(map1);

    brown = texmanager::load_texture("assets/dirt.png");
    green = texmanager::load_texture("assets/grass.png");
    blue = texmanager::load_texture("assets/ground.png");
    for(int i=0;i<9;i++){
        std::string str = "assets/sand/"+ std::to_string(i) + ".png";
        sand[i] = texmanager::load_texture(str.c_str());
    }
    ground[0] = texmanager::load_texture("assets/ground/ground.png");
    for(int i=1;i<4;i++){
        std::string str = "assets/ground/ground" + std::to_string(i+1) + ".png";
        ground[i] = texmanager::load_texture(str.c_str());
    }
    
}

map::~map(){}

void map::load_map(int arr[maprows][mc]){
    for(int i=0;i<maprows;i++){
        for(int j=0;j<mc;j++){
            if(arr[i][j] == 0){
                int r = rand()%4;
                mp[i][j] = r;
                continue;
            }
            this->mp[i][j] = arr[i][j];
        }
    }
}

void map::draw_map(){
    int type;
    for(int row=0;row<maprows;row++){
        for(int col=0;col<mc;col++){
            type = mp[row][col];
            destR.x = col*mapscale;
            destR.y = row*mapscale;

            if(type<0){
                texmanager::draw(brown,destR);
            }
            else if(type <= 3){
                texmanager::draw(ground[type],destR);
            }
            else{
                // texmanager::draw(blue,destR);
                int r = rand()%4;
                switch(type){
                    // case 0:
                    //     texmanager::draw(ground[r],destR);
                    //     break;
                    // case 1:
                    //     // texmanager::draw(sand[4],destR);
                    //     texmanager::draw(ground[0],destR);
                        break;
                    case 10:
                        texmanager::draw(sand[0],destR);
                        break;
                    case 11:
                        texmanager::draw(sand[1],destR);
                        break;
                    case 12:
                        texmanager::draw(sand[2],destR);
                        break;
                    case 13:
                        texmanager::draw(sand[3],destR);
                        break;
                    case 14:
                        texmanager::draw(sand[4],destR);
                        break;
                    case 15:
                        texmanager::draw(sand[5],destR);
                        break;
                    case 16:
                        texmanager::draw(sand[6],destR);
                        break;
                    case 17:
                        texmanager::draw(sand[7],destR);
                        break;
                    case 18:
                        texmanager::draw(sand[8],destR);
                        break;
                    case 100:
                        texmanager::draw(ground[0],destR);
                        break;
                    }
            }
        }
    }
}

void map::update_map(int x,int y,int z){
    mp[x][y] = z;
}

void map::update_map(int x, int y, int house_w, int house_h) {
    int col = (x + house_w / 2) / mapscale;
    int row = (y + house_h / 2) / mapscale;

    if (row >= 0 && row < maprows && col >= 0 && col < mc) mp[row][col] = 1;
}

void map::update_map(vec2 coords){
    vec2 loc = coord_to_idx(coords.x,coords.y);
    int row = (int)loc.x;
    int col = (int)loc.y;
    mp[row][col] = 100;
}

void map::show_map(){
    for(int i=0;i<maprows;i++){
        for(int j=0;j<mc;j++){
            std::cout<< mp[i][j] << ' ';
        }
        std::cout<< '\n';
    }
}

int map::gettile(int x,int y){  
    vec2 temp = coord_to_idx(x,y);
    int cx = static_cast<int>(temp.x);
    int cy = static_cast<int>(temp.y);
    return mp[cx-1][cy-1];
}