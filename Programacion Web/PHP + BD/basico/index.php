<head>
	<title>PHP + BD</title>	
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
</head>

<body>

<?php
$usuario = "USUARIO";
$contrasena = "CONTRASENA";


try {
	// Abrir conexion
    $conexion­ = new PDO('mysql:host=localhost;dbname=DBNAME', $usuario, $contrasena);
    
    // Consultar valores
    $resultados = $conexion­->query('SELECT * from FRUTAS');
    echo '<table class="table table-striped table-bordered" style="width: 50%">';
	foreach ( $resultados as $fila ) {
		echo "<tr>";
		echo "<td>nombre</td>";
		echo "<td>". $fila["NOMBRE"] . "</td>" ;		
		echo "<tr>";
		echo "<td>color</td>";
		echo "<td>" . $fila["COLOR"] . "</td>"; 		
		echo "</tr>";
	}
	echo "</table>";

	echo "<hr/>";

	// Consultar valores utilizando marcadores de parametros
	$consultaSQL  = "SELECT * FROM FRUTAS WHERE COLOR = :color";
	$sentenciaSQL = $conexion­->prepare($consultaSQL);

	$color = "verde";
	$sentenciaSQL->bindValue(":color", $color, PDO::PARAM_STR );
	$sentenciaSQL->execute();

	foreach ($sentenciaSQL->fetchAll() as $fruta ) {
		echo "nombre = " . $fruta["NOMBRE"] . "<br />";
		echo "color = " . $fruta["COLOR"] . "<br />";
	}

	echo "<hr/>";
	
	// Cerrar conexion
    $mbd = null;

} catch (PDOException $e) {
    print "¡Error!: " . $e->getMessage() . "<br/>";
    die();
}
?>

</body>