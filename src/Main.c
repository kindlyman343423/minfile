#include "function.c"

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
       

        if(checkValid(argv[1]))                                                         //if valid filename found
        {
            //booleans for file extensions
            bool js=false;                                                              //initial value of js is false
            bool css = false;                                                           //initial value of css is false
            bool html=false;                                                            //initial value of html is false

            //setting the boolean according to file extensions
            int len = strlen(argv[1]);
            
            if(argv[1][len-1]=='s' && argv[1][len-2]=='j')                              //checking for js
            {
                js=true;
            }
            else if(argv[1][len-1]=='s' && argv[1][len-2]=='s' && argv[1][len-3]=='c')  //checking for css
            {
                css=true;
            }
            else if(argv[1][len-1]=='l' && argv[1][len-2]=='m' && argv[1][len-3]=='t' && argv[1][len-4]=='h') //checking for html
            {
                html=true;
            }

            FILE *ptr;
            ptr = fopen(argv[1],"r");                                                   //reading file for conversion
            if(ptr==NULL)
            {
                printf("ERROR: No file found\n");
                exit(1);
            }
            
            /**
             * create new file extension
             * 
             * main.js -> main.min.js
             **/
            int newlen = len+5;                                                         //increased length because of min
            int i=0;
            int j=0;
            char *newfile = (char*)malloc(sizeof(char)*newlen);                         //heap memory for new file creation
            
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
            bool flag=false;                                    //boolean for parsing
            char str[100];
            int l=0;

            while(!feof(ptr))
            {
                char ch = fgetc(ptr);
                if(ch==' ' || ch=='\n' || ch=='\t' || ch==EOF)
                {
                    if(flag==true)
                    {
                        str[l]='\0';
                        if(reservedJS(str) && ch==' ')          //if js reserved word found
                        {
                            fputc(ch,copy);
                        }
                        else if(html && ch==' ')             //print space only for js and html files
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
