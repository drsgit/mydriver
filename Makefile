
obj-m := config_driver.o
KERNELDIR := /lib/modules/$(shell uname -r)/build 
PWD ：=$(shell pwd)

modules:
	make -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -rf *.o *.ko *.mod.c *.order *.symvers 
