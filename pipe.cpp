#include"pipe.hpp"
#include"supplier.hpp"

pipe::pipe(std::string str,int x,int y,float mult,int one,int two,int pipeid,int in) : object(str,x,y){
    this->multiplier = mult;
    this->Sprite = new sprite(pump_texture);
    this->from = one;
    this->to = two;
    this->id = pipeid;
    this->in = in;
}

void pipe::update(const std::vector<object*>& houses){
    house* fromHouse = dynamic_cast<house*>(houses[from]);
    supplier* fromSupplier = dynamic_cast<supplier*>(houses[from]);

    if (fromSupplier)
        in = fromSupplier->supply;
    else if (fromHouse)
        in = fromHouse->in;

    out = in * multiplier;
}

void pipe::update(){}

void pipe::addmux(const std::vector<object*>& houses,float mux){
    this->multiplier = mux;
    house* temp = static_cast<house*>(houses[to]);
    if(!temp) return;
    temp->in -= this->out;
    temp->in += this->out;
}