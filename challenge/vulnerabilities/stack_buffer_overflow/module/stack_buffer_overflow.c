#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <asm/uaccess.h>

#define MAX_LENGTH 64

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ryan Welton");
MODULE_DESCRIPTION("Stack Buffer Overflow Example");

static struct proc_dir_entry *stack_buffer_proc_entry;

int proc_entry_write(struct file *file, const char __user *ubuf, unsigned long count, void *data)
{
    char buf[MAX_LENGTH];

    if (copy_from_user(&buf, ubuf, count)) {
        printk(KERN_INFO "stackBufferProcEntry: error copying data from userspace\n");
        return -EFAULT;
    }

    return count;
}

static struct file_operations cmd_file_ops = {
    .write = proc_entry_write,
};

static int __init stack_buffer_proc_init(void)
{

    stack_buffer_proc_entry = proc_create("stack_buffer_overflow", 0666, NULL, &cmd_file_ops);

    printk(KERN_INFO "created /proc/stack_buffer_overflow\n");

    return 0;
}

static void __exit stack_buffer_proc_exit(void)
{
    if (stack_buffer_proc_entry) {
        proc_remove(stack_buffer_proc_entry);
    }

    printk(KERN_INFO "vuln_stack_proc_entry removed\n");
}

module_init(stack_buffer_proc_init);
module_exit(stack_buffer_proc_exit);

