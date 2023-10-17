#include <stdio.h>
void main()
{
	int n, temp;
	printf("Enter size of the array: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter %d Numbers: ", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	printf("Sorted Array Elements: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
