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
    }
    
    return 0;
}

int isUniversal(int U[],int v)
{
    int c=0;
    for(int i = 0; i < max; i++)
        if(U[i]==v)
        {
            c=1;
            return 1;
        }
    if(c==0) printf("Element not present in Universal set\n");
    return 0;
}

void bitstring(int U[],int A[],int BA[],int sa)
{
    int k=0;
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
}

void set_union(int a[],int b[],int c[])
{
    int k=0;
    while(k!=max)
    {
        if(a[k]==1 || b[k]==1)
            c[k]=1;
        else
            c[k]=0;
        k++;
    }
}

void set_intersection(int a[],int b[],int c[])
{
    int k=0;
    while(k!=max)
    {
        if(a[k]==1 && b[k]==1)
            c[k]=1;
        else
            c[k]=0;
        k++;
    }
}

void main()
{
    int a,b,sa,sb,k=0;
    printf("Enter size of universal set: ");
    scanf("%d",&max);
    int U[max],A[max],B[max],BA[max],BB[max],union_set[max],intersection[max],v;
    printf("Enter UNIVERSAL SET ELEMENTS: ");
    for (int i=0;i<max;i++)
    {
        scanf("%d",&v);
        if(isDuplicate(U,v)==0)
            U[i]=v;
        else
            i--;
    }
    printf("\nU SET ELEMENTS: ");
    for (int i=0;i<max;i++)
    {
        printf("%d ",U[i]);
    }
    printf("\n\nEnter size of set A: ");
    scanf("%d",&sa);
    printf("Enter SET A ELEMENTS: ");
    for (int i=0;i<sa;i++)
    {
        scanf("%d",&v);
        a=isDuplicate(A,v);
        b=isUniversal(U,v);
        if(a==0 && b==1)
            A[i]=v;
        else
            i--;    
    }
    
    printf("\nSET A ELEMENTS: ");
    for (int i=0;i<sa;i++)
    {
        printf("%d ",A[i]);
    }
    
    
    
    printf("\n\nEnter size of set B: ");
    scanf("%d",&sb);
    printf("Enter SET B ELEMENTS: ");
    for (int i=0;i<sb;i++)
    {
        scanf("%d",&v);
        a=isDuplicate(B,v);
        b=isUniversal(U,v);
        if(a==0 && b==1)
            B[i]=v;
        else
            i--;    
    }
    
    printf("\nSET B ELEMENTS: ");
    for (int i=0;i<sb;i++)
    {
        printf("%d ",B[i]);
    }
    bitstring(U,A,BA,sa);

    printf("\n\nBIT Representation of SET A: ");
    for (int i=0;i<max;i++)
    {
        printf("%d ",BA[i]);
    }
    
    bitstring(U,B,BB,sb);

    printf("\nBIT Representation of SET A: ");
    for (int i=0;i<max;i++)
    {
        printf("%d ",BB[i]);
    }
    printf("\n\nUNION OF SET A and B: ");
    set_union(BA,BB,union_set);
    for (int i=0;i<max;i++)
    {
        printf("%d ",union_set[i]);
    }

    printf("\n\nINTERSECTION OF SET A and B: ");
    set_intersection(BA,BB,intersection);
    for (int i=0;i<max;i++)
    {
        printf("%d ",intersection[i]);
    }

}