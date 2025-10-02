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

#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL"); //*
MODULE_AUTHOR("Jose Figueroa");
MODULE_DESCRIPTION("A simple example kernel module");

static int ldd_init(void)
{
    printk("Hello, World! from Jose\n");
    return 0; // Non-zero return means that the module couldn't be loaded.
}

static void ldd_exit(void)
{
    printk("Goodbye, World! from Jose\n");
}

module_init(ldd_init);
module_exit(ldd_exit);