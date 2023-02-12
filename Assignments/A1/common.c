#include<stdio.h>
#include "common.h"

void cmnprn(unsigned int n)
{
	if(n>999)
	{
		printf("big");
	}
	else
	{
		int h=(n/100)%10,t=(n/10)%10,u=n%10;
		switch(h)
		{
			case 1:
			{
				printf("one ");
				break;
			}
			case 2:
			{
				printf("two ");
				break;
			}
			case 3:
                        {
                                printf("three ");
                                break;
                        }
                        case 4:
                        {
                                printf("four ");
                                break;
                        }
			case 5:
                        {
                                printf("five ");
                                break;
                        }
                        case 6:
                        {
                                printf("six ");
                                break;
                        }
			case 7:
                        {
                                printf("seven ");
                                break;
                        }
                        case 8:
                        {
                                printf("eight ");
                                break;
                        }
			case 9:
                        {
                                printf("nine ");
                                break;
                        }
                        default:
                        {
                                break;
                        }
		}
		if(h!=0)
		{
			printf("hundred");
		}
		if(h && t)
		{
			printf(" ");
		}
		if(t!=1)
		{
		switch(t)
		{
                        case 2:
                        {
                                printf("twenty");
                                break;
                        }
                        case 3:
                        {
                                printf("thirty");
                                break;
                        }
                        case 4:
                        {
                                printf("fourty");
                                break;
                        }
                        case 5:
                        {
                                printf("fifty");
                                break;
                        }
                        case 6:
                        {
                                printf("sixty");
                                break;
                        }
                        case 7:
                        {
                                printf("seventy");
                                break;
                        }
			case 8:
                        {
                                printf("eighty");
                                break;
                        }
                        case 9:
                        {
                                printf("ninety");
                                break;
                        }
                        default:
                        {
                                break;
                        }
		}
		if((h || t) && u)
		{
			printf(" ");
		}
		switch(u)
		{
			case 1:
                        {
                                printf("one");
                                break;
                        }
                        case 2:
                        {
                                printf("two");
                                break;
                        }
                        case 3:
                        {
                                printf("three");
                                break;
                        }
                        case 4:
                        {
                                printf("four");
                                break;
                        }
                        case 5:
                        {
                                printf("five");
                                break;
                        }
                        case 6:
                        {
                                printf("six");
                                break;
                        }
                        case 7:
                        {
                                printf("seven");
                                break;
                        }
			case 8:
                        {
                                printf("eight");
                                break;
                        }
                        case 9:
                        {
                                printf("nine");
                                break;
                        }
                        default:
                        {
                                break;
                        }
		}
		}
		else
		{
			int temp=10*t+u;
			switch(temp)
			{
				case 10:
				{
					printf("ten");
					break;
				}
                                case 11:
                                {
                                        printf("eleven");
                                        break;
                      		}
                                case 12:
                                {
                                        printf("twelve");
                                        break;
                   		}
                                case 13:
                                {
                                        printf("thirteen");
                                        break;
                        	}
                                case 14:
                                {
                                        printf("fourteen");
                                        break;
                        	}
                                case 15:
                                {
                                        printf("fifteen");
                                        break;
                        	}
                                case 16:
                                {
                                        printf("sixteen");
                                        break;
                        	}
                                case 17:
                                {
                                        printf("seventeen");
                                        break;
                        	}
                                case 18:
                                {
                                        printf("eighteen");
                                        break;
                        	}
                                case 19:
                                {
                                        printf("nineteen");
                                        break;
                        	}

			}
		}
	}
}
