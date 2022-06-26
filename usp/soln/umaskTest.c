#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    umask(0);
    if (creat("file1", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)
        printf("creat error for foo");
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if (creat("file2", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0)
        printf("creat error for bar");
    exit(0);
}
