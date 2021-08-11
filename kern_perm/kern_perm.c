#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
MODULE_LICENSE("GPL");
//MODULE_AUTHOR("ABRAR");


static char* charvar = "module";


module_param(charvar, charp, S_IRUGO);


static int __init param_init(void)
{
  printk("\n we are in init function\n");
  printk("\n  The value of charvar is %s\n", charvar);
  return 0;
}
static void __exit param_exit(void)
{
 printk("\n GoodBye\n"); 
}

module_init(param_init);
module_exit(param_exit);
