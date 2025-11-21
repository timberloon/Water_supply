#include"texmanager.hpp"

SDL_Texture* texmanager::load_texture(const char* tex){
    SDL_Surface* surface = IMG_Load(tex);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(program::renderer,surface);
    SDL_SetTextureScaleMode(texture,SDL_SCALEMODE_NEAREST);
    SDL_DestroySurface(surface);

    return texture;
}

SDL_Texture* texmanager::load_texture_from_surface(SDL_Surface* surf){
    SDL_Texture* texture = SDL_CreateTextureFromSurface(program::renderer,surf);
    SDL_SetTextureScaleMode(texture,SDL_SCALEMODE_NEAREST);
    return texture;
}

void texmanager::draw(SDL_Texture* tex,SDL_FRect rect){
    SDL_RenderTexture(program::renderer,tex,NULL,&rect);
}
