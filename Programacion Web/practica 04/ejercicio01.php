<<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<title>Prueba de php</title>
	<link rel="stylesheet" href="">
</head>
<body>
	
<?php
	/*Bucle for*/
	for ($i=0; $i <= 9 ; $i++) { 
		for ($j=0; $j <=9; $j++) { 
			$result = $i * $j;
			echo "<p>$i x $j = $result <p>\n";
		}
	}

	/*Bucle while*/
	i = 0; j = 0;
	while (i <= 9) {
		while (j <= 9) {
			$result = $i * $j;
			echo "<p>$i x $j = $result <p>\n";
			j++;
		}
		i++;
	}

	/*Bucle do... while*/
	do {
		do {
			$result = $i * $j;
			echo "<p>$i x $j = $result <p>\n";
			j++;
		}while (j<=9);
		i++;
	}while(i<=9);
?>

</body>
</html>
