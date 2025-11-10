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

map::map(){
    mp = std::vector<std::vector<int>>(20, std::vector<int>(25, 0));
    destR.h = destR.w = 32;
    load_map(map1);

    brown = texmanager::load_texture("assets/dirt.png");
    green = texmanager::load_texture("assets/grass.png");
    blue = texmanager::load_texture("assets/water.png");
}

map::~map(){}

void map::load_map(int arr[20][25]){
    for(int i=0;i<20;i++){
        for(int j=0;j<25;j++){
            this->mp[i][j] = arr[i][j];
        }
    }
}

void map::draw_map(){
    int type;
    for(int row=0;row<20;row++){
        for(int col=0;col<25;col++){
            type = mp[row][col];
            destR.x = col*32;
            destR.y = row*32;

            if(type<0){
                texmanager::draw(brown,destR);
            }
            else{
                switch(type){
                    case 0:
                        // texmanager::draw(blue,destR);
                        break;
                    case 1:
                        texmanager::draw(green,destR);
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
    int col = (x + house_w / 2) / 32;
    int row = (y + house_h / 2) / 32;

    if (row >= 0 && row < 20 && col >= 0 && col < 25) mp[row][col] = 1;
}

void map::update_map(vec2 coords){
    vec2 loc = coord_to_idx(coords.x,coords.y);
    int row = (int)loc.x;
    int col = (int)loc.y;
    mp[row][col] = 1;
}

void map::show_map(){
    for(int i=0;i<20;i++){
        for(int j=0;j<25;j++){
            std::cout<< mp[i][j] << ' ';
        }
        std::cout<< '\n';
    }
}
