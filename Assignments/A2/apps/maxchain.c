#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<trie.h>
#include<wordutils.h>

int maxLength=0;
int length=0,cnt=0;
char finalword[50];

void func(dict d, char* a)
{
    int i,j;
    if(strlen(addbefore(d,a))==0 && strlen(addafter(d,a))==0)
    {
        if(length>maxLength)
        {
            maxLength=length;
            for(i=0;i<length;i++)
            {
                finalword[i]=a[i];
            }
        }
        return;
    }
    char* b=addbefore(d,a);
    char* c=addafter(d,a);
    for(i=0;i<strlen(b);i++)
    {
        char* new=(char*)malloc(sizeof(a)+sizeof(char));
        strncpy(new,b+i,1);
        strcat(new,a);
        length++;
        func(d,new);
        length--;
    }
    for(i=0;i<strlen(c);i++)
    {
        char* new=(char*)malloc(sizeof(a)+sizeof(char));
        strcpy(new,a);
        strncat(new,c+i,1);
        length++;
        func(d,new);
        length--;
    }
}

int fagain(dict d, char* a, char** final)
{
    int i,j;
    if(strlen(addbefore(d,a))==0 && strlen(addafter(d,a))==0)
    {
        if(length==maxLength)
        {
            return 1;
        }
    }
    char* b=addbefore(d,a);
    char* c=addafter(d,a);
    for(i=0;i<strlen(b);i++)
    {
        char* new=(char*)malloc(sizeof(a)+sizeof(char));
        strncpy(new,b+i,1);
        strcat(new,a);
        length++;
        int p=fagain(d,new,final);
        length--;
        if(p==1)
        {
            final[cnt]=strdup(new);
            cnt++;
            return 1;
        }
    }
    for(i=0;i<strlen(c);i++)
    {
        char* new=(char*)malloc(sizeof(a)+sizeof(char));
        strcpy(new,a);
        strncat(new,c+i,1);
        length++;
        int p=fagain(d,new,final);
        length--;
        if(p==1)
        {
            final[cnt]=strdup(new);
            cnt++;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i;
    dict d=loaddfltdict();
    for(i=0;i<26;i++)
    {
        length=0;
        char*s=(char*)malloc(50*sizeof(char));
        char c=(char)('a'+i);
        strncpy(s,&c,1);
        length=1;
        func(d,s);
    }
    char **finalRes=(char**)malloc(1000*sizeof(char*));
    for(i=0;i<26;i++)
    {
        length=0;
        char*s=(char*)malloc(50*sizeof(char));
        char c=(char)('a'+i);
        strncpy(s,&c,1);
        length=1;
        int p=fagain(d,s,finalRes);
        if(p==1)
        {
            finalRes[cnt]=strdup(s);
            cnt++;
            break;
        }
    }
    finalword[maxLength]='\0';
    printf("The maxchain for our dictionary is:\n");
    for(i=cnt-1;i>=0;i--)
    {
        printf("%d) %s\n",cnt-i,finalRes[i]);
    }
    return 0;
}