#include <linux/kernel.h>       
#include <linux/module.h>       
#include <linux/kdev_t.h>       
#include <linux/printk.h>       
#include <linux/cdev.h> 
#include <linux/device.h>       
#include <linux/delay.h>        
#include <linux/fs.h>   
#include <linux/uaccess.h>      

static int base_minor = 0;
static const char *device_name = "msg21";
static int count = 1;
static dev_t dev_num;

MODULE_LICENSE("GPL");

static struct class *class = NULL;
static struct device *device = NULL;
static struct cdev mycdev;

#define MAX_SIZE 1024
static char kernel_buffer[MAX_SIZE];
static int buffer_index;

static int device_open(struct inode *inode, struct file *file)
{
        pr_info("%s\n", __func__);
        file->f_pos = 0;
        buffer_index = 0;
        return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
        pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t read_count, loff_t *offset)
{
        int retval;
        pr_info("%s read offset %lld \n", __func__, *offset);

        if (buffer_index + read_count > MAX_SIZE) {
                pr_err("%s buffer_index %d\t: read_count: %lu\t Max size %d\n", __func__, buffer_index, read_count, MAX_SIZE);
                return -ENOSPC;
        }

        retval = copy_to_user(user_buffer, kernel_buffer + *offset, read_count);
        pr_info("%s copy_to_user returned %d\n", __func__, retval);

        if (retval == 0) {
                *offset += read_count;
                return read_count;
        } else {
                return -EFAULT;
        }
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t write_count, loff_t *offset)
{
        int retval;
        pr_info("%s\n", __func__);
        pr_info("%s write offset: %lld\n", __func__, *offset);

        if (buffer_index + write_count > MAX_SIZE) {
                pr_err("%s : buffer_index: %d\t write_count %lu\t max size %d\n", __func__, buffer_index, write_count, MAX_SIZE);
                return -ENOSPC;
        }

        retval = copy_from_user(kernel_buffer + buffer_index, user_buffer, write_count);

        pr_info("%s copy_from_user returned %d\n", __func__, retval);
        pr_info("%s kernel_buffer: %s\n", __func__, kernel_buffer);

        if (retval == 0) {
                buffer_index += write_count;
                *offset += write_count;
                return write_count;
        } else {
                return -EFAULT;
        }
}

struct file_operations device_fops = {
        .read = device_read,
        .write = device_write,
        .open = device_open,
        .release = device_release
};

static int __init test_hello5_init(void)
{
        int result;

        result = alloc_chrdev_region(&dev_num, base_minor, count, device_name);
        if (result < 0) {
                printk(KERN_WARNING "Device number not registered\n");
                return result;
        }

        printk(KERN_INFO "Device number registered, Major number: %d\n", MAJOR(dev_num));

        class = class_create(THIS_MODULE, "myclass6a");
        if (IS_ERR(class)) {
                unregister_chrdev_region(dev_num, count);
                printk(KERN_WARNING "Class creation failed\n");
                return PTR_ERR(class);
        }

        device = device_create(class, NULL, dev_num, NULL, device_name);
        if (IS_ERR(device)) {
                class_destroy(class);
                unregister_chrdev_region(dev_num, count);
                printk(KERN_WARNING "Device creation failed\n");
                return PTR_ERR(device);
        }

        cdev_init(&mycdev, &device_fops);
        mycdev.owner = THIS_MODULE;
        result = cdev_add(&mycdev, dev_num, count);
        if (result < 0) {
                device_destroy(class, dev_num);
                class_destroy(class);
                unregister_chrdev_region(dev_num, count);
                printk(KERN_WARNING "cdev_add failed\n");
                return result;
        }

        return 0;
}

static void __exit test_ext(void)
{
        cdev_del(&mycdev);
        device_destroy(class, dev_num);
        class_destroy(class);
        unregister_chrdev_region(dev_num, count);
        printk(KERN_INFO "Driver unloaded\n");
}

module_init(test_hello5_init);
module_exit(test_exit);
i
