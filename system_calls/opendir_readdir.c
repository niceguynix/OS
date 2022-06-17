#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
    DIR *dirname;
    struct dirent *dir;
    dirname=opendir(argv[1]);
    dir=readdir(dirname);

    while(dir!=NULL)
    {
        printf("Entry found :%s\n",dir->d_name);
        printf("Inode number of entry:%d\n",dir->d_ino);
        printf("Length of this record:%d\n",dir->d_reclen);
        dir=readdir(dirname);
        getchar();
    }
}