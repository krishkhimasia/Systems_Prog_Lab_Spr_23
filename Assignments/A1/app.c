#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "common.h"
#include "foo.h"
#include "bar.h"

int main()
{
	srand(time(0));
	unsigned int n;
	int c=0;
	#ifdef INTERACTIVE
	printf("Enter n: ");
	scanf("%i",&n);
	printf("\nfoo: \"");
	fooprn(n);
	printf("\"\nbar: \"");
	barprn(n);
	printf("\"\n");
	#else
	n=rand();
	while(c==0)
	{
		printf("n = %i", n);
		printf("\nfoo: \"");
        	fooprn(n);
        	printf("\"\nbar: \"");
        	barprn(n);
        	printf("\"\n\n");
		if(n==0)
		{
			c++;
		}
		n/=10;
	}
	#endif
	return 0;
}
