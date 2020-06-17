
<!DOCTYPE html>

<html>

	<!-- Cabecera de la pagina -->
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" type="text/css" href="../styles.css"/>
		<link rel="shortcut icon" href="../img/head.png">
		<title>Music</title>
		<!-- Includes de php para simplificar el codigo -->
		<?php
			session_start();
			include('classControl.php');
			include('classIndex.php')
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
							Control::titulo();
						?>

					</section>

					<!-- Lista las tres ultimas novedades -->
					<section class = "novedades">
						
						<?php
							Index::areaNoticia();
						?>

					</section>

				</header>

				<!-- Menu de la página -->
				<nav class = "menu">

					<?php
						Control::menu();
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
										Index::tabla();
									?>

							</article>
							
							<!-- Disco mas comentados -->
							<?php
								Index::disco_area();
							?>

						</article>

						<article class = "genero">

							<!-- Opciones de seleccion de genero -->
							<article class = "option-genero">

								<ul>
									<?php
										echo '<li><a href="index.php?tipo=\'rock\'&tipo2='.$_GET['tipo2'].'">Rock</a></li>
											<li><a href="index.php?tipo=\'pop\'&tipo2='.$_GET['tipo2'].'">Pop</a></li>';
									?>
								</ul>

							</article>

							<!-- Ultimos discos por genero -->
							<article class = "genero_discos">
							
								<?php  
										echo '<!-- Ultimo disco -->
										<article class ="discoGenero">';

											Index::ultimosDiscosGenero($_GET['tipo']);
										
										echo '</article>';
								?>

							</article>

						</article>

					</article>

					<!-- Lista de novedades por genero -->
					<article class = "novedadesGenero">
						
						<!-- Opciones de seleccion de genero -->
						<article class = "option-genero">
							<form method="get" action="<?php echo $_SERVER['PHP_SELF']; ?>">

							<select name="tipo2">
								<option>'Rock'</option>
								<option>'Pop'</option>
							</select>							
							<input type="hidden" name="tipo" value=<?php echo '"'.$_GET['tipo'].'"';?>/>
							<input type="submit" value="Enviar" /><br>

							</form>

						</article>

						<article class = "genero_discos">
						
							<?php  
									echo '<!-- Ultimo disco -->
									<article class ="discoNovedades">';

										Index::ultimosDiscosNoticias($_GET['tipo2']);
									
									echo '</article>';
							?>

						</article>

					</article>

				</section>

			</article>

			<!-- Páginas de publicidad -->
			<aside class = "public">
				
				<?php					
					Control::publicidad();
				?>

			</aside>

		</section>

		<!-- Pie de página -->
		<footer class ="pie_pagina">

			<?php				
				Control::aniadir_pie();
			?>

		</footer>

	</body>

</html>