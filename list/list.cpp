#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List myList = {nullptr, nullptr, 0};

    cout << "\nInitial list:\n" << endl;
    print_list(&myList);

    cout << "\nTesting push_front() and push_back():" << endl;
    push_front(&myList, 10);
    print_list(&myList);
    push_back(&myList, 20);
    print_list(&myList);
    push_back(&myList, 30);
    print_list(&myList);
    push_front(&myList, 5);
    print_list(&myList);

    cout << "\nTesting insert():" << endl;
    insert(&myList, 15, 2); 
    print_list(&myList);
    insert(&myList, 1, 0); 
    print_list(&myList);
    insert(&myList, 40, 10);
    print_list(&myList);

    cout << "\nTesting erase():" << endl;
    erase(&myList, 2);  
    print_list(&myList);
    erase(&myList, 0);  
    print_list(&myList);
    erase(&myList, 10); 
    print_list(&myList);

    cout << "\nAll tests have been completed." << endl;
    return 0;
}