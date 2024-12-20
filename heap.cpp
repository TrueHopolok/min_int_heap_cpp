#include "heap.hpp"

//* PRIVATE METHODS

void MinHeap::push_down(int i) {
    const int 
    l = (i << 1) + 1;
    if (l >= len) return; // l is out of range

    const int 
    r = l + 1, 
    vi = arr[i], 
    vl = arr[l];
    if (r >= len) { // r is out of range
        if (vi <= vl) return; // i is smallest of the two
        arr[i] = vl;
        arr[l] = vi;
        return;
    }

    const int 
    vr = arr[r];
    if (vr <= vl) { // r is smallest beetwen l and r
        if (vi <= vr) return; // i is smallest of the three
        arr[i] = vr;
        arr[r] = vi;
        push_down(r);
    } else { // l is smallest beetwen l and r
        if (vi <= vl) return; // i is smallest of the three
        arr[i] = vl;
        arr[l] = vi;
        push_down(l);
    }
}

void MinHeap::push_up(int i) {
    if (0 == i) return; // i is at the top
    const int
    u = (i - 1) >> 1,
    vi = arr[i],
    vu = arr[u];
    if (vu > vi) { // if parent is bigger than son
        arr[i] = vu;
        arr[u] = vi;
        push_up(u);
    }
}

//* CONSTRUCTORS AND DESTRUCTOR

MinHeap::MinHeap(int capacity) {
    if (capacity <= 0) throw std::range_error("given capacity is less or equal then 0");
    arr = new int[capacity];
    len = 0;
    cap = capacity;
}

MinHeap::MinHeap(int* data_start, int* data_end) {
    if (data_end < data_start) throw std::range_error("given end pointer is before start pointer");
    const int capacity = data_end - data_start + 1; 
    arr = data_start;
    len = capacity;
    cap = capacity;
    for (int i = capacity>>1; i >= 0; i--) push_down(i);
}

MinHeap::~MinHeap() {
    delete[] arr;
}

//* SIZE RELATED METHODS

bool MinHeap::empty() const {
    return len == 0;
}

bool MinHeap::full() const {
    return len == cap;
}

int MinHeap::size() const {
    return len;
}

int MinHeap::capacity() const {
    return cap;
}

//* ELEMENT MANAGEMENT METHODS

int MinHeap::top() const {
    if (len == 0) throw std::range_error("heap is empty");
    return arr[0];
}

int MinHeap::pop() {
    if (len == 0) throw std::range_error("heap is empty");
    int min_value = arr[0];
    len--;
    arr[0] = arr[len];
    push_down(0);
    return min_value;
}

void MinHeap::insert(int value) {
    if (len == cap) throw std::range_error("heap is full");
    arr[len] = value;
    len++;
    push_up(len-1);
}

void MinHeap::print() const {
    for (int i = 0; i < len; i++) std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

