#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<linux/ioctl.h>
#include<unistd.h>
#include<sys/stat.h>
#include "ioctl.h"
struct Data{
	int Baudrate;
	int StopBits;
	int Parity;
};
int main()
{
	int fd, Res, BAUD_RATE = 9600, STP_BITS = 8, *test;
	struct Data ToSend={9800,1,0};
	char Ubuff[] = "hello kernel.....iam the user";
	char Kbuff[100];
	fd = open("/dev/charioctl",O_RDWR,0777);
	if(fd<0)
	{
		printf("\nerror opening file\n");
		exit(1);
	}
	Res = ioctl (fd, SET_BAUD_RATE, BAUD_RATE);
	if(Res<0)
	{
		printf("\n IOCTL Error");
		return(-1);
	
	}
	test =&STP_BITS;
	ioctl (fd, SET_NO_STOP_BITS, test);
	ioctl (fd, SET_DIRECTION_WRITE, NULL);
	ioctl (fd, DEFAULT_DATA, &ToSend);
	write(fd,Ubuff,sizeof(Ubuff));
	read(fd,Kbuff,sizeof(Ubuff));
	printf("\ndata from kernel:\n %s \n",Kbuff);
	close(fd);
}
