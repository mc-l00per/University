<?php 

	/**
	* Clase para contr
	*/
	class User {
		
		static function sesionIniciada($usuario)	{
			echo "<article id = ''>
				<asside class='login.php'><strong><h1>Bienvenido:</strong>". Control::getNombreUsuario($usuario)."</h1></asside>
				<p><a href='./logout.php'><button><img class = 'botton' src='../img/logout.png' alt=''></button></a></p> 
			</article>";
		}

		static function inicioSecion(){
			echo"<form action='login.php' method='POST' left>
	            <p><label><h1>Inserte el usuario</h1></label>
	            	<input type = 'text' id = 'usuario' name='usuario' placeholder='usuario' /></p>
	            <p><label><h1>Inserte la contraseña</h1></label>
	            	<input type = 'password' id = 'contrasena' name='contrasena' placeholder='********'  /></p>
	            <button><img class = 'botton' src='../img/login.png' alt=''></button>
	        </form>";
		}

		static function menuAdmin(){
			echo "<article id='menu' class=''>
				<ul>
					<li><a href='./usuario.php?tipo=ver'>Ver lista de usuarios</a></li>
					<li><a href='./usuario.php?tipo=modificar'>Modificar usuario</a></li>
					<li><a href='./usuario.php?tipo=crear'>Crear nuevo usuario</a></li>
					<li><a href='./usuario.php?tipo=borrar'>Borrar usuario</a></li>
				</ul>
			</article><!-- /menu -->";
		}

		static function menuUser(){

		}
	}


?>