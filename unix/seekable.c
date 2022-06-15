#include<fcntl.h>

int main(){

    int fdesc = open("files/random.txt", 0);
    if(fdesc == -1){
        write(1, "Error in opening the file!");
        return 0;
    }
    int lsk = lseek(fdesc, 0, SEEK_SET );
    // write("test");
    if(lsk == -1){
        write(1, "File not seekable");
    }
    else {
        write(1, "File Seekable");
    }
    return 0;
}