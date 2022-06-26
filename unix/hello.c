#include<stdio.h>
#include<sys/types.h>

int main(){
	fork();
	if(fork()) printf("hello\n");
	else printf("world\n");
	return 0;
}
