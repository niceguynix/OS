#include<unistd.h>
#include<string.h>
#include <dirent.h>
#include<stdio.h>

main()
{
    char fn[10],pat[10],temp[1000];
    FILE *fp;
    printf(" enter file name:");
    scanf("%s",fn);
    printf("\n enter the pattern::");
    scanf("%s",pat);
    fp=fopen(fn,"r");
    while(!feof(fp))
    {
        fgets(temp,1000,fp);
        if(strstr(temp,pat))
        {
            printf("%s",temp);
        }
    }
    fclose(fp);
}