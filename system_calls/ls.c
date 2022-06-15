#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<dirent.h>
main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *link;
    dp=opendir(argv[1]);
    printf("contents of directory %s are \n",argv[1]);
    while((link=readdir(dp))!=0)
        printf("%s",link->d_name);
    closedir(dp);
}