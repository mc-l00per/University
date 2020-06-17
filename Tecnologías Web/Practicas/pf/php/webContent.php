<?php
	
	include 'object.php';

	/**
	 * Clase para controlar la web segun el usuario 		
	 */
	class WebContenido	{
		
		static function menuAdmin(){
			echo "<article id='menu' class=''>
				<ul id='menuPrincipal'>
					<li><a href='?ver=webComponentes'>Componentes</a>
						<ul id='submenu'>
							<li><a href='?ver=componentesAniadir'>Añadir</a></li>
							<li><a href='?ver=componentesEditar'>Editar</a></li>
							<li><a href='?ver=componentesBorrar'>Borrar</a></li>
						</ul>
					</li>
					<li><a href='?ver=webBibliografia'>Bibliografia</a>
						<ul id='submenu'>
							<li><a href='?ver=bibliografiaAniadir'>Añadir</a></li>
							<li><a href='?ver=bibliografiaEditar'>Editar</a></li>
							<li><a href='?ver=bibliografiaBorrar'>Borrar</a></li>
						</ul>
					</li>			
					<li><a href='?ver=discografia'>Discografía</a>
						<ul id='submenu'>
							<li><a href='?ver=discografiaAniadir'>Añadir</a></li>
							<li><a href='?ver=discografiaEditar'>Editar</a></li>
							<li><a href='?ver=discografiaBorrar'>Borrar</a></li>
						</ul>
					</li>
					<li><a href='?ver=conciertos'>Conciertos</a>
						<ul id='submenu'>
							<li><a href=''>Añadir</a></li>
							<li><a href=''>Editar</a></li>
							<li><a href=''>Borrar</a></li>
						</ul>
					</li>
					<li><a href='?ver=usuarios'>Usuarios</a>
						<ul id='submenu'>
							<li><a href=''>Añadir</a></li>
							<li><a href=''>Editar</a></li>
							<li><a href=''>Borrar</a></li>
						</ul>
					</li>
					<li><a href='?ver=log'>Ver Log</a></li>
				</ul>
			</article><!-- /menu -->";
		}

		static function menuGestorCompra(){
			echo "<article id='menu' class=''>
				<ul>
					<li><a id='salir' href=''>Consultar Petisiones</a></li>
					<li><a id='salir' href=''>Historial</a></li>
					<li><a id='salir' href=''>Editar Precio</a></li>
				</ul>
			</article><!-- /menu -->";
		}

		static function menuDefecto(){
			echo "<article id='menu' class=''>
				<ul>
					<li><a id='salir' href='?ver=grupo'>Grupo</a></li>
					<li><a id='salir' href='?ver=discografia'>Discografía</a></li>
					<li><a id='salir' href='?ver=conciertos'>Conciertos</a></li>
				</ul>
			</article><!-- /menu -->";
		}

		static function webGrupo(){
			$listaComponentes=Control::obtenerComponentes();
			echo "<article id='contenido'>
				<h1>Componentes</h1>
				<section id='componente'>";
					
		 		
		 		for ($i=0; $i < count($listaComponentes); $i++) {
		 			echo "<article>
		 					<section id='componentes-detalles'>
		 						<img src='".$listaComponentes[$i]->foto."' alt='foto' id='componentes-img'>
		 						<section id='componentes-detalles-ext'>
			 			 			<a>".$listaComponentes[$i]->nombre."</a>
			 			 			<a>".$listaComponentes[$i]->fecha."</a>
			 			 			<a>".$listaComponentes[$i]->lugarNacimiento."</a>
		 						</section>
		 					</section>
		 					<section>
		 			 			<a>".$listaComponentes[$i]->bibliografia."</a>
		 					</section>
		 			 </article>"; 	
		 		}
				
			echo "</section>
				</sectio>";
			$bibliografia = Control::obtenerBibliografia();
			echo "<section id='componente'>";
				for ($i=0; $i < count($bibliografia); $i++) { 
					echo "<p>".$bibliografia[$i]->texto."</p>";
				}		
			echo "</section>
			</article>";	
		}

		static function webDiscografia(){
			$listaDiscos=Control::obtenerDiscos();
			echo "<article id='contenido'>
				<section id='discografia'>
					<h2>Álbumes de estudio</h2>";
			
			for ($i=0; $i < count($listaDiscos); $i++) { 
				echo "<section id='discografia-disco'>
					<section id='enlace-disco'>
						<img src='".$listaDiscos[$i]->foto."' alt='image9'>
						<section id='info-disco'>
							<section id='disco'>
								<section id='detalles-disco'>
									<h3>Precio:</h3><h4>".$listaDiscos[$i]->precio."€</h4>					
								</section>
								<section id='detalles-disco'>
									<h3>Fecha:</h3><h4>".$listaDiscos[$i]->anio."</h4>						
								</section>
							</section>
								<a href=".$listaDiscos[$i]->urlCompra."><button type='button'>Comprar</button></a>						
						</section>
					</section>
					<section id='lista-canciones'>
						<section id='mitad-lista'>";
							for ($j=0; $j < count($listaDiscos[$i]->listaCanciones); $j+=2) { 
								echo "<section id='cacion'>
									<h5>".$listaDiscos[$i]->listaCanciones[$j]->indice."</h5>
									<h5>".$listaDiscos[$i]->listaCanciones[$j]->titulo."</h5>
									<h5>".$listaDiscos[$i]->listaCanciones[$j]->duracion."</h5>
								</section>";
							}
						echo "</section>
						<section id='mitad-lista'>";
							for ($j=1; $j < count($listaDiscos[$i]->listaCanciones); $j+=2) { 
								echo "<section id='cacion'>
									<h5>".$listaDiscos[$i]->listaCanciones[$j]->indice."</h5>
									<h5>".$listaDiscos[$i]->listaCanciones[$j]->titulo."</h5>
									<h5>".$listaDiscos[$i]->listaCanciones[$j]->duracion."</h5>
								</section>";
							}
						echo "</section>
					</section>
				</section>";
			}
		
			echo "</section>
				</article><!-- /contenido -->";
		}

		static function webConciertos(){
			$listaConciertos=Control::obtenerConciertos();
			echo "<article id='contenido'>
				<h1>Conciertos</h1>";
				
		 		
		 		for ($i=0; $i < count($listaConciertos); $i++) {
		 			echo "<section id='componente'>
		 				<article>
	 						<section id='detalles'>
		 			 			<a>Fecha: ".$listaConciertos[$i]->fecha."</a>
		 			 			<a>Hora: ".$listaConciertos[$i]->hora."</a>
		 			 			<a>Lugar: ".$listaConciertos[$i]->lugar."</a>
	 						</section>
		 					<section>
		 			 			<a><h3>Descripción: </h3>".$listaConciertos[$i]->descripcion."</a>
		 					</section>
		 					<a href=".$listaConciertos[$i]->urlCompra."><button type='button'>Comprar</button></a>
		 			 </article>"; 	
		 		}
					
			echo "</section>
			</article>";
		}

		static function webComponentes(){
			$listaComponentes=Control::obtenerComponentes();
			echo "<article id='contenido'>
				<h1>Componentes</h1>
				<section id='componente'>";
		 		
		 		for ($i=0; $i < count($listaComponentes); $i++) {
		 			echo "<article>
		 					<section id='componentes-detalles'>
		 						<img src='".$listaComponentes[$i]->foto."' alt='foto' id='componentes-img'>
		 						<section id='componentes-detalles-ext'>
			 			 			<a>".$listaComponentes[$i]->nombre."</a>
			 			 			<a>".$listaComponentes[$i]->fecha."</a>
			 			 			<a>".$listaComponentes[$i]->lugarNacimiento."</a>
		 						</section>
		 					</section>
		 					<section>
		 			 			<a>".$listaComponentes[$i]->bibliografia."</a>
		 					</section>
		 			 </article>"; 	
		 		}
				
			echo "</section>
				</article>";
		}

		static function webComponentesAniadir(){
			if (isset($_GET['nombre']) && isset($_GET['fecha']) && isset($_GET['foto']) && isset($_GET['lugarNacimiento']) && isset($_GET['bibliografia'])) 
				Control::aniadirComponentes($_GET['nombre'], $_GET['fecha'], $_GET['foto'], $_GET['lugarNacimiento'], $_GET['bibliografia']);
			else
				echo "<article id='contenido'>
					<h1>Componentes</h1>
					<section id='componentes-editar'>
						<form action='' method='get' accept-charset='utf-8'>
							<div>
								<label>Nombre</label> <input type='text' name='nombre' value='' placeholder=''>
							</div>
							<div>
								<label>Fecha</label> <input type='date' name='fecha' value='' placeholder=''>
							</div>
							<div>
								<label>Lugar Nacimiento</label><input type='text' name='lugarNacimiento' value='' placeholder=''>
							</div>
							<div>
								<label>URL FOTO</label> <input type='text' name='foto' value='' placeholder=''>
							</div>
							<div>
								<label>Bibliografia</label> <textarea id='textarea' name='bibliografia'></textarea>
							</div>
							<input type='hidden' name='ver' value='componentesAniadir'>
							<article id='boton'><a href=''><button>Guardar</button></a></article>
						</form>
					</section>
		 		</article>"; 	
		}

		static function webComponentesEditar(){
			if (isset($_GET['nombre']) && isset($_GET['fecha']) && isset($_GET['foto']) && isset($_GET['lugarNacimiento']) && isset($_GET['bibliografia']) && isset($_GET['idComponentes'])) 
				Control::editarComponentes($_GET['nombre'], $_GET['fecha'], $_GET['foto'], $_GET['lugarNacimiento'], $_GET['bibliografia'], $_GET['idComponentes']);
			else{
				$listaComponentes=Control::obtenerComponentes();
		 		for ($i=0; $i < count($listaComponentes); $i++) {
					echo "<article id='contenido'>
						<h1>Componentes</h1>
						<section id='componentes-editar'>
							<form action='' method='get' accept-charset='utf-8'>
								<div>
									<label>Nombre</label> <input type='text' name='nombre' value='".$listaComponentes[$i]->nombre."' placeholder=''>
								</div>
								<div>
									<label>Fecha</label> <input type='text' name='fecha' value='".$listaComponentes[$i]->fecha."' placeholder=''>
								</div>
								<div>
									<label>Lugar NAcimiento</label><input type='text' name='lugarNacimiento' value='".$listaComponentes[$i]->lugarNacimiento."' placeholder=''>
								</div>
								<div>
									<label>URL FOTO</label> <input type='text' name='foto' value='".$listaComponentes[$i]->foto."' placeholder=''>
								</div>
								<div>
									<label>Bibliografia</label> <textarea id='textarea' name='bibliografia' value=''>".$listaComponentes[$i]->bibliografia."</textarea>
								</div>
								<input type='hidden' name='ver' value='componentesEditar'>
								<input type='hidden' name='idComponentes' value='".$listaComponentes[$i]->idComponentes."'>
								<article id='boton'><a href=''><button>Guardar</button></a></article>
							</form>
						</section>
			 		</article>";
			 	}
		 	}
		}

		static function webComponentesBorrar(){

		}

		static function webBibliografia(){
			$bibliografia = Control::obtenerBibliografia();
			echo "<article id='contenido'>
				<h1>Bibliografia</h1>
				<section id='componente'>";
				for ($i=0; $i < count($bibliografia); $i++) { 
					echo "<p>".$bibliografia[$i]->texto."</p>";
				}		
			echo "</section>
				</article>";
		}

		static function webBibliografiaAniadir(){
			if (isset($_GET['fecha']) && isset($_GET['bibliografia'])) 
				Control::aniadirBiliografia($_GET['fecha'], NULL, $_GET['bibliografia']);
			else
				echo "<article id='contenido'>
					<h1>Bibliografia</h1>
					<section id='componentes-editar'>
						<form action='' method='get' accept-charset='utf-8'>
							<div>
								<label>Fecha</label> <input type='date' name='fecha' value='' placeholder=''>
							</div>
							<div>
								<label>Texto</label> <textarea id='textarea' name='texto'></textarea>
							</div>
							<input type='hidden' name='ver' value='bibliografiaAniadir'>
							<article id='boton'><a href=''><button>Guardar</button></a></article>
						</form>
					</section>
		 		</article>"; 	
		}

		static function webBibliografiaEditar(){
			if (isset($_GET['fecha']) && isset($_GET['bibliografia'])) 
				Control::editarBibliografia($_GET['fecha'], NULL, $_GET['bibliografia']);
			else{
				$bibliografia = Control::obtenerBibliografia();
				for ($i=0; $i < count($bibliografia); $i++) {
					echo "<article id='contenido'>
						<h1>Bibliografia</h1>
						<section id='componentes-editar'>
							<form action='' method='get' accept-charset='utf-8'>
								<div>
									<label>Fecha</label> <input type='text' name='fecha' value='".$bibliografia[$i]->fecha."' placeholder=''>
								</div>
								<div>
									<label>Texto</label> <textarea id='textarea' name='texto'>".$bibliografia[$i]->texto."</textarea>
								</div>
								<input type='hidden' name='ver' value='bibliografiaAniadir'>
								<input type='hidden' name='idBibliografia' value='".$bibliografia[$i]->idBibliografia."'>
								<article id='boton'><a href=''><button>Guardar</button></a></article>
							</form>
						</section>
			 		</article>";
		 		}
		 	}
		}

		static function webBibliografiaBorrar(){
			/*DELETE FROM `componentes` WHERE `componentes`.`idComponentes` = 3*/
		}
	}
	
?>