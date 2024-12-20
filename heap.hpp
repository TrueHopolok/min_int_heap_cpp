#pragma once
#include <stdexcept>
#include <iostream>
class MinHeap {
    //! --------------------------------------
    private:

    //* PRIVATE FIELDS

    int* arr;
    int  len;
    int  cap;

    //* PRIVATE METHODS

    void push_down(int i);
    void push_up(int i);

    //! --------------------------------------
    public:

    //* CONSTRUCTORS AND DESTRUCTOR

    /*
    
    @brief Allocates memory for an empty heap.
    
    ---

    @param capacity Max possible size of a heap.

    @note Time complexity: `O(cap)`
    
    */
    MinHeap(int capacity);

    /*
    
    @brief Heapify an array.

    ---

    Full description:

    ```txt
    Method works in place. Array is heapified.
    Heapify works by continuously pushing all elements down so in the end all properties of the heap are restored.
    ```

    ---

    @param data_start Pointer to the first element of an array.
    @param data_end Pointer to the last element of an array. 
    @throws `std::range_error` if pointer to the end of an array is before the pointer of the start of an array.

    @note Time complexity: `O(cap * log[cap]), size == cap`

    */
    MinHeap(int* data_start, int* data_end);

    /*

    @brief Free allocated memory of the heap.

    ---

    @note Time complexity: `O(cap)`

    */
    ~MinHeap();

    //* SIZE RELATED METHODS

    /*
    
    @brief Check whether heap is empty.

    ---
    
    @note Time complexity: `O(1)`
    
    */
    bool empty() const;

    /*
    
    @brief Check whether heap is full.

    ---
    
    @note Time complexity: `O(1)`
    
    */
    bool full() const;
    
    /*
    
    @brief Return amount of elements in the heap.

    ---
    
    @return Size of the heap.

    @note Time complexity: `O(1)`
    
    */
    int  size() const;


    /*
    
    @brief Return maximum amount of elements in the heap.

    ---

    @return Capacity of the heap. 

    @note Time complexity: `O(1)`
    
    */
    int  capacity() const;

    //* ELEMENT MANAGEMENT METHODS
    
    /*
    
    @brief Return a value of a min/top element of the heap.

    ---

    @return Min/Top value of the heap.
    @throws `std::range_error` if heap was empty.

    @note Time complexity: `O(1)`

    */
    int  top() const;

    /*
    
    @brief Remove a top element from the heap and return it.

    ---

    Full description:

    ```txt
    Save old min/top element, then placing last element onto place of the first.
    After that continuously pushing it down till heap properties are restored.
    ```
    
    ---

    @return Min/Top value of the heap.
    @throws `std::range_error` if the heap was empty.

    @note Time complexity: `O(log[size])`

    */
    int  pop();

    /*
    
    @brief Insert new element into heap.
    
    ---

    Full description:

    ```txt
    Insert new element into first available place in the heap.
    After that continuously pushing it up till heap properties are restored.
    ```

    ---

    @throws `std::range_error` if the heap was full.

    @note Time complexity: `O(log[size])`

    */
    void insert(int value);

    /*

    @brief Prints in stdout all elements of a heap.

    ---

    Full description:

    ```txt
    This method prints all elements in stdout using cout.
    All elements come with space and last element is followed by space and empty string.
    In case of empty heap, method just output newline.
    ```

    ---

    @note Time complexity: `O(size)`
    
    */
    void print() const;
    //! --------------------------------------
};