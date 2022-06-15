#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
    int fd;
    char buf1[1000],fname[30];
    printf("Enter the filename:");
    scanf("%s",fname);
    fd=open(fname,O_RDONLY);
    read(fd,buf1,1000);
    printf("\n The content is %s:",buf1);
    close(fd);
}