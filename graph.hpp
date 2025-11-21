#pragma once
#include<iostream>
#include<vector>
#include"list.hpp"
#include<memory>

struct graphnode{
    int id;
    char type;
    mlist<int> edges;
};

class u_graph{
private:
    vector<std::unique_ptr<graphnode>> nodes;
    vector<bool> space;
    int curr;

    void re_size();
public:
    u_graph();
    ~u_graph();

    template<typename...args>
    void add_node(char type,int idx,args...val);
    void add_node(char type,int idx);

    template<typename... Args>
    void make_connections(Args... args) {
        vector<int> arguments = {args...};

        for(int i=0;i<arguments.size();i++){
            for(int j=i+1;j<arguments.size();j++){
                int a = arguments[i];
                int b = arguments[j];

                if(space[a] && space[b]){
                    nodes[a]->edges.insert_head(b);
                    nodes[b]->edges.insert_head(a);
                }
                else{
                    cout<< "invalid connection between " << a << " and " << b << endl;
                }
            }
        }
    }
    void make_connections();

    void delete_node(int id);
    void delete_connection(int v1,int v2);

    void show_connections(int id);
};
