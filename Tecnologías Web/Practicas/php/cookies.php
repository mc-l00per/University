<!DOCTYPE html>
<html>
	<head>
		<link rel="icon" type="image/png" href="../image/cookies.png">
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<link rel="stylesheet" href="../css/styles.css">
		<title>Cookies</title>
		<meta charset="utf-8">
	</head><!-- /head -->

	<body>		
		<?php
		
			include 'class/classCokies.php';
			include 'system.php';

			System::header('PARTE COOKIES');

			if(empty($_GET)){
				Cookies::primeraVez();
			}else{
				if (isset($_GET['nombre']) && isset($_GET['prenda'])) {
					setcookie('nombre',$_GET['nombre']);
					setcookie('prenda',$_GET['prenda']);
					if ($_GET['nombre'] == '' || $_GET['prenda'] == '') {
						Cookies::error();
						Cookies::primeraVez();
					}else{
						if (!isset($_GET['color'])) {
							Cookies::segundaVez();
						}else{ 
							if ($_GET['color'] == '' || $_GET['talla'] == '') {
								Cookies::error();
								Cookies::segundaVez();
							}
						}
					}
				}else{
					if ($_COOKIE['nombre'] == '' || $_COOKIE['prenda'] == '') {
						Cookies::error();
						Cookies::primeraVez();
					}else{
						if (!isset($_GET['color'])) {
							Cookies::segundaVez();
						}else{ 
							if ($_GET['color'] == '' || $_GET['talla'] == '') {
								Cookies::error();
								Cookies::segundaVez();
							}else{
								Cookies::mostrarDatos();
							}
						}
					}
				}
			}

			System::footer();
		?>
	</body>
</html>
