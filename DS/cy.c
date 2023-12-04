#include <stdio.h>
#include <stdlib.h>
int c = 0;
void dfs(int n, int si, int a[si][si], int v[])
{
    if (v[n] != 1)
    {
        v[n] = 1;
        for (int i = 0; i < si; i++)
        {
            if (a[n][i] == 1)
            {
                if (v[i] == 0)
                    dfs(i, si, a, v);
                else
                {
                    printf("%d hi %d hello ", i, n);
                    c = 1;
                }
            }
        }
    }
}

void main()
{
    int v[5] = {0};
    int a[5][5] = {999, 1, 999, 1, 999,
                   999, 999, 1, 1, 999,
                   999, 999, 999, 999, 999,
                   999, 999, 1, 999, 1,
                   999, 999, 999, 999, 999};
    for (int i = 0; i < 5; i++)
        dfs(i, 5, a, v);
    if (c == 1)
        printf("Cycle");
}