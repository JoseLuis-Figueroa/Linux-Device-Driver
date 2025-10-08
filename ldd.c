/**
 * @file ldd.c
 * @author Jose Luis Figueroa
 * @brief Implement the Linux Device Driver. 
 * @version 1.0
 * @date 2025-Oct-02
 * @note 
 * 
 * @copyright Copyright (c) 2025 Jose Luis Figueroa. MIT License.
 * 
 */

#include <linux/init.h>     // Needed for module_init and module_exit macros
#include <linux/module.h>   // Needed for all kernel modules
#include <proc_fs.h>        // Needed for proc filesystem operations

MODULE_LICENSE("GPL"); // License type -- affects kernel behavior
MODULE_AUTHOR("Jose Figueroa"); // Module author
MODULE_DESCRIPTION("A simple example kernel module"); // Short description

static struct proc_dir_entry *custom_proc_node;

/**
 * @brief Read function for the proc file.
 * This function is called when the proc file is read.
 * It currently just prints a message to the kernel log.
 * 
 * @param file_ptr Pointer to the file structure.
 * @param user_space_buffer Buffer to store data read from the proc file.
 * @param count Number of bytes to read.
 * @param offset Offset in the file.
 * @return ssize_t Number of bytes read or negative error code.
 */
static ssize_t ldd_read(struct file *file_ptr, char *user_space_buffer, size_t count, loff_t *offset)
{
    printk("ldd_read \n");
    return 0;
}

struct proc_ops driver_proc_ops = 
{
    .proc_read = ldd_read
};

/**
 * @brief Module initialization function.
 * This function is called when the module is loaded into the kernel.
 * It prints stage messages to the kernel log and creates a proc entry.
 * 
 * @return int Returns 0 on success. Non-zero means module can't be loaded.
 */
static int ldd_init(void)
{
    printk("ldd_init: entry\n"); 
    // Create a proc entry. 
    custom_proc_node = proc_create("ldd_Driver", 0, NULL, &driver_proc_ops); 
    printk("ldd_init: exit\n"); 

    return 0; // Return 0 for successful loading
}

/**
 * @brief Module cleanup function.
 * This function is called just before the module is removed from the kernel.
 * It prints stage messages to the kernel log and removes the proc entry.
 */
static void ldd_exit(void)
{
    printk("ldd_exit: entry\n"); 
    // Remove the proc entry.
    proc_remove(custom_proc_node); 
    printk("ldd_exit: exit\n"); 
}

/* Macros to register module entry and exit points */
module_init(ldd_init); // Register initialization function
module_exit(ldd_exit); // Register cleanup function