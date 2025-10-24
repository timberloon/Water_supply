#include"program.hpp"
#include"map.hpp"
#include"house.hpp"
#include"sampler.hpp"
#include"background.hpp"
#include"algorithms.hpp"

SDL_Renderer* program::renderer = nullptr;
map* main_map;
std::vector<house*> houses;
sampler plotter;
background* bg = new background();

void program::init(std::string title,int width,int height,SDL_WindowFlags flag){
    this->window = nullptr;
    this->renderer = nullptr;
    if(SDL_Init(SDL_INIT_VIDEO)){
        if(SDL_CreateWindowAndRenderer(title.c_str(),width,height,flag,&(this->window),&(this->renderer))){
            cout<< "Window created\n";
            this->running = true;
            SDL_SetRenderDrawColor(this->renderer,0,0,0,255);
        }
        else{
            cout<< "failed to create window\n";
            this->running = false;
        }
    }
    else{
        cout<< "SDL_Init failed\n";
        this->running = false;
    }

    start();
}

void program::start(){
    main_map = new map();
    srand(time(NULL));
    std::vector<vec2> house_coords;
    plotter.poission_sampling(9,house_coords);
    vec2 house_dimensions = get_image_dimensions(house_texture);
    for(int i=0;i<house_coords.size();i++){
        houses.push_back(new house(i,house_coords[i].x,house_coords[i].y));
        main_map->update_map((int)house_coords[i].x,(int)house_coords[i].y,house_dimensions.x,house_dimensions.y);
    }

    static_render();
}

void program::update(){
    
}

void program::render(){
    // SDL_RenderClear(renderer);
    // bg->draw();
    // main_map->draw_map(); 
    // for(house* h : houses)h->render();
    // SDL_RenderPresent(renderer);
}

void program::static_render(){
    SDL_RenderClear(renderer);
    bg->draw();
    main_map->draw_map(); 
    for(house* h : houses)h->render();
    SDL_RenderPresent(renderer);
}

void program::handle_events(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_EVENT_QUIT:
            this->running = false;
            break;
        case SDL_EVENT_KEY_UP:
            this->running = false;
            break;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            float x = event.button.x;
            float y = event.button.y;
            int h = house_clicked({x,y},houses);
            if(h != -1) std::cout<< "clicked house no: " << h << '\n';
            break;
    }

}

void program::clean(){
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
    cout<< "Window Destroyed\n";
}
