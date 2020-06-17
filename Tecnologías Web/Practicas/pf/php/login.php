<?php
	
    ini_set('display_errors', true);
    error_reporting(E_ALL);         
    require_once "dispatcher.php";
    if ((isset($_POST['usuario'])) and (isset($_POST['contrasena']))){
        $usuario = $_POST['usuario'];
        $pass = $_POST['contrasena'];
        Control::login($usuario, $pass);
    }var_dump($_SESSION['usuario']);
    header("Location: ../index.php?ver=''");

?>