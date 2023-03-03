#include <linux/kernel.h>   /* for printk */
#include <linux/syscalls.h> /* for SYSCALL_DEFINE1 macro */
#include <linux/sched.h> /* for task_struct and task_pid_nr*/

SYSCALL_DEFINE3(getsiblingpids, int, to_print, int*, pidlist, int, pidlist_size){
    printk(KERN_DEBUG "Hello! This is A0200751W from %d", to_print);

    struct task_struct* sibling_pcb;
    struct list_head* list;
    int idx = 0;
    list_for_each(list, &current->sibling) {
        if (idx >= pidlist_size) break; // Prevent overwriting data
        sibling_pcb = list_entry(list, struct task_struct, sibling);
        int sibling_pid = task_pid_nr(sibling_pcb);
        if (sibling_pid != 0) { pidlist[idx++] = sibling_pid; }
    }
    return idx;
}

