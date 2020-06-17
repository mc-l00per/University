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
			include('publicidad.inc');
			include('pie_pag.inc');
			include('header.inc');
			include('area_noticias.inc');
			include('genero.inc');
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
							titulo();
						?>

					</section>

					<!-- Lista las tres ultimas novedades -->
					<section class = "novedades">
						
						<!-- Primer disco -->
						<article class ="disco">

							<?php
								$primero;
								disco($primero);
							?>

						</article>

						<!-- Segundo disco -->
						<article class ="disco">
							
							<?php
								$segundo;
								disco($segundo);						
							?>
							
						</article>

						<!-- Tercero disco -->
						<article class ="disco">
							
							<?php
								$tercero;
								disco($tercero);						
							?>
							
						</article>

					</section>

				</header>

				<!-- Menu de la página -->
				<nav class = "menu">

					<ul class ="nav">

						<li><a href="index.html">Generos</a>

							<ul>

								<li><a href="rock/rock.php">Rock</a></li>
								<li><a href="#">Pop</a></li>
								<li><a href="#">Clasica</a></li>
								<li><a href="#">Reggae</a></li>
								<li><a href="#">Rap</a></li>

							</ul>

						</li>
						<li><a href="#">Más Vendido</a></li>
						<li><a href="#">Más comentados</a></li>

					</ul>

				</nav>

				<!-- Subcuerpo de la página -->
				<section class = "subcuerpo">

					<article>

						<!-- Ultimas noticias -->
						<article class ="noticias">

							<!-- Lista de noticias musicales -->
							<article class = "area_noticia">

									<?php
										tabla();
									?>

							</article>
							
							<!-- Disco mas comentados -->
							<article class = "area_noticia">
								
								<?php
									disco_area();
								?>

							</article>

							<!-- Disco mas destacado -->
							<article class = "area_noticia">
									
								<?php
									disco_area();
								?>
								
							</article>

							<!-- Discos mas comentados -->
							<article class = "area_noticia">
									
								<?php
									disco_area();
								?>
								
							</article>

						</article>

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
					publicidad();
				?>

			</aside>

		</section>

		<!-- Pie de página -->
		<footer class ="pie_pagina">

			<?php				
				aniadir_pie();
			?>

		</footer>

	</body>

</html>