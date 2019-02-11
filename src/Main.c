#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int hash(char *str)
{
    int result=0;
    for(register int i=0;i<strlen(str);i++)
    {
        result= result + (int)str[i];
    }
    return result;
}

bool reserved(char* str)
{

}
/**
 * this is the main program
 **/
int main(int argc,char *argv[])
{
    if(argc==1 || argc>2)                                   //check arguments
    {
        printf("Invalid arguments !!!\n");
        printf("Format should be: ./minfile filename\n");
    }
    else if(argc==2)
    {
        //check for valid file
        printf("Valid filename: %d\n",checkValid(argv[1]));
        
        //checking the hash value
        exit(0);
        if(checkValid(argv[1]))                             //if valid filename found
        {
            FILE *ptr;
            ptr = fopen(argv[1],"r");
            if(ptr==NULL)
            {
                printf("ERROR: No file found\n");
                exit(1);
            }
            //create new file extension
            //main.js -> main.min.js
            int newlen = strlen(argv[1])+5;
            int i=0;
            int j=0;
            char *newfile = (char*)malloc(sizeof(char)*newlen);
            
            while(argv[1][i]!='\0')
            {
                if(argv[1][i]=='.')
                {
                    //add min. to string
                    newfile[j]=argv[1][i]; //.
                    j++;
                    newfile[j]='m';
                    j++;
                    newfile[j]='i';
                    j++;
                    newfile[j]='n';
                    j++;
                    newfile[j]='.';
                }
                else
                {
                    newfile[j]=argv[1][i];
                }
                i++;
                j++;
            }
            newfile[j]='\0';
            
            FILE *copy;
            copy = fopen(newfile,"w");
            bool flag=false;

            while(!feof(ptr))
            {
                char ch = fgetc(ptr);
                if(ch==' ' || ch=='\n' || ch=='\t' || ch==EOF)
                {
                    if(flag==true)
                    {
                        if(ch==' ')
                            fputc(ch,copy);    
                        flag=false;
                    }
                }
                else
                {
                    if(flag==false)
                    {
                        flag=true;
                    }
                    fputc(ch,copy);
                }
            }
            
            printf("Generated new file name: %s\n",newfile);
            fclose(copy);
            fclose(ptr); 
            free(newfile);
        }
    }
}
