
<?php 

	/**
	* Clase para controlar la parte de la web de biblioteca
	* para la parte primera de la practica
	*/
	class Biblioteca{
		
		/**
		 * Formulario para buscar un titulo en la biblioteca UGR
		 * @return null No devuelve nada pinta directamente en pantalla
		 */
		static function primeraVez(){
			echo "<form action=\"biblioteca.php\" method=\"get\">
				<p id=\"formulario\">Inserta un nombre de busqueda:</p> 
				<p><input type=\"text\" name=\"nombre\" /></p>
				<p id=\"formulario\"><input type=\"submit\" /></p>
			</form>"; 
		}

		/**
		 * Muestra los datos encontrados por autor y titulo
		 * @return null No devuelve nada pinta directamente en pantalla
		 */
		static function mostrarScrapingPhp(){
			$busqueda = "http://bencore.ugr.es/iii/encore/search?formids=target&lang=spi&suite=def&reservedids=lang%2Csuite&submitmode=&submitname=&target=".($_GET['nombre'])."&submit.x=0&submit.y=02";

	        $curl = curl_init(); // Inicia sesión cURL
	        curl_setopt($curl, CURLOPT_RETURNTRANSFER, true); // Configura cURL para devolver el resultado como cadena	  
	        curl_setopt($curl, CURLOPT_URL, $busqueda); 
	        curl_setopt($curl,CURLOPT_USERAGENT,'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.17 (KHTML, like Gecko) Chrome/24.0.1312.52 Safari/537.17');

	        $info = curl_exec($curl); // Establece una sesión cURL y asigna la información a la variable $info

	        curl_close($curl); // Cierra sesión cURL   

	        $regex = '/<span class="title"><a id="recordDisplayLink.*>\n?.*?\n?(.*?)</';
			
			if ( preg_match_all($regex, $info, $list,PREG_SET_ORDER) )
			    
			$regex2 = '/<span class="additionalFields customSecondaryText">(.*?)<\/span>/';
			
			if ( preg_match_all($regex2, $info, $list2,PREG_SET_ORDER) )
			    
			for ($i=0; $i < count($list2); $i++) {
				if($list2[$i][1] != '' || $list[$i][1] != '') {
					echo "<articulo id=\"resutl\">
						<ul>
						<li>
							<h1>Titulo</h1>";
							echo $list[$i][1];
						echo "</li>
						<li>
							<h2>Autor</h2>";
							echo $list2[$i][1];
						echo "</ul>
					</article>";
				}
			}			
		}
	}

?>