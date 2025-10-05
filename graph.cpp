#include"graph.hpp"

template<int n>
u_graph<n>::u_graph(){
    for(int i=0;i<n;i++){
            nodes[i] = new graphnode;
            nodes[i]->id = i;
            space[i] = false;
        }
        this->curr = 0;
}

template<int n>
u_graph<n>::~u_graph(){
    for(int i=0;i<n;i++) delete nodes[i];
}

template<int n>
template<typename...args>
void u_graph<n>::add_node(char type,args...val){
    this->curr = 0;
    while(space[curr] == true) curr++;
    nodes[curr]->type = type;
    space[curr] = true;
    make_connections(curr,val...);
    cout<< "Node created with id: " << curr << endl;
}

template<int n>
void u_graph<n>::add_node(char type){
    this->curr = 0;
    while(space[curr] == true) curr++;
    nodes[curr]->type = type;
    space[curr] = true;
    cout<< "Node created with id: " << curr << endl;
}

template<int n>
template<typename... Args>
void u_graph<n>::make_connections(Args... args) {
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

template<int n>
void u_graph<n>::make_connections(){}

template<int n>
void u_graph<n>::delete_node(int id){
    delete nodes[id];
    nodes[id] = new graphnode;
    space[id] = false;

    for(int i=0;i<n;i++){
        nodes[i]->edges.delete_val(id);
    }
    cout<< "Node deleted with id: " << id << endl;
}

template<int n>
void u_graph<n>::show_connections(int id){
    nodes[id]->edges.display();
}

template<int n>
void u_graph<n>::delete_connection(int v1,int v2){
    nodes[v1]->edges.delete_val(v2);
    nodes[v2]->edges.delege_val(v1);
}
