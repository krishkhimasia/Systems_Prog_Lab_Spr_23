#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<trie.h>
#include<dicttype.h>

int count=0;        //global variable for maintaining count in anagrams()

char * addbefore(dict d, char* s)
{
    int l=strlen(s),cnt=0;
    char * str=(char*)malloc(sizeof(s)+2*sizeof(char));
    str[0]='a';
    strcat(str,s);
    str[l+1]='\0';
    char *res=(char*)malloc(27*sizeof(char));
    for(int i=0;i<26;i++)
    {
        str[0]=(char)('a'+i);
        if(triesearch(d,str))
        {
            res[cnt]=(char)('a'+i);
            cnt++;
        }
    }
    res[cnt]='\0';
    return res;
}

char * addafter(dict d, char* s)
{
    int l=strlen(s),cnt=0;
    char* str=strdup(s);
    str=realloc(str,2*sizeof(char)+sizeof(s));
    str[l]='a';
    str[l+1]='\0';
    char *res=(char*)malloc(27*sizeof(char));
    for(int i=0;i<26;i++)
    {
        str[l]=(char)('a'+i);
        if(triesearch(d,str))
        {
            res[cnt]=(char)('a'+i);
            cnt++;
        }
    }
    res[cnt]='\0';
    return res;
}
void swap(char* x, char* y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(dict d, char** res, char* str, int l, int r)       //goes thru each permutation and runs triesearch()
{
    int i;
    if(l==r)
    {
        if(triesearch(d,str))
        {
            res[count]=strdup(str);
            count++;
            res[count]=NULL;
        }
    }
    else
    {
        for(i=l;i<=r;i++)
        {
            char temp;
            temp = *(str+l);
            *(str+l) = *(str+i);
            *(str+i) = temp;
            permute(d,res,str,l+1,r);
            temp = *(str+l);
            *(str+l) = *(str+i);
            *(str+i) = temp;
        }
    }
}

char ** anagrams(dict d, char* s)
{
    count=0;
    int l=strlen(s),cnt=0;
    char* str=strdup(s);
    int f=1,i=0,j;
    while(l-i>0)
    {
        f*=(l-i);
        i++;
    }
    char** res=(char**)malloc((f+1)*sizeof(s));
    permute(d,res,str,0,l-1);
    for(i=0;i<f+1;i++)      //to find no. of anagrams
    {
        if(res[i]==NULL)
        {
            cnt=i;
            break;
        }
    }
    for(i=0;i<cnt;i++)      //to find no. of anagrams
    {
        for(j=i+1;j<cnt;j++)
        {
            if(strcmp(res[i],res[j])==0)
            {
                for(int k=j;k<cnt;k++)
                {
                    if(res[k]!=NULL)
                    {
                        res[k]=res[k+1];
                    }
                }
                cnt--;
            }
        }
    }
    return res;
}
