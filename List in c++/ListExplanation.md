# List Operations in C++

This C++ program demonstrates various operations on `std::list` from the Standard Template Library (STL).
The program covers the following topics:

## Features of the Program

### 1. Initializing a List

A list is initialized with elements using different methods:

#### Direct Initialization

```cpp
list<int> mylist = {10, 20, 30, 40, 50};
```

#### Default Initialization and Adding Elements

```cpp
list<int> mylist;
mylist.push_back(10);
mylist.push_back(20);
mylist.push_back(30);
```

### 2. Accessing Elements

Lists do not support direct access using an index. You must use iterators to traverse and access elements:

```cpp
for (auto it = mylist.begin(); it != mylist.end(); ++it) {
    cout << *it << " ";
}
```

### 3. Adding and Removing Elements

- **Add Elements to Front and Back:**

```cpp
mylist.push_front(5);   // Adds 5 at the front
mylist.push_back(60);   // Adds 60 at the back
```

- **Remove Specific Element:**

```cpp
mylist.remove(20);  // Removes the first occurrence of 20
```

- **Erase Elements Using Iterators:**

```cpp
auto it = mylist.begin();
advance(it, 2);  // Move iterator to the 3rd element
mylist.erase(it);
```

### 4. Traversing the List

#### Method 1: Range-Based Loop

```cpp
for (auto element : mylist) {
    cout << element << " ";
}
```

#### Method 2: Using Iterators

```cpp
for (auto it = mylist.begin(); it != mylist.end(); ++it) {
    cout << *it << " ";
}
```

### 5. Sorting and Reversing the List

- **Sort the List:**

```cpp
mylist.sort();
```

- **Reverse the List:**

```cpp
mylist.reverse();
```

### 6. Merging Two Lists

Combine two lists into one:

```cpp
list<int> list2 = {15, 25, 35};
mylist.merge(list2);
```

### 7. Clearing and Checking the List

- **Clear All Elements:**

```cpp
mylist.clear();
```

- **Check if List is Empty:**

```cpp
if (mylist.empty()) {
    cout << "List is empty";
}
```

## Notes on `std::list`

- **Doubly Linked List:**
  - Each element in a `std::list` is stored in a node with pointers to the next and previous nodes.

- **Advantages:**
  - Efficient insertion and deletion of elements at any position (O(1) if the iterator is known).

- **Disadvantages:**
  - No direct access to elements (unlike `std::vector`).

## Sample Output

```
Initial List: 10 20 30 40 50 
After Adding Elements: 5 10 20 30 40 50 60 
After Removing 20: 5 10 30 40 50 60 
After Sorting: 5 10 30 40 50 60 
After Reversing: 60 50 40 30 10 5 
After Merging Another List: 5 10 15 25 30 35 40 50 60 
List is now empty.
```

## Conclusion

This program provides an overview of common `std::list` operations in C++. By understanding these operations, you can effectively use `std::list` in your programs where dynamic insertion and deletion are required.
