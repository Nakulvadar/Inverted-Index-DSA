#include "inver_index.h" 


/* ================= SEARCH DATABASE ====================
   Searches a word in the hash table and displays results
======================================================= */
int Search_database(hash_t hash_table[],char *word , int index)
{
    main_node *mtemp = hash_table[index].link;

    while(mtemp){
        if(strcmp(mtemp->word,word)==0){

            sub_node *stemp = mtemp->sub_link;
            while(stemp){
                printf("\n[Index : %d ]  In file: %s  %d time/s.\n",index, stemp->filename, stemp->W_count);
                stemp = stemp->link;
            }
            return SUCCESS;
        }
        mtemp = mtemp->link;
    }

    return FAILURE;
}
