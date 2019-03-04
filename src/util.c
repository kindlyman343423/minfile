#include "util.h"

/*HASHTABLE WORK*/

/**
 * This is my hash function
 * 
 * @param string for hash
 * 
 * @return hash value
 **/
int hashfunction(char* str)
{
    int sum=0;
    register int i=0;
    while(str[i]!='\0')
    {
        sum=sum + (int)str[i] - 65;
        i++;
    }
    return sum;
}

/**
 * this function will print the hashtable
 * just for testing
 * 
 * @return void
 **/
void printHashTable()
{
    if(HASH==NULL)
    {
        printf("NULL\n");
        return;
    }
    register int i=0;

    for(i=0;i<HASHSIZE;i++)
    {
        if(HASH[i]!=NULL)
        {
            printf("%d\t%s\n",i,HASH[i]);
        }
    }
}

/**
 * This function will free the memory taken by the hashtable
 * 
 * @return void
 **/
void freeHashTable()
{
    register int i=0;
    
    for(i=0;i<HASHSIZE;i++)
    {
        free(HASH[i]);
    }
    free(HASH);
}