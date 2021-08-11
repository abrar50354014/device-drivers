obj-m :=kern_add.o kern_avg.o
KDIR=/lib/modules/$(shell uname -r)/build
PWD=$(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -rf /lib/modules/$(shell uname -r)/extra/*

install:
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install
	depmod -a

