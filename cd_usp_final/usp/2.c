// Write a C program
//     a.to read first 20 characters from a file
//         b.seek to 10th byte from the beginning and display 20 characters from there
//             c.seek 10 bytes ahead from the current file offset and display 20 characters
//                 d.display the file size

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = open("sample.txt", O_RDONLY);
    char buf[20];
    read(fd, buf, 20);
    write(1, buf, 20);
    lseek(fd, 10, SEEK_SET);
    printf("next\n");
    read(fd, buf, 20);
    write(1, buf, 20);
    lseek(fd, 10, SEEK_CUR);
    printf("next\n");
    read(fd, buf, 20);
    write(1, buf, 20);

    int k = lseek(fd, 0, SEEK_END);
    char size[10];
    sprintf(size, "%d", k);
    write(1, size, strlen(size));
    return 0;
}
