#include "inver_index.h" 


/* ================= DISPLAY DATABASE ===================
   Displays the complete inverted index database table
======================================================= */
int Display_database(hash_t hash_table[])
{
    printf("\n===================================================================================\n");
    printf("                           DISPLAY DATABASE\n");
    printf("===================================================================================\n");

    int flag = 0;    
    for(int i = 0; i < 27; i++)
    {
        if(hash_table[i].link != NULL)
        {
            flag = 1;
            main_node *mtemp = hash_table[i].link;

            while(mtemp)
            {
                printf("[Index : %2d]   [Word : %-12s]   [Total Files : %d]   ",i, mtemp->word, mtemp->file_count); 
                sub_node *stemp = mtemp->sub_link;
                while (stemp)
                {
                    printf("[File : %-12s]   [Word : %2d]",stemp->filename, stemp->W_count);stemp = stemp->link;
                }
                  
                printf("\n");
                mtemp = mtemp->link;
            }
        }
    }

    if(!flag){
        return FAILURE;
    }

    printf("\n===================================================================================\n");
    printf("                               END\n");
    printf("===================================================================================\n");

    return SUCCESS;
}
