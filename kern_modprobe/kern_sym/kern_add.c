#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ABRAR");


static int my_add(int a, int b)
{
  return(a+b);
}

EXPORT_SYMBOL(my_add);


static int __init add_init(void)
{
  printk("\n we are in add function\n");
  return 0;
}


static void __exit add_exit(void)
{
 printk("\n GoodBye\n"); 
}

module_init(add_init);
module_exit(add_exit);

