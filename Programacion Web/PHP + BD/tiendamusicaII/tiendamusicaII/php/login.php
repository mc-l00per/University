<?php        
    ini_set('display_errors', true);
    error_reporting(E_ALL);         
    require_once "classControl.php";
    if ((isset($_POST['usuario'])) and (isset($_POST['contrasena']))){
        $usuario = $_POST['usuario'];
        $pass = $_POST['contrasena'];
        Control::login($usuario, $pass);
    }
    header("Location: ./index.php?tipo='pop'&tipo2='pop'");
?>