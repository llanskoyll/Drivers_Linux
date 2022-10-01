#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

uint8_t getParams(void);

static int integer = 0;
module_param(integer, int, S_IRUSR | S_IWUSR);

uint8_t getParams(void)
{
	uint8_t ret = 0;
	printk(KERN_INFO "Intger argument int: %d\n", integer);

	return ret;
}

static int __init ModuleInit(void)
{
	uint8_t ret = 0;
	printk(KERN_INFO "Started loading module\n");
	printk(KERN_INFO "Success loading module!\n");

	ret = getParams();
	if (ret) {
		printk(KERN_INFO "Error invalid arguments!\n");
		printk(KERN_INFO "Started unloading module\n");
	}
	return ret;
}

static void __exit ModuleExit(void)
{
	printk(KERN_INFO "Success unloading module!\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Maximov Artem");
MODULE_DESCRIPTION("Module for education");
MODULE_VERSION("1.0");
