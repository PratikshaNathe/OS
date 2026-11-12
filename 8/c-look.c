#include <stdio.h>
#include <stdlib.h>

int main()
{
    int RQ[100], n, i, j, temp, head, move;
    int total = 0, index;

    printf("Enter number of Requests\n");
    scanf("%d", &n);

    printf("Enter Requests sequence\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &RQ[i]);
    }

    printf("Enter initial head position\n");
    scanf("%d", &head);

    printf("Enter direction (1=High, 0=Low)\n");
    scanf("%d", &move);

    // Bubble Sort
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(RQ[j] > RQ[j+1])
            {
                temp = RQ[j];
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
        }
    }

    // Find index
    for(i = 0; i < n; i++)
    {
        if(RQ[i] > head)
            break;
    }

    index = i;

    if(move == 1)
    {
        for(i = index; i < n; i++)
        {
            total += abs(RQ[i] - head);
            head = RQ[i];
        }

        for(i = 0; i < index; i++)
        {
            total += abs(RQ[i] - head);
            head = RQ[i];
        }
    }
    else
    {
        for(i = index-1; i >= 0; i--)
        {
            total += abs(RQ[i] - head);
            head = RQ[i];
        }

        for(i = n-1; i >= index; i--)
        {
            total += abs(RQ[i] - head);
            head = RQ[i];
        }
    }

    printf("Total head movement is %d", total);

    return 0;
}