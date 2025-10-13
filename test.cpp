#include<iostream>
#include<ctime>

int main(){
    srand(time(NULL));
    for(int i=0;i<50;i++){
        int temp = (rand()%50)+1;
        std::cout<< temp << ' ';
    }
}