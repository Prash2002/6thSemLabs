// Write a C program to implement the ls –li command which list the files in a specified directory.
// Your program should Print 5 attributes of files.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    dp = opendir(".");
    struct stat buf;
    while ((dirp = readdir(dp)) != NULL)
    {
        lstat(dirp->d_name, &buf);
        printf("%s\n", dirp->d_name);
        printf("%lld\n", (long long)buf.st_ino);
        printf("%lld\n", (long long)buf.st_nlink);
        printf("%lld\n", (long long)buf.st_mode);
        printf("%lld\n", (long long)buf.st_size);
        printf("%s\n", ctime(&buf.st_ctime));
        printf("%s\n", ctime(&buf.st_atime));
        printf("%s\n", ctime(&buf.st_mtime));
        printf("\n\n");
    }
    closedir(dp);
    return 0;
}
