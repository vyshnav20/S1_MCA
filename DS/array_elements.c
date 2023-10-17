#include<stdio.h>
void main()
{	
	int a[3];
	printf("Enter 3 Numbers: ");
	for(int i=0;i<3;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Array Elements: ");
	for(int i=0;i<3;i++)
	{
		printf("%d ",a[i]);
	}
}

