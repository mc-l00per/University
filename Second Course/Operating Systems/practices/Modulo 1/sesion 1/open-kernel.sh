#/bin/bash

#nos situaremos en primer lugar en el /tmp
cd /tmp

#descargamos los ficheros necesarios del directorio principal para no generar problemas por el enlace vpn
wget https://www.dropbox.com/s/hdnm139vfxelmbw/Fedora14-x86-root_fs?dl=0
wget https://www.dropbox.com/s/ibznk67rzln4n8j/kernel32-3.0.4?dl=0

#renombramos los ficheros descargados para mas facilidad de uso
mv /tmp/Fedora14-x86-root_fs?dl=0 /tmp/fedora
mv /tmp/kernel32-3.0.4?dl=0 /tmp/kernel

# en primer lugar tendremos que darle a los fichero permisos de ejecucion porque por defecto no los tinen, luego simplemente llamar al script nos genera el arranque del kernet como root.
./tmp/kernel ubda=./fedora mem=1024m

sudo mount none ~/montaje/ -t hostfs -o /fenix/depar/lsi/so/paquetes