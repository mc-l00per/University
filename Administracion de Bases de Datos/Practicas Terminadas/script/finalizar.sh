#!/bin/bash

#para oracle interprace
echo "	DESCONECTANDO ORACLE ENTERPRISE MANAGER
"

emctl stop dbconsole

echo "		
		ORACLE DESCONECTADO"

sleep 3
clear

#paramos la base de datos del system
echo "	DESCONECTANDO SQLPLUS
	INTRODUCIMOS EL SIGUIENTE COMANDO
		shutdown immediate
		exit"

sqlplus sys as sysdba

echo "		
		SQLPLUS DETENIDO"

sleep 3
clear

#paramos el listener
echo "	DETENIENDO EL SERVICIO LSNRCTL"
lsnrctl stop

echo "		
		SQLPLUS DETENIDO"

sleep 3
clear

#para desmontar la unidad extraible
echo "	DESMONTANDO HDD"
sudo umount /databases

sleep 3
clear
