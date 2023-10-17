#include<stdio.h>
void main()
{	
	int a[5];
	printf("Enter 5 Numbers: ");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter number to be searched: ");
	int s,c=0,p=0;
	scanf("%d",&s);
	for(int i=0;i<5;i++)
	{
		if(a[i]==s)
		{
			p=i+1;	
			c=1;
		}
	}
	if(c==1)
		printf("\n%d is present in position %d of the array",s,p);
	else
		printf("\n%d is not found in the array ",s);
}

