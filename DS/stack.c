#include <stdio.h>
int MAX = 10, top = -1;
int a[10];

void push()
{
	int val;

	if (top == MAX - 1)
		printf("\n STACK OVERFLOW!!!");
	else
	{
		printf("\n Enter value to be inserted: ");
		scanf("%d", &val);
		top++;
		a[top] = val;
		printf("\n %d inserted to the stack", val);
	}
}

int pop()
{
	if (top == -1)
		printf("\n STACK UNDERFLOW!!!");
	else
	{
		int v = a[top];
		top--;
		printf("\n Removed Element: %d", v);
	}
}

int peek()
{
	if (top == -1)
		printf("\n STACK EMPTY!!!!");
	printf("\n Element in top of stack: = %d ", a[top]);
}

void display()
{
	if (top == -1)
		printf("\n STACK EMPTY!!!!");
	else
	{
		printf("\n STACK ELEMENTS: ");
			for (int i = 0; i <= top; i++)
				printf("%d ", a[i]);
	}
		
}

void main()
{
	printf("Enter max size of stack: ");
	scanf("%d", &MAX);
	int ch = 4;
	do
	{
		printf("\n\n-----------------------------------------------------\n 1: Insertion\n 2: Deletion\n 3: Stack Display\n 4: Peek\n 5: Exit\n-----------------------------------------------------\n Enter your choice: ");

		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			push();
			break;
		case 2:
			 pop();
			break;
		case 3:
			display();
			break;
		case 4:
			peek();
			break;
		}
	} while (ch < 5);
}
