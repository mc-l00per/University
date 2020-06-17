<?php 
	require_once ('fruta.class.inc');
	$frutas = Fruta::obtenerFrutas(0, 10, "ID");
	
	foreach ( $frutas[0] as $fruta ) {
		echo 
			$fruta->devolverValor("ID") . " " .
			$fruta->devolverValor("NOMBRE") . " " .
			$fruta->devolverValor("COLOR") . " " .
			$fruta->devolverValor("TIPO") . " " ;
	}
?> 