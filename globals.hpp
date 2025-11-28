#pragma once

//? window
constexpr int window_width = 800;
constexpr int window_height = 640;

//? textures
constexpr float house_scale = 0.5;
constexpr const char* house_texture = "assets/houses/1.png";
constexpr const char* background_image = "assets/water.png";
constexpr const char* supplier_texture = "assets/tower.png";
constexpr const char* mux_texture = "assets/grass.png";
constexpr const char* pump_texture = "assets/water.png";

//? font
constexpr int letter_size = 22;
constexpr SDL_Color font_color = {(Uint8)255,(Uint8)255,(Uint8)255,(Uint8)255};
constexpr SDL_Color green = {(Uint8)0,(Uint8)255,(Uint8)0,(Uint8)255};
constexpr const char* font_path = "assets/fonts/Comic Sans MS 400.ttf";

//? map
constexpr int mapscale = 32;
constexpr int maprows = 20;
constexpr int mc = 25;
