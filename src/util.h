#include "Main.h"
#define HASHSIZE INT_MAX/100000

/*HASHTABLE*/
char** HASH=NULL;

/*FUNCTIONS*/

int hashfunction(char*);
void printHashTable();
void freeHashTable();