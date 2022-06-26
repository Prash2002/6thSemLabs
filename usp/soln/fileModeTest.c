#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int val,  fd;
	if(argc!=2)
    {
		printf("Usage: %s <descriptor> \n", argv[0]);
        exit(1);
    }

	fd=open(argv[1], O_RDONLY, 0);
	if(fd == -1)
	{
		printf("error opening the file\n");
		exit(1);
	}
	printf("file descriptor for %s: %d\n",argv[1],fd);
	val=fcntl(fd, F_GETFL, 0);

    switch(val & O_ACCMODE)
    {
         case O_RDONLY:
                        printf("read only\n");
                        break;
         case O_WRONLY:
                        printf("write only\n");
                        break;
         case O_RDWR:
                        printf("read write\n");
                        break;
         default:
                        printf("unknown access mode\n");
    }
        exit(0);
 }
