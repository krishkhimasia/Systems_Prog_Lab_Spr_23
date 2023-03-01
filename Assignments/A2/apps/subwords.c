#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<trie.h>
#include<wordutils.h>

int main()
{
    dict d=loaddfltdict();
    char *s=(char*)malloc(45*sizeof(char));
    char** res=(char**)malloc(1000*sizeof(char*));
    printf("Enter a lower-case string: ");
    scanf("%s",s);
    int l=strlen(s);
    int repeat[l];
    for(int i=0;i<l;i++)
    {
        repeat[i]=0;
    }
    for(int i=0;i<l;i++)
    {
        for(int j=i+1;j<l;j++)
        {
            if(s[j]==s[i])
            {
                repeat[j]=1;
            }
        }
    }
    int num=0;
    for(int i=0;i<l;i++)
    {
        if(repeat[i])
        {
            continue;
        }
        char* str=(char*)malloc((l)*sizeof(char));
        str[l-1]='\0';
        int k=0;
        for(int j=0;j<l;j++)
        {
            if(j!=i)
            {
                str[k]=s[j];
                k++;
            }
        }
        char **r=anagrams(d,str);
        int it=0;
        while(r[it]!=NULL)
        {
            res[num]=strdup(r[it]);
            num++;
            it++;
        }
    }
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(res[i]==res[j])
            {
                for(int k=j;k<num;k++)
                {
                    if(res[k]!=NULL)
                    {
                        res[k]=res[k+1];
                    }
                }
                num--;
            }
        }
    }
    for(int i=0;i<num;i++)
    {
        printf("%s\n",res[i]);
    }
    printf("%d subwords found\n",num);
    free(s);
}