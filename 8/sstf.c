#include <stdio.h>
#include <stdlib.h>

int main()
{
    int RQ[100], n, i, head, count=0;
    int total=0, min, d, index;

    printf("Enter number of Requests\n");
    scanf("%d",&n);

    printf("Enter Requests sequence\n");
    for(i=0;i<n;i++)
        scanf("%d",&RQ[i]);

    printf("Enter initial head position\n");
    scanf("%d",&head);

    while(count<n)
    {
        min=1000;

        for(i=0;i<n;i++)
        {
            d=abs(RQ[i]-head);
            if(d<min)
            {
                min=d;
                index=i;
            }
        }

        total+=min;
        head=RQ[index];
        RQ[index]=1000;
        count++;
    }

    printf("Total head movement is %d",total);
    return 0;
}