#include<stdio.h>


int main(){
    int n,r;
    printf("Enter the no of resouces: ");
    scanf("%d",&r);
    printf("Enter the no of processes: ");
    scanf("%d",&n);
    int alloc[n][r];
    int max[n][r];
    int need[n][r];
    int avail[r];
    int i,j;

    printf("Enter the available resources: ");
    for(i=0;i<r;i++){
        scanf("%d",&avail[i]);
    }

    printf("Enter the allocation matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the maximum matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    printf("Allocation  max     need\n");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            printf("%2d",alloc[i][j]);
        }
        printf("     ");
        for(j=0;j<r;j++){
            printf("%2d",max[i][j]);
        }
        printf("   ");
        for(j=0;j<r;j++){
            printf("%2d",need[i][j]);
        }
        printf("\n");
    }

    printf("\nProcess executes in the following order:\n");
    int finish[n] ;
    for(i=0;i<n;i++){
        finish[i]=0;
    }
    int flag1 = 0;
    int flag =0;
    do{
        flag1=0;
        for(i=0;i<n;i++){
            flag = 0;
            for(j=0;j<r;j++){
                if(need[i][j]>avail[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0 && finish[i]==0){
                flag1 = 1;
                printf("p%d ",i+1);
                for(j=0;j<r;j++){
                    avail[j]+=alloc[i][j];
                }
                finish[i] = 1;
            }
        }
    }while(flag1==1);





    return 0;
}