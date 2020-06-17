
<!DOCTYPE html>

<!-- Cabecera de la pagina -->
<html>

	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" type="text/css" href="../styles.css"/>
		<script type="text/javascript" src="../js/validator.js"></script>
		<link rel="shortcut icon" href="../img/head.png">
		<title src="img/head.png">Music</title>
		<!-- Includes de php para simplificar el codigo -->
        <?php
        	session_start();
            include('classControl.php');
            include('classGenero.php')
        ?>
	</head> 

	<body>
		<section class = "principal">
			<article class = "cabecera">
				<header>
					<section class = "titulo">
						<?php
                        	Control::titulo();
                    	?>
					</section>
				</header><!-- /header -->
				<nav class = "menu">
					<?php
	                    Control::menu();
	                ?>
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
							<form action="<?php echo $_SERVER['PHP_SEFL'];?>" method="post" accept-charset="utf-8">
							
						<?php
									echo '<article class = "dato">
										<h2>Usuario</h2><input size="20" maxlength="20" type="text" id="nombre" name="nombre" placeholder="nombre">
									</article>
									<article class = "dato">
										<h2>Apellidos</h2><input size="20" maxlength="20" type="text" id="apellidos" name="apellidos" placeholder="apellidos">
									</article>
									<article class = "dato">
										<h2>Nombre Usuario</h2><input size="20" maxlength="20" type="text" id="nick" name="nick" placeholder="nick">
									</article>
									<article class = "dato">
										<h2>Clave</h2><input size="20" maxlength="20" type="password" id="key" name="key" placeholder="******">
									</article>
									<article class = "dato">
										<h2>Ciudad</h2><input size="20" maxlength="20" type="text" id="ciudad" name="ciudad" placeholder="ciudad">
									</article>
									<article class = "dato">
										<h2>Codigo postal</h2><input size ="20" maxlength="20" type="text" id="postal" name="postal" placeholder="18000">
									</article>
									<article class = "dato">
										<h2>Provincia</h2><select name="ciudad">
											<option>Granada</option>
											<option>Sevilla</option>
											<option>Almería</option>
										</select>
									</article>
									<article class = "dato">
										<h2>Email</h2><input size="20" maxlength="200" type="text" id="email" name="email" placeholder="correo">
									</article>
									<article class = "dato">
										<h2>DNI</h2><input size="20" maxlength="20" type="text" id="dni" name="dni" placeholder="dni">
									</article>
									<article class = "dato">
										<h2>Tarjeta de credito</h2><input size="6" maxlength="20" type="text" id="car1" name="car1" placeholder="00">
										<input size="6" maxlength="20" type="text" id="car2" name="car2" placeholder="0000" >
										<input size="2" maxlength="20" type="text" id="car3" name="car3" placeholder="000">
										<input size="6" maxlength="20" type="text" id="car4" name="car4" placeholder="000000">
									</article>
									<article class = "dato">
										<h2>Observaciones</h2><textarea name="comentarios" rows="10" cols="30" maxlength="Escribe aqui tus comentarios"></textarea>
									</article>
									<article class = "dato">
										<h2>Envio:</h2> <input type="radio" id="envio1" name="envio" value="1" ><h2>Mensual</h2> <input type="radio" id="envio2" name="envio" value="2"><h2>Semanal</h2> <input type="radio" id="envio3" name="envio" value="3"><h2>Diario</h2> 
									</article>
									<article class = "dato">
										<input class = "valor" type="checkbox" id="transporte" name="transporte" value="1"><h2>He leido y acepto las condiciones del servicio de suscrípción:</h2>
									</article>
										
									<article class = "botones_login">
                						<input type=image id="boton_aceptar" src="../img/regi_save.png" onclick="validarCamposRegistroUser()"/>
									</article>
								</form>';
							
							if(isset($_POST['envio'])){
	                            $numero2 = count($_POST);
	                            $tags2 = array_keys($_POST); 
	                            $valores2 = array_values($_POST);

	                            // crea las variables y les asigna el valor
	                            for($i=0;$i<$numero2;$i++){ 
	                            $$tags2[$i]=$valores2[$i]; 
	                            }
	                            
	                            echo '<img class = "exito" src="../img/exito.png" alt="">';
	                            Control::almacenarRegistroUser($nombre, $apellidos, $key, $nick, $ciudad, $c_postal, $email, $dni, $car1, $car2, $car3, $car4, $comentarios);
	                        }
						?>
					</article>
				</section>
			</article>
			<aside class = "public">
				<?php                   
                    Control::publicidad();
                ?>
			</aside>
		</section>
		
		<footer class ="pie_pagina">
            <?php               
                Control::aniadir_pie();
            ?>     
        </footer>

	</body>

</html>