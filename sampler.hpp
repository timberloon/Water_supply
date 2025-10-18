#include"program.hpp"

class sampler{
private:
    int rad,k;
    std::vector<vec2> active;
    vec2 house_dim;
public:
    sampler();
    ~sampler();
    vec2 get_image_dimensions(const char* str);
    inline std::shared_ptr<vec2> rand_coord(vec2 pos);
    bool check(std::vector<vec2>& houses,vec2 currpt);
    void poission_sampling(int tries,std::vector<vec2>& houses);
};
