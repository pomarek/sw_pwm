#linux makefile part
obj-m := pwmd.o
pwmd-objs :=pwm_drv.o pwm_drv_hw.o pru.o



#module makefile part
-include ../makefile.inc


MY_ARCH := arm


all:	build deploy
	


build: 	pasm
	$(MAKE) ARCH=$(MY_ARCH) CROSS_COMPILE=$(MY_COMPILER) -C $(MY_SOURCE) M=$(CURDIR) modules

pasm:
	pasm -c pru_pwm_sw.p

pasm2:
	pasm2 -PRUv2 -c pru_pwm_sw.p

deploy:
	scp pwmd.ko root@192.168.1.6:/mnt/p3/
	ssh -l root 192.168.1.6 '/sbin/rmmod pwmd;/sbin/insmod /mnt/p3/pwmd.ko'

test:
	gcc test.c -o test.x
	./test.x
	rm test.x

clean:
	rm -f *.ko *.o *.mod.c modules.order Module.symvers *_bin.h


