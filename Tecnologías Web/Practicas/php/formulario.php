<!DOCTYPE html>
<html>
	<head>
		<link rel="icon" type="image/png" href="../image/formulario.png">
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<link rel="stylesheet" href="../css/styles.css">
		<title>Formulario</title>
		<meta charset="utf-8">
	</head><!-- /head -->

	<body>		
		<?php
		
			include 'class/classFormulario.php';
			include 'system.php';

			System::header('FORMULARIO');

			if(empty($_GET)){
				Formulario::primeraVez();
			}else if(!isset($_GET['nombre'])){
				Formulario::rellenarFormulario();
			}else{
				echo "<form action=\"procesar.php\" method=\"get\" accept-charset=\"utf-8\">
					<input type=\"hidden\" name=\"tipo1\" value=\""; isset($_GET['tipo1']) ? print($_GET['tipo1']) : ""; echo "\">
					<input type=\"hidden\" name=\"tipo2\" value=\""; isset($_GET['tipo2']) ? print($_GET['tipo2']) : ""; echo "\">
					<input type=\"hidden\" name=\"tipo3\" value=\""; isset($_GET['tipo3']) ? print($_GET['tipo3']) : ""; echo "\">
					
					<div><button type=\"submit\">Pulsa para enviar</button></div>

				</form>";
			}

			System::footer();
		?>
	</body>
</html>
