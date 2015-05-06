#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/fcntl.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/major.h>
#include <linux/delay.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>


static int config_open (struct inode *inode, struct file *filp)
{
	return 0;		
}

static int config_release (struct inode *inode, struct file *filp)
{
	return 0;		
}

static int config_unlocked_ioctl( struct file *file, unsigned int cmd,  unsigned long arg)
{
	return 0;		
}

static struct file_operations config_fops=  {
	.owner		    = THIS_MODULE,
	.open    	    = config_open,
	.release   		= config_release,
	.unlocked_ioctl = config_unlocked_ioctl,
};

static struct miscdevice config_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name   = "config_dev",
	.fops   = &config_fops,
};



static int __init config_init(void)
{
	int ret;

	ret = misc_register(&config_dev);
printk(KERN_ERR "config driver init\n");
	if (ret < 0)
	{
		printk("torch misdev register failed!\n");
		return ret;
	}
	return 0;
}



static void __exit config_exit(void)
{
	misc_deregister(&config_dev);
printk(KERN_ERR "config driver exit\n");
}


module_init(config_init);
module_exit(config_exit);
MODULE_AUTHOR("drs");
MODULE_DESCRIPTION("config driver");
MODULE_LICENSE("GPL");
