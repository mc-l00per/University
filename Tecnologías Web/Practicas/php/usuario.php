<!DOCTYPE html>
<html>
	<head>
		<link rel="icon" type="image/png" href="../image/login.png">
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<link rel="stylesheet" href="../css/styles.css">
		<title>Usuario</title>
		<meta charset="utf-8">
	</head><!-- /head -->
		
	<body>
		
		<?php
			
			session_start();

			include 'class/classUser.php';
			include 'system.php';

			System::header('USUARIO');

            if (isset($_SESSION['usuario'])){
                User::sesionIniciada ($_SESSION['usuario']);
                switch (Control::obtenerTipoUsuario($_SESSION['usuario'])) {
                	case 'admin':
                		User::menuAdmin();
                		if(isset($_GET['tipo']))
	                		switch ($_GET['tipo']) {
	                			case 'ver':
	                				echo "mostrar usuario";
	                				break;
	                			
	                			default:
	                				# code...
	                				break;
	                		}
                		break;
                	
                	case 'user':
                		User::menuUser();
                		break;
                }                 
            } else {                
                User::inicioSecion();
            }

			System::footer();

		?>

	</body>
</html>
