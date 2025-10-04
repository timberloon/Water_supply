#include<iostream>
using namespace std;

template<typename u>
struct node{
    u data;
    node<u>* next;
};

template<typename t>
class mlist{
private:
    node<t>* head;
    node<t>* tail;

    node<t>* createnode(t val){
        node<t>* temp = new node<t>;
        temp->data = val;
        temp->next = nullptr;
        return temp;
    }

    void delete_head(){
        node<t>* temp = head;
        head = head->next;
        delete temp;
    }
public:
    mlist(){  
        head = nullptr;
        tail = nullptr;
    }
    mlist(t val){
        head = new node<t>;
        head->data = val;
        head->next = nullptr;
        tail = head;
    }

    ~mlist(){}

    void insert_end(t val){
        if(!head){
            head = createnode(val);
            tail = head;
            return;
        }
        tail->next = createnode(val);
        tail = tail->next;
    }

    void insert_head(t val){
        if(!head){
            head = createnode(val);
            tail = head;
            return;
        }
        node<t>* temp = createnode(val);
        temp->next = head;
        head = temp;
    }

    void delete_val(t val){
        while(head && head->data == val){
            delete_head();
        }
        node<t>* temp = head;
        while(temp && temp->next){
            if(temp->next->data == val){
                if(temp->next == tail) tail - temp;
                node<t>* buffer = temp->next;
                temp->next = temp->next->next;
                delete buffer;
            }
            else temp = temp->next;
        }
    }

    bool find(t val){
        node<t>* temp = head;
        while(temp){
            if(temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void display(){
        if(!head){
            cout<<"List is empty\n";
            return;
        }
        node<t>* temp = head;
        while(temp){
            cout<< temp->data << ' ';
            temp = temp->next;
        }
        cout<< '\n';
    }

    void delete_list(){
        node<t>* temp = head;
        while(temp){
            node<t>* buffer = temp;
            temp = temp->next;
            delete buffer;
        }
        head = nullptr;
    }
};
