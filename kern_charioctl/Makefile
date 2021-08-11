obj-m := my_ioctl.o
KDIR= /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)
MAKE:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	gcc -o ioctlapp ioctlapp.c

CLEAN:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -rf  ioctlapp
