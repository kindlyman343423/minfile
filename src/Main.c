#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
bool wildcard(char ch)
{
    switch(ch)
    {
        case '_':
        case '+':
        case '-':
        case '/':
        case ';':
        case '^':
        case '$':
        case '#':
        case '@':
            return true;
        default:
            return false;
    }
}
bool checkValid(char *str)
{
    int count=0;
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
    if(count==1)
    {
        return true;
    }
    return false;
}
int main(int argc,char *argv[])
{
    // printf("%d",argc);
    // for(register int i=0;i<argc;i++)
    // {
    //     printf("%s",argv[i]);
    // }
    if(argc==1 || argc>2)
    {
        printf("Invalid arguments !!!\n");
        printf("Format should be: ./minfile filename\n");
    }
    else if(argc==2)
    {
        //check for valid file
        printf("Valid filename: %d\n",checkValid(argv[1]));
        if(checkValid(argv[1]))
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
            
            while(!feof(ptr))
            {
                char ch = fgetc(ptr);
                if(ch=='\n' || ch=='\t' || ch==EOF)
                {
                    //do nothing
                }
                else
                {
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
