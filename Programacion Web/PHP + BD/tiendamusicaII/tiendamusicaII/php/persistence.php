
<?php
    /**
     * Dependencias de la clase
     */
    include('classCancion.php');
    include('classDisco.php');

    /**
    * clase que se encargara de las consultas a la base de datos
    */
    class Persistence
    {
        /**
         * datos miembros a los que le consultaremos la informacion
         */
        private static $discos;
        
        /**
         * constructor por defecto sin parametros
         */
        function __construct(){
        }
        
        private function conectar(){
            $host='localhost';
            $dsn = 'db74725175';
            $user = 'x74725175';
            $key = 'x74725175';
            $DB_DSN = 'mysql:host=localhost;dbname=db74725175';
            
            $conexion = mysqli_connect($host, $user, $key, $dsn) or exit ('Error al conectar la base de datos.');
           
            return $conexion;
        }

        static function conectarUser(){
            $user = 'x74725175';
            $key = 'x74725175';
            $DB_DSN = 'mysql:host=localhost;dbname=db74725175';
            try { 
                $conexion = new PDO( $DB_DSN, $user, $key ); 
                // Se permite a PHP que mantenga la conexión MySQL abierta para
                // que se emplee en otras partes de la aplicación.
                $conexion->setAttribute( PDO::ATTR_PERSISTENT, true ); 
                $conexion->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION ); 
            } catch ( PDOException $e ) { 
                die( "Conexión fallida: " . $e->getMessage() ); 
            } 
            return $conexion;
        }

        private function desconectar($conexion){
            mysqli_close($conexion);
        }

        static function desconectarUser($conexion){
            $conexion=NULL;
        }

        public static function obtenerDatosDescendentemente($nameTable, $atributo, $cantidadResultaros=null){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT idDisco FROM ".$nameTable." ORDER BY ".$atributo." DESC LIMIT ".$cantidadResultaros;
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);
            
            if ($filas > 0) {
                for ($i=0; $i < $cantidadResultaros; $i++) { 
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $resultadoTMP[]=$resultado['idDisco'];
                }
            }

            $resultado=$resultadoTMP;

            Persistence::desconectar($conexion);
            
            return $resultado;
        }

        public static function obtenerDatosAscendente($nameTable, $atributo, $cantidadResultaros=null){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT idDisco FROM ".$nameTable." ORDER BY ".$atributo." DESC LIMIT ".$cantidadResultaros;
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);
            
            if ($filas > 0) {
                for ($i=0; $i < $cantidadResultaros; $i++) { 
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $resultadoTMP[]=$resultado['idDisco'];
                }
            }

            $resultado=$resultadoTMP;
            
            Persistence::desconectar($conexion);

            return $resultado;
        }

        public static function obtenerComentariosDescendentemente($idDisco, $cantidadResultaros){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT comentario FROM comentarios WHERE idDisco = ".$idDisco." ORDER BY comentario DESC LIMIT ".$cantidadResultaros;
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);
            if ($filas > 0) {
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                for ($i=0; $i < $cantidadResultaros; $i++) { 
                    $resultadoTMP[]=$resultado['comentario'];          
                }
            }

            $resultado=$resultadoTMP;

            Persistence::desconectar($conexion);
            
            return $resultado;
        }

        public static function obtenerNoticiasDescendentemente($cantidadResultaros){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT comentario FROM comentarios ORDER BY comentario DESC LIMIT ".$cantidadResultaros;
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);
            if ($filas > 0) {
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                for ($i=0; $i < $cantidadResultaros; $i++) { 
                    $resultadoTMP[]=$resultado['comentario'];          
                }
            }

            $resultado=$resultadoTMP;

            Persistence::desconectar($conexion);
            
            return $resultado;
        }

        public static function getDiscoID($idDisco){
            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT * FROM disco WHERE idDisco = ".$idDisco;
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);

            if ($filas > 0) {
                $valoracion=0;
                $resultado=mysqli_fetch_assoc($sentenciaSQL);

                $canciones=Persistence::obtenerCanciones($idDisco);

                $comentarios=Persistence::obtenerComentarios($idDisco);

                $disco = new Disco($resultado['idDisco'], $resultado['nombre'], $canciones, $resultado['genero'], $resultado['fecha'], $resultado['valoracion'], $resultado['caratula'], $comentarios, $resultado['url']);

            }

            Persistence::desconectar($conexion);

            return $disco;
        }

        public static function obtenerComentarios($idDisco){
            $comentarios=null;
            return $comentarios;
        }

        public static function obtenerCanciones($idDisco){
            $conexion=Persistence::conectar();

            $consultaSQL = "SELECT * FROM cancion WHERE idDisco = ".$idDisco;
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);
            $filas=mysqli_num_rows($sentenciaSQL);
            
            if ($filas > 0) {
                for ($i=0; $i < $filas; $i++) {
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $idCancion=$resultado['idCancion'];
                    $pista=$resultado['pista'];
                    $nombre=$resultado['nombre'];
                    $url=$resultado['url'];
                    $canciones[]=new Cancion($idCancion, $pista, $nombre, $url);
                }
            }
            else $canciones=null;

            Persistence::desconectar($conexion);

            return $canciones;
        }

        public static function obtenerDatosGeneroDescendentemente($genero, $numeroDiscos){
            $resultado=0;

            $conexion=Persistence::conectar();

            $consultaSQL = "SELECT idDisco FROM disco WHERE genero = ".$genero." ORDER BY fecha DESC LIMIT ".$numeroDiscos;
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);
            
            if ($filas > 0) {
                for ($i=0; $i < $numeroDiscos; $i++) { 
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $resultadoTMP[]=$resultado['idDisco'];
                }
            }
            else $resultadoTMP=null;

            $resultado=$resultadoTMP;

            Persistence::desconectar($conexion);
                        
            return $resultado;
        }

        public static function obtenerDatosGeneroDiscoDescendentemente($genero, $numeroDiscos){
            $resultado=0;

            $conexion=Persistence::conectar();

            $consultaSQL = "SELECT idDisco FROM disco WHERE genero = '".$genero."' ORDER BY fecha DESC LIMIT ".$numeroDiscos;
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);

            if ($filas > 0) {
                for ($i=0; $i < $numeroDiscos; $i++) { 
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $resultadoTMP[]=$resultado['idDisco'];
                }
            }
            else $resultadoTMP=null;

            $resultado=$resultadoTMP;

            Persistence::desconectar($conexion);
                        
            return $resultado;
        }

        function masValorado($genero){
            $resultado=0;

            $conexion=Persistence::conectar();

            $consultaSQL = "SELECT idDisco FROM disco ORDER BY valoracion DESC LIMIT 1";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);

            if ($filas > 0) {
                $resultado=mysqli_fetch_assoc($sentenciaSQL);
                $resultadoTMP=$resultado['idDisco'];
            }
            else $resultadoTMP=null;

            $resultado=$resultadoTMP;

            Persistence::desconectar($conexion);
                        
            return $resultado;
        }

        function discosMasValorado($genero, $num_disco){
            $resultado=0;

            $conexion=Persistence::conectar();

            $consultaSQL = "SELECT idDisco FROM disco ORDER BY valoracion DESC LIMIT ".$num_disco;
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);

            if ($filas > 0) {
                $resultado=mysqli_fetch_assoc($sentenciaSQL);
                $resultadoTMP=$resultado['idDisco'];
            }
            else $resultadoTMP=null;

            $resultado=$resultadoTMP;

            Persistence::desconectar($conexion);
                        
            return $resultado;
        }

        function almacenarRegistroDisco($nombre, $genero, $fecha, $caratula, $url, $valoracion, $canciones, $pistas, $urls){
            $conexion=Persistence::conectar();
            $consultaSQL = "INSERT INTO db74725175.disco (`idDisco`,`nombre`, `genero`, `fecha`, `caratula`, `url`, `valoracion`) VALUES (NULL,'".$nombre."', '".$genero."', '".$fecha."', '".$caratula."', '".$url."', '".$valoracion."');";
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);
            Persistence::desconectar($conexion);

            $conexion=Persistence::conectar();
            $consultaSQL="SELECT MAX(idDisco) AS idDisco FROM disco";
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);
            $filas=mysqli_num_rows($sentenciaSQL);

            if ($filas > 0) {
                $resultado=mysqli_fetch_assoc($sentenciaSQL);
                $idDisco=$resultado['idDisco'];
            }
            Persistence::desconectar($conexion);

            for ($i=0; $i < count($canciones)-1; $i++) { 
                $conexion=Persistence::conectar();
                $consultaSQL= "INSERT INTO db74725175.cancion (`idCancion`,`idDisco`, `pista`, `nombre`, `url`) VALUES (NULL,'".$idDisco."', '".$pistas[$i]."', '".$canciones[$i]."', '".$urls[$i]."');";
                $sentenciaSQL=mysqli_query($conexion, $consultaSQL);
                Persistence::desconectar($conexion);
            }
        }

        function generarComentariosTMP(){
            $conexion=Persistence::conectar();

            $consultaSQL = "SELECT * FROM disco";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);
            $filas=mysqli_num_rows($sentenciaSQL);
            
            if ($filas > 0) {
                for ($i=0; $i < $filas; $i++) {
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $idDiscos[]=$resultado['idDisco'];
                }
            }
            else $canciones=null;

            Persistence::desconectar($conexion);
            

            for ($i=0; $i < count($idDiscos); $i++) {
                for ($j=0; $j < 20; $j++) { 
                    $conexion=Persistence::conectar();    
                    $consultaSQL= "INSERT INTO db74725175.comentarios (`idDisco`, `comentario`) VALUES ('".$idDiscos[$i]."', 'Comentarios.');";
                    $sentenciaSQL=mysqli_query($conexion, $consultaSQL);
                    Persistence::desconectar($conexion);
                }
            }
        }

        function generarComentarios($idDisco){
            for ($j=0; $j < 20; $j++) { 
                $conexion=Persistence::conectar();    
                $consultaSQL= "INSERT INTO db74725175.comentarios (`idDisco`, `comentario`) VALUES ('".$idDiscos[$i]."', 'Comentarios.');";
                $sentenciaSQL=mysqli_query($conexion, $consultaSQL);
                Persistence::desconectar($conexion);
            }
        }

        function almacenarRegistroUser($usuario, $apellidos, $keys, $nick, $ciudad, $c_postal, $email, $dni, $car1, $car2, $car3, $car4, $comentarios){
            $conexion=Persistence::conectar();
            $consultaSQL = "INSERT INTO db74725175.user (`idUser`, `usuario`, `apellidos`, `key`, `nick`, `ciudad`, `c_postal`, `email`, `dni`, `car1`, `car2`, `car3`, `car4`, `comentarios`) VALUES (NULL, '".$usuario."', '".$apellidos."', '".$keys."', '".$nick."', '".$ciudad."', '".$c_postal."','".$email."', '".$dni."', '".$car1."', '".$car2."', '".$car3."', '".$car4."', '".$comentarios."');";
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);
            Persistence::desconectar($conexion);
        }

        public static function login($usuario,$pass){
            $conexion = Persistence::conectarUser();
                
            $consultaSQL = "SELECT * FROM `user` WHERE `usuario` = :usuario AND `key` = :key ";
            try{
                $sentenciaSQL = $conexion->prepare($consultaSQL);
                $sentenciaSQL->bindValue(':usuario',$usuario,PDO::PARAM_STR);
                $sentenciaSQL->bindValue(':key',$pass,PDO::PARAM_STR);
                $sentenciaSQL->execute();
                $result = $sentenciaSQL->fetch();
                
                Persistence::desconectarUser($conexion);
                
                if($result){
                    session_start();
                    $_SESSION['usuario']=$usuario;
                }

            }catch(PDOException $e){
                Persistence::desconectarUser($conexion);
                die("Consulta fallida: ".$e->getMessage());
            }
        }

        public static function getNombreUsuario($usuario){
            $conexion = Persistence::conectarUser();
            
            $consultaSQL = "SELECT * FROM user WHERE usuario = :usuario";
            
            try{
                $sentenciaSQL = $conexion->prepare($consultaSQL);
                $sentenciaSQL->bindValue(":usuario",$usuario,PDO::PARAM_STR);
                $sentenciaSQL->execute();
                $result = $sentenciaSQL->fetch();
                
                Persistence::desconectarUser($conexion);
                
                if($result)
                    return $result["nick"];
                else
                    return NULL;
            }catch(PDOException $e){
                Persistence::desconectarUser($conexion);
                die("Consulta fallida: ".$e->getMessage());
            }
        }

        public static function existeUsuario($usuario,$email){
            $conexion = Persistence::conectarUser();
            
            $consultaSQL = "SELECT * FROM user WHERE usuario = :usuario OR email = :email";
            
            try{
                $sentenciaSQL = $conexion->prepare($consultaSQL);
                $sentenciaSQL->bindValue(":usuario",$usuario,PDO::PARAM_STR);
                $sentenciaSQL->bindValue(":email",$correo,PDO::PARAM_STR);
                $sentenciaSQL->execute();
                $result = $sentenciaSQL->fetch();
                
                Persistence::desconectarUser($conexion);
                
                if($result)
                    return true;
            }catch(PDOException $e){
                Persistence::desconectarUser($conexion);
                die("Consulta fallida: ".$e->getMessage());
            }
        }

        function getIdDiscoNombre($nombre){
            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT `idDisco` FROM disco WHERE nombre = '".$nombre."'";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);
            echo $consultaSQL;
            $filas=mysqli_num_rows($sentenciaSQL);

            if ($filas > 0) {
                $valoracion=0;
                $resultado=mysqli_fetch_assoc($sentenciaSQL);
                $idDisco=$resultado['idDisco'];
            }

            Persistence::desconectar($conexion);

            return $idDisco;
        }

        function insertarComentario($idDisco, $comentarios){
            $conexion=Persistence::conectar();
            $consultaSQL = "INSERT INTO db74725175.comentarios (`idDisco`, `comentario`) VALUES ('".$idDisco."', '".$comentarios."');";
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);
            Persistence::desconectar($conexion);
        }

    }

?>