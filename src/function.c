#include "function.h"

/**
 * this function will tell whether given char is wildcard or not
 * for discarding char in filename
 * 
 * @param ch for char
 * @return bool
 **/
bool wildcard(char ch)
{
    switch(ch)
    {
        case '!':
        case '\"':
        case '#':
        case '$':
        case '%':
        case '&':
        case '(':
        case ')':
        case '*':
        case '+':
        case '\'':
        case ',':
        case '-':
        case '/':
        case ':':
        case ';':
        case '<':
        case '=':
        case '>':
        case '?':
        case '@':
        case '[':
        case '\\':
        case ']':
        case '^':
        case '_':
        case '`':
        case '{':
        case '|':
        case '}':
        case '~':
            return true;
        default:
            return false;
    }
}

/**
 * it will check wheter the string is valid or not
 * 
 * @param string
 * @return bool
 **/
bool checkValid(char *str)
{
    int count=0;                    //counting the number of dots in the filename
    int i=0;
    while(str[i]!='\0')
    {
        if(wildcard(str[i]))
        {
            return false;
        }
        if(str[i]=='.')
        {
            count++;
        }
        i++;
    }
    if(count==1)                    //valid for only one dot in string
    {
        return true;
    }
    return false;
}

//0-999 hashes
int sha(char *str)
{
    int result=0;
    for(register int i=0;i<strlen(str);i++)
    {
        result= result + (int)str[i];
    }
    return result%1000;
}

bool reservedJS(char* str)
{
    //better efficiency is needed here
    //may be binary search tree for string searching
    //js reserved words
    char* JS[] = {"abstract","else","instanceof","super","boolean","enum","int","switch","break","export","interface","synchronised","byte","extends","let"
                ,"this","case","false","long","throw","catch","final","native","throws","char","finally","new","transient","class","float","null","true"
                ,"const","for","package","try","continue","function","private","typeof","debugger","goto","protected","var","default","if","public","void","delete"
                ,"implements","return","volatile","do","import","short","while","double","in","static","with"};
    
    for(int i=0;i<60;i++)
    {   
        if(strcmp(JS[i],str)==0)
        {
            return true;
        }
    }
    return false;
}