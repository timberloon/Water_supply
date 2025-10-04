#include"list.hpp"
#include<vector>

struct graphnode{
    int id;
    char type;
    mlist<int> edges;
};

template<int n>
class u_graph{
private:
    graphnode* nodes[n];
    bool space[n];
    int curr;

public:
    u_graph(){
        for(int i=0;i<n;i++){
            nodes[i] = new graphnode;
            nodes[i]->id = i;
            space[i] = false;
        }
        this->curr = 0;
    }
    ~u_graph(){
        for(int i=0;i<n;i++) delete nodes[i];
    }

    template<typename...args>
    void add_node(char type,args...val){
        this->curr = 0;
        while(space[curr] == true) curr++;
        nodes[curr]->type = type;
        space[curr] = true;
        make_connections(curr,val...);
        cout<< "Node created with id: " << curr << endl;
    }
    void add_node(char type){
        this->curr = 0;
        while(space[curr] == true) curr++;
        nodes[curr]->type = type;
        space[curr] = true;
        cout<< "Node created with id: " << curr << endl;
    }

    template<typename... Args>
    void make_connections(Args... args) {
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
    void make_connections(){}

    void delete_node(int id){
        delete nodes[id];
        nodes[id] = new graphnode;
        space[id] = false;

        for(int i=0;i<n;i++){
            nodes[i]->edges.delete_val(id);
        }
        cout<< "Node deleted with id: " << id << endl;
    }

    void show_connections(int id){
        nodes[id]->edges.display();
    }

    void delete_connection(int v1,int v2){
        nodes[v1]->edges.delete_val(v2);
        nodes[v2]->edges.delege_val(v1);
    }


};

int main(){
    u_graph<10> grph;
    grph.add_node('h');
    grph.add_node('h',0);
    grph.add_node('h',0);
    grph.add_node('h',1);
    grph.make_connections(0,3);
    grph.show_connections(3);
    grph.show_connections(0);
    grph.show_connections(0);
}
