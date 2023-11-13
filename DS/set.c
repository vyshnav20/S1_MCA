#include<stdio.h>
#include<stdlib.h>
int max=10;
int isDuplicate(int arr[],int v)
{
    for (int i=0;i<max;i++)
    {
        if(arr[i]==v)
        {
            printf("Element already present in SET\n");
             return 1;
        }           
        else
         return 0;
            
    }
}

int isUniversal(int arr[],int v)
{
    int c=0;
    for (int i=0;i<max;i++)
    {
        if(arr[i]==v)
            c=1;
            break;
    }
    if(c==1)
        return 1;
    else 
    {
        printf("Element not part of UNIVERSAL SET\n");
        return 0;
    }
}

void main()
{
    int sa,sb,k=0;
    printf("Enter size of universal set: ");
    scanf("%d",&max);
    int U[max],A[max],BA[max],v;
    printf("Enter UNIVERSAL SET ELEMENTS: ");
    for (int i=0;i<max;i++)
    {
        scanf("%d",&v);
        if(isDuplicate(U,v)==0)
            U[i]=v;
        else
            i--;
    }
    printf("Enter size of set A: ");
    scanf("%d",&sa);
    printf("Enter SET A ELEMENTS: ");
    for (int i=0;i<sa;i++)
    {
        scanf("%d",&v);
        if(isDuplicate(A,v)==0)
            A[i]=v;
        else
            i--;    
    }
    printf("U SET ELEMENTS: ");
    for (int i=0;i<max;i++)
    {
        printf("%d ",U[i]);
    }
    printf("\nSET A ELEMENTS: ");
    for (int i=0;i<sa;i++)
    {
        printf("%d ",A[i]);
    }
    while(k!=max)
    {
        for(int i=0;i<sa;i++)
            if(U[k]==A[i])
            {
                BA[k]=1;
                break;
            }
                
            else BA[k]=0;
        k++;
    }
    printf("\nBIT SET A ELEMENTS: ");
    for (int i=0;i<max;i++)
    {
        printf("%d ",BA[i]);
    }
    
}