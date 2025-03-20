#include <iostream>
#include <memory>

using namespace std;

struct Node {
    shared_ptr<Node> next;
    int value;
};

struct List {
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    u_int8_t size;
};

shared_ptr<Node> create_node(int value){
    shared_ptr<Node> node = make_shared<Node>();
    node->next = nullptr;
    node->value = value;
    return node;
}

void push_front(List *list, int value){
    shared_ptr<Node> new_node = create_node(value);
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    return;
}

void push_back(List *list, int value){
    shared_ptr<Node> new_node = create_node(value);
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    return;
}

void insert(List *list, int value, int pos){
    if (pos + 1 > list->size){
        list->tail = create_node(value);
        return;
    }
    shared_ptr<Node> curr = list->head;
    for (int i = 0; i <= pos; i++){
        curr = curr->next;
    }    
}

void erase(){

}

void print_list(){

}