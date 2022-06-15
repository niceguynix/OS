#include<stdio.h>
#include<stdlib.h>
int main()
{
    int alloc[20][20],max[20][20],avail[20],need[20][20],work[20]= {0};
    int newavail[20],req[20]= {0},check=0,check2=0,cond=0,p;
    int i=0,j=0,m=0,n=0,t=0,x=0,c[20]= {0},k=0,count,count2,a[20],b;
    int x2=0,c2[20];
    printf("Enter the no. of resources\n");
    scanf("%d",&m);
    printf("Enter the no. of process");
    scanf("%d",&n);

    printf("\n Enter the resources for available\n");
    for(j=1; j<=m; j++)
    {
        printf("Enter the %d resources of avail",j);
        scanf("%d", &avail[j]);
        work[j]=avail[j];
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            printf("Enter the %d resources of %d alloc",j,i);
            scanf("%d", &alloc[i][j]);
        }
        for(j=1; j<=m; j++)
        {
            printf("\n Enter the %d resource of %d max",j,i);
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\n Allocation max need\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            printf("%2d",alloc[i][j]);
        printf("\t");
        for(j=1; j<=m; j++)
            printf("%2d",max[i][j]);
        printf("\t");
        for(j=1; j<=m; j++)
            printf("%2d",need[i][j]);
        printf("\n");
    }
    printf("\n Process executes in this order\n");
    do {
        for(i=1; i<=n; i++)
        {
            count=0;
            if(c[i]!=i+1)
            {
                for(j=1; j<=m; j++)
                {
                    if(need[i][j]<=work[j])
                        count = count+1;
                }

                if(count == m)
                {
                    printf("p%d\t",i);
                    c[i]=i+1;
                    x = x+1;
                    for(j=1; j<=n; j++)
                        work[j]=work[j]+alloc[i][j];
                }
            }
        }
        check = check +1;
    }
    while(x<n && check <=n);
    if(x==n)
        printf("\n system is in saftey\n");
    else
        printf("\n System is not in saftey");
    printf("\n Checking the bankers algorithm after the request");
    printf("\n Enter the request process number");
    scanf("%d",&p);
    printf("\n Enter the values");
    for(j=1; j<=m; j++)
    {
        scanf("%d",&req[j]);
    }
    for(j=1; j<=m; j++)
    {
        if(req[j]<=avail[j]&&req[j]<=need[p][j])
            cond=cond+1;
    }
    if(cond==m)
    {
        for(j=1; j<=m; j++)
        {
            alloc[p][j]=alloc[p][j]+req[j];
            avail[j]=avail[j]-req[j];
            need[p][j]=need[p][j]-req[j];
        }
    }
    else
    {
        printf("req is not satisfied");
        exit(0);
    }
    printf("\n Execution of process after request");
    do

    {
        for(i=1; i<=n; i++)
        {
            count2=0;
            if(c2[i]!=i+1)
            {
                for(j=1; j<=m; j++)
                {
                    if(need[i][j]<=avail[j])
                        count2 = count2+1;
                }
                if(count2 == m)
                {
                    rintf("p%d\t",i);
                    c2[i]=i+1;
                    x2=x2+1;
                    for(j=1; j<=n; j++)
                    {
                        avail[j]=avail[j]+alloc[i][j];
                    }
                }
            }
        }
        check2 = check2 +1;
    } while((x2<n)&&(check2<=n));
    if(x2==n)
        printf("\n System is in safe state we can grant the request");
    else
        printf("\n System is in unsafe state we cannot grant the request");
}