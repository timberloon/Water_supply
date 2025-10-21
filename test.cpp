#include<iostream>
#include"vector2.hpp"

int main(){
    vec2 one(1,1);
    vec2 two(1,1);
    vec2 three(2,4);

    std::cout<< (one==two) << ' ' << (one==three);
}