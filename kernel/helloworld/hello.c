#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Francis Hodianto");
MODULE_DESCRIPTION("A simple Linux module");
MODULE_VERSION("0.01");

static unsigned long ulong_param = 0;
module_param(ulong_param, ulong, 0444);

/* Declare tasklet */
static struct tasklet_struct print_param_tasklet;

/* Tasklet Function */
void print_param(unsigned long param) {
    printk(KERN_INFO "Executing tasklet function - parameter passed in: %lu\n", param);
}

static int __init hello_init(void) {
    printk(KERN_INFO "Hello World!\n");
    /* Initialize tasklet */
    tasklet_init(&print_param_tasklet, print_param, ulong_param);
    /* Schedule the tasklet */
    tasklet_schedule(&print_param_tasklet);
    return 0;
}

static void __exit hello_exit(void) {
    /* Kill the Tasklet (if not completed) */ 
    tasklet_kill(&print_param_tasklet);
    printk(KERN_INFO "Goodbye, cruel world!\n");
}

module_init(hello_init);
module_exit(hello_exit);

