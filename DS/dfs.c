#include<stdio.h>
#include<stdlib.h>
void dfs(int n,int si,int a[si][si],int v[])
{
	if(v[n]!=1)
	{
		printf("%d ",n);
		v[n]=1;
		for(int i=0;i<si;i++)
		{
			if(a[n][i]==1 && v[i]==0)
			dfs(i,si,a,v);
		}
	}
}
void main()
{
	int n,start;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int a[n][n],v[n];
	printf("Enter Adjacency matrix for the graph: ");
	for(int i=0;i<n;i++)
	{	
		v[i]=0;
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("Enter starting node (0-%d): ",(n-1));
	scanf("%d",&start);
	printf("\nDFS Traversal: ");
	dfs(start,n,a,v);
}