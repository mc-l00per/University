<?php
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
						<td>
							<?php
								$primera;
								nuevaNoticia($primera);
							?>
						</td>
					</tr>
					<tr>
						<td><?php
								$segunda;
								nuevaNoticia($segunda);
							?>
						</td>
					</tr>
					<tr>
						<td>
							<?php
								$tercera;
								nuevaNoticia($tercera);
							?>
						</td>
					</tr>
					<tr>
						<td>
							<?php
								$cuarta;
								nuevaNoticia($cuarta);
							?>
						</td>
					</tr>
					<tr>
						<td>
							<?php
								$quinta;
								nuevaNoticia($quinta);
							?>
						</td>
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
?>