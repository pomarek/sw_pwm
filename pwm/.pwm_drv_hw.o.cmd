cmd_/home/szakal/uc/pwm/pwm_drv_hw.o := /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/bin/armv7a-angstrom-linux-gnueabi/arm-angstrom-linux-gnueabi-gcc -Wp,-MD,/home/szakal/uc/pwm/.pwm_drv_hw.o.d  -nostdinc -isystem /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/lib/armv7a-angstrom-linux-gnueabi/gcc/arm-angstrom-linux-gnueabi/4.5.4/include -I/home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-omap2/include -Iarch/arm/plat-omap/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -marm -fno-dwarf2-cfi-asm -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables -mthumb -Wa,-mimplicit-it=always -Wa,-mno-warn-deprecated -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -Wframe-larger-than=1024 -fno-stack-protector -fomit-frame-pointer -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO  -DMODULE  -fno-optimize-sibling-calls -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(pwm_drv_hw)"  -D"KBUILD_MODNAME=KBUILD_STR(pwmd)" -c -o /home/szakal/uc/pwm/.tmp_pwm_drv_hw.o /home/szakal/uc/pwm/pwm_drv_hw.c

source_/home/szakal/uc/pwm/pwm_drv_hw.o := /home/szakal/uc/pwm/pwm_drv_hw.c

deps_/home/szakal/uc/pwm/pwm_drv_hw.o := \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/include/linux/kconfig.h \
    $(wildcard include/config/h.h) \
    $(wildcard include/config/.h) \
    $(wildcard include/config/foo.h) \
  include/linux/kernel.h \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/sysroots/i686-linux/usr/lib/armv7a-angstrom-linux-gnueabi/gcc/arm-angstrom-linux-gnueabi/4.5.4/include/stdarg.h \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/linkage.h \
  include/linux/stddef.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/posix_types.h \
  include/linux/bitops.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/bitops.h \
    $(wildcard include/config/smp.h) \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/system.h \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/cpu/32v6k.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arch/has/barriers.h) \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/sa110.h) \
    $(wildcard include/config/cpu/v6.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  include/linux/typecheck.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/irqflags.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/arm/thumb.h) \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/hwcap.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/outercache.h \
    $(wildcard include/config/outer/cache/sync.h) \
    $(wildcard include/config/outer/cache.h) \
  include/asm-generic/cmpxchg-local.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/lock.h \
  include/asm-generic/bitops/le.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/swab.h \
  include/linux/byteorder/generic.h \
  include/asm-generic/bitops/ext2-atomic-setbit.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/printk.h \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  include/linux/dynamic_debug.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/div64.h \
  include/linux/ioport.h \
  include/linux/io.h \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/has/ioport.h) \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/io.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/memory.h \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/have/tcm.h) \
    $(wildcard include/config/arm/patch/phys/virt.h) \
    $(wildcard include/config/arm/patch/phys/virt/16bit.h) \
  include/linux/const.h \
  arch/arm/mach-omap2/include/mach/memory.h \
  arch/arm/plat-omap/include/plat/memory.h \
    $(wildcard include/config/arch/omap1.h) \
    $(wildcard include/config/arch/omap15xx.h) \
    $(wildcard include/config/fb/omap/consistent/dma/size.h) \
    $(wildcard include/config/fb/da8xx/consistent/dma/size.h) \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/sizes.h \
  include/asm-generic/sizes.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  arch/arm/mach-omap2/include/mach/io.h \
  arch/arm/plat-omap/include/plat/io.h \
    $(wildcard include/config/arch/omap730.h) \
    $(wildcard include/config/arch/omap850.h) \
    $(wildcard include/config/arch/omap16xx.h) \
    $(wildcard include/config/soc/omap2420.h) \
    $(wildcard include/config/soc/omap2430.h) \
    $(wildcard include/config/arch/omap3.h) \
    $(wildcard include/config/soc/omapti816x.h) \
    $(wildcard include/config/soc/omapam33xx.h) \
    $(wildcard include/config/arch/omap4.h) \
  arch/arm/mach-omap2/include/mach/hardware.h \
  arch/arm/plat-omap/include/plat/hardware.h \
    $(wildcard include/config/reg/base.h) \
  arch/arm/plat-omap/include/plat/cpu.h \
    $(wildcard include/config/arch/omap2.h) \
    $(wildcard include/config/soc/omap3430.h) \
  arch/arm/plat-omap/include/plat/multi.h \
    $(wildcard include/config/arch/omap2plus.h) \
  arch/arm/plat-omap/include/plat/serial.h \
  arch/arm/plat-omap/include/plat/omap7xx.h \
    $(wildcard include/config/base.h) \
  arch/arm/plat-omap/include/plat/omap1510.h \
  arch/arm/plat-omap/include/plat/omap16xx.h \
  arch/arm/plat-omap/include/plat/omap24xx.h \
  arch/arm/plat-omap/include/plat/omap34xx.h \
  arch/arm/plat-omap/include/plat/omap44xx.h \
  arch/arm/plat-omap/include/plat/ti816x.h \
  arch/arm/plat-omap/include/plat/am33xx.h \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/page.h \
    $(wildcard include/config/cpu/copy/v3.h) \
    $(wildcard include/config/cpu/copy/v4wt.h) \
    $(wildcard include/config/cpu/copy/v4wb.h) \
    $(wildcard include/config/cpu/copy/feroceon.h) \
    $(wildcard include/config/cpu/copy/fa.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/copy/v6.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
  /home/szakal/Pulpit/beagle/angstrom/builds/setup-scripts/build/tmp-angstrom_2010_x-eglibc/work/beaglebone-angstrom-linux-gnueabi/linux-ti33x-psp-3.1-r2g+gitr1d84d8853fa30cf3db2571a5aec572accca4e29d/git/arch/arm/include/asm/glue.h \
  include/asm-generic/getorder.h \
  /home/szakal/uc/pwm/pwm_drv_hw.h \
  /home/szakal/uc/pwm/pru.h \
  /home/szakal/uc/pwm/pru_pwm_sw_bin.h \

/home/szakal/uc/pwm/pwm_drv_hw.o: $(deps_/home/szakal/uc/pwm/pwm_drv_hw.o)

$(deps_/home/szakal/uc/pwm/pwm_drv_hw.o):