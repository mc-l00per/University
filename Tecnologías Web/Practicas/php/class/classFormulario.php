<?php 

	/**
	* Clase para controlar la parte de la web formularios
	* para la parte segunda de la practica
	*/
	class Formulario{
		
		static function primeraVez(){
			echo "<form action=\"formulario.php\" method=\"get\">
				<p id=\"formulario\">Seleciona las tematicas deseadas:</p>
				<fieldset> 
				<legend><p><input type=\"checkbox\" name=\"tipo1\" />Divulgacion</p></legend>
					<p>Sabelotodo</p>
					<p>Solo sé que no sé nada</p>
					<p>Muy interesado</p>
					<p>Ciencia con sabor</p>
				</fieldset>
				<fieldset> 
				<legend><p><input type=\"checkbox\" name=\"tipo2\" />Motor</p></legend>
				<p>Supercoches</p>
				<p>Corre que te pillo</p>
				<p>El más lento de la carretera</p>
				</fieldset>
				<fieldset> 
				<legend><p><input type=\"checkbox\" name=\"tipo3\" />Viajes</p></legend>
					<p>Paraisos del mundo</p>
					<p>Conoce tu ciudad</p>
					<p>La casa de tu vecino: rincones inhóspitos</p>
				</fieldset>
				<div><button type=\"submit\">Pulsa para enviar</button></div>
			</form>";
		}

		static function obtenerListaRevistas(){
			$i=0;

			if($_GET['tipo1'] == 'on'){
				$lista[$i++] = 'Sabelotodo';
				$lista[$i++] = 'Solo se que no se nada';
				$lista[$i++] = 'Ciencia con sabor';
				$lista[$i++] = 'Muy interesado';
			}

			if($_GET['tipo2'] == 'on'){
				$lista[$i++] = 'Supercoches';
				$lista[$i++] = 'Corre que te pillo';
				$lista[$i++] = 'El mas lento de la carretera';
			}

			if($_GET['tipo3'] == 'on'){
				$lista[$i++] = 'Paraisos del mundo';
				$lista[$i++] = 'Conoce tu ciudad';
				$lista[$i++] = 'La casa de tu veciono';
			}

			return $lista;
		}

		static function rellenarFormulario(){
			echo "<form action=\"procesar.php\" method=\"get\" accept-charset=\"utf-8\">
				<input type=\"hidden\" name=\"tipo1\" value=\""; isset($_GET['tipo1']) ? print($_GET['tipo1']) : ""; echo "\">
				<input type=\"hidden\" name=\"tipo2\" value=\""; isset($_GET['tipo2']) ? print($_GET['tipo2']) : ""; echo "\">
				<input type=\"hidden\" name=\"tipo3\" value=\""; isset($_GET['tipo3']) ? print($_GET['tipo3']) : ""; echo "\">

				<fieldset id=\"formulario\" class=\"\">
					<legend>Informacion personal:</legend>
					<label for=\"album\">Nombre:</label><input type=\"text\" name=\"nombre\" value=\"\">
					<label for=\"album\">Apellidos:</label><input type=\"text\" name=\"apellidos\" value=\"\">
					<label for=\"album\">Dirección postal:</label><input type=\"text\" name=\"dp\" value=\"\">
					<label for=\"album\">Fecha de nacimiento:</label><input type=\"text\" name=\"fn\" value=\"\">
					<label for=\"album\">Email:</label><input type=\"text\" name=\"email\" value=\"\">
					<label for=\"album\">Número de CC:</label><input type=\"text\" name=\"num\" value=\"\">
				</fieldset>

				<fieldset id=\"formulario\" class=\"\">
					<legend>Informacion sobre la suscripcion:</legend>
					<label for=\"anio\">Escoge una revista:</label> 
							<select name=\"anio\">
								<option value=\"\" selected=\"tipo\">- Selecciona -</option>";
								$lista = Formulario::obtenerListaRevistas();

								for ($i=0; $i < count($lista); $i++) { 
									echo "<option value=$lista[$i]>$lista[$i]</option>";
								}

							echo "</select><br>
					<label for=\"anio\">Tiempo de compra:</label> 
							<select name=\"anio\">
								<option value=\"\" selected=\"tipo\">- Selecciona -</option>
								<option value=\"anual\">Anual</option>
	  							<option value=\"bianual\">Bianual</option>
							</select>
					<fieldset id=\"tarjeta\" class=\"\">
						<legend><input type=\"radio\" name=\"reembolso\" />Datos de la tarjeta:</legend>
						<div>
							<fieldset id=\"formulario\" class=\"\">
								<legend>Tipo de tarjeta</legend>
									<label for=\"tarjeta\"><input type=\"radio\" id=\"tarjeta\" name=\"tarjeta\" value=\"1\">
			    					Visa</label>
			    					<label for=\"tarjeta\"><input type=\"radio\" id=\"tarjeta\" name=\"tarjeta\" value=\"2\">
			    					MasterCard</label>
			    			</fieldset>		
						</div>

						<div> 
							<label for=\"cod-tarjeta\">Número de tarjeta:</label><input type=\"text\" name=\"cod-tarjeta\" value=\"\"> 
						</div>

						<div>
							<label for=\"mes\">Mes:</label> 
							<select name=\"anio\">
								<option value=\"\" selected=\"tipo\">- Selecciona -</option>";		
								for ($i=1; $i < 13; $i++) { 
									echo "<option value=$i>$i</option>";
								}				
							echo "</select>
						</div>

						<div>
							<label for=\"anio\">Año:</label> 
							<select name=\"anio\">
								<option value=\"\" selected=\"tipo\">- Selecciona -</option>";
								for ($i=2034; $i > 1980; $i--) { 
									echo "<option value=$i>$i</option>";
								}
							echo "</select>
						</div>						
					</fieldset>
					<fieldset id=\"tarjeta\" class=\"\">
						<legend><input type=\"radio\" name=\"reembolso\" value='1' />Reembolso</legend>												
					</fieldset>
				</fieldset>
				
				<fieldset id=\"formulario\" class=\"\">
					<legend>Informacion personal:</legend>
					<label for=\"album\">Temas de interes:</label><br><textarea name='interes'></textarea><br>
					<label for=\"acepta\"><input type=\"checkbox\" name=\"acepta\" value=\"1\"> Quiere recibir publicidad.</label><br>
				</fieldset>


				<div><button type=\"submit\">Pulsa para enviar</button></div>
				</form>";
		}

		static function comprobarFormulario(){

		}

		static function corregirFormulario(){

		}
		
		static function mostrarFormulario(){

		}
	}


?>