#include"program.hpp"
#include"vector2.hpp"

class object{
private:
    SDL_Renderer* renderer;

protected:
    SDL_FRect destR;
    const char* texture;

public:
    int xpos,ypos;
    object(std::string str,int x ,int y);
    object(int x,int y);
    virtual void update() = 0;
    void render();
    vec2 get_texture_dimensions();
};