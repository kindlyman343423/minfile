#include "Main.h"

/*structure for bst*/
struct Node
{
    char* str;
    int len;
    struct Node* left;
    struct Node* right;
};
struct Node* ROOT=NULL;
bool insert(char* str,int length);
bool deletetree();
bool inorder();