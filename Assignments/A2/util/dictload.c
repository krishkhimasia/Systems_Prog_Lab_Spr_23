#include<stdio.h>
#include<string.h>
#include<trie.h>
#include<dicttype.h>
#include<dictload.h>

dict loaddfltdict()
{
    FILE * DFLT_DICT;
    DFLT_DICT=fopen("../dict/words.txt", "a+");
    dict d=trieinit();

    char str[50];
    while(fgets(str,50, DFLT_DICT) != NULL)
    {
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='\n')
            {
                str[i]='\0';
            }
        }
        trieinsert(d, str);
    }
    return d;
}

dict loaddict(char *fname)
{
    FILE * DICT;
    DICT=fopen(fname, "a+");
    dict d=trieinit();

    char str[50];
    while(fgets(str,50, DICT) != NULL)
    {
        for(int i=0;i<strlen(str);i++)
        {
            if(str[i]=='\n')
            {
                str[i]='\0';
            }
        }
        trieinsert(d, str);
    }
    return d;
}