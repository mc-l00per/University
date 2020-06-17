<?php 
	
	include 'php/dispatcher.php';
	
	session_start();

	System::head();
	
	if (isset($_SESSION['usuario'])){
        System::headerLoginOn($_SESSION['usuario']);	
		System::menu(Control::obtenerTipoUsuario($_SESSION['usuario']));
		if (isset($_GET['ver'])) {
			System::web($_GET['ver']);
			echo $_GET['ver'];
		}                 
    } else {                
        System::headerLoginOff();	
		System::menu('anonymous');
		System::web($_GET['ver']);
    }

	System::footer();

?>