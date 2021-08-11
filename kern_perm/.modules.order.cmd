cmd_/home/pi/device-driver/kern_perm/modules.order := {   echo /home/pi/device-driver/kern_perm/kern_perm.ko; :; } | awk '!x[$$0]++' - > /home/pi/device-driver/kern_perm/modules.order
