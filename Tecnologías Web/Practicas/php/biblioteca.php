<!DOCTYPE html>
<html>
	<head>
		<link rel="icon" type="image/png" href="../image/biblioteca.png">
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<link rel="stylesheet" href="../css/styles.css">
		<title>Biblioteca</title>
		<meta charset="utf-8">
	</head><!-- /head -->

	<body>
		<?php
		
			include 'class/classBiblioteca.php'; 
			include 'system.php';

			System::header('BIBLIOTECA');
			
			if(empty($_GET)){
				Biblioteca::primeraVez();
			}else {
				Biblioteca::mostrarScrapingPhp();
			}

			System::footer();
		?>
	</body>
</html>
