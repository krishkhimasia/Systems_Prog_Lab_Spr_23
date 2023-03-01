#include <stdio.h>              //search got a problem
#include <stdlib.h>
#include <string.h>
#include <trie.h>

trie trieinit()
{
    trie t = (trie)malloc(sizeof(_trie));
    t->root = (trienode)malloc(sizeof(_trienode));
    t->root->c = '-';
    t->root->eow = 0;
    t->root->fc = NULL;
    t->root->sib = NULL;
    return t;
}

int triesearch(trie t, char *s)
{
    int len = strlen(s);
    trienode p = t->root->fc;
    while (p != NULL)
    {
        if (p->c == s[0])
        {
            break;
        }
        p=p->sib;
    }
    for (int i = 0; i < len; i++)
    {
        if (i == len - 1)
        {
            while (p != NULL)
            {
                if (p->c == s[i])
                {
                    if (p->eow)
                        return 1;
                    else
                        return 0;
                }
                p=p->sib;
            }
        }
        else
        {
            while (p != NULL)
            {
                if (p->c == s[i])
                {
                    p = p->fc;
                    break;
                }
                p=p->sib;
            }
        }
    }
    return 0;
}

void trieinsert(trie t, char* s)
{
    int len = strlen(s);
    trienode prev=t->root->fc,curr=prev;
    if (triesearch(t, s)) // if s already exists in t
    {
        return;
    }
    if(curr==NULL)
    {
        for(int i=0;i<len;i++)
        {
            trienode temp=(trienode)malloc(sizeof(_trienode));
            temp->c=s[i];
            if(i==0)
            {
                t->root->fc=temp;
                prev=temp;
                curr=prev->fc;
            }
            else
            {
                prev->fc=temp;
                prev=temp;
                curr=prev->fc;
            }
            if(i==len-1)
            {
                prev->eow=1;
            }
        }
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            trienode temp=(trienode)malloc(sizeof(_trienode));
            temp->c=s[i];
            if(i==len-1)
            {
                temp->eow=1;
            }
            if(curr==NULL)
            {
                prev->fc=temp;
                curr=temp->fc;
                prev=temp;
                i++;
                while(i<len)
                {
                    trienode temp2=(trienode)malloc(sizeof(_trienode));
                    temp2->c=s[i];
                    prev->fc=temp2;
                    curr=temp2->fc;
                    prev=temp2;
                    if(i==len-1)
                    {
                        prev->eow=1;
                    }
                    i++;
                }
            }
            while(curr!=NULL)
            {
                if(curr->c>s[i])
                {
                    if(prev->fc==curr)
                    {
                        prev->fc=temp;
                        temp->sib=curr;
                        prev=temp;
                        curr=temp->fc;
                        if(i==len-1)
                        {
                            temp->eow=1;
                        }
                        break;
                    }
                    else if(prev==curr)
                    {
                        t->root->fc=temp;
                        temp->sib=curr;
                        prev=temp;
                        curr=temp->fc;
                        if(i==len-1)
                        {
                            temp->eow=1;
                        }
                        break;
                    }
                    else
                    {
                        prev->sib=temp;
                        temp->sib=curr;
                        prev=temp;
                        curr=temp->fc;
                    }
                }
                else if(curr->c==s[i])
                {
                    if(i==len-1)
                    {
                        curr->eow=1;
                    }
                    prev=curr;
                    curr=curr->fc;
                    break;
                }
                else
                {
                    prev=curr;
                    curr=curr->sib;
                    if(curr==NULL)
                    {
                        prev->sib=temp;
                        curr=temp->fc;
                        prev=temp;
                        i++;
                        while(i<len)
                        {
                            trienode temp2=(trienode)malloc(sizeof(_trienode));
                            temp2->c=s[i];
                            prev->fc=temp2;
                            curr=temp2->fc;
                            prev=temp2;
                            if(i==len-1)
                            {
                                prev->eow=1;
                            }
                            i++;
                        }
                    }
                }
            }
        }
    }
}

void helpList(trienode n, char *s,int level)
{
    if(n->eow)
    {
        s[level]=n->c;
        s[level+1]='\0';
        printf("%s\n",s);
    }
    if(n->fc!=NULL)
    {
        s[level]=n->c;
        s[level+1]='\0';
        helpList(n->fc,s,level+1);
    }
    if(n->sib!=NULL)
    {
        helpList(n->sib,s,level);
    }
}

void listall(trie t)
{
    int l=0;
    trienode curr=t->root->fc;
    if(curr==NULL)
    {
        printf("No words in the trie.\n");
        return;
    }
    else
    {
        printf("List of words in the trie:\n");
        char s[50];
        helpList(curr,s,l);
    }
}