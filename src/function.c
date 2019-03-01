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

/**
 * This function will search a string in the collection of JavaScript reserved words
 * 
 * @param search string
 * 
 * @return bool
 **/
bool reservedJS(char* str)
{
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
        if(strcmp(JS[i],str)==0)
        {
            return true;
        }
    }
    return false;
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
    char* C[] = {"auto","else","lo ng","switch","break","enum","register","typedef","case",
    "extern","return","union","char","float","short","unsigned","const","for","signed"
    ,"void","continue","goto","sizeof","volatile","default","if","static","while","do",
    "int","struct","double","bool","true","false"};

    register int i;
    for(i=0;i<35;i++)
    {
        if(strcmp(C[i],str)==0)
        {
            return true;
        }
    }
    return false;
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
    char* CPP[]={"auto","double","int","struct","break","else","long","switch","case","enum","register",
    "typedef","char","extern","return","union","const","float","short","unsigned","continue",
    "for","signed","void","default","goto","sizeof","volatile","do","if","static","while","asm","bool"
    ,"catch","class","const_cast","delete","dynamic_cast","explicit","export","false","friend",
    "inline","mutable","namespace","new","operator","private","protected","public","reinterpret_cast",
    "static_cast","template","this","throw","true","try","typeid","typename","using","virtual","wchar_t"};

    register int i;
    for(i=0;i<63;i++)
    {
        if(strcmp(CPP[i],str)==0)
        {
            return true;
        }
    }
    return false;
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
    char* JAVA[]={"abstract","assert","boolean","break","byte","case","catch","char",
    "class","continue","default","do","double","else","enum","extends","final","finally",
    "float","for","if","implements","import","istanceof","int","interface","long","native",
    "new","null","package","private","protected","public","return","short","static","strictfp",
    "super","switch","synchronized","this","throw","throws","transient","try","void","volatile",
    "while"};

    register int i=0;
    for(i=0;i<49;i++)
    {
        if(strcmp(JAVA[i],str)==0)
        {
            return true;
        }
    }
    return false;
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
        if(strcmp(CSHARP[i],str)==0)
        {
            return true;
        }
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
    char* HTML[] ={"<html","<head","<title","<!DOCTYPE","<body","<header","<section","<footer","<style","<script",
    "<meta","<b","<i","<input","<select"};

    register int i;
    for(i=0;i<15;i++)
    {
        if(strcmp(HTML[i],str)==0)
        {
            return true;
        }
    }
    return false;
}

/**
 * It will build keyword tree of html keywords
 * 
 * @return void
 **/
void buildHTML()
{

}

/**
 * It will build keyword tree of Javscript keywords
 * 
 * @return void
 **/
void buildJS()
{

}

/**
 * It will build keyword tree of C keywords
 * 
 * @return void
 **/
void buildC()
{

}

/**
 * It will build keyword tree of C++ keywords
 * 
 * @return void
 **/
void buildCPP()
{

}

/**
 * It will build keyword tree of JAVA keywords
 * 
 * @return void
 **/
void buildJAVA()
{

}

/**
 * It will build keyword tree of CSharp keywords
 * 
 * @return void
 **/
void buildCSharp()
{

}