#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>

#define NAME mydevice


//function prototypes
int NAME_open(struct inode *inode,struct file *filp);
int NAME_release(struct inode *inode, struct file *filp);
ssize_t NAME_write(struct file *filp, const char __user *Ubuff,size_t count, loff_t *offp);
ssize_t NAME_read(struct file *filp, char __user *Ubuff,size_t count, loff_t *offp);


//structure defining operations that the driver provides
struct file_operations fops = 
{
	.owner	= THIS_MODULE,
	.open	= NAME_open,
	.read	= NAME_read,
	.write  = NAME_write,
	.release= NAME_release,

};


//structure for a chararcter driver
struct cdev *my_cdev;


//init module
static int __init chardevice_init(void)
{
	int result;
	int major,minor;
	dev_t mydev;
	mydev=MKDEV(255,0);  //creating a device number
	major=MAJOR(mydev);
	minor=MINOR(mydev);
	printk("\n major number %d.....minor number %d\n",major,minor);
	result=register_chrdev_region(mydev,1,"mydevice");//register device region
	if(result<0)
	{
		printk("\nthe region is not obtainable\n");
		return(-1);
				
	}

	my_cdev = cdev_alloc();//allocate memory to char device structure
	my_cdev->ops = &fops;//link file operations to char device
	result = cdev_add(my_cdev,mydev,1);//notify kernal abt device
	if(result<0)
	{
		printk("\nchar device not created\n");
		unregister_chrdev_region(mydev,1);
		return (-1);
	}
	return 0;
			
}

//cleanup module
void __exit chardevice_exit(void)
{
	dev_t mydev;
	int major,minor;
	mydev=MKDEV(255,0);
	major=MAJOR(mydev);
	minor=MINOR(mydev);
	printk("\n major numberr: %d.....minor number: %d\n",major,minor);
	unregister_chrdev_region(mydev,1);//unregister the device numbers and devuce created
	cdev_del(my_cdev);
	printk("device unregisterd that was allocated");
}

//open sys call
int NAME_open(struct inode *inode,struct file *filp)
{
	printk("\nthis is kernal..... open call\n");
	return 0;
}

//close sys call
int NAME_release(struct inode *inode, struct file *filp)
{
	printk("\n release method of character device\n");
	return 0;
}


//write functionality
ssize_t NAME_write(struct file *filp, const char __user *Ubuff,size_t count, loff_t *offp)
{
	char Kbuff[100];
        unsigned long res;
        ssize_t ret;
        res = copy_from_user((char *)Kbuff,(char *)Ubuff,count);//get data from user

        if (res==0)
        {
                printk("\n Message from the user is: %s \n",Kbuff);
                printk("\n data written successfuly \n");
                ret=count;
                return ret;
        }
	else if(res>0)
	{
		printk("\n message from the user is: %s \n",Kbuff);
		printk("\n data partially copied from user \n");
		ret=(count-res);
		return ret;
	}
	else
	{
		printk("\n Error Writing data\n");
		ret=-EFAULT;
		return ret;
	}

	return 0;
}
//read functionality
ssize_t NAME_read(struct file *filp, char __user *Ubuff,size_t count, loff_t *offp)
{
	char Kbuff[100] = "Hello user....iam kernal";
	unsigned long res;
	ssize_t ret;
	res = copy_to_user((char *)Ubuff,(char *)Kbuff,count);//send data to user

	if (res==0)
	{
		printk("\n Message to the user is: %s \n",Kbuff);
		printk("\n data read successfuly \n");
		ret=count;
		return ret;
	}

	else if(res>0)
        {
                printk("\n message to the user is: %s \n",Kbuff);
                printk("\n data partially copied to the user \n");
                ret=(count-res);
                return ret;
        }
	else
        {
                printk("\n Error reading data\n");
                ret=-EFAULT;
                return ret;
        }

	return 0;
}



module_init(chardevice_init);
module_exit(chardevice_exit);
