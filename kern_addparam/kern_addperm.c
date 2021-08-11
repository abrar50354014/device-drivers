#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include"add.h"
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ABRAR");

static int a = 10;
static int b = 20;
static char* charvar = "add";

module_param(charvar, charp, S_IRUGO);
module_param(a, int, S_IRUGO);
module_param(b, int,S_IRUGO);

static int __init add_init(void)
{
  printk("in %s function",charvar);
  printk("value of addition is: %d", my_add(a,b));
  return 0;
}

void __exit add_exit(void)
{
  printk("job done good bye");
}


module_init(add_init);
module_exit(add_exit);
