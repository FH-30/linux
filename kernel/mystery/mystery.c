#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_DESCRIPTION("Oops aqUWZmMS");
MODULE_LICENSE("MIT");

void do_something_strange(void) {
    unsigned *p = (unsigned *)&do_something_strange;
    *p = 0x300;
}

static int cs5250_oops_init(void) {
    pr_info("===[[ Here we go ]]===\n");
    do_something_strange();
    pr_info("===[[ Cheers ]]===\n");
    return 0;
}

static void cs5250_oops_exit(void) {
    pr_info("I'm gone\n");
}

module_init(cs5250_oops_init);
module_exit(cs5250_oops_exit);

