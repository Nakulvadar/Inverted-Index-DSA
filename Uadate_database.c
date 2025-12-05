#include "inver_index.h" 


/* ================= UPDATE DATABASE ====================
   Restores the inverted index database from backup file
======================================================= */
int update_database(hash_t hashtable[])
{
    

    FILE *fp = fopen("Backup.txt","r");
    if(!fp){
        printf("Error: Failed to open the file.\n");
        return FAILURE;
    }

    /* Clear existing database before restore */
    clear_database(hashtable);
    
    int index, file_count;
    char word[50];

    while(fscanf(fp, "#%d;%d;%[^;];", &index, &file_count, word) == 3){
 
        main_node *new_main = malloc(sizeof(main_node));
        if(new_main == NULL) return FAILURE;

        new_main->file_count = file_count;
        strcpy(new_main->word, word);
        new_main->sub_link = NULL;
        new_main->link = NULL;

        if(hashtable[index].link == NULL){
            hashtable[index].link = new_main;
        }
        else{
            main_node *mtemp = hashtable[index].link;
            while(mtemp->link != NULL){
                mtemp = mtemp->link;
            }
            mtemp->link = new_main;
        }

        char file_name[50];
        int W_count;

        while(fscanf(fp,"%[^;];%d;", file_name, &W_count) == 2){

            sub_node *nsub = malloc(sizeof(sub_node));
            if(nsub == NULL) return FAILURE;

            strcpy(nsub->filename, file_name);
            nsub->W_count = W_count;
            nsub->link = NULL;

            if(new_main->sub_link == NULL){
                new_main->sub_link = nsub;
            }
            else{
                sub_node *stemp = new_main->sub_link;
                while (stemp->link){
                    stemp = stemp->link;
                }
                stemp->link = nsub;
            }

            char ch = getc(fp);
            if(ch == '#'){
                fgetc(fp);    
                break;
            }
            else{
                ungetc(ch, fp);
            }
        }
    }

    fclose(fp);
    return SUCCESS;
}

/* ================= CLEAR DATABASE ====================
   Frees all allocated nodes and resets the hash table
====================================================== */
void clear_database(hash_t *hash_table)
{
    for(int i = 0; i < 27; i++){
        main_node *mtemp = hash_table[i].link;

        while(mtemp){
            sub_node *stemp = mtemp->sub_link;
            while(stemp){
                sub_node *sdel = stemp;
                stemp = stemp->link;
                free(sdel);
            }

            main_node *mdel = mtemp;
            mtemp = mtemp->link;
            free(mdel);
        }

        hash_table[i].link = NULL;
    }
}
