#include"graph.hpp"


u_graph::u_graph(){
    this->curr = 0;
}

u_graph::~u_graph(){
    for(int i=0;i<nodes.size();i++) delete nodes[i];
}

template<typename...args>
void u_graph::add_node(char type,args...val){
    this->curr = 0;
    while(space[curr] == true && curr < nodes.size()) curr++;
    if(curr >= nodes.size()) re_size();
    nodes[curr] = new graphnode();
    nodes[curr]->type = type;
    space[curr] = true;
    make_connections(curr,val...);
    cout<< "Node created with id: " << curr << endl;
}

void u_graph::add_node(char type){
    this->curr = 0;
    while(space[curr] == true && curr < nodes.size()) curr++;
    if(curr >= nodes.size())re_size();
    nodes[curr] = new graphnode();
    nodes[curr]->id = curr;
    nodes[curr]->type = type;
    space[curr] = true;
    cout<< "Node created with id: " << curr << endl;
}

template<typename... Args>
void u_graph::make_connections(Args... args) {
    vector<int> arguments = {args...};

    for(int i=0;i<arguments.size();i++){
        for(int j=i+1;j<arguments.size();j++){
            int a = arguments[i];
            int b = arguments[j];

            if(space[a] && space[b]){
                nodes[a]->edges.insert_end(b);
                nodes[b]->edges.insert_end(a);
            }
            else{
                cout<< "invalid connection between " << a << " and " << b << endl;
            }
        }
    }
}

void u_graph::make_connections(){}

void u_graph::delete_node(int id){
    delete nodes[id];
    space[id] = false;

    for(int i=0;i<nodes.size();i++){
        nodes[i]->edges.delete_val(id);
    }
    cout<< "Node deleted with id: " << id << endl;
}

void u_graph::show_connections(int id){
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