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