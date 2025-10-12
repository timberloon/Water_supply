#include"texmanager.hpp"

SDL_Texture* texmanager::load_texture(const char* tex){
    SDL_Surface* surface = IMG_Load(tex);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(program::renderer,surface);
    SDL_DestroySurface(surface);

    return texture;
}

void texmanager::draw(SDL_Texture* tex,SDL_FRect rect){
    SDL_RenderTexture(program::renderer,tex,NULL,&rect);
}
