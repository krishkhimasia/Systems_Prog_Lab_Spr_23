#include<stdio.h>
#include "common.h"
#include "foo.h"

void fooprn(unsigned int n)
{
	int i;
	if(n==0)
	printf("zero");
	else
	{
        int a[11];
        for(i=10;i>=1;i--)
        {
                a[i]=n%10;
                n/=10;
        }
	int n1=a[1];
        if(n1)
	{
                cmnprn(n1);
                printf(" billion");
        }
	int n2=100*a[2]+10*a[3]+a[4];
        if(n2)
	{
                if(n1)
                {
                        printf(" ");
                }
	        cmnprn(n2);
                printf(" million");
        }
        int n3=100*a[5]+10*a[6]+a[7];
        if(n3)
        {
                if(n1 || n2)
                {
                        printf(" ");
                }
	        cmnprn(n3);
                printf(" thousand");
        }
        int n4=100*a[8]+10*a[9]+a[10];
        if(n4)
        {
                if(n1 || n2 || n3)
                {
                        printf(" ");
                }
                cmnprn(n4);
        }
	}
}
