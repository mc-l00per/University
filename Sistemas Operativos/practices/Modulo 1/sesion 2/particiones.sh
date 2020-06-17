#/bin/bash

#generamos los ficheros que utilizaremos para los disco fisticios
mknod /dev/loop0 b 7 0 
mknod /dev/loop1 b 7 1

#generamos ficheros con un peso
dd if=/dev/zero of=/root/archivo_SA20 bs=2k count=10000
dd if=/dev/zero of=/root/archivo_SA30 bs=3k count=10000

#asociar los dispositivos con los ficheros generados
losetup /dev/loop0 /root/archivo_SA20
losetup /dev/loop1 /root/archivo_SA30

#comprobamos que la configuracion se realizo con exito
fdisk -l /dev/loop0 /dev/loop1

#creacion de archivos, formateo logico de las particiones
mke2fs -c /dev/loop0 -t ext3 -L LABEL_ext3
mke2fs -c /dev/loop1 -t ext4 -L LABEL_ext4

#
