<!DOCTYPE html>

<html>

	<!-- Cabecera de la pagina -->
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" type="text/css" href="styles.css"/>
		<link rel="shortcut icon" href="img/head.png">
		<title>Music</title>
		<!-- Includes de php para simplificar el codigo -->
		<?php
			include('php/inicio.php');
			include('php/index.inc');
			include('php/general.php');
		?>
	</head> 

	<body>

		<!-- Parte principal de la pagina -->
		<section class = "principal">
			
			<!-- Cuerpo de la página -->
			<article class = "cuerpo">
				
				<!-- Cabecera de la página -->
				<header>

					<!-- Titulo de la página -->
					<section class = "titulo">
						
						<?php
							General::titulo();
						?>

					</section>

					<!-- Lista las tres ultimas novedades -->
					<section class = "novedades">
						
						<?php
							Inicio::areaNoticia();
						?>

					</section>

				</header>

				<!-- Menu de la página -->
				<nav class = "menu">

					<?php
						General::menu();
					?>

				</nav>

				<!-- Subcuerpo de la página -->
				<section class = "subcuerpo">

					<article>

						<!-- Ultimas noticias -->
						<article class ="noticias">

							<!-- Lista de noticias musicales -->
							<article class = "area_noticia">

									<?php
										Inicio::tabla();
									?>

							</article>
							
							<!-- Disco mas comentados -->
							<article class = "area_noticia">
								
								<?php
									Inicio::disco_area();
								?>

							</article>

							<!-- Disco mas destacado -->
							<article class = "area_noticia">
									
								<?php
									Inicio::disco_area();
								?>
								
							</article>

							<!-- Discos mas comentados -->
							<article class = "area_noticia">
									
								<?php
									Inicio::disco_area();
								?>
								
							</article>

						</article>

						<!-- Seleccion por genero -->
						<article class = "genero">

							<!-- Opciones de seleccion de genero -->
							<article class = "option-genero">

								<ul>
									<li><a href="rock/Khri_Khri_20130101/khri.html">Rock</a></li>
									<li><a href="pop.html">Pop</a></li>
									<li><a href="clasica.html">Clasica</a></li>
									<li><a href="regge.html">Regge</a></li>
									<li><a href="rap.html">Rap</a></li>
								</ul>

							</article>

							<!-- Ultimos discos por genero -->
							<article class = "genero_discos">

								<!-- Ultimo disco -->
								<article class ="disco">

								<?php
									genero_disco();
								?>
								
								</article>

								<!-- Ultimo disco -->
								<article class ="disco">
									
								<?php
									genero_disco();
								?>
								
								</article>

								<!-- Ultimo disco -->
								<article class ="disco">

								<?php
									genero_disco();
								?>
								
								</article>

							</article>

						</article>

					</article>

					<!-- Lista de novedades por genero -->
					<article class = "novedades">
						
						<aside>
							
							<?php

							?>

						</aside>

					</article>

				</section>

			</article>

			<!-- Páginas de publicidad -->
			<aside class = "public">
				
				<?php					
					General::publicidad();
				?>

			</aside>

		</section>

		<!-- Pie de página -->
		<footer class ="pie_pagina">

			<?php				
				General::aniadir_pie();
			?>

		</footer>

	</body>

</html>