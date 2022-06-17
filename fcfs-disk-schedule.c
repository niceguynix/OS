#include <stdio.h>
#include <math.h>

int main(){
    int req[20],disk,no,total=0,i,diff[20];
    printf("Enter the no of location: ");
    scanf("%d",&no);
    printf("Enter the head position: ");
    scanf("%d",&disk);
    printf("Enter the requests: ");
    for ( i = 0; i < no; i++)
    {
        scanf("%d",&req[i]);
        diff[i]=abs(req[i]-disk);
        disk = req[i];
        total += diff[i];
    }

    for(i=0;i<no;i++)
    {
        printf("%d ",diff[i]);
    }

    printf("\nTotal head movement: %d",total);
    

}