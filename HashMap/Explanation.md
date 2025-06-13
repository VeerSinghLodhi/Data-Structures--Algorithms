# Unordered Map Operations in C++

This C++ program demonstrates various operations on `unordered_map` from the Standard Template Library (STL). 
The program covers the following topics:

## Features of the Program

### 1. Initializing an Unordered Map

An unordered map `cities` is initialized with the following key-value pairs:
- Sagar: 2 Lakhs
- Bhopal: 3 Lakhs
- Jabalpur: 4 Lakhs

```cpp
unordered_map<string, int> cities = {{"Sagar", 2}, {"Bhopal", 3}, {"Jabalpur", 4}};
```

### 2. Accessing Elements

- **Using `[]` Operator:** This operator adds a new key with a default value (0) if the key does not exist.

```cpp
int pop = cities["Sagar"];
cout << "\nPopulation of Sagar is " << pop << " Lakhs";
```

- **Using `at` Method:** This method retrieves the value for a given key but throws an exception if the key does not exist.

```cpp
pop = cities.at("Bhopal");
cout << "\nPopulation of Bhopal is " << pop << " Lakhs";
```

### 3. Using Iterators

- Retrieve the value for a specific key using `find` and iterators.

```cpp
unordered_map<string, int>::iterator it = cities.find("Jabalpur");
cout << "\nPopulation of Jabalpur is " << it->second << " Lakhs";
```

### 4. Printing the Map

#### Method 1: Using Range-Based Loop

```cpp
for (auto a : cities)
    cout << "\n" << a.first << ", " << a.second;
```

### 5. Searching for Keys

- Search for a key using `find` and check if the iterator is not equal to `end()`.

```cpp
unordered_map<string, int>::iterator it1 = cities.find("Sagar");
if (it1 != cities.end()) {
    cout << "\nFound!!";
} else {
    cout << "\nNot Found!!";
}
```

### 6. Adding Elements

- **Using `insert` Method:**

```cpp
cities.insert(make_pair("Damoh", 1));
```

- **Using `[]` Operator:**

```cpp
cities["Indore"] = 3;
```

### 7. Printing After Modifications

- After inserting new elements, print the entire map.

```cpp
cout << "\n\nAfter Insert Damoh\n";
for (auto i : cities)
    cout << "\n" << i.first << ", " << i.second;

cout << "\n\nAfter Insert Indore\n";
for (auto i : cities)
    cout << "\n" << i.first << ", " << i.second;
```

## Notes on `unordered_map`

- **Key-Value Structure:**
  - Key: Acts as the primary identifier.
  - Value: Stores the associated data.

```cpp
unordered_map<string, int> cities;
         |     |
        Key   Value
```

- **Performance:**
  - Average complexity of operations like insertion, deletion, and search is `O(1)`.

- **No Specific Order:** Elements are not stored in any specific order.

## Sample Output

```
Population of Sagar is 2 Lakhs
Population of Bhopal is 3 Lakhs
Population of Jabalpur is 4 Lakhs

PRINTING COMPLETE MAP
Method 1
Sagar, 2
Bhopal, 3
Jabalpur, 4
Found!!

After Insert Damoh
Sagar, 2
Bhopal, 3
Jabalpur, 4
Damoh, 1

After Insert Indore
Sagar, 2
Bhopal, 3
Jabalpur, 4
Damoh, 1
Indore, 3
```

## Conclusion

This program provides a comprehensive understanding of `unordered_map` operations in C++, including initialization, element access, iteration, searching, and modification.
