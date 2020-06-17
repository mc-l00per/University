<!DOCTYPE html>

<!-- Cabecera de la pagina -->
<html>

	<head>
		<meta charset="utf-8">
		<base href="http://bahia.ugr.es/~x74725175/tiendamusica/" target="_blank, _self, _parent, _top">
		<link rel="stylesheet" type="text/css" href="styles.css"/>
		<link rel="shortcut icon" href="img/head.png">
		<title src="img/head.png">Music McMayXIII</title>
	</head> 

	<body>
		<section class = "principal">
			<article class = "cabecera">
				<header>
					<section class = "titulo">
						<article class ="img">
							<img class = "pequeña_cartel" src="img/head.png" alt="">
						</article>
						<article class ="text_titulo">
							<h1>Music McMayXIII</h1>
						</article>
						<article class = "user">
							<form action="login.php" method="post" accept-charset="utf-8">
								<input size="10" maxlength="20" type="text" name="Usuario" value="user">
								<input size="10" maxlength="20" type="text" name="password" value="********">
								<button class = "botton_aceptar"><img class = "botton" src="img/login.png" alt=""></button>
								<a href="user.html">
									<img class = "botton" src="img/regi.png" alt="">
								</a>
							</form>
						</article>
					</section>
				</header><!-- /header -->
				<nav class = "menu">
					<ul class ="nav">
						<li><a href="index.html">Generos</a>
							<ul>
								<li><a href="rock/rock.html">Rock</a></li>
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
				<section class = "cartel">
					<article class ="text_titulo">
						<h1>Suscripcion al servicio</h1>
					</article>
				</section>
				<section class = "cartel">
					<article class ="text_titulo">
						<h1>Subtitulo de la suscripcion</h1>
					</article>
				</section>
				<section>
					<article class = "user">
						<form action="login.php" method="post" accept-charset="utf-8">
							<article class = "dato">
								<h1>Usuario</h1><input size="20" maxlength="20" type="text" name="usuario" value="">
							</article>
							<article class = "dato">
								<h1>Apellidos</h1><input size="20" maxlength="20" type="text" name="apellidos" value="">
							</article>
							<article class = "dato">
								<h1>Nombre Usuario</h1><input size="20" maxlength="20" type="text" name="Nombre_Usuario" value="">
							</article>
							<article class = "dato">
								<h1>Clave</h1><input size="20" maxlength="20" type="password" name="key" value="******">
							</article>
							<article class = "dato">
								<h1>Dirección postal</h1><input size="0" maxlength="20" type="text" name="Usuario" value="">
							</article>
							<article class = "dato">
								<h1>Ciudad</h1><input size="20" maxlength="20" type="text" name="ciudad" value="">
							</article>
							<article class = "dato">
								<h1>Codigo postal</h1><input size ="20" maxlength="20" type="text" name="c_postal" value="">
							</article>
							<article class = "dato">
								<h1>Provincia</h1><select name="ciudad">
									<option>Granada</option>
									<option>Sevilla</option>
									<option>Almería</option>
								</select>
							</article>
							<article class = "dato">
								<h1>Email</h1><input size="20" maxlength="200" type="text" name="email" value="">
							</article>
							<article class = "dato">
								<h1>DNI</h1><input size="20" maxlength="20" type="text" name="dni" value="">
							</article>
							<article class = "dato">
								<h1>Tarjeta de credito</h1><input size="6" maxlength="20" type="text" name="car1" value="">
								<input size="6" maxlength="20" type="text" name="car2" value="">
								<input size="2" maxlength="20" type="text" name="car3" value="">
								<input size="6" maxlength="20" type="text" name="car4" value="">
							</article>
							<article class = "dato">
								<h1>Observaciones</h1><textarea name="comentarios" rows="10" cols="30">Escribe aquí tus comentarios</textarea>
							</article>
							<article class = "dato">
								<h1>Envio:</h1> <input type="radio" name="envio" value="1"><h1>Mensual</h1> <input type="radio" name="envio" value="1"><h1>Semanal</h1> <input type="radio" name="envio" value="1"><h1>Diario</h1> 
							</article>
								
							<article class = "botones_login">
								<button class = "botton_aceptar"><img class = "botton" src="img/regi_save.png" alt=""></button>
								<article class = "dato">
									<input class = "valor" type="checkbox" name="transporte" value="1"><h1>He leido y acepto las condiciones del servicio de suscrípción:</h1>
								</article>
							</article>
						</form>
					</article>
				</section>
			</article>
			<aside class = "public">
				<nav>
					<ul>
						<li><a href="http://jenesaispop.com/">Jenesaispop</a></li>	
						<li><a href="http://www.hipersonica.com/">hipersonica</a></li>
						<li><a href="http://indiespot.es/">indiespot</a></li>
						<li><a href="http://www.mondosonoro.com/">mondosonoro</a></li>
						<li><a href="http://www.indiehoy.com/">indiehoy</a></li>
						<li><a href="http://www.indierocks.mx/">indierocks</a></li>	
						<li><a href="http://www.binaural.es/">binaural</a></li>
						<li><a href="http://www.dodmagazine.es/">dodmagazine</a></li>
						<li><a href="http://muzikalia.com/">muzikalia</a></li>
						<li><a href="http://gladyspalmera.com/">gladyspalmera</a></li>
					</ul>
				</nav>
			</aside>
		</section>
		
		<?php
			include('pie_pag.inc');
		?>

	</body>

</html>