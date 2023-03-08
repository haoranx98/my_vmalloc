#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("haoranx98");
MODULE_DESCRIPTION("A simple example of kmalloc.");
MODULE_VERSION("0.01");

static int __init vmalloc_InitFunc(void);
static void __exit vmalloc_ExitFunc(void);

#define MEMORY_8KB 8192
#define MEMORY_1MB 1048576
#define MEMORY_64MB 67108864
char *app_8KB_memory;
char *app_1MB_memory;
char *app_64MB_memory;

int __init vmalloc_InitFunc(void){
	
	app_8KB_memory = (char *)vmalloc(MEMORY_8KB);
	if(app_8KB_memory == NULL){
		printk("Can not apply memory!!!!\n");
	}else{
		printk("8KB address is 0x%1x\n", (unsigned long)app_8KB_memory);
	}
	app_1MB_memory = (char *)vmalloc(MEMORY_1MB);
	if(app_1MB_memory == NULL){
		printk("Can not apply memory!!!!\n");
	}else{
		printk("1MB address is 0x%1x\n", (unsigned long)app_1MB_memory);
	}
	app_64MB_memory = (char *)vmalloc(MEMORY_64MB);
	if(app_64MB_memory == NULL){
		printk("Can not apply memory!!!!\n");
	}else{
		printk("64MB address is 0x%1x\n", (unsigned long)app_64MB_memory);
	}

	return 0;
}

void __exit vmalloc_ExitFunc(void){
	if(app_8KB_memory != NULL){
		vfree(app_8KB_memory);
		printk("free the kernel memory of 8KB");
	}

	if(app_1MB_memory != NULL){
		vfree(app_1MB_memory);
		printk("free the kernel memory of 1MB");
	}

	if(app_64MB_memory != NULL){
		vfree(app_64MB_memory);
		printk("free the kernel memory of 64MB");
	}

	printk("Exit kernel module!!!!");
}

module_init(vmalloc_InitFunc);
module_exit(vmalloc_ExitFunc);


