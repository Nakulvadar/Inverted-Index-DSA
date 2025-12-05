# Inverted Index – DSA Project in C

This project implements an **Inverted Index** using Data Structures and Algorithms in C.  
It reads multiple text files, extracts unique words, stores file-wise occurrence counts,  
and supports searching and displaying the complete indexed database.

---

## 📸 Sample Output

```
[Index : 0 ]  [Word : adada ]   [Total Files : 1]   [File : file2.txt ]  [Word : 1]
[Index : 0 ]  [Word : abc   ]   [Total Files : 1]   [File : file2.txt ]  [Word : 1]
[Index : 7 ]  [Word : hi    ]   [Total Files : 1]   [File : file1.txt ]  [Word : 1]
[Index : 10]  [Word : king  ]   [Total Files : 1]   [File : file2.txt ]  [Word : 1]
[Index : 13]  [Word : nakul ]   [Total Files : 1]   [File : file1.txt ]  [Word : 1]
[Index : 15]  [Word : pushker]  [Total Files : 1]   [File : file1.txt ]  [Word : 1]
[Index : 15]  [Word : papu ]    [Total Files : 1]   [File : file2.txt ]  [Word : 1]
[Index : 21]  [Word : vaibhav]  [Total Files : 1]   [File : file1.txt ]  [Word : 1]
```

---

## 🧠 Project Overview

The program:

- Validates `.txt` input files  
- Reads each word from files  
- Computes a hash based on the first character  
- Inserts the word into a hash table (26 buckets)  
- Handles collisions using linked lists  
- Maintains per-file occurrence count  
- Provides search and display functionality  

---

## 📚 Data Structures Used

### **Sub Node (File-Level Info)**
Stores how many times a word appears in one file.

```c
typedef struct sub_node {
    int W_count;
    char filename[100];
    struct sub_node *link;
} sub_node;
```

### **Main Node (Word-Level Info)**

```c
typedef struct main_node {
    int file_count;
    char word[50];
    sub_node *sub_link;
    struct main_node *link;
} main_node;
```

### **Hash Table Bucket**

```c
typedef struct hash_stack {
    int index;
    main_node *link;
} hash_t;
```

### **File List Node**

```c
typedef struct Slist {
    char filename[50];
    struct Slist *link;
} Slist;
```

---

## 🏗 Project Structure

```
inverted-index-dsa/
│
├── src/
├── include/
├── data/
├── Makefile
└── README.md
```

---

## ▶️ Build and Run

### **Compile**
```
make
```

### **Run**
```
./inverted_index file1.txt file2.txt file3.txt
```

---

## 🔍 Search Example

```
Enter word to search: king
Word found in file2.txt (1 time)
```

---

## 🏁 Why This Project Is Useful

- Demonstrates understanding of hashing  
- Shows linked list collision handling  
- Uses memory management and file parsing  
- Reflects strong modular design in C   
---

## 👤 Author
**Nakul Anil Vadar**

