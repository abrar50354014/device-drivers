obj-m := my_device.o
KDIR= /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)
MAKE:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	gcc -o application application.c

CLEAN:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -rf  application
