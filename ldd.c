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

#include <linux/init.h>      // Needed for module_init and module_exit macros
#include <linux/module.h>    // Needed for all kernel modules

MODULE_LICENSE("GPL"); // License type -- affects kernel behavior
MODULE_AUTHOR("Jose Figueroa"); // Module author
MODULE_DESCRIPTION("A simple example kernel module"); // Short description

/**
 * @brief Module initialization function.
 * This function is called when the module is loaded into the kernel.
 * It prints a hello message to the kernel log.
 * 
 * @return int Returns 0 on success. Non-zero means module can't be loaded.
 */
static int ldd_init(void)
{
    printk("Hello, World! from Jose\n"); // Print message to kernel log
    return 0; // Return 0 for successful loading
}

/**
 * @brief Module cleanup function.
 * This function is called just before the module is removed from the kernel.
 * It prints a goodbye message to the kernel log.
 */
static void ldd_exit(void)
{
    printk("Goodbye, World! from Jose\n"); // Print message to kernel log
}

/* Macros to register module entry and exit points */
module_init(ldd_init); // Register initialization function
module_exit(ldd_exit); // Register cleanup function