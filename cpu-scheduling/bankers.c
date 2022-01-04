#include <stdio.h>


int main()
{
    int process_num, resource_num, i, j, k, y=0, flag=0;
    int alloc[20][20], max[20][20], avail[20];
    int f[20], ans[20], ind = 0, need[20][20];;

    printf("\nEnter the no. of processes : ");
    scanf("%d",&process_num);
    printf("\nEnter the no. of resource types : ");
    scanf("%d",&resource_num);
    printf("\n\nEnter allocated resource array :\n");
    
    for (i = 0; i < process_num; i++)
        for (j = 0; j < resource_num; j++)
            scanf("%d",&alloc[i][j]);



    printf("\nEnter maximum resource array :\n");
    for (i = 0; i < process_num; i++)
        for (j = 0; j < resource_num; j++)
            scanf("%d",&max[i][j]);
    
    

    printf("\nEnter available resource array: \n");
    
    for (i = 0; i < resource_num; i++)
        scanf("%d",&avail[i]);
    
    for (i = 0; i < process_num; i++)
    {
        f[i] = 0;
    }
    
    for (i = 0; i < process_num; i++)
    {
        for (j = 0; j < resource_num; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    printf("\n\nAllocated resource array :\n");
    for (i = 0; i < process_num; i++)
    {
        printf("P%d  ",i+1);
        for (j = 0; j < resource_num; j++)
            printf("%d  ", alloc[i][j]);
        printf("\n");
    }

    printf("\nMaximum resource array :\n");
    for (i = 0; i < process_num; i++)
    {
        printf("P%d  ",i+1);
        for (j = 0; j < resource_num; j++)
            printf("%d  ", max[i][j]);
        printf("\n");
    }

    printf("\nNeed matrix :\n");
    for (i = 0; i < process_num; i++)
    {
        printf("P%d  ",i+1);
        for (j = 0; j < resource_num; j++)
            printf("%d  ",need[i][j]);
        printf("\n");
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < process_num; j++)
        {
            if (f[j] == 0)
            {
                flag = 0;
                for (i = 0; i < resource_num; i++)
                {
                    if (need[j][i] > avail[i])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = j;
                    for (y = 0; y < resource_num; y++)
                        avail[y] += alloc[j][y];
                    f[j] = 1;
                }
            }
        }
    }
    printf("\n\nSafe Sequence: \n");

    for (i = 0; i < process_num - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d\n", ans[process_num - 1]);

    return 0;
}