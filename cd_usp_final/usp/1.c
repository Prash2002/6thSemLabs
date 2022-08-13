// Write a C program to display the file content in reverse order using lseek system call.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char ch;
    int fd = open(argv[1], O_RDONLY);
    int k = -1;
    int beg = lseek(fd, 0, SEEK_CUR);
    int end = lseek(fd, k, SEEK_END);
    while (end >= beg)
    {
        read(fd, &ch, 1);
        write(1, &ch, 1);
        k--;
        end = lseek(fd, k, SEEK_END);
    }
    return 0;
}