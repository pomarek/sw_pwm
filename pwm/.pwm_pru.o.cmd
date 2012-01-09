cmd_/home/szakal/uc/pwm/pwm_pru.o := /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/bin/armv7a-angstrom-linux-gnueabi/arm-angstrom-linux-gnueabi-gcc -Wp,-MD,/home/szakal/uc/pwm/.pwm_pru.o.d  -nostdinc -isystem /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/lib/armv7a-angstrom-linux-gnueabi/gcc/arm-angstrom-linux-gnueabi/4.5.4/include -I/home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-omap2/include -Iarch/arm/plat-omap/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -marm -fno-dwarf2-cfi-asm -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables -mthumb -Wa,-mimplicit-it=always -Wa,-mno-warn-deprecated -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -Wframe-larger-than=1024 -fno-stack-protector -fomit-frame-pointer -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO  -DMODULE  -fno-optimize-sibling-calls -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(pwm_pru)"  -D"KBUILD_MODNAME=KBUILD_STR(pwmd)" -c -o /home/szakal/uc/pwm/.tmp_pwm_pru.o /home/szakal/uc/pwm/pwm_pru.c

source_/home/szakal/uc/pwm/pwm_pru.o := /home/szakal/uc/pwm/pwm_pru.c

deps_/home/szakal/uc/pwm/pwm_pru.o := \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/include/linux/kconfig.h \
    $(wildcard include/config/h.h) \
    $(wildcard include/config/.h) \
    $(wildcard include/config/foo.h) \

/home/szakal/uc/pwm/pwm_pru.o: $(deps_/home/szakal/uc/pwm/pwm_pru.o)

$(deps_/home/szakal/uc/pwm/pwm_pru.o):
