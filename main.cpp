#include "heap.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

void print_everything(const MinHeap& h) {
    cout 
    << "Empty= " << h.empty() 
    << " | Size= " << h.size() 
    << " | Cap= " << h.capacity() 
    << " | Full= " << h.full() 
    << endl
    << "Data= ";
    h.print();
}

void print_sorted(MinHeap &h) {
    cout << "Sorted= ";
    while (!h.empty()) {
        cout << h.pop() << " ";
    }
    cout << endl;
}

int main() {
    cout << endl << "---------------------------" << endl;

    cout << endl << "Initialization on existing array:" << endl;
    int a[] = {4, 3, 2, 1, 5, 6};
    MinHeap h2(a, a + sizeof(a)/sizeof(a[0]) - 1);
    print_everything(h2);
    print_sorted(h2);

    cout << endl << "---------------------------" << endl;

    cout << endl << "Regular initialization:" << endl;
    MinHeap h(4);
    print_everything(h);
    
    cout << endl << "Insertion (ok):" << endl << "Top element= ";
    h.insert(5); cout << h.top() << " ";
    h.insert(3); cout << h.top() << " ";
    h.insert(2); cout << h.top() << " ";
    h.insert(4); cout << h.top() << endl;
    print_everything(h);

    cout << endl << "Deletion (ok):" << endl;
    cout << "Deleted= " << h.pop() <<  " " << h.pop() << endl;
    print_everything(h);

    cout << endl << "---------------------------" << endl;

    cout << endl << "Insertion (error):" << endl;
    try {
       h.insert(10); h.insert(15); h.insert(3); return -1;
    } catch (runtime_error e) {
        cout << e.what() << endl;
    }

    cout << endl << "Deletion (error):" << endl;
    try {
       h.pop(); h.pop(); h.pop(); h.pop(); h.pop(); return -1;
    } catch (runtime_error e) {
        cout << e.what() << endl;
    }

    cout << endl << "---------------------------" << endl;
    
    return 0;
}