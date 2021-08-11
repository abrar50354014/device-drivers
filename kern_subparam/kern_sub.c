#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ABRAR");


static int my_sub(int a, int b)
{
  return(a-b);
}

EXPORT_SYMBOL(my_sub);


static int __init sub_init(void)
{
  printk("\n we are in sub function\n");
  return 0;
}


static void __exit sub_exit(void)
{
 printk("\n GoodBye\n"); 
}

module_init(sub_init);
module_exit(sub_exit);

