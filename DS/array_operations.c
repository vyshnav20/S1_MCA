#include <stdio.h>
void main()
{
	int a[10];
	int n = -1, val;
	int ch = 0;
	do
	{
		printf("\n\n-----------------------------------------------------\n 1: Insertion in Begining\n 2: Insertion at End\n 3: Insertion in a Position\n 4: Display Array\n 5: Deletion from Begining\n 6: Deletion at End\n 7: Deletion from a Position\n 8: Search Elements\n 9: Exit\n\n-----------------------------------------------------\n Enter your choice: ");

		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\n Enter a number to be inserted: ");
			scanf("%d", &val);
			n++;
			for (int i = n; i >= 0; i--)
			{
				a[i] = a[i - 1];
			}
			a[0] = val;
			break;
		case 2:
			printf("\n Enter a number to be inserted: ");
			scanf("%d", &val);
			n += 1;
			a[n] = val;
			break;

		case 3:
			printf("\n Enter a number to be inserted: ");
			scanf("%d", &val);
			int p;
			printf("\n Enter position: ");
			scanf("%d", &p);
			p--;
			if (p > n + 1)
				printf("\n INVALID POSITION:- Position between 1 and %d", n);
			else
			{

				n++;
				for (int i = n; i >= p; i--)
				{
					a[i] = a[i - 1];
				}
			}

			a[p] = val;
			break;
		case 4:
			if (n < 0)
				printf("\n Array Empty");
			else
			{
				printf("\n Array Elements: ");
				for (int i = 0; i <= n; i++)
				{
					printf("%d ", a[i]);
				}
			}
			break;
		case 5:
			if (n < 0)
				printf("\n Array Empty");
			else
			{
				printf("\n %d is deleted from the array", a[0]);
				for (int i = 0; i <= n; i++)
				{
					a[i] = a[i + 1];
				}
				n--;
			}

			break;
		case 6:
			if (n < 0)
				printf("\n Array Empty");
			else
			{
				printf("\n %d is deleted from the array", a[n]);
				n--;
			}
			break;

		case 7:
			if (n < 0)
				printf("\n Array Empty");
			else
			{
				printf("\n Enter position: ");
				scanf("%d", &p);
				p--;
				if (p > n)
					printf("\n INVALID POSITION:- Position between 1 and %d", n);
				else
				{
					printf("\n %d is deleted from the array", a[p]);
					for (int i = p; i < n; i++)
					{
						a[i] = a[i + 1];
					}

					n--;
				}
			}
			break;
		case 8:
			if (n < 0)
				printf("\n Array Empty");
			else
			{
				printf("\n Enter number to be searched: ");
				int s, c = 0, pos = 0;
				scanf("%d", &s);
				for (int i = 0; i <= n; i++)
				{
					if (a[i] == s)
					{
						p = i + 1;
						c = 1;
					}
				}
				if (c == 1)
					printf("\n%d is present in position %d of the array", s, p);
				else
					printf("\n%d is not found in the array ", s);
				break;
			}
		}
	} while (ch < 9);
}
