#include <stdio.h>
void main()
{
    int n, m, k = 0;
    printf("\nEnter size of 2 arrays array: ");
    scanf("%d %d", &n, &m);
    int a[n], b[m];
    printf("\nEnter %d values to first array: ", n);
    for (int i = 0; i < n; i++)

        scanf("%d", &a[i]);
    printf("\nEnter %d values to second array: ", m);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    printf("\nArray 1: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nArray 2: ");
    for (int i = 0; i < m; i++)
        printf("%d ", b[i]);
    for (int i = n; i < (n + m); i++)
    {
        a[i] = b[k];
        k++;
    }
    printf("\n\nMerged Array : ");
    for (int i = 0; i < (n + m); i++)
        printf("%d ", a[i]);
}