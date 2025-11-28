#include"program.hpp"
#include"graph.hpp"
#include"map.hpp"
#include"house.hpp"
#include"sampler.hpp"
#include"background.hpp"
#include"algorithms.hpp"
#include"supplier.hpp"
#include"text.hpp"
#include"pipe.hpp"
#include"mux.hpp"

#define totalhouses 6

std::vector<object*> houses;
std::vector<pipe*> pipes;

std::vector<int> input_buffer;

SDL_Renderer* program::renderer = nullptr;
map* main_map;
sampler plotter;
background* bg = new background();
u_graph game;
supplier* pump;

void program::init(std::string title,int width,int height,SDL_WindowFlags flag){
    this->window = nullptr;
    this->renderer = nullptr;
    if(SDL_Init(SDL_INIT_VIDEO)){
        if(SDL_CreateWindowAndRenderer(title.c_str(),width,height,flag,&(this->window),&(this->renderer))){
            TTF_Init();
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
    plotter.poission_sampling(totalhouses,house_coords);
    vec2 house_dimensions = get_image_dimensions(house_texture);
    bool flag = 1;
    for(int i=0;i<house_coords.size()-1;i++){
        int temp;
        if(flag){
            temp = 1;
            flag = 0;
        }
        else temp = (rand()%5)+1; 
        houses.push_back(new house(i,temp,house_coords[i].x,house_coords[i].y));
        main_map->update_map(house_coords[i]);
        game.add_node('h',i);
    }
    pump = new supplier(house_coords[house_coords.size()-1].x,house_coords[house_coords.size()-1].y,1);
    houses.push_back(pump);
    game.add_node('s',houses.size()-1);
    main_map->update_map(house_coords[house_coords.size()-1]);

}

void program::update(){
    int completed = 0;
    for(object* h : houses){
        h->update();
        house* temp = dynamic_cast<house*>(h);
        if(temp && temp->in == temp->req){
            completed++;
            continue;
        }
    }
    for(auto p : pipes) p->update(houses);
    if(completed == totalhouses){
        completed = 0;
        clear();
        start();
    }
}

void program::clear(){
    for(auto o : houses) delete o;
    for(auto p : pipes) delete p;
    houses.clear();
    pipes.clear();
}

void program::render(){
    SDL_RenderClear(renderer);
    bg->draw();
    main_map->draw_map(); 
    for(object* h : houses)h->render();
    pump->render();
    SDL_RenderPresent(renderer);
}

void program::handle_events(){
    float currmux = 1;
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_EVENT_QUIT:
            this->running = false;
            break;
        case SDL_EVENT_KEY_DOWN:{
            SDL_Keycode button = event.key.key;
            switch(button){
                case SDLK_1:
                    currmux = 0.5;
                    break;
                case SDLK_2:
                    currmux = 2;
                    break;
                case SDLK_R:
                    clear();
                    start();
                    break;
                default:
                    this->running = false;
            }
            std::cout<< "multiplier set to: " << currmux << '\n';
            break;
        }
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            float x = event.button.x;
            float y = event.button.y;
            int h = house_clicked({x,y},houses);
            if(h != -1){
                input_buffer.push_back(h);
                if(input_buffer.size() >= 2){
                    connect(game,input_buffer,main_map->mp,houses,pipes);
                    input_buffer.clear();
                }
            }
            break;
    }
}

void program::clean(){
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
    cout<< "Window Destroyed\n";
}
