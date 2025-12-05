#ifndef INVER_INDEX_H
#define INVER_INDEX_H


/* ================= STANDARD LIBRARIES ================= */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


/* ================= MACROS ================= */

#define SUCCESS 1
#define FAILURE 0


/* ================= SUB NODE =================
   Stores file-wise information for a word
*/
typedef struct sub_node
{
   
   int W_count; 
   char filename[100]; 
   struct sub_node *link;

} sub_node;


/* ================= MAIN NODE =================
   Stores unique word information
*/
typedef struct main_node
{
   int file_count;
   char word[50];
   sub_node *sub_link;
   struct main_node *link;

} main_node;


/* ================= HASH TABLE =================
   Hash table bucket structure
*/
typedef struct hash_stack
{
   int index;
   main_node *link;

} hash_t;


/* ================= FILE LIST =================
   Stores input file names
=============================================*/
typedef struct Slist
{
   char filename[50]; 
   struct Slist *link;

} Slist;


/* ================= FUNCTION PROTOTYPES ================= */


/* ============================================================
   Validates input files from command-line arguments.
   Also checks file format and duplicate entries.
   Creates a linked list of valid input files.
============================================================ */
int FILE_validation(int argc, char *argv[], Slist **head);


/* ============================================================
   Checks whether a file name already exists in the file list.
   Used to avoid duplicate file insertion.
============================================================ */
int Check_Duplicate_File(Slist **head , char *file_name);


/* ============================================================
   Creates the inverted index database.
   Reads each validated file and inserts words into hash table.
============================================================ */
int Create_Database(Slist **head, hash_t *hash_table);


/* ============================================================
   Inserts a file name at the end of the singly linked file list.
============================================================ */
int Insert_last(Slist **head, char *filename);


/* ============================================================
   Generates the hash index using the first character of a word.
============================================================ */
int get_index(char ch);


/* ============================================================
   Inserts a word into the hash table.
   Also creates or updates sub-nodes for file-wise word count.
============================================================ */
int insert_hash(hash_t *hash_table, int index, char *word, char *filename);


/* ============================================================
   Displays the complete inverted index database on the screen.
============================================================ */
int Display_database(hash_t *hash_table);


/* ============================================================
   Searches a word in the inverted index database using hash.
============================================================ */
int Search_database(hash_t *hash_table ,char *word , int index);


/* ============================================================
   Saves the complete inverted index database into a backup file.
============================================================ */
int save_database_file(hash_t hash_table[]);


/* ============================================================
   Restores the inverted index database from the backup file.
============================================================ */
int update_database(hash_t hashtable[]);

/* ================= CLEAR DATABASE ====================
   Frees all allocated nodes and resets the hash table
====================================================== */
void clear_database(hash_t *hash_table);
#endif
