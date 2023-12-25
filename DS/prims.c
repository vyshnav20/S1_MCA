#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n;
	printf("Enter no:of vertices: ");
	scanf("%d",&n);
	int A[n][n],vi[n],u,v,min=999,cost=0,e=1;
	printf("Enter adjacency matrix: ");
	for(int i=0;i<n;i++)
	{
		vi[i]=0;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
			if(A[i][j]==0)
				A[i][j]=999;
			if(A[i][j]<min)
			{
				min=A[i][j];
				u=i;
				v=j;
			}
		}
	}
	cost+=min;
	vi[u]=1;
	vi[v]=1;
	printf("\nSpanning Tree\n");
	printf("Edge {%d,%d}= %d\n",u,v,min);
	while(e<n-1)
	{
		min=999;
		for(int i=0;i<n;i++)
		{
			if(vi[i]==1)
			{
				for(int j=0;j<n;j++)
				{
					if(A[i][j]<min && vi[j]==0)
					{
						min=A[i][j];
						u=i;
						v=j;
					}
				}
			}
		}
		cost+=min;
		vi[v]=1;
		printf("Edge {%d,%d}= %d\n",u,v,min);
		e+=1;
	}
	printf("Cost = %d",cost);
}