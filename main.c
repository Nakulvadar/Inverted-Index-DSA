/*Inverted Index Search 
Name: Nakul Anil Vadar
Project Name: Inverted Index Search
Batch ID: 25021_325
________________________________________
1. Introduction
The Inverted Index Search project reads multiple .txt files and creates a database that maps each word -> the files in which the word appears.
This indexing method is commonly used in search engines to speed up word-based searching.
________________________________________
2. Features
1	Accepts multiple input text files
2	Validates file formats
3	Creates a searchable inverted index
4	Displays the full database
5	Searches for any specific word
6	Updates database with new files
7	Saves index to a text file
________________________________________
3. Data Structures Used
1	Singly Linked List -> Stores the list of input files
2	Hash Table (27 buckets)
3	Index 0-25 -> words starting with a-z
4	Index 26 -> words starting with numbers/special characters
5	Main Node -> Stores a word
6	Sub Node -> Stores filename + word count
________________________________________
4. Working Flow (Based on Your main.c Menu)
Program Menu
1. Create Database  
2. Search a Word  
3. Display Database  
4. Save Database  
5. Update Database  
6. Exit
Flow
1.	Validate input files
2.	Initialize 27 hash buckets
3.	Based on user choice:
o	Create database -> read and index all words
o	Search -> find the word and display details
o	Display -> print entire inverted index
o	Save -> store database to a file
o	Update -> add new file words to existing index
o	Exit -> save one last time
________________________________________
5. Display Database (Your Actual Output)
(Used exactly as shown in your screenshot)
===========================================================
                     DISPLAY DATABASE
===========================================================

[Index :  0]   [Word : avi         ]   [Total Files : 1]   [File : file2.txt   ]   [Word :  1]
[Index :  0]   [Word : abc         ]   [Total Files : 1]   [File : file2.txt   ]   [Word :  1]
[Index :  7]   [Word : hi          ]   [Total Files : 1]   [File : file1.txt   ]   [Word :  1]
[Index : 10]   [Word : king        ]   [Total Files : 1]   [File : file2.txt   ]   [Word :  1]
[Index : 13]   [Word : nakul       ]   [Total Files : 1]   [File : file2.txt   ]   [Word :  1]
[Index : 15]   [Word : pushker     ]   [Total Files : 1]   [File : file1.txt   ]   [Word :  1]
[Index : 15]   [Word : prince      ]   [Total Files : 1]   [File : file2.txt   ]   [Word :  1]
[Index : 21]   [Word : vaibhav     ]   [Total Files : 1]   [File : file1.txt   ]   [Word :  1]

===========================================================
                               END
===========================================================
________________________________________
6. Explanation of the Output
Each line represents:
1	Index: Hash bucket number
2	Word: Extracted word
3	Total Files: Number of files containing the word
4	File: Name of the file
5	Word : 1 -> number of occurrences
Example:
[Index : 0] [Word : abc ] [Total Files : 1] [File : file2.txt ] [Word : 1]
Meaning:
1	"abc" goes to hash index 0
2	Appears in file2.txt
3	Occurs once in that file
________________________________________
7. Why 27 Hash Buckets?
Your code uses:
hash_t hash_table[27];
1	0 - 25 -> a to z
2	26 -> words starting with numbers or special characters
This prevents invalid indexes (like 27, 28, etc.).
________________________________________
8. Advantages
1	Very fast searching due to hashing
2	Supports multiple files
3	Clean menu-driven interface
4	Easy to update and save database
________________________________________
9. Conclusion
Your program correctly creates an inverted index, displays words alphabetically via hashing, handles collisions, and maintains accurate file information. The output confirms that the indexing and display logic work exactly as required.
This project demonstrates strong understanding of:
1	Hash tables
2	Linked lists
3	File handling
4	Modular C programming

*/
#include<stdio.h>
#include "inver_index.h"
int main(int argc ,char *argv[])
{
    if(argc < 2){
        printf("\nError: No input files provided.\n");
        printf("Usage: ./a.out <file1.txt> <file2.txt> ...\n");
        return 0;
    }
    Slist *head = NULL;
    if (FILE_validation(argc, argv, &head) == FAILURE || head == NULL) {
    printf("No valid files to process. Exiting.\n");
    return 1;
}
    
    hash_t hash_table[27];
    for (int i = 0; i < 27; i++)
    {
        hash_table[i].index = i;
        hash_table[i].link = NULL;
    }
    
    while(1){
        printf("\n===============================================================\n");
        printf("                    INVERTED INDEX SEARCH MENU\n");
        printf("===============================================================\n");
        printf("1. Create Database\n");
        printf("2. Search a Word\n");
        printf("3. Display Database\n");
        printf("4. Save Database\n");
        printf("5. Update Database\n");
        printf("6. Exit\n");
        printf("===============================================================\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(Create_Database(&head,hash_table)==SUCCESS){
                printf("Database created successfully.\n");
            }
            else{
                printf("Error: Failed to create database.\n");
            }
            break;
        case 2:{
            char word[100];
            printf("Enter the word to search: ");
            scanf("%99s",word);

            int index = get_index(word[0]);
            if(Search_database(hash_table,word,index)==SUCCESS){
                printf("\nWord found successfully in database.\n");
            }
            else{
                printf("\nWord not found in database.\n");
            }
            break;
        }
        case 3:
            if(Display_database(hash_table)==SUCCESS){
                printf("\nDatabase displayed successfully.\n");
            }
            else{
                printf("\nDatabase is empty. Nothing to display.\n");
            }
            break;
        
        case 4:
            if(save_database_file(hash_table)==SUCCESS){
                printf("\nDatabase saved successfully.\n");
            }
            else{
                printf("\nError: Failed to save database.\n");
            }
            break;

        case 5:
            if(update_database(hash_table)==SUCCESS){
                printf("\nDatabase updated successfully.\n");
            }
            else{
                printf("\nError: Failed to update database.\n");
            }
            break;
            
        case 6:
            if (save_database_file(hash_table) == SUCCESS)
                printf("Database saved successfully.\n");
            else
                printf("Error: Failed to save database.\n");

            printf("\nExiting program. Thank you!\n");
            return 0;


        default:
            printf("\nInvalid choice! Please select a valid option (1–6).\n");
            break;
        }
    }
    
}
