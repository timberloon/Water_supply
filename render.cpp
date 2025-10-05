#include"program.hpp"

int main(){
    program* newprogram = new program();
    newprogram->init("new window",800,600,SDL_WINDOW_RESIZABLE);
    while(newprogram->is_running()){
        newprogram->update();
        newprogram->render();
        newprogram->handle_events();
    }
    newprogram->clean();
}
