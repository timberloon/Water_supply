#include"program.hpp"
#include"vector2.hpp"

constexpr int rad = 40;
const int k = 30;
constexpr int grid_size = rad/1.41;
constexpr int rows = window_width/grid_size;
constexpr int cols = window_height/grid_size;
int grid[rows][cols];
std::vector<vec2> active;

vec2 get_image_dimensions(const char* str){
    SDL_Surface* surf = IMG_Load(str);
    vec2 result(surf->w*house_scale,surf->h*house_scale);
    SDL_DestroySurface(surf);

    return result;
}

inline std::shared_ptr<vec2> rand_coord(vec2 pos){
    std::shared_ptr<vec2> p_vec(new vec2());
    int temp1 = rand()%rad + rad;
    int temp2 = rand()%rad + rad;

    int temp3 = rand();
    if(temp3%4 == 0){
        p_vec->x = pos.x+temp1;
        p_vec->y = pos.y+ temp2;
    }
    else if(temp3%4 == 1){
        p_vec->x = pos.x+temp1;
        p_vec->y = pos.y-temp2;
    }
    else if(temp3%4 == 2){
        p_vec->x = pos.x-temp1;
        p_vec->y = pos.y+temp2;
    }
    else{
        p_vec->x = pos.x-temp1;
        p_vec->y = pos.y-temp2;
    }

    return p_vec;
}

bool check_grid(std::shared_ptr<vec2> coord){
    for(int i=max(0,(int)coord->x-2);i<=min((int)coord->x+2,rows-1);i++){
        for(int j=max(0,(int)coord->y-2);j<=min((int)coord->y+2,cols-1);j++){
            if(grid[i][j] == 1) return false;
        }
    }
    grid[(int)coord->x][(int)coord->y] = 1;
    return true;
}

void poission_sampling(int tries,std::vector<vec2>& houses){
    while(tries--){
        bool can_generate = false;
        for(int i=0;i<k;i++){
            std::shared_ptr<vec2> currpt = rand_coord(active[active.size()-1]);
            if(currpt->x < 0 || currpt->x > window_width || currpt->y < 0 || currpt->y > window_height) continue;
            active.push_back(*currpt);
            bool temp = check_grid(currpt);
            if(temp){
                houses.push_back(*currpt);
                can_generate = true;
                break;
            }
        }
        if(!can_generate) active.pop_back();
    }
}
