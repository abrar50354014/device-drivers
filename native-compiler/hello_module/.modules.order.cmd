cmd_/home/pi/device-driver/native-compiler/hello_module/modules.order := {   echo /home/pi/device-driver/native-compiler/hello_module/hello.ko; :; } | awk '!x[$$0]++' - > /home/pi/device-driver/native-compiler/hello_module/modules.order
