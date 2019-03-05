#include "function.h"

/**
 * this function will tell whether given char is wildcard or not
 * for discarding char in filename
 * 
 * @param ch for char
 * 
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
 * it will check whether the string is valid or not
 * i.e it contains single . or not
 * 
 * @param string
 * 
 * @return bool
 **/
bool checkValid(char *str)
{
    int count=0;                                            // counting the number of dots in the filename
    int i=0;
    
    /**
     * traversing the string and counting . chars
     **/
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
    if(count==1)                                            // valid for only one dot in string
    {
        return true;
    }
    return false;
}

/**
 * This function conveys that the string is a html keyword or not
 * 
 * @param search string
 * 
 * @return bool
 **/
bool reservedHTML(char *str)
{
    int key = hashfunction(str);                            // finding the key of string

    /**
     * collison: 146 <code
     * collison: 109 <del
     * collison: 282 <details
     * collison: 165 <link
     * collison: 156 <main
     * collison: 118 <map
     * collison: 130 <sub
     * collison: 144 <sup
     * collison: 81 <td
     * collison: 188 <thead
     * collison: 166 <time
     * collison: 216 <title
     * collison: 95 <tr
     * collison: 131 <wbr
     **/
    char ch = str[1];
    switch (ch)
    {
        case 'c':
            if(strcmp(str,"<code")==0)
            {
                key++;
            }
            break;
        case 'd':
            if(strcmp(str,"<del")==0 || strcmp(str,"<details")==0)
            {
                key++;
            }
            break;
        case 'l':
            if(strcmp(str,"<link")==0)
            {
                key++;
            }
            break;
        case 'm':
            if(strcmp(str,"<main")==0 || strcmp(str,"<map")==0)
            {
                key++;
            }
            break;
        case 's':
            if(strcmp(str,"<sub")==0 || strcmp(str,"<sup")==0)
            {
                key++;
            }
            break;
        case 't':
            {
                ch = str[2];
                switch (ch)
                {
                    case 'h':
                        if(strcmp(str,"<thead")==0)
                        {
                            key++;
                        }
                        break;
                    case 'i':
                        if(strcmp(str,"<time")==0 || strcmp(str,"<title")==0)
                        {
                            key++;
                        }
                        break;
                    case 'r':
                        if(strcmp(str,"<tr")==0)
                        {
                            key++;
                        }
                        break;
                    default:
                        break;
                }
            }
            break;
        case 'w':
            if(strcmp(str,"<wbr")==0)
            {
                key++;
            }
            break;
        default:
            break;
    }

    if(key<0 || key>HASHSIZE)                               // if key not valid
    {
        return false;
    }
    else if(HASH[key]!=NULL && strcmp(str,HASH[key])==0)    // key found but checking the string for total surety
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * This function will search a string in the collection of JavaScript reserved words
 * 
 * @param search string
 * 
 * @return bool
 **/
bool reservedJS(char* str)
{
    int key = hashfunction(str);                            // finding the key of string
    
    /**
     * COLLISION SOLUTION
     * Added initial shift value
     * 
     * float -- 210
     **/
    if(strcmp(str,"float")==0)
    {
        key++;
    }

    if(key<0 || key>HASHSIZE)                               // if key is not valid
    {
        return false;
    }
    else if(HASH[key]!=NULL && strcmp(str,HASH[key])==0)    // if key found
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * it will search a string in the collection of reserved words in C language
 * 
 * @param search string
 * 
 * @return bool
 **/
bool reservedC(char* str)
{
    int key = hashfunction(str);                            // finding the key of string

    /**
     * COLLISION SOLUTION
     * Adding initial shift value to key
     * 
     * 349 -- continue  
     * 181 -- goto
     **/
    if(strcmp(str,"continue")==0 || strcmp(str,"goto")==0)
    {
        key++;
    }

    if(key<0 || key>HASHSIZE)                               // if key is not valid
    {
        return false;
    }
    else if(HASH[key]!=NULL && strcmp(str,HASH[key])==0)    // if key founded
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * it will search a string in the collection of reserved words in C++ language
 * 
 * @param search string
 * 
 * @return bool
 **/
bool reservedCPP(char* str)
{
    int key = hashfunction(str);
    
    /**
     * COLLISION SOLUTION
     * Added initial shift value to key
     * 
     * 349-continue
     * 209-class 
     * 181-goto 
     * 356-operator 
     * 249-public
     **/
    char ch = str[0];
    switch (ch)                                             // faster mechanism for comparing strings
    {
        case 'c':
            {
                ch = str[1];
                switch (ch)
                {
                    case 'o':
                        if(strcmp(str,"continue")==0)
                        {
                            key++;
                        }
                        break;
                    case 'l':
                        if(strcmp(str,"class")==0)
                        {
                            key++;
                        }
                        break;
                    default:
                        break;
                }
            }
            break;
        case 'g':
            if(strcmp(str,"goto")==0)
            {
                key++;
            }
            break;
        case 'o':
            if(strcmp(str,"operator")==0)
            {
                key++;
            }
            break;
        case 'p':
            if(strcmp(str,"public")==0)
            {
                key++;
            }
            break;
        default:
            break;
    }

    if(key<0 || key>HASHSIZE)                                   // if the key is not valid       
    {
        return false;
    }
    else if(HASH[key]!=NULL && strcmp(str,HASH[key])==0)        // if key found
    {
        return true;
    }
    else
    {
        return false;
    }
} 

/**
 * it will search a string in the collection of reserved words in JAVA language
 * 
 * @param search string
 * 
 * @return bool
 **/
bool reservedJAVA(char* str)
{
    int key = hashfunction(str);       
    /**
     * collision solution
     * 209-float 
     * 308-private
     * 268-switch
     **/
    if(strcmp(str,"float")==0 || strcmp(str,"private")==0 || strcmp(str,"switch")==0)  
    {
        key++;
    }

    if(key<0 || key>HASHSIZE)                                   // if key is not valid
    {
        return false;
    }
    else if(HASH[key]!=NULL && strcmp(str,HASH[key])==0)        // if key found
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * it will search a string in the collection of reserved words in C# language
 * 
 * @param search string
 * 
 * @return bool
 **/
bool reservedCSharp(char* str)
{
    int key = hashfunction(str);       
    
    /**
     * COLLISIONS FOUND
     * 209 -- float
     * 165 -- lock
     * 356 -- operator
     * 226 -- sbyte
     * 273 -- string
     * 273 -- typeof
     * 188 -- unit
     * 287 -- ushort
     * 344 -- volatile
     **/
    char ch = str[0];
    switch (ch)
    {
        case 'f':
            if(strcmp(str,"float")==0)
            {
                key++;
            }
            break;
        case 'l':
            if(strcmp(str,"lock")==0)
            {
                key++;
            }
            break;
        case 'o':
            if(strcmp(str,"operator")==0)
            {
                key++;
            }
            break;
        case 's':
            {
                ch = str[1];
                switch (ch)
                {
                    case 'b':
                        if(strcmp(str,"sbyte")==0)
                        {
                            key++;
                        }
                        break;
                    case 't':
                        if(strcmp(str,"string")==0)
                        {
                            key++;
                        }
                        break;
                    default:
                        break;
                }
            }
            break;
        case 't':
            if(strcmp(str,"typeof")==0)
            {
                key=key+2;
            }
            break;
        case 'u':
            {
                ch = str[1];
                switch (ch)
                {
                    case 'n':
                        if(strcmp(str,"unit")==0)
                        {
                            key++;
                        }
                        break;
                    case 's':
                        if(strcmp(str,"ushort")==0)
                        {
                            key++;
                        }
                        break;
                    default:
                        break;
                }
            }
            break;
        case 'v':
            if(strcmp(str,"volatile")==0)
            {
                key++;
            }
            break;
        default:
            break;
    }

    if(key<0 || key>HASHSIZE)                                   // if key is not valid
    {
        return false;
    }
    else if(HASH[key]!=NULL && strcmp(str,HASH[key])==0)        // is key found
    {
        return true;
    }
    else
    {
        return false;
    }   
}



/**
 * It will build keyword tree of html keywords
 * 
 * @return void
 **/
void buildHTML()
{
    int key = INT_MIN;

    HASH = (char**)malloc(sizeof(char*)*HASHSIZE);      // making hashtable of the size
    
    char* HTML[] ={"<!DOCTYPE","<a","<abbr","<address","<area","<article","<aside","<audio","<b","<base",
    "<bdi","<bdo","<blockquote","<body","<br/","<br","<button","<canvas","<caption","<cite","<code","<col",
    "<colgroup","<data","<datalist","<dd","<del","<details","<dfn","<dialog","<div","<dl","<dt","<em","<embed",
    "<fieldset","<figcaption","<figure","<footer","<form","<frame","<frameset","<h1","<h2","<h3","<h4","<h5",
    "<h6","<head","<header","<hr","<html","<i","<iframe","<img","<input","<ins","<kbd","<label","<legend",
    "<li","<link","<main","<map","<amrk","<meta","<meter","<nav","<noscript","<object","<ol","<optgroup",
    "<option","<output","<p","<param","<picture","<pre","<progress","<q","<rp","<rt","<ruby","<s","<samp",
    "<script","<section","<select","<small","<source","<span","<strong","<style","<sub","<summary","<sup",
    "<svg","<table","<tbody","<td","<template","<textarea","<tfoot","<th","<thead","<time","<title","<tr",
    "<track","<tt","<u","<ul","<var","<video","<wbr"};

    register int i;
    for(i=0;i<115;i++)
    {
        key = hashfunction(HTML[i]);

        if(key >= 0 && key<HASHSIZE && HASH[key]==NULL)
        {
            int s = strlen(HTML[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],HTML[i]);
        }
        else
        {
            // printf("collison: %d %s\n",key,HTML[i]);
            // printf("BUG FOUND IN BuildHTML!!!");
            // exit(1);
            key++;
            int s = strlen(HTML[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],HTML[i]);
        }
    }
}

/**
 * It will build keyword tree of Javscript keywords
 * 
 * @return void
 **/
void buildJS()
{
    int key = INT_MIN;

    HASH = (char**)malloc(sizeof(char*)*HASHSIZE);      // making hashtable of the size

    //better efficiency is needed here
    //may be binary search tree for string searching
    //js reserved words
    char* JS[] = {"new","abstract","else","instanceof","super","boolean","enum","int","switch","break","export","interface","synchronised","byte","extends","let"
                ,"this","case","false","long","throw","catch","final","native","throws","char","finally","transient","class","float","null","true"
                ,"const","for","package","try","continue","function","private","typeof","debugger","goto","protected","var","default","if","public","void","delete"
                ,"implements","return","volatile","do","import","short","while","double","in","static","with"};
    
    register int i;
    for(i=0;i<60;i++)
    {   
        key = hashfunction(JS[i]);
        
        if(key >= 0 && key<HASHSIZE && HASH[key]==NULL)
        {
            int s = strlen(JS[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],JS[i]);
        }
        else                                                // collision on 210 float
        {
            key++;
            int s = strlen(JS[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],JS[i]);
        }
    }
}

/**
 * It will build keyword tree of C keywords
 * 
 * @return void
 **/
void buildC()
{
    int key = INT_MIN;

    HASH = (char**)malloc(sizeof(char*)*HASHSIZE);      // making hashtable of the size

    char* C[] = {"auto","else","long","switch","break","enum","register","typedef","case",
    "extern","return","union","char","float","short","unsigned","const","for","signed"
    ,"void","continue","goto","sizeof","volatile","default","if","static","while","do",
    "int","struct","double","bool","true","false"};

    register int i;
    for(i=0;i<35;i++)
    {
        key = hashfunction(C[i]);

        if(key >= 0 && key<HASHSIZE && HASH[key]==NULL)
        {
            int s = strlen(C[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],C[i]);
        }
        else                                        // collision on 349 continue  181 - goto
        {
            // printf("collision %d  %s\n",key,C[i]);
            key++;
            int s = strlen(C[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],C[i]);
        }
    }
}

/**
 * It will build keyword tree of C++ keywords
 * 
 * @return void
 **/
void buildCPP()
{
    int key = INT_MIN;

    HASH = (char**)malloc(sizeof(char*)*HASHSIZE);      // making hashtable of the size

    char* CPP[]={"auto","double","int","struct","break","else","long","switch","case","enum","register",
    "typedef","char","extern","return","union","const","float","short","unsigned","continue",
    "for","signed","void","default","goto","sizeof","volatile","do","if","static","while","asm","bool"
    ,"catch","class","const_cast","delete","dynamic_cast","explicit","export","false","friend",
    "inline","mutable","namespace","new","operator","private","protected","public","reinterpret_cast",
    "static_cast","template","this","throw","true","try","typeid","typename","using","virtual","wchar_t"};

    register int i;
    for(i=0;i<63;i++)
    {
        key = hashfunction(CPP[i]);

        if(key >= 0 && key<HASHSIZE && HASH[key]==NULL)
        {
            int s = strlen(CPP[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],CPP[i]);
        }
        else                                        // collisions 349-continue 181-goto 209-class 356-operator 249-public
        {
            // printf("collision %d  %s\n",key,CPP[i]);
            // exit(1);
            key++;
            int s = strlen(CPP[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],CPP[i]);
        }
    }
}

/**
 * It will build keyword tree of JAVA keywords
 * 
 * @return void
 **/
void buildJAVA()
{
    int key = INT_MIN;

    HASH = (char**)malloc(sizeof(char*)*HASHSIZE);      // making hashtable of the size

    char* JAVA[]={"abstract","assert","boolean","break","byte","case","catch","char",
    "class","continue","default","do","double","else","enum","extends","final","finally",
    "float","for","if","implements","import","istanceof","int","interface","long","native",
    "new","null","package","private","protected","public","return","short","static","strictfp",
    "super","switch","synchronized","this","throw","throws","transient","try","void","volatile",
    "while"};

    register int i=0;
    for(i=0;i<49;i++)
    {
        key = hashfunction(JAVA[i]);

        if(key >= 0 && key<HASHSIZE && HASH[key]==NULL)
        {
            int s = strlen(JAVA[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],JAVA[i]);
        }
        else                                        // collisions 209-float 308-private 268-switch
        {
            // printf("collision %d  %s\n",key,JAVA[i]);
            // exit(1);
            key++;
            int s = strlen(JAVA[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],JAVA[i]);
        }
    }
}

/**
 * It will build keyword tree of CSharp keywords
 * 
 * @return void
 **/
void buildCSharp()
{
    int key = INT_MIN;

    HASH = (char**)malloc(sizeof(char*)*HASHSIZE);      // making hashtable of the size

    char* CSHARP[] ={"abstract","as","base","bool","break","byte","case","catch","char"
    ,"checked","class","const","continue","decimal","default","delegate","do","double"
    ,"else","enum","event","explicit","extern","false","finally","fixed","float","for"
    ,"foreach","goto","if","implicit","in","int","interface","internal","is","lock"
    ,"long","namespace","new","null","object","operator","out","override","params","private"
    ,"protected","public","readonly","ref","return","sbyte","sealed","short","sizeof"
    ,"stackalloc","static","string","struct","switch","this","throw","true","try","typeof"
    ,"unit","ulong","unchecked","unsafe","ushort","using","using static","virtual","void","volatile"
    ,"while"};

    register int i;
    for(i=0;i<78;i++)
    {
        key = hashfunction(CSHARP[i]);

        if(key >= 0 && key<HASHSIZE && HASH[key]==NULL)
        {
            int s = strlen(CSHARP[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],CSHARP[i]);
        }
        else                                        
        {
            /**
             * COLLISIONS FOUND
             * 209 -- float
             * 165 -- lock
             * 356 -- operator
             * 226 -- sbyte
             * 273 -- string
             * 273 -- typeof
             * 188 -- unit
             * 287 -- ushort
             * 344 -- volatile
             **/
            // printf("collision %d  %s\n",key,CSHARP[i]);
            // exit(1);
            if(strcmp(CSHARP[i],"typeof")==0)
            {
                key=key+2;
            }
            else
            {
                key++;
            }
            int s = strlen(CSHARP[i]);
            HASH[key] = (char*)malloc(sizeof(char)*(s+1));
            strcpy(HASH[key],CSHARP[i]);
        }
    }
}