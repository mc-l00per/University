#!/bin/bash

#para montar la unidad extraible
echo "	MONTADO HDD
"
sudo mount /dev/sdb1 /databases;

sleep 3
clear

#para iniciar el listenig
echo "	CONECTANDO LSNRCTL"
lsnrctl start

sleep 3
clear

#para iniciar sqlplus con oracle
echo "Hay que introducir los siguientes comandos
	connect sys as sysdba 	key->ABD3oradba
	startup
	exit
"
sqlplus /nolog

echo "	
	ORACLE ON"
sleep 3
clear

#poner en marcha oracle
echo "	INICIANDO ORACLE EN RED"
emctl start dbconsole 
msgbox "
	RECUERDA
		user: sys
		key: ADB3oradba
	"
sleep 5
clear

#para iniciar en el navegador oracle
google-chrome https://pclab.localdomain:1158/em/

clear