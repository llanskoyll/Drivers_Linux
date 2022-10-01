#ifndef PARAM_C
#define PARAM_C

#include "param.h"


uint8_t getParams(void) {

	uint8_t ret = 0;
	int integer = 0;
	char* str = "";
	uint64_t arr[] = {0, 0, 0, 0, 0};

	module_param(integer, int, S_IRUSR|S_IWUSR);

	printk(KERN_INFO "Intger argument int: %d\n", integer);
	printk(KERN_INFO "String argument char: %s\n", str);
	for(size_t i = 0; i < sizeof(arr)/sizeof(*arr); i++) {
		printk(KERN_INFO "Index %lu in arr value %lld\n", i, arr[i]);
	}
	return ret;
}

/* 
 
0 //<< If perm is set to 0, there is no sysfs(system file system) entry at all,
	it appears under /sys/module with the given set of permissions
	
S_IRUGO //<< parametr that can be read by the world but cannot be change

S_IRUGO | S_IWUSR //<< root to change the parameter. If parameter is changed by sysfs
the value of that parameter as seen by your module changes, but your module is not notified in ane other way

*/	

#endif // PARAM_C
