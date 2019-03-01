#include "Main.h"

/*structure for bst*/
struct Node
{
    char* str;
    int len;
    struct Node* left;
    struct Node* right;
};
struct Node* ROOTBST=NULL;
bool insert(char* str,int length,struct Node* root);
bool deletetree(struct Node* root);
bool inorder(struct Node* root);
bool search(char* key,struct Node* root);

bool greaterThan(char* str1,char* str2);
bool smallerThan(char* str1,char* str2);