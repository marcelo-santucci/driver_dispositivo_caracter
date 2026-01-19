#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "dispositivo_simple_de_caracter"
#define BUFFER_SIZE 1024

static int major_number;
static char message[BUFFER_SIZE];
static short size_of_message;

static int device_open(struct inode *inode, struct file *file) {
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t device_read(struct file *file, char *buffer, size_t len, loff_t *offset) {
    if (*offset >= size_of_message) {
        return 0;
    }
    if (*offset + len > size_of_message) {
        len = size_of_message - *offset;
    }
    if (copy_to_user(buffer, message + *offset, len) != 0) {
        return -EFAULT;
    }
    *offset += len;
    return len;
}

static ssize_t device_write(struct file *file, const char *buffer, size_t len, loff_t *offset) {
    if (len > BUFFER_SIZE) {
        len = BUFFER_SIZE;
    }
    if (copy_from_user(message, buffer, len) != 0) {
        return -EFAULT;
    }
    size_of_message = len;
    return len;
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
};

static int __init dispositivo_simple_de_caracter_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Fallo al registrar el dispositivo simple de caracter");
        return major_number;
    }
    printk(KERN_INFO "dispositivo_simple_de_caracter registrado con numero mayor %dn", major_number);
    return 0;
}

static void __exit dispositivo_simple_de_caracter_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "dispositivo_simple_de_caracter des-registrado");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sistemas Operativos URL");
MODULE_DESCRIPTION("Driver de dispositivo simple de caracter");
MODULE_VERSION("0.1");

module_init(dispositivo_simple_de_caracter_init);
module_exit(dispositivo_simple_de_caracter_exit);
