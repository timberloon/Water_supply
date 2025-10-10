#include"program.hpp"

class object{
private:
    SDL_Renderer* renderer;

protected:
    SDL_FRect* destR;
    const char* texture;
    int xpos,ypos;

public:
    object(std::string str,int x ,int y,int width,int height);
    virtual void update() = 0;
    void render();
};