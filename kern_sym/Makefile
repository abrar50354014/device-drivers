obj-m :=kern_add.o kern_avg.o
KDIR=/lib/modules/$(shell uname -r)/build
PWD=$(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

cleam:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

