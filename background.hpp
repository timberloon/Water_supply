#include"program.hpp"

class background{
private:
    std::string texture;
    SDL_FRect destR;
public:
    background();
    background(std::string str);
    void draw();
    ~background();
};