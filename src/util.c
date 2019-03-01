#include "util.h"

//implementing the bst of strings

/**
 * this function will insert the key in bst
 * 
 * @param string for key value
 * @param length of the string
 * @param root of bst
 * 
 * @return bool whether the insertion is done successfully or not
 **/
bool insert(char* str,int length,struct Node* root)
{

}

/**
 * This function will delete the whole bst
 * 
 * @param root of bst
 * 
 * @return bool whether the tree is successfully deleted or not
 **/
bool deletetree(struct Node* root)
{

}

/**
 * This function will traverse the bst in inorder traversal for checking
 * 
 * @param root of bst
 * 
 * @return bool whether inorder is possible or not
 **/
bool inorder(struct Node* root)
{

}

/**
 * This function is main function it will search the string in bst
 * 
 * @param key to search
 * @param root of bst
 * 
 * @return bool whether the key is found in bst or not
 **/
bool search(char* key,struct Node* root)
{

}

/**
 * This function tells whether the string 1 is greater than string 2 or not
 * 
 * @param string 1
 * @param string 2
 * 
 * @return bool for result of str1 > str2
 **/
bool greaterThan(char* str1,char* str2)
{
    register int i=0;
    register int j=0;
    while(true)
    {
        if(str1[i]=='\0' && str2[j]=='\0')
        {
            return true;
        }
        else if(str1[i]=='\0')
        {
            return false;
        }
        else if(str2[j]=='\0')
        {
            return true;
        }
        if(str1[i]==str2[j])
        {
            i++;
            j++;
        }
        else if(str1[i]>str2[j])
        {
            return true;
        }
        else if(str1[i]<str2[j])
        {
            return false;
        }
    }
    return false;
}

/**
 * This function tells whether the string 1 is smaller than string 2 or not
 * 
 * @param string 1
 * @param string 2
 * 
 * @return bool for result of str1 < str2
 **/
bool smallerThan(char* str1,char* str2)
{

}