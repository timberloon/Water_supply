#pragma once
#include"program.hpp"

class vec2{
public:
    float x,y;
    vec2();
    vec2(float x,float y);
    ~vec2();

    float mod();
    vec2 operator-(vec2& other);
    bool operator==(vec2& other);
    float distance(vec2 other);
};