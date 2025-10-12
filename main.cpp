#include"program.hpp"

int main(){
    const int fps = 60;
    const int framedelay = 1000/fps;

    program* newprogram = new program();
    newprogram->init("new window",800,600,SDL_WINDOW_RESIZABLE);

    Uint32 framestart;
    int frametime;

    while(newprogram->is_running()){
        newprogram->handle_events();
        newprogram->render();
        newprogram->update();

        frametime = SDL_GetTicks()-framestart;
        if(framedelay>frametime){
            SDL_Delay(framedelay-frametime);
        }
    }
    newprogram->clean();

    return 0;
}
