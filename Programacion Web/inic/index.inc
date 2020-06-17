<?php
	class Index{








		/*funcion para crear el titulo del indice*/
		function titulo(){
			echo '<article class ="img">
				<img class = "pequeña_cartel" src="img/head.png" alt="">
			</article>
			<article class ="text_titulo">
				<h1>Music ETTSIT</h1>
			</article>
			<article class = "user">
				<form action="login.php" method="post" accept-charset="utf-8">
					<input size="10" maxlength="20" type="text" name="Usuario" value="user">
					<input size="10" maxlength="20" type="text" name="password" value="********">
					<button class = "botton_aceptar"><img class = "botton" src="img/login.png" alt=""></button>
					<a href="user.html">
						<img class = "botton" src="img/regi.png" alt="">
					</a>
				</form>
			</article>';
		}

		/*funcion para crear los discos que hay en novedades del titulo*/
		function disco($id_disco, $num_com = 10){
			echo '<article class = "caratula">
				<img class = "mediana" src="$ubicacion_car" alt="">
			</article>
			<article class ="comentarios">
				<ol>';
					for($i=0; $i<$num_com; $i++){
						echo '<li>Comentario.</li>';
					}
				echo '</ol>
			</article>
			<article class ="play">
				<a href="$ubicacion_music">
					<img class = "pequeña" src="img/ir_play.png" alt="">
				</a>
			</article>';	
		}
	};
?>