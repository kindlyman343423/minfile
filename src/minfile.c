#include "minfile.h"

/**
 * this function is the main function of the application
 * it will single file into minfile
 * 
 * @param string for filename
 * 
 * @return void
 **/
void minfile(char* argv)
{
    printf("Valid filename: %d\n",checkValid(argv));                                    // check for valid file
        
    if(checkValid(argv))                                                                // if valid filename found
    {
        //booleans for file extensions
        bool css    =   false;                                                          //* initial
        bool scss   =   false;                                                          //* values 
        bool json   =   false;                                                          //* for             
        bool html   =   false;                                                          //* all
        bool js     =   false;                                                          //* langauge
        bool c      =   false;                                                          //* are
        bool cpp    =   false;                                                          //* taken
        bool java   =   false;                                                          //* false
        bool csharp =   false;                                                          //*
        bool other  =   false;                                                          //* for other files

        /**
         * setting the boolean according to file extensions
         **/
        int len = strlen(argv);
        
        char ch=argv[len-1];                                                            // last char of file extension
        
        /**
         * making hashtable according to language extension found
         **/
        switch(ch)
        {
            case 'c':                                                                   // chances: c
                c=true;                                                                 // file found: c
                buildC();                                                               // C HASHTABLE MADE
                break;
            case 'p':                                                                   // chances: cpp
                if(argv[len-2]=='p' && argv[len-3]=='c')
                {
                    cpp = true;                                                         // file found: cpp
                    buildCPP();                                                         // CPP HASHTABLE MADE
                }               
                break;
            case 's':                                                                   // chances: cs css js scss
                ch = argv[len-2];                                                       // second last char of file extension
                switch(ch)
                {
                    case 'c':                                                           // chances: cs
                        csharp=true;                                                    // file found: c#
                        buildCSharp();                                                  // CSHARP HASHTABLE MADE
                        break;
                    case 's':                                                           // chances: css scss
                        ch = argv[len-3];                                               // last third char of file extension
                        switch(ch)
                        {
                            case 'c':                                                   // chances: css scss                                
                                ch = argv[len-4];
                                switch(ch)
                                {
                                    case '.':                                           // chances: css
                                        css=true;                                       // file found: css
                                        break;
                                    case 's':                                           // chances: scss
                                        scss=true;                                      // file found: scss
                                        break;
                                    default:
                                        break;
                                }                                                       // end of switch arg 4
                                break;
                            default:
                                break;
                        }                                                               // end of switch arg 3
                        break;
                    case 'j':                                                           // chances js
                        js = true;                                                      // js file found
                        buildJS();                                                      // JS HASHTABLE MADE
                        break;
                    default:                                    
                        break;
                }                                                                       // end of switch arg 2
                break;
            case 'l':                                                                   // chances: html
                if(argv[len-2]=='m' && argv[len-3]=='t' && argv[len-4]=='h')
                {
                    html = true;                                                        // file found: html
                    buildHTML();                                                        // HTML HASHTABLE MADE
                }
                break;
            case 'a':                                                                   // chances: java
                if(argv[len-2]=='v' && argv[len-3]=='a' && argv[len-4]=='j')
                {
                    java=true;                                                          // file found: java
                    buildJAVA();                                                        // JAVA HASHTABLE BUILD
                }
                break;
            case 'n':                                                                   // chances: json
                if(argv[len-2]=='o' && argv[len-3]=='s' && argv[len-4]=='j')
                    json=true;                                                          // file found: json
                break;
            default:                                            
                break;          
        }                                                                               // end of switch arg 1

        /**
         * printing hashtable for checking
         **/
        // printHashTable();
        // exit(1);
        
        /**
         * CHECKING THE FILE NAME IS VALID OR NOT
         **/
        FILE *ptr;
        ptr = fopen(argv,"r");                                                          // reading file for conversion
        if(ptr==NULL)
        {
            printf("ERROR: No file found\n");                                           // if file not found then exit the program
            exit(1);
        }

        /**
         * Create new file extension with min in it
         *
         * test.css     ->  test.min.css        -----
         * test.scss    ->  test.min.scss       -----
         * test.json    ->  test.min.json       -----
         * test.html    ->  test.min.html       --
         * test.js      ->  test.min.js         -----
         * test.c       ->  test.min.c          ----
         * test.cpp     ->  test.min.cpp
         * test.java    ->  test.min.java
         * test.cs      ->  test.min.cs
         **/
        int newlen = len+5;                                                             // increased length for adding .min
        int i=0;
        int j=0;
        char *newfile = (char*)malloc(sizeof(char)*newlen);                             // heap memory for new file creation
        
        /**
         * extracting the new file name from old file name
         **/
        while(argv[i]!='\0')
        {
            if(argv[i]=='.')                                                            // file name should have . in it
            {
                /**
                 * add min. to string
                 **/
                newfile[j]=argv[i];                                                     //.
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
                newfile[j]=argv[i];
            }
            i++;
            j++;
        }
        newfile[j]='\0';
        
        /**
         * Writing the new file i.e is minfile i.e main task
         **/
        FILE *copy;                                                                     // file pointer for copying files
        copy = fopen(newfile,"w");                                                      // open file for writing
        bool flag=false;                                                                // boolean for parsing
        char str[100];                                                                  // string for temp storage
        int l=0;                                                                        // iterator for string storage
        
        /**
         * Initialize FLAGS for exceptional behaviour
         **/
        bool dcomma=false;                                                              // boolean for double commas
        bool lessgreater=false;                                                         // boolean for html > <
        bool cart = false;                                                              // boolean for ` for js
        bool curlybrackets = false;                                                     // boolean for { } for js
        bool chashtag = false;                                                          // boolean for #include for c,cpp
        bool cdefine = false;                                                           // boolean for #define for c,cpp
        bool cppclass = false;                                                          // boolean for class

        while(!feof(ptr))                                                               // writing the file
        {
            char ch = fgetc(ptr);
            if(ch==' ' || ch=='\n' || ch=='\t' || ch==EOF)                              // if space new line or tab found
            {
                if(flag)                                                                // when we go from word to space
                {
                    str[l]='\0';
                    if(css || scss || json)                                             // when css,scss,json file found
                    {
                        fprintf(copy,"%s",str);                                         // print the string formed
                        //compress all chars
                        if(dcomma==true && json && ch==' ')                             // comma mechanism for json
                        {
                            fputc(ch,copy);
                        }
                    }
                    else if(html)                                                       // print space only for html files
                    {
                        fprintf(copy,"%s",str);                                         // print the string formed
                        if((reservedHTML(str) || !lessgreater || dcomma) && ch==' ')
                        {
                            fputc(ch,copy);                                             // if html tag found then there should be 1 space    
                        }
                    }
                    else if(js)                                                         // if js file found
                    {
                        fprintf(copy,"%s",str);                                         // print the string formed
                        if(ch=='\n' && str[l-1]!=';' && !curlybrackets)
                        {
                            fputc(';',copy);
                        }
                        if((reservedJS(str) || dcomma || cart) && ch==' ')
                        {
                            fputc(ch,copy);
                        }
                    }
                    else if(c)                                                          // if c file found
                    {
                        fprintf(copy,"%s",str);                                         // print the string formed
                        if(strcmp(str,"#define")==0)                                    // if #define string is finded
                        {
                            cdefine=true;
                        }
                        else if(ch=='\n')                                               // if line end found
                        {
                            cdefine=false;
                            if(chashtag)                                                // printing \n when header file line is there in c
                            {
                                fputc(ch,copy);
                                chashtag = false;
                            }
                        }
                        if((reservedC(str) || dcomma || cdefine) && ch==' ')            // if c reserved words found or double commas
                        {
                            fputc(ch,copy);                                             // printing the space char when reserved word found in c
                        }
                    }
                    else if(cpp)                                                        // if cpp file found
                    {
                        fprintf(copy,"%s",str);                                         // print the string formed
                        if(strcmp(str,"#define")==0)                                    // if #define string is finded
                        {
                            cdefine=true;
                        }
                        else if(ch=='\n')                                               // if line end found
                        {
                            cdefine=false;
                            if(chashtag)                                                // printing \n when header file line is there in c
                            {
                                fputc(ch,copy);
                                chashtag = false;
                            }
                        }
                        if((reservedCPP(str) || dcomma || cdefine) && ch==' ')          // if cpp reserved words found or double commas
                        {
                            fputc(ch,copy);                                             // printing the space char when reserved word found in c
                        }
                    }
                    else if(ch==' ')                                                    // for other file format
                    {
                        fputc(ch,copy);
                    }
                    l=0;
                    flag=false;
                }
            }
            else                                                                        // if chars found
            {
                if(flag==false)
                {
                    flag=true;
                }
                /**
                 * MAINTAINING FLAGS BY CHECKING CHAR BY CHAR
                 * for handling the flags for exceptions in file extension
                 **/
                if(ch=='\"' && (json || html || js || c || cpp))                        // if double commas come in json,html,js,c
                {
                    if(dcomma==true)                                                    // if string is ending then do it false
                    {
                        dcomma=false;
                    }
                    else                                                                // if string is started then doing it true                                                
                    {
                        dcomma=true;
                    }
                }
                else if((ch=='<' || ch=='>') && html)                                   // if < > char found change flags
                {
                    if(lessgreater==true)                                               // if lessgreater flag is true make it false for data
                    {
                        lessgreater=false;
                    }
                    else                                                                // if lessgreater flag is false make it true as tags found
                    {
                        lessgreater=true;
                    }
                }
                else if(ch=='`' && js)                                                  // if ` found in string in js
                {
                    if(cart==true)
                    {
                        cart=false;
                    }
                    else
                    {
                        cart=true;
                    }
                }
                else if((ch=='{' || ch=='}') && js)                                     // if { } found in the string while parsing in js file
                {
                    if(curlybrackets==true)
                    {
                        curlybrackets=false;
                    }
                    else
                    {
                        curlybrackets=true;
                    }
                }
                else if(str[0]=='#' && (c || cpp))                                      // if # found in the c and cpp file
                {
                    if(chashtag == false)
                    {
                        chashtag = true;
                    }
                }
                // fputc(ch,copy);                                                         // printing all the chars directly to the file
                str[l] = ch;                                                            // storing the char in temporary string for checks
                l++;
            }
        }
        printf("Generated new file name: %s\n",newfile);
        fclose(copy);
        fclose(ptr); 
        free(newfile);

        /**
         * FREEING THE HASHTABLE
         **/
        freeHashTable();
    }
}