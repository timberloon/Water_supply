#include"sampler.hpp"

sampler::sampler(){
    rad = 150;
    k = 100;
    house_dim = get_image_dimensions(house_texture);
}

sampler::~sampler(){}

vec2 sampler::get_image_dimensions(const char* str){
    SDL_Surface* surf = IMG_Load(str);
    vec2 result(surf->w*house_scale,surf->h*house_scale);
    SDL_DestroySurface(surf);

    return result;
}

std::shared_ptr<vec2> sampler::rand_coord(vec2 pos){
    std::shared_ptr<vec2> p_vec(new vec2());
    float angle = ((float)rand() / RAND_MAX) * 2 * M_PI;
    float r = rad * (1 + ((float)rand() / RAND_MAX));
    p_vec->x = pos.x + r * cos(angle);
    p_vec->y = pos.y + r * sin(angle);

    return p_vec;
}

bool sampler::check(std::vector<vec2>& houses,vec2 currpt){
    for(vec2& house : houses){
        if(currpt.distance(house)<rad) return false;
    }
    return true;
}

void sampler::poission_sampling(int tries,std::vector<vec2>& houses){
    vec2 start((window_width/2)-house_dim.x/2,(window_height/2)-house_dim.y/2);
    active.push_back(start);
    houses.push_back(start);
    while(tries-- && !active.empty()){
        bool can_generate = false;
        int buffer = rand()%active.size();
        for(int i=0;i<k;i++){
            buffer = rand() % active.size();
            auto& base = active[buffer];
            std::shared_ptr<vec2> currpt = rand_coord(base);
            float half_w = house_dim.x / 2.0f;
            float half_h = house_dim.y / 2.0f;

            if (currpt->x < half_w || currpt->x > window_width - house_dim.x ||
                currpt->y < half_h || currpt->y > window_height - house_dim.y)
                continue;
            bool temp = check(houses,*currpt);
            if(temp){
                active.push_back(*currpt);
                houses.push_back(*currpt);
                can_generate = true;
                break;
            }
        }
        if(!can_generate) active.erase(active.begin()+buffer);
    }
}
