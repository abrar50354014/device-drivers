#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include"kern_add.h"
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ABRAR");


static int one = 10;
static int two = 20;


static int __init avg_init(void)
{
  printk("\n add result is: %d\n", my_add(one,two));
  printk("\n avg result is: %d\n", my_add(one,two)/2);
  return 0;
}
static void __exit avg_exit(void)
{
 printk("\n GoodBye\n"); 
}

module_init(avg_init);
module_exit(avg_exit);

