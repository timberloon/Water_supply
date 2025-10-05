#include<iostream>
#include<vector>
#include"list.hpp"
#include<memory>

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
    u_graph();
    ~u_graph();

    template<typename...args>
    void add_node(char type,args...val);
    void add_node(char type);

    template<typename... Args>
    void make_connections(Args... args);
    void make_connections();

    void delete_node(int id);
    void delete_connection(int v1,int v2);

    void show_connections(int id);
};
