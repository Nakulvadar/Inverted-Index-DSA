# Inverted Index – DSA Project in C

A complete implementation of an **Inverted Index** using **Data Structures & Algorithms** in C.  
The project processes multiple text files, extracts unique words, and builds a searchable index using a **hash table with linked lists**.

This project demonstrates strong skills in **C programming, hashing, file handling, dynamic memory allocation, and modular design**.

## 🚀 Features

- Validates input `.txt` files
- Reads and extracts all unique words
- Builds a hash-based inverted index (26 buckets)
- Collision handling using linked lists (separate chaining)
- Stores:
  - Word
  - Number of files containing it
  - Occurrence count per file
- Search functionality for any word
- Update database with new text files
- Structured, clean console output
- Modular code structure (src + include)

## 📂 Project Structure

```
inverted-index-dsa/
│
├── src/
│   ├── main.c
│   ├── file_validation.c
│   ├── create_database.c
│   ├── update_database.c
│   ├── search_word.c
│   ├── display_database.c
│   ├── utils.c
│   └── inverted_search.c
│
├── include/
│   ├── inverted_search.h
│   ├── structures.h
│   └── macros.h
│
├── data/
│   ├── file1.txt
│   ├── file2.txt
│   └── ...
│
├── Makefile
└── README.md
```

## 🧠 Data Structures Used

### 1️⃣ Hash Table (size = 26)
```
index = tolower(word[0]) - 'a';
```

### 2️⃣ Main Node Structure
```
word
file_count
sub_link
link
```

### 3️⃣ Sub Node Structure
```
filename
word_count
link
```

## 🛠️ Build & Run

### Build:
```
make
```

### Run:
```
./inverted_index file1.txt file2.txt file3.txt
```

## 🔍 Search Example

```
Enter word to search: data
Word found in 2 files:
  - file1.txt (3 times)
  - file3.txt (1 time)
```

## 📊 Sample Output

```
===========================================================
                      DISPLAY DATABASE
===========================================================
[Index :  3] [Word : data         ] [Total Files : 2]
   [File : file1.txt   ] [Word :  3]
   [File : file3.txt   ] [Word :  1]
```

## 📜 License
MIT License.

## 👤 Author
Nakul Anil Vadar
