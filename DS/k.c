#include <stdio.h>
#include <stdlib.h>
void main()
{
    int a[7][7]={0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1,0};
    int v[7]={0,0,0,0,0,0,0};
    int b[2]={3,4};
    int c=0,k=0,l=b[0];
    v[l]=1;
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    for(int i=0;i<7;i++)
    {
           if(i==b[1] && a[l][i]==1)
                {
                    printf("Cycle");
                    i=7;
                }
            else if(a[l][i]==1&&v[i]==0)
            {
                v[i]=1;
                l=i;
                i=-1;
            }
    }
}