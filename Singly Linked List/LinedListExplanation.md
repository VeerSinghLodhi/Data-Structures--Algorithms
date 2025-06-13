# Student Management System Using Linked List in C

This program demonstrates the creation and management of a linked list for storing student records. Each student has a roll number, name, and a pointer to the next student in the list.

## Features of the Program

### 1. Data Structure

A `struct Student` is used to store information about each student:

```c
struct Student {
    int rollno;             // Student's roll number
    char name[20];          // Student's name
    struct Student *next;   // Pointer to the next student
} *head;
```

- `head`: Pointer to the first student in the linked list.

### 2. Adding a New Student

The `add()` function performs the following steps:

1. Allocates memory for a new `Student` structure using `malloc`.
2. Takes the roll number and name of the student as input.
3. If the list is empty, the new student becomes the head of the list.
4. Otherwise, traverses the list to find the last student and appends the new student.

```c
void add() {
    struct Student *s, *p, *prev;
    s = (struct Student*)malloc(sizeof(struct Student));
    if (s == NULL)
        printf("\nCannot allocate memory!!");
    else {
        printf("\nEnter Roll no: ");
        scanf("%d", &s->rollno);
        printf("\nEnter name: ");
        scanf("%s", &s->name);
        if (head == NULL) {
            head = s;
            s->next = NULL;
        } else {
            for (p = head; p != NULL; p = p->next)
                prev = p;
            prev->next = s;
            s->next = NULL;
        }
    }
}
```

### 3. Displaying All Students

The `show()` function iterates through the linked list, printing the details of each student:

```c
void show() {
    struct Student *veer;
    for (veer = head; veer != NULL; veer = veer->next) {
        printf("\nRoll no: %d", veer->rollno);
        printf("\nName: %s", veer->name);
        printf("\n-------------------------------");
    }
}
```

### 4. User Interaction

The program uses a menu-driven interface for the following operations:

1. Add a new student.
2. Display all students.
3. Exit the program.

```c
void main() {
    head = NULL;
    int c;
    do {
        printf("\n1. Add new Student ");
        printf("\n2. Show all Students");
        printf("\n3. Exit");
        printf("\nSelect a Choice: ");
        scanf("%d", &c);
        if (c == 1)
            add();
        else if (c == 2)
            show();
    } while (c != 3);
    printf("\nThank You!!");
}
```

## Sample Output

```
1. Add new Student 
2. Show all Students
3. Exit
Select a Choice: 1

Enter Roll no: 101
Enter name: Veer

1. Add new Student 
2. Show all Students
3. Exit
Select a Choice: 1

Enter Roll no: 102
Enter name: Muskan

1. Add new Student 
2. Show all Students
3. Exit
Select a Choice: 2

Roll no: 101
Name: Veer
-------------------------------
Roll no: 102
Name: Muskan
-------------------------------

1. Add new Student 
2. Show all Students
3. Exit
Select a Choice: 3
Thank You!!
```

## Notes on Linked List Implementation

- **Dynamic Memory Allocation:** Each node is allocated memory dynamically, ensuring efficient use of memory.
- **Traversal:** The `add` function traverses the list to append the new node at the end.
- **Advantages:** Linked lists provide dynamic storage and ease of insertion and deletion compared to arrays.
- **Limitations:** Linked lists do not allow direct access to elements and require traversal for operations.

## Conclusion

This program is a simple implementation of a linked list for managing student records. It serves as a foundation for more advanced data structure and algorithm concepts.
