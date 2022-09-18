#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Maximov Artem");
MODULE_DESCRIPTION("Module for education");
MODULE_VERSION("1.0");

static int __init ModuleInit(void) {
	printk(KERN_INFO "Hello world!\n");
	return 0;
}
module_init(ModuleInit);

static void  __exit ModuleExit(void) {
	printk(KERN_INFO "Exit module\n");
}


module_exit(ModuleExit);

