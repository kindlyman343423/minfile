#include "Main.h"
#include "util.c"
#include "function.c"
#include "minfile.c"

/**
 * this is the main program
 *
 * @return int
 **/
int main(int argc,char* argv[])
{
    buildJAVA();
    // printf("%d\n",reservedJAVA("synchronized"));
    printHashTable();
    freeHashTable();
    exit(0);
    if(argc==1)                                                             // check argument count
    {
        printf("Invalid arguments !!!\n");
        printf("Format should be: ./minfile filename\n");
        
        /*GLOBAL VARIABLES FOR PARSING*/
        char clistring[100];                                                // for taking input string
        bool parseflag=false;                                               // flag for parsing the string
        register int i=0,j=0,k=0;                                           // register values for looping
        char copy[30];                                                      // string needed for parsing
        argc=0;
        argv=NULL;
        
        printf("minfile: ");
        scanf("%[^\t\n]s",clistring);                                       // input the string with spaces
        
        while(clistring[i]!='\0')                                           // traversing and counting the arguments
        {
            if(clistring[i]==' ' || clistring[i]=='\n')
            {
                if(parseflag)
                {
                    parseflag=false;
                    argc++;
                }
            }
            else
            {
                if(!parseflag)
                {
                    parseflag=true;
                }
            }
            i++;
        }
        argc++;
        // printf("arguments: %d\n",argc);
        argv = (char**)malloc(sizeof(char *)*argc);                  // storing the arguments

        /**
         * RESETTING VARAIBLES
         **/
        i=0;
        j=0;
        k=0;
        parseflag=false;

        while(i<(strlen(clistring)+1))                                           // string parsing anf storing
        {
            if(clistring[i]==' ' || clistring[i]=='\n' || clistring[i]=='\0')                     // if character found while parsing
            {
                if(parseflag)                                               // if flag is true change to false as string gets end
                {
                    parseflag=false;
                    copy[j]='\0';

                    int len = strlen(copy);
                    //allocating memory
                    argv[k] = (char*)malloc(sizeof(char)*(len+1));
                    strcpy(argv[k],copy);

                    k++;
                    j=0;
                }
            }
            else                                                            // if other char found
            {
                if(!parseflag)                                              // if flag gets false then change to true
                {
                    parseflag=true;
                }
                copy[j] = clistring[i];                                     // storing the characters
                j++;
            }
            i++;
        }
        
        // free(argv);  
    }
    printf("ARGUMENT CHECK: %d\n",argc);
    int i=0;
    for(i=0;i<argc;i++)
    {
        printf("%s\n",argv[i]);
    }

    if(argc==1)
    {
        printf("awesome");
    }
    else if(argc==2)
    {
        minfile(argv[1]);
    }
}
