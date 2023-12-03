#include <stdio.h>
#include <stdlib.h>
int c=0;
int  dfs(int n,int si,int a[si][si],int v[])
{
	if(v[n]!=1)
	{
		
		v[n]=1;
		for(int i=0;i<si;i++)
		{
			if(a[n][i]==1)
            {
                if(v[i]==0)
			        dfs(i,si,a,v);
                else
                {
                    c=1;
                    break;
                }
            }            
		}
	}
}

void main()
{
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int a[n][n],ts[n];
	printf("Enter adjacency matrix for a directed acyclic graph: ");
	for(int i=0;i<n;i++)
	{	ts[i]=0;
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
    dfs(0,n,a,ts);
    if(c==1)
        printf("Cycle");
}