<?php
	class Inicio{
		/*proporciona informacion sobre los discos*/
		function disco($id_disco, $num_com = 10){
			echo '<article class = "caratula">
				<img class = "mediana" src="$ubicacion_car" alt="">
			</article>
			<article class ="comentarios">
				<ol>';
					for($i=0; $i<$num_com; $i++){
						echo '<li>Comentario.</li>';
					}
				echo '</ol>
			</article>
			<article class ="play">
				<a href="$ubicacion_music">
					<img class = "pequeña" src="img/ir_play.png" alt="">
				</a>
			</article>';	
		}

		/*muestra las tres novedades en la cabecera del titulo*/		
		function areaNoticia(){
			echo '<!-- Primer disco -->
			<article class ="disco">';
				$primero;
				Inicio::disco($primero);
			echo '</article>			
			<!-- Segundo disco -->
			<article class ="disco">';
				$segundo;
				Inicio::disco($segundo);					
			echo '</article>
			<!-- Tercero disco -->
			<article class ="disco">';		
					$tercero;
					Inicio::disco($tercero);									
			echo '</article>';
		}

		function nuevaNoticia(){

		}

		function tabla(){
			echo '<article class ="disco">
				<table>
					<!-- Titulo de la tabla -->
					<thead>
						<tr>
							<th>Nuevas Noticias</th>
						</tr>
					</thead>

					<!-- Cuerpo de la tabla -->
					<tbody>
						<tr>
							<td>';
								
									$primera;
									Inicio::nuevaNoticia($primera);
								
							echo '</td>
						</tr>
						<tr>
							<td>';
									$segunda;
									Inicio::nuevaNoticia($segunda);
								
							echo '</td>
						</tr>
						<tr>
							<td>';
									$tercera;
									Inicio::nuevaNoticia($tercera);
							echo '</td>
						</tr>
						<tr>
							<td>';
									$cuarta;
									Inicio::nuevaNoticia($cuarta);
							echo '</td>
						</tr>
						<tr>
							<td>';
									$quinta;
									Inicio::nuevaNoticia($quinta);
							echo '</td>
						</tr>
					</tbody>
				</table>
			</article>';
		}

		function disco_area(){
			echo '<article class ="disco">
				<article class = "caratula">
					<img class = "mediana" src="rock/Khri_Khri_20130101/Khri_Khri_20130101.jpg" alt="">
				</article>
				<article class ="play">
					<a href="rock/Khri_Khri_20130101/khri.html">
						<img class = "pequeña" src="img/ir_play.png" alt="">
					</a>
				</article>	
			</article>';
		}



	}

?>