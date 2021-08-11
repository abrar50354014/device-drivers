#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include"sub.h"
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ABRAR");

static int a = 10;
static int b = 20;
static char* charvar = "sub";

module_param(charvar, charp, S_IRUGO);
module_param(a, int, S_IRUGO);
module_param(b, int,S_IRUGO);

static int __init sub_init(void)
{
  printk("in %s function",charvar);
  printk("value of subtraction is: %d", my_sub(a,b));
  return 0;
}

void __exit sub_exit(void)
{
  printk("job done good bye");
}


module_init(sub_init);
module_exit(sub_exit);
