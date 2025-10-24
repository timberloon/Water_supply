#include"map.hpp"
#include"texmanager.hpp"

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

            // switch(type){
            // case 0:
            //     texmanager::draw(blue,destR);
            //     break;
            // case 1:
            //     texmanager::draw(brown,destR);
            //     break;
            // case 2:
            //     texmanager::draw(green,destR);
            //     break;
            // }
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

void map::show_map(){
    for(int i=0;i<20;i++){
        for(int j=0;j<25;j++){
            std::cout<< mp[i][j] << ' ';
        }
        std::cout<< '\n';
    }
}
