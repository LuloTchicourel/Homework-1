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
    if (list->size == 0) list->tail = new_node;
    list->size++;
    return;
}

void push_back(List *list, int value){
    shared_ptr<Node> new_node = create_node(value);
    if (list->size == 0){
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
    return;
}

void insert(List *list, int value, int pos){
    if (pos + 1 > list->size){
        cout << "Position exceeds length of list, value has been pushed back." << endl;
        push_back(list, value);
        return;
    }

    if (pos == 0) {push_front(list, value); return;}

    shared_ptr<Node> curr = list->head;
    for (int i = 0; i < pos - 1; i++){
        curr = curr->next;
    }    

    shared_ptr<Node> new_node = create_node(value);
    new_node->next = curr->next;
    curr->next = new_node;
    list->size++;
    return;
}

void erase(List *list, int pos) {
    if (list->size == 0) {
        cout << "List is empty, there is nothing to erase." << endl;
        return;
    }
    if (pos + 1 > list->size) {
        cout << "Position exceeds length of list, erasing last node." << endl;
        pos = list->size - 1;
    }
    if (pos == 0) {
        list->head = list->head->next; 
        list->size--;
        if (list->size == 0) list->tail = nullptr;
        return;
    }
    shared_ptr<Node> curr = list->head;
    for (int i = 0; i < pos - 1; i++) curr = curr->next;
    shared_ptr<Node> temp = curr->next;
    curr->next = temp->next; 
    if (pos == list->size - 1) list->tail = curr;
    list->size--;
}

void print_list(List *list) {
    if (!list->head) {
        cout << "List is empty." << endl;
        return;
    }
    shared_ptr<Node> temp = list->head;
    while (temp) {
        cout << temp->value;
        if (temp->next) cout << " -> "; 
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}