#include"graph.hpp"


u_graph::u_graph(){
    this->curr = 0;
    nodes.resize(1);
    space.resize(1,false);
}

u_graph::~u_graph(){

}

template<typename...args>
void u_graph::add_node(char type,int idx,args...val){
    this->curr = 0;
    if(!space.empty()){
        while(space[curr] == true && curr < nodes.size()) curr++;
        if(curr >= nodes.size()) re_size();
    }
    nodes[curr] = std::make_unique<graphnode>();
    nodes[curr]->type = type;
    nodes[curr]->id = idx;
    space[curr] = true;
    make_connections(curr,val...);
    cout<< "Node created with id: " << curr << endl;
}

void u_graph::add_node(char type,int idx){
    this->curr = 0;
    if(!space.empty()){
        while(space[curr] == true && curr < nodes.size()) curr++;
        if(curr >= nodes.size()) re_size();
    }
    nodes[curr] = std::make_unique<graphnode>();
    nodes[curr]->id = idx;
    nodes[curr]->type = type;
    space[curr] = true;
    cout<< "Node created with id: " << idx << endl;
}

void u_graph::make_connections(){}

void u_graph::delete_node(int id){
    space[id] = false;

    for(int i=0;i<nodes.size();i++){
        nodes[i]->edges.delete_val(id);
    }
    cout<< "Node deleted with id: " << id << endl;
}

void u_graph::show_connections(int id){
    std::cout<< "connections for " << id << ": ";
    nodes[id]->edges.display();
}

void u_graph::delete_connection(int v1,int v2){
    nodes[v1]->edges.delete_val(v2);
    nodes[v2]->edges.delete_val(v1);
}

void u_graph::re_size(){
    nodes.resize(nodes.size()*2);
    int temp = space.size();
    space.resize(space.size()*2);
    for(int i=temp;i<space.size();i++) space[i] = false;
}
