cmd_/home/pi/device-drivers/kern_charioctl/modules.order := {   echo /home/pi/device-drivers/kern_charioctl/my_ioctl.ko; :; } | awk '!x[$$0]++' - > /home/pi/device-drivers/kern_charioctl/modules.order