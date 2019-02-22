#include "function.c"
#include "util.c"

/**
 * this is the main program
 * 
 * @param argc
 * @param argv
 * 
 * @return int
 **/
int main(int argc,char *argv[])
{
    if(argc==1 || argc>2)                                           //check argument count
    {
        printf("Invalid arguments !!!\n");
        printf("Format should be: ./minfile filename\n");
    }
    else if(argc==2)
    {
        printf("Valid filename: %d\n",checkValid(argv[1]));         //check for valid file
       
        if(checkValid(argv[1]))                                     //if valid filename found
        {
            //booleans for file extensions
            bool js     =   false;                                  //* initial
            bool css    =   false;                                  //* values
            bool scss   =   false;                                  //* for 
            bool json   =   false;                                  //* all             
            bool html   =   false;                                  //* langauge
            bool c      =   false;                                  //* are
            bool cpp    =   false;                                  //* taken
            bool java   =   false;                                  //* false
            bool csharp =   false;                                  //*

            /**
             * setting the boolean according to file extensions
             * checking in better way using jumping table
             **/
            int len = strlen(argv[1]);
            
            char ch=argv[1][len-1];                                 //last char of file extension
            
            switch(ch)
            {
                case 'c':                                           //chances: c
                    c=true;                                         //file found: c
                    break;
                case 'p':                                           //chances: cpp
                    if(argv[1][len-2]=='p' && argv[1][len-3]=='c')
                    {
                        cpp = true;                                 //file found: cpp
                    }               
                    break;
                case 's':                                           //chances: cs css js scss
                    ch = argv[1][len-2];                            //second last char of file extension
                    switch(ch)
                    {
                        case 'c':                                   //chances: cs
                            csharp=true;                            //file found: c#
                            break;
                        case 's':                                   //chances: css scss
                            ch = argv[1][len-3];                    //last third char of file extension
                            switch(ch)
                            {
                                case 'c':                           //chances: css scss
                                
                                    ch = argv[1][len-4];
                                    switch(ch)
                                    {
                                        case '.':                   //chances: css
                                            css=true;               //file found: css
                                            break;
                                        case 's':                   //chances: scss
                                            scss=true;              //file found: scss
                                            break;
                                        default:
                                            break;
                                    }                               //end of switch arg 4
                                    break;
                                default:
                                    break;
                            }                                       //end of switch arg 3
                            break;
                        case 'j':                                   //chances js
                            js = true;                              //js file found
                            break;
                        default:                                    
                            break;
                    }                                               //end of switch arg 2
                    break;
                case 'l':                                           //chances: html
                    if(argv[1][len-2]=='m' && argv[1][len-3]=='t' && argv[1][len-4]=='h')
                        html = true;                                //file found: html
                    break;
                case 'a':                                           //chances: java
                    if(argv[1][len-2]=='v' && argv[1][len-3]=='a' && argv[1][len-4]=='j')
                        java=true;                                  //file found: java
                    break;
                case 'n':                                           //chances: json
                    if(argv[1][len-2]=='o' && argv[1][len-3]=='s' && argv[1][len-4]=='j')
                        json=true;                                  //file found: json
                    break;
                default:                                            
                    break;          
            }                                                       //end of switch arg 1

            // printf("printing boolean: %d %d %d %d %d %d %d %d %d\n",js,css,scss,json,html,c,cpp,java,csharp);

            //making hashtable
            // unsigned int hashtable[UINT_MAX];
            
            // register int k=0;
            // for(k=0;k<UINT_MAX;k++)
            // {
            //     hashtable[k]=0;
            // }
            // for(k=0;k<UINT_MAX;k++)
            // {
            //     printf("%u ",hashtable[k]);
            // }
            // exit(0);

            FILE *ptr;
            ptr = fopen(argv[1],"r");                               //reading file for conversion
            if(ptr==NULL)
            {
                printf("ERROR: No file found\n");                   //if file not found then exit the program
                exit(1);
            }
            /**
             * create new file extension
             * 
             * test.html    ->  test.min.html
             * test.css     ->  test.min.css
             * test.scss    ->  test.min.scss
             * test.json    ->  test.min.json
             * test.js      ->  test.min.js
             * test.c       ->  test.min.c
             * test.cpp     ->  test.min.cpp
             * test.java    ->  test.min.java
             * test.cs      ->  test.min.cs
             **/
            int newlen = len+5;                                     //increased length because of min
            int i=0;
            int j=0;
            char *newfile = (char*)malloc(sizeof(char)*newlen);     //heap memory for new file creation
            
            //extracting the new file name from old file name
            while(argv[1][i]!='\0')
            {
                if(argv[1][i]=='.')                                 //file name should have . in it
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
            
            FILE *copy;                                             //file pointer for copying files
            copy = fopen(newfile,"w");                              //open file for writing
            bool flag=false;                                        //boolean for parsing
            char str[100];                                          //string for temp storage
            int l=0;                                                //iterator for string storage

            while(!feof(ptr))                                       //writing the file
            {
                char ch = fgetc(ptr);
                if(ch==' ' || ch=='\n' || ch=='\t' || ch==EOF)
                {
                    if(flag)                                        //when we go from word to space
                    {
                        str[l]='\0';
                        if(css || scss || json)                     //when css,scss,json file found
                        {
                            //do nothing just compress
                        }
                        else if(js && reservedJS(str) && ch==' ')   //if js reserved word found
                        {
                            fputc(ch,copy);
                        }
                        else if(c && reservedC(str) && ch==' ')     //if c reserved words are found
                        {
                            fputc(ch,copy);
                        }
                        else if(html && ch==' ')                    //print space only for html files
                        {
                            if(reservedHTML(str))
                            {
                                fputc(ch,copy);    
                            }
                        }
                        else if(ch==' ')                            //for other file format
                        {
                            fputc(ch,copy);
                        }
                        l=0;
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

                    str[l] = ch;
                    l++;
                }
            }
            
            printf("Generated new file name: %s\n",newfile);
            fclose(copy);
            fclose(ptr); 
            free(newfile);
        }
    }
}
