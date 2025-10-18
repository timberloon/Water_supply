#include"vector2.hpp"
#include<math.h>

vec2::vec2(){
    x = 0;
    y=0;
}

vec2::vec2(float x,float y){
    this->x = x;
    this->y = y;
}

float vec2::mod(){
    return sqrt((x*x)+(y*y));
}

float vec2::distance(vec2 other){
    vec2 temp = *this-other;
    return temp.mod();
}

vec2 vec2::operator-(vec2& other){
    float tempx = other.x;
    float tempy = other.y;

    vec2 newvec(abs(tempx-this->x),abs(tempy-this->y));
    return newvec;
}

vec2::~vec2(){
    
}