<?php
	class General{
		/*funcion para general el titulo de la web*/
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

		function menu(){
			echo '<ul class ="nav">
				<li><a href="index.html">Generos</a>
					<ul>
						<li><a href="rock/rock.php">Rock</a></li>
						<li><a href="#">Pop</a></li>
						<li><a href="#">Clasica</a></li>
						<li><a href="#">Reggae</a></li>
						<li><a href="#">Rap</a></li>
					</ul>
				</li>
				<li><a href="#">Más Vendido</a></li>
				<li><a href="#">Más comentados</a></li>
			</ul>';
		}

		function aniadir_pie(){
			echo '<article>
				<section>
					<address> 
						<p> Universidad de Granada </p> 
						<br />Cuesta del Hospicio, s/n 
						<br />Granada, 18071
					</address>	
				</section>
				<section>
					<img class = "pequeña" src="img/ugr.png" /> 				
				</section>
			</article>
			<article>
				<p>Contacto: <a href="mailo:info@ugr.es">UGR</a></p>
				<p>Contacto: <a href="aralaminos@correo.ugr.es">AUTOR</a></p>
				<p><a href="como_se_hizo.pdf"><img class = "boton_descargar" src="img/pdf.gif" alt=""></a></p>
			</article>';
		} 

		function publicidad(){
			echo '<nav>
				<ul>
					<li><a href="http://jenesaispop.com/">Jenesaispop</a></li>	
					<li><a href="http://www.hipersonica.com/">hipersonica</a></li>
					<li><a href="http://indiespot.es/">indiespot</a></li>
					<li><a href="http://www.mondosonoro.com/">mondosonoro</a></li>
					<li><a href="http://www.indiehoy.com/">indiehoy</a></li>
					<li><a href="http://www.indierocks.mx/">indierocks</a></li>	
					<li><a href="http://www.binaural.es/">binaural</a></li>
					<li><a href="http://www.dodmagazine.es/">dodmagazine</a></li>
					<li><a href="http://muzikalia.com/">muzikalia</a></li>
					<li><a href="http://gladyspalmera.com/">gladyspalmera</a></li>
				</ul>
			</nav>';
		}
	}
?>