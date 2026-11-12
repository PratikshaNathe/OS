
#include <stdio.h>

int main()
{
    int n, m;
    int allocation[10][10], max[10][10], need[10][10];
    int available[10], work[10], finish[10];
    int safeSequence[10];
    int i, j, count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i);

        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    }

    // Input Maximum Matrix
    printf("\nEnter Maximum Matrix:\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i);

        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");

    for (j = 0; j < m; j++)
        scanf("%d", &available[j]);

    // Calculate Need Matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize Work and Finish
    for (j = 0; j < m; j++)
        work[j] = available[j];

    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Banker's Algorithm
    while (count < n)
    {
        int found = 0;

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int canExecute = 1;

                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canExecute = 0;
                        break;
                    }
                }

                if (canExecute)
                {
                    for (j = 0; j < m; j++)
                        work[j] += allocation[i][j];

                    safeSequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
            break;
    }

    // Check Safe State
    if (count == n)
    {
        printf("\nSystem is in a SAFE STATE.\n");
        printf("Safe Sequence: ");

        for (i = 0; i < n; i++)
        {
            printf("P%d", safeSequence[i]);

            if (i != n - 1)
                printf(" -> ");
        }

        printf("\n");
    }
    else
    {
        printf("\nSystem is in an UNSAFE STATE.\n");
    }

    return 0;
}
