<?php 

	/**
	* Clase para controlar la parte de la web cookies
	* para la parte tercera de la practica
	*/
	class Cookies{
		
		/**
		 * Mensaje para los datos incorrectos
		 * @return null No devuelve nada pinta directamente en pantalla
		 */
		static function error(){
			echo "<p>Inserción incorrecta de los datos.</p>";
		}

		/**
		 * Primera ejecucion
		 * @return null No devuelve nada pinta directamente en pantalla
		 */
		static function primeraVez(){
			echo "<form action='cookies.php' method='get' accept-charset='utf-8'>
					<label>Inserta tu nombre:</label><input type='text' name='nombre' value=''>
					<label>Seleciona tu prenda:</label>
					<select name='prenda'>
						<option value=''>- Selecciona -</option>
						<option value='camisa'>Camisa</option>
						<option value='pantalon'>Pantalon</option>
						<option value='falda'>Falda</option>
					</select>
					<div><button type='submit'>Pulsa para enviar</button></div>
				</form>";
		}

		/**
		 * Segunda ejecucion
		 * @return null No devuelve nada pinta directamente en pantalla
		 */
		static function segundaVez(){
			echo "<form action='cookies.php' method='get' accept-charset='utf-8'>
					<label>Selecione su color:</label>
						<select name='color'>
							<option value=''>- Selecciona -</option>
							<option value='rojo'>Rojo</option>
							<option value='verde'>Verde</option>
							<option value='azul'>Azul</option>
						</select>
					<label>Seleciona su talla:</label>
						<select name='talla'>
							<option value=''>- Selecciona -</option>";
							for ($i=30; $i < 50; $i++) { 
								echo "<option value=$i>$i</option>";
							}
						echo "</select>
					<div><button type='submit'>Pulsa para enviar</button></div>
				</form>";
		}

		/**
		 * Muestra los datos
		 * @return null No devuelve nada pinta directamente en pantalla
		 */
		static function mostrarDatos(){
			$nombre=$_COOKIE['nombre'];
			$prenda=$_COOKIE['prenda'];
			$talla=$_GET['talla'];
			$color=$_GET['color'];

			echo "<articulo id='datos'>
				<ul>
				<li>
					<h1>Nombre</h1>
					<h2>$nombre</h2>
				</li>
				<li>
					<h1>Prenda</h1>
					<h2>$prenda</h2>
				</li>
				<li>
					<h1>Talla</h1>
					<h2>$talla</h2>
				</li>
				<li>
					<h1>Color</h1>
					<h2>$color</h2>
				</li>
				</ul>
			</article>";
		}
	}

?>