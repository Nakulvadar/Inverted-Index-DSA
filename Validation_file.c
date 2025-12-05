#include "inver_index.h" 


/* ================= FILE VALIDATION ====================
   Validates input files and creates a valid file list
======================================================= */
int FILE_validation(int count ,char *argv[],Slist **head)
{
    int flag =0;

    for(int i=1;i<count;i++){

        char *file_name = argv[i];

        if((strstr(file_name,".txt"))== NULL){
            printf("Error: '%s' is not a '.txt' file.\n", file_name);
            continue;
        }

        FILE *fp = fopen(file_name,"r");
        if(!fp){
            printf("Error: File '%s' does not exist.\n", file_name);
            continue;
        }

        fseek(fp,0,SEEK_END);
        long size = ftell(fp);
        fclose(fp);

        if(size == 0){
            printf("Error: File '%s' is empty.\n", file_name);
            continue;
        }

        if (Check_Duplicate_File(head, file_name) == SUCCESS){
            printf("Error: Duplicate file '%s' ignored.\n", file_name);
            continue;
        }

        Insert_last(head,file_name);
        flag =1;
    }

    if(!flag){
        printf("No valid files found.\n");
        return FAILURE;
    }

    return SUCCESS;
}


/* ================= INSERT FILE NODE ===================
   Inserts a file name at the end of the file list
======================================================= */
int Insert_last(Slist **head, char *file_name)
{
    if (head == NULL || file_name == NULL)
        return FAILURE; 

    Slist *new_node = malloc(sizeof(Slist));
    if(new_node == NULL) return FAILURE;

    strcpy(new_node->filename,file_name);
    new_node->link = NULL;

    if(*head == NULL){
        *head = new_node;
        return SUCCESS;
    }

    Slist *temp = *head;
    while(temp->link != NULL){
        temp = temp ->link;
    }

    temp->link = new_node;
    return SUCCESS;
}


/* ================= DUPLICATE FILE CHECK ===============
   Checks whether a file already exists in the file list
======================================================= */
int Check_Duplicate_File(Slist **head , char *file_name)
{
    if(*head == NULL){
        return FAILURE;
    }

    Slist *temp = *head;
    while(temp){

        if(strcmp(temp->filename,file_name)==0){
            return SUCCESS;
        }

        temp = temp->link;
    }

    return FAILURE;
}
