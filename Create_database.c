#include "inver_index.h" 

/* ================= CREAET DATABASE =================
   Builds the inverted index from all validated files
==================================================== */
int Create_Database(Slist **head , hash_t *hash_table)
{

    Slist *temp = *head;
    while(temp != NULL){
        char *filename = temp->filename;
        FILE *fp = fopen(filename,"r");
        char word[100];

        while (fscanf(fp,"%99s",word)==1){
            int index = get_index(word[0]);
            insert_hash(hash_table, index, word, filename);
        }

        fclose(fp);
        temp = temp->link;
    }

    return SUCCESS;
}


/* ================= GET HASH INDEX ==================
   Generates index based on the first character of word
==================================================== */
int get_index(char ch)
{
    if (isupper((unsigned char)ch))
        return ch - 'A';
    else if (islower((unsigned char)ch))
        return (ch - 'a');
    else
        return 26;
}


/* ================= INSERT INTO HASH =================
   Inserts new word or updates existing word information
===================================================== */
int insert_hash(hash_t *hash_table, int index, char *word, char *filename)
{
    main_node *mtemp = hash_table[index].link;
    main_node *prev = NULL;

    while(mtemp){

        if(strcmp(mtemp->word,word)==0){
            sub_node *stemp = mtemp->sub_link;
            
            while(stemp){
                if(strcmp(stemp->filename,filename)==0){
                    stemp->W_count++;
                    return SUCCESS;
                }
                stemp = stemp->link;
            }

            sub_node *new_sub = malloc(sizeof(sub_node));
            if(new_sub == NULL) return FAILURE;

            new_sub->W_count = 1; 
            strcpy(new_sub->filename,filename);
            new_sub->link=NULL;

            new_sub->link = mtemp->sub_link;
            mtemp->sub_link = new_sub;

            mtemp->file_count++;
            return SUCCESS;
        }

        prev = mtemp;
        mtemp = mtemp->link;
    }

    main_node *new_main = malloc(sizeof(main_node));
    if(new_main == NULL) return FAILURE;

    new_main->file_count = 1;
    strcpy(new_main->word , word);
    new_main->sub_link = NULL;
    new_main->link = NULL;

    sub_node *new_sub = malloc(sizeof(sub_node));
    if(new_sub == NULL) return FAILURE;

    new_sub->W_count = 1; 
    strcpy(new_sub->filename,filename);
    new_sub->link=NULL;

    new_main->sub_link = new_sub;

    if(prev == NULL){
        hash_table[index].link = new_main;
    }
    else{
        prev->link = new_main;
    }

    return SUCCESS;
}