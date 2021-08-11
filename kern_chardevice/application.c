#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
	int fd;
	char Ubuff[] = "hello kernel.....iam the user";
	char Kbuff[100];
	fd = open("/dev/mydevice",O_RDWR,0777);
	if(fd<0)
	{
		printf("\nerror opening file\n");
		exit(1);
	}
	write(fd,Ubuff,sizeof(Ubuff));
	read(fd,Kbuff,50);
	printf("\ndata from kernel:\n %s \n",Kbuff);
	close(fd);
}
