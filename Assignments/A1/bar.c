#include<stdio.h>
#include "common.h"
#include "bar.h"

void barprn(unsigned int n)
{
	int i;
	if(n==0)
	{
		printf("zero");
	}
	else
	{
	int a[11];
	for(i=10;i>=1;i--)
	{
		a[i]=n%10;
		n/=10;
	}
	int n1=100*a[1]+10*a[2]+a[3];
	if(n1)
	{
		cmnprn(n1);
		printf(" crore");
	}
	int n2=10*a[4]+a[5];
	if(n2)
	{
		if(n1)
		{
			printf(" ");
		}
		cmnprn(n2);
		printf(" lakh");
	}
	int n3=10*a[6]+a[7];
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
