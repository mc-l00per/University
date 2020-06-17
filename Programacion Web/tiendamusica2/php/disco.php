<?php
	class disco{
		/*datos privativos/
		private IDdisco;
		private nombre;
		private caratula;
		private n_canciones;
		private canciones;

		/*contrutor por defecto*/
		function __constructor($IDdisco, $nombre, $caratula, $n_canciones, $canciones){
			_setIDdisco=$IDdisco;

		}

		/*obtener disco*/
		function obtenerDisco($IDdisco){
			$enlace = mysql_connect('anfitrión_mysql', 'usuario_mysql', 'contraseña_mysql');
			if (!$enlace) {
			    die('No se pudo conectar: ' . mysql_error());
			}
			if (!mysql_select_db('nombre_base_datos')) {
			    die('No se pudo seleccionar la base de datos: ' . mysql_error());
			}
			$resultado = mysql_query('SELECT name FROM work.employee');
			if (!$resultado) {
			    die('No se pudo consultar:' . mysql_error());
			}
			echo mysql_result($resultado, 2); // imprime el nombre del tercer empleado

			mysql_close($enlace);
		}
	}
?>