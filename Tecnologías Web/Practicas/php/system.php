<?php
	
	include 'persistencia.php';

	/**
	* Clase para mostrar las parte principales de las web
	* para toda la practica
	*/
	class System{
		
		/**
		 * Cabecera 	
		 * @param  string $titulo titulo de la cabecera
		 * @return null         No devuelve nada
		 */
		static function header($titulo){
			echo "<header id=\"header\" class=\"\">
				<article id=\"titulo\" class=\"\">
					<h1>Tecnologías Web (2017-2018)<br><br>GRADO EN INGENIERÍA INFORMÁTICA<br> UNIVERSIDAD DE GRANADA</h1>
					<h2>PRACTICA 3 - $titulo</h2>
					<h3>Autor: Antonio Rodríguez Alaminos</h3>
				</article>
				<img src=\"../image/ugr.png\" alt=\"\">
			</header><!-- /header -->";
		}

		/**
		 * Pie de pagina
		 * @return null 		No devuelve nada
		 */
		static function footer(){
			echo "<footer id=\"footer\" class=\"\">
				<section id=\"enlace-footer\" class=\"\">
					<a href=\"http://www.copyright.es/index.html?utm_source=AdWords&utm_medium=PPC&utm_term=copyright&utm_content=147553632213&utm_campaign=AdGroup&Network=Search&SiteTarget=&gclid=CjwKCAjwhcjVBRBHEiwAoDe5x4_bexGQ58dBNqZ-aU3qlD7y0a6u7WPO9JCphtpFIcKm0QxOgMUANBoCuNQQAvD_BwE\" style=\"color:#FFFFFF\" target=\"_blank\">(C) Copyright Antonio Rodríguez Alaminos | Tecnologías Web</a>
				</section>
				<a href=\"https://github.com/McMayXIII\" target=\"_blank\"><img src=\"../image/git.png\" alt=\"\"></a>
			</footer><!-- /footer -->";
		}
	}

	/**
	* Unidad de control de la base de datos
	*/
	class Control {
		
		public static function login($usuario,$pass){
            $estado=Persistence::login($usuario,$pass);
            $estado;
        }
		
		public static function getNombreUsuario($usuario){
            $nombre = Persistence::getNombreUsuario($usuario);
            return $usuario;
        }
        
        public static function existeUsuario($usuario,$email){
            $estado=Persistence::existeUsuario($usuario, $email);
            return $estado;
        }

		static function obtenerTipoUsuario(){
			return 'admin';
		}
	}

?>