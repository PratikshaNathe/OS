#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int a[20], n, i, j, t;

    printf("Enter number of integers: ");
    scanf("%d",&n);

    if(n<1 || n>20)
        return 1;

    printf("Enter integers: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    pid=fork();

    if(pid<0)
        return 1;

    if(pid==0)
    {
        printf("\nChild Process\n");

        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(a[i]>a[j])
                {
                    t=a[i]; a[i]=a[j]; a[j]=t;
                }

        printf("Ascending: ");
        for(i=0;i<n;i++)
            printf("%d ",a[i]);

        exit(0);
    }
    else
    {
        printf("\nParent Process\n");

        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(a[i]<a[j])
                {
                    t=a[i]; a[i]=a[j]; a[j]=t;
                }

        printf("Descending: ");
        for(i=0;i<n;i++)
            printf("%d ",a[i]);

        wait(NULL);
        printf("\nChild completed.\n");
    }

    // Zombie Process
    printf("\nZombie Demonstration\n");
    pid=fork();

    if(pid==0)
        exit(0);
    else if(pid>0)
    {
        sleep(5);
        wait(NULL);
        printf("Zombie process collected.\n");
    }

    // Orphan Process
    printf("\nOrphan Demonstration\n");
    pid=fork();

    if(pid==0)
    {
        sleep(3);
        printf("Child is orphan. New PPID: %d\n",getppid());
        exit(0);
    }
    else if(pid>0)
        exit(0);

    return 0;
}