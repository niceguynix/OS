#include<stdio.h>
main()
{
    int i,n,j=0;
    int b[20],b1[20],f[20],w[20];
    int start,finish,t,total=0;
    float aw=0.0,at=0.0;
    printf("\nEnter no. of process:");
    scanf("%d",&n);
    printf("\nEnter the time slice:");
    scanf("%d",&t);
    for(i=1; i<=n; i++)
    {
        printf("\nEnter the burst time of process %d:",i);
        scanf("%d",&b[i]);
        b1[i]=b[i];
        total=total+b[i];
    }
    printf("\n\t\t Round Robbin Scheduing");
    start=0;
    printf("\nThe process Scheduling is as follows");
    printf("\nTime slice:%d ms",t);

    while(j<total)
    {
        for(i=1; i<=n; i++)
        {
            if(b[i]==0)
                continue;
            if(b[i]>t)
            {
                printf("\nProcess %d:",i);
                finish=start+t;
                j=j+t;
                start=finish;
                b[i]=b[i]-t;
                printf("\nRemaining burst time:%d ms",b[i]);
            }
            else
            {
                printf("\nProcess %d:",i);
                finish=start+b[i];
                j=j+b[i];
                start=finish;
                f[i]=finish;
                b[i]=0;
                w[i]=finish-b1[i];
                printf("\tRemaining burst time:%dms",b[i]);
            }
        }
    }
    printf("\n\nProcess no\tBurst time\tWaiting time\tTurnaround time");
    for(i=1; i<=n; i++)
    {
        printf("\n\n%d%20d%20d%20d",i,b1[i],w[i],f[i]);
        aw=aw+w[i];
        at=at+f[i];
    }
    aw=aw/(float)n;
    at=at/(float)n;
    printf("\nAvg wt time:%f",aw);
    printf("\nAvg tat:%f\n",at);
}