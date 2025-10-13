#include"program.hpp"
#include"vector2.hpp"

vec2 get_image_dimensions(const char* str);

vector<vec2*> points;
vec2 borders = get_image_dimensions("assets/house3.png");
const int width_buffer = 800-borders.x;
const int height_buffer = 600-borders.y;

inline void pos_generate(int& a,int& b){
    vec2 arr[10];
    float distances[10] = {0.0f};
    for(int i=0;i<10;i++){
        int temp1 = rand()%width_buffer;
        int temp2 = rand()%height_buffer;

        arr[i] = vec2(temp1,temp2);
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<points.size();j++){
            vec2 tempvec = arr[i]-(*points[j]);
            distances[i] += tempvec.mod();
        }
    }

    float maxi = 0;
    int idx = 0;
    for(int i=0;i<10;i++){
        if(distances[i] > maxi){
            maxi = distances[i];
            idx = i;
        }
    }

    a = arr[idx].x;
    b = arr[idx].y;
    std::cout<< a << ' ' << b << '\n';
    points.push_back(new vec2(a,b));
}

void clean_house_buffer(){
    for(vec2* v : points) delete v;
}

vec2 get_image_dimensions(const char* str){
    SDL_Surface* surf = IMG_Load(str);
    vec2 result(surf->w*house_scale,surf->h*house_scale);
    SDL_DestroySurface(surf);

    return result;
}