<?php 

	include 'persistencia.php';
	include 'webContent.php';

	/**
	* Clase para controlar el sistema
	*/
	class System {
		
		/**
		 * Cabecera 	
		 * @param  string $titulo titulo de la cabecera
		 * @return null         No devuelve nada
		 */
		static function headerLoginOn($usuario){
			echo "<header>
					<article>
						<asside class=''><strong><h1>Bienvenido: </strong>".Control::getNombreUsuario($usuario)."</h1></asside>
					</article>
					<article id='boton'><a href='php/logout.php'><button>Salir</button></a></article> 
					
				</header><!-- /header -->";
		}

		/**
		 * Cabecera 	
		 * @param  string $titulo titulo de la cabecera
		 * @return null         No devuelve nada
		 */
		static function headerLoginOff(){
			echo "<header>
					<form action='php/login.php' method='POST' left>
						<article>
				            <label><h3>Inserte el usuario</h3><input type = 'text' id = 'usuario' name='usuario' placeholder='usuario' /></label>
				            <label><h3>Inserte la contraseña</h3><input type = 'password' id = 'contrasena' name='contrasena' placeholder='********'  /></label>
						</article>
			            <button>Entrar</button>
			        </form>
				</header><!-- /header -->";
		}

		/**
		 * Pie de pagina
		 * @return null 		No devuelve nada
		 */
		static function footer(){
			echo "<footer id='footer' class=''>
				<section id='enlace-footer' class=''>
					<a href='http://www.copyright.es/index.html?utm_source=AdWords&utm_medium=PPC&utm_term=copyright&utm_content=147553632213&utm_campaign=AdGroup&Network=Search&SiteTarget=&gclid=CjwKCAjwhcjVBRBHEiwAoDe5x4_bexGQ58dBNqZ-aU3qlD7y0a6u7WPO9JCphtpFIcKm0QxOgMUANBoCuNQQAvD_BwE' style='color:#FFFFFF' target='_blank'>(C) Copyright Antonio Rodríguez Alaminos | Tecnologías Web</a>
				</section>
				<a href='https://github.com/McMayXIII' target='_blank'><img src='image/git.png' alt=''></a>
			</footer><!-- /footer -->";
		}

		static function head(){
			echo "<head>
					<meta http-equiv='X-UA-Compatible' content='IE=edge'>
					<link rel='icon' type='image/png' href='image/ugr.png'>
					<link rel='stylesheet' href='css/styles.css'>
					<title>PRACTICA FINAL</title>
					<meta charset='utf-8'>
				</head>";
		}

		static function menu($user){
			switch ($user) {
				case 'admin':
					WebContenido::menuAdmin();
					break;
				case 'compra':
					WebContenido::menuGestorCompra();
					break;
				default:
					WebContenido::menuDefecto();
					break;
			}	
		}

		static function web($tipo){
			switch ($tipo) {
				case 'grupo':
					WebContenido::webGrupo();
					break;
				case 'discografia':
					WebContenido::webDiscografia();
					break;
				case 'conciertos':
					WebContenido::webConciertos();
					break;
				case 'webComponentes':
					WebContenido::webComponentes();
					break;
				case 'componentesAniadir':
					WebContenido::webComponentesAniadir();
					break;
				case 'componentesEditar':
					WebContenido::webComponentesEditar();
					break;
				case 'webBibliografia':
					WebContenido::webBibliografia();
					break;
				case 'bibliografiaAniadir':
					WebContenido::webBibliografiaAniadir();
					break;
				case 'bibliografiaEditar':
					WebContenido::webBibliografiaEditar();
					break;
				default:
					break;
			}
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
            return Persistence::getNombreUsuario($usuario);
        }
        
        public static function existeUsuario($usuario,$email){
            return Persistence::existeUsuario($usuario, $email);
        }

		static function obtenerTipoUsuario($nombre){
			return Persistence::obtenerTipoUsuario($nombre);
		}

		public static function obtenerListaUsuario(){
			return Persistence::listaUsuario();
		}

		public static function eliminarUsuario($idUser){
			Persistence::eliminarUsuario($idUser);
		}

		public static function insertarUsuario($nombre,$apellidos,$email,$key,$tipo){
			Persistence::insertarUsuario($nombre,$apellidos,$email,$key,$tipo);
		}

		public static function obtenerComponentes(){
		 	return Persistence::obtenerComponentes();
		}

		public static function obtenerBibliografia(){
		 	return Persistence::obtenerBibliografia();
		}

		public static function obtenerDiscos(){
		 	return Persistence::obtenerDiscos();
		}

		public static function obtenerConciertos(){
			return Persistence::obtenerListaConciertos();
		} 

		public static function aniadirComponentes($nombre, $fecha, $lugarNacimineto, $foto, $bibliografia){
			Persistence::aniadirComponentes($nombre, $fecha, $lugarNacimineto, $foto, $bibliografia);
		}

		public static function editarComponentes($nombre, $fecha, $lugarNacimineto, $foto, $bibliografia, $idComponentes){
			Persistence::editarComponentes($nombre, $fecha, $lugarNacimineto, $foto, $bibliografia, $idComponentes);
		}
	}
?>