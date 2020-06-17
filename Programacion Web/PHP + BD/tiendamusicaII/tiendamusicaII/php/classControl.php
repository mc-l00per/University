
<?php 
    include ('persistence.php');
    error_reporting(0);

    /**
    * clase que controla las consultas de la web a la persistence
    */
    class Control
    {

        function ultimosDiscos($numeroDiscos){
            $idDiscos = Persistence::obtenerDatosDescendentemente("disco", "fecha", $numeroDiscos);
            $resultado = array();
            for ($i=0; $i < $numeroDiscos; $i++) { 
                $idDisco=$idDiscos[$i];
                $resultado[$i]=Persistence::getDiscoID($idDisco);
            }
            return $resultado;
        }

        function obtenerIdDeDisco($nombre){
            $disco=new Disco;
            $disco=Persistence::getIdDiscoNombre($nombre);
            return $disco;
        }

        function insertarComentario($idDisco, $comentarios){
            Persistence::insertarComentario($idDisco, $comentarios);
        }

        function obtenerIdDisco($idDisco){
            $disco=new Disco;
            $disco=Persistence::getDiscoID($idDisco);
            return $disco;
        }

        function obtenerComentarios($idDisco, $num_com){
            $comentarios=Persistence::obtenerComentariosDescendentemente($idDisco, $num_com);
            return $comentarios; 
        }
        
        function obtenerNoticias($num_com){
            $comentarios=Persistence::obtenerNoticiasDescendentemente($num_com);
            return $comentarios; 
        }

        /*funcion para general el titulo de la web*/
        function titulo(){
            echo '<article class ="img">
                <img class = "pequeña_cartel" src="../img/head.png" alt="">
            </article>
            <article class ="text_titulo">
                <h1>Music ETTSIT</h1>
            </article>
            <article class = "user">';
                if (isset($_SESSION['usuario'])){
                    $usuario = $_SESSION['usuario'];;
                    echo "<asside class='login'><strong><h1>Bienvenido:</strong> ".Control::getNombreUsuario($usuario)."</h1></asside>";
                    echo "
                        <p id='ident'> <a href='./logout.php'> <button class = \"botton_aceptar\"><img class = \"botton\" src=\"../img/logout.png\" alt=\"\"></a></button> </p> ";
                } else {
                    
                    echo"<form action='login.php' method='POST' left  >";
                    echo"<p><input type = 'text' id = 'usuario' name='usuario' placeholder='usuario'  /></p> ";
                    echo"<p><input type = 'password' id = 'contrasena' name='contrasena' placeholder='********'  /></p>";
                    echo"<button class = \"botton_aceptar\"><img class = \"botton\" src=\"../img/login.png\" alt=\"\"></button>";
                    echo '<a href="user.php">
                            <img class = "botton" src="../img/regi.png" alt="">
                        </a>';
                    echo"</form>";
                }
            echo '</article>';
        }
        
        /*funcion para general el menu de la web*/
        function menu(){
            echo '<ul class ="nav">
                <li><a href="index.php?tipo=\'pop\'&tipo2=\'pop\'">Generos</a>
                    <ul>
                        <li><a href="genero.php?genero=rock">Rock</a></li>
                        <li><a href="genero.php?genero=pop">Pop</a></li>
                    </ul>
                </li>
                <li><a href="#">Más Vendido</a></li>
                <li><a href="#">Más comentados</a></li>';
                if($_SESSION){
                    echo '<li><a href="comentarios.php">Ingresar Comentario</a></li>';
                    if($_SESSION['usuario']=='admin')
                        echo '<li><a href="registrarDisco.php">Ingresar Disco Nuevo</a></li>';
                }
            echo '</ul>';
        }
        
        /*funcion para general el pie de la web*/
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
                    <img class = "pequeña" src="../img/ugr.png" />                 
                </section>
            </article>
            <article>
                <p>Contacto: <a href="mailo:info@ugr.es">UGR</a></p>
                <p>Contacto: <a href="mailo:aralaminos@correo.ugr.es">AUTOR</a></p>
                <p><a href="../como_se_hizo.pdf"><img class = "boton_descargar" src="../img/pdf.gif" alt=""></a></p>
            </article>';
        } 
        
        /*funcion para general el publicidad de la web*/
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
 
        function ultimosDiscosGenero($generoTMP, $numeroDiscos){
            $idDiscos = Persistence::obtenerDatosGeneroDescendentemente($generoTMP, $numeroDiscos);
            $resultado = array();
            for ($i=0; $i < $numeroDiscos; $i++) { 
                $idDisco=$idDiscos[$i];
                $resultado[$i]=Persistence::getDiscoID($idDisco);
            }
            return $resultado;
        }

        function ultimosDiscosGeneroDiscos($generoTMP, $numeroDiscos){
            $idDiscos = Persistence::obtenerDatosGeneroDiscoDescendentemente($generoTMP, $numeroDiscos);
            $resultado = array();
            for ($i=0; $i < $numeroDiscos; $i++) { 
                $idDisco=$idDiscos[$i];
                $resultado[$i]=Persistence::getDiscoID($idDisco);
            }
            return $resultado;
        }

        function masValorado($genero){
            $idDisco=Persistence::masValorado($genero);
            $disco=Persistence::getDiscoID($idDisco);
            return $disco;
        }

        function discosMasValorado($generoTMP, $numeroDiscos){
            $idDiscos = Persistence::discosMasValorado($generoTMP, $numeroDiscos);
            $resultado = array();
            for ($i=0; $i < $numeroDiscos; $i++) { 
                $idDisco=$idDiscos[$i];
                $resultado[$i]=Persistence::getDiscoID($idDisco);
            }
            return $resultado;
        }

        function almacenarRegistroDisco($nombre, $genero, $fecha, $caratula, $url, $valoracion, $canciones, $pistas, $urls){
            Persistence::almacenarRegistroDisco($nombre, $genero, $fecha, $caratula, $url, $valoracion, $canciones, $pistas, $urls);
        }

        function almacenarRegistroUser($usuario, $apellidos, $key, $nick, $ciudad, $c_postal, $email, $dni, $car1, $car2, $car3, $car4, $comentarios){
            Persistence::almacenarRegistroUser($usuario, $apellidos, $nick, $key, $ciudad, $c_postal, $email, $dni, $car1, $car2, $car3, $car4, $comentarios);
        }

        public static function login($usuario,$pass){
            $estado=Persistence::login($usuario,$pass);
            $estado;
        }
        
        public static function getNombreUsuario($usuario){
            $nombre = Persistence::getNombreUsuario($usuario);
            return $usuario;
        }
        
        public static function existeUsuario($usuario,$email){
            $estado=Persistence::existeUsuario($usuario, $email);
            return $estado;
        }

    }
    
?>