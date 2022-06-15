#include<stdio.h>
main()
{
    int n,size,la,i,pno[10],fno[10],offset,pa,limit,p;
    printf("Enter the number ofpages:");
    scanf("%d",&n);
    printf("Enter the size of page:");
    scanf("%d",&size);
    limit=n*size-1;
    printf("Enter logical address within the limit %d:",limit);
    scanf("%d",&la);
    for(i=0; i<n; i++)
    {
        printf("Enter the pageno:");
        scanf("%d",&pno[i]);
        printf("Enter the frame no:");
        scanf("%d",&fno[i]);
    }
    printf("pageno\tframeno");
    for(i=0; i<n; i++)
    {
        printf("\n%d\t\t%d",pno[i],fno[i]);
    }
    p=la/size;
    printf("\n The page number is %d",p);

    offset=la%size;
    printf("\nOffset is %d",offset);
    pa=fno[p]*size+offset;
    printf("\n The physical address is %d",pa);
}