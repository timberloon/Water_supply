#include"program.hpp"
#include"map.hpp"
#include"house.hpp"
#include"algorithms.hpp"

SDL_Renderer* program::renderer = nullptr;
map* main_map;
vector<house*> houses;

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
    main_map = new map();
    srand(time(NULL));
    for(int i=0;i<5;i++){
        int temp1,temp2;
        pos_generate(temp1,temp2);
        houses.push_back(new house(i,temp1,temp2));
    }
    clean_house_buffer();
}

void program::update(){
    
}

void program::render(){
    SDL_RenderClear(renderer);
    main_map->draw_map();
    for(house* h : houses) h->render();
    SDL_RenderPresent(renderer);
}

void program::handle_events(){
    SDL_Event event;
    SDL_PollEvent(&event);
    if(event.type == SDL_EVENT_QUIT) this->running = false;
}

void program::clean(){
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
    cout<< "Window Destroyed\n";
}
