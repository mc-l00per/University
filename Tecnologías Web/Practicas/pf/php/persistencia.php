
<?php
    
    /**
    * clase que se encargara de las consultas a la base de datos
    */
    class Persistence{
        
        static private function conectar(){
            $host='localhost';
            $dsn = 'aralaminos1718';
            $user = 'aralaminos1718';
            $key = '4Pt9IgId';
            $DB_DSN = 'mysql:host=localhost;dbname=aralaminos1718';
            
            $conexion = mysqli_connect($host, $user, $key, $dsn) or exit ('Error al conectar la base de datos.');
           
            return $conexion;
        }

        static function conectarUser(){
            $user = 'aralaminos1718';
            $key = '4Pt9IgId';
            $DB_DSN = 'mysql:host=localhost;dbname=aralaminos1718';
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

        static private function desconectar($conexion){
            mysqli_close($conexion);
        }

        static function desconectarUser($conexion){
            $conexion=NULL;
        }

        static function login($usuario,$pass){
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

        static function getNombreUsuario($usuario){
            $conexion = Persistence::conectarUser();
            
            $consultaSQL = "SELECT * FROM user WHERE usuario = :usuario";
            
            try{
                $sentenciaSQL = $conexion->prepare($consultaSQL);
                $sentenciaSQL->bindValue(":usuario",$usuario,PDO::PARAM_STR);
                $sentenciaSQL->execute();
                $result = $sentenciaSQL->fetch();
                
                Persistence::desconectarUser($conexion);
                
                if($result)
                    return $result["usuario"];
                else
                    return NULL;
            }catch(PDOException $e){
                Persistence::desconectarUser($conexion);
                die("Consulta fallida: ".$e->getMessage());
            }
        }

        static function existeUsuario($usuario,$email){
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

        static function obtenerTipoUsuario($nombre){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT tipo FROM user WHERE usuario='".$nombre."'";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);
            $tipo=0;
            if ($filas > 0) {
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $tipo=$resultado['tipo'];
            }

            Persistence::desconectar($conexion);
            
            return $tipo;
        }

        static function listaUsuario(){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT * FROM user";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);

            $lista = array();

            if ($filas > 0) {
                for ($i=0; $i < $filas; $i++) {
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $lista[$i]=new User($resultado['idUser'],$resultado['usuario'],$resultado['apellidos'],$resultado['email'],$resultado['key'],$resultado['tipo']);
                }
            }

            Persistence::desconectar($conexion);
            
            return $lista;
        }

        static function eliminarUsuario($idUser){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "DELETE FROM `user` WHERE `user`.`idUser` = '".$idUser."'";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            Persistence::desconectar($conexion);
        }

        static function insertarUsuario($nombre,$apellidos,$email,$key,$tipo){
            $conexion=Persistence::conectar();
            
            $consultaSQL = "INSERT INTO `user`(`idUser`, `usuario`, `apellidos`, `email`, `key`, `tipo`) VALUES (NULL, '$nombre','$apellidos','$email','$key','$tipo')";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            Persistence::desconectar($conexion);
        }

        static function obtenerComponentes(){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT * FROM componentes";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);

            $lista = array();

            if ($filas > 0) {
                for ($i=0; $i < $filas; $i++) {
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $lista[$i]=new Componente($resultado['nombre'],$resultado['fecha'],$resultado['lugarNacimiento'],$resultado['foto'],$resultado['bibliografia'],$resultado['idComponentes']);
                }
            }

            Persistence::desconectar($conexion);
            
            return $lista;
        }

        static function obtenerBibliografia(){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT * FROM bibliografia";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);

            $lista = array();

            if ($filas > 0) {
                for ($i=0; $i < $filas; $i++) {
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $lista[$i]=new Bibliografia($resultado['fecha'],$resultado['idBibliografia'],$resultado['texto']);
                }
            }

            Persistence::desconectar($conexion);
            
            return $lista;
        }

        static function obtenerDiscos(){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT * FROM disco";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);

            $lista = array();

            if ($filas > 0) {
                for ($i=0; $i < $filas; $i++) {
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $lista[$i]=new Disco($resultado['idDisco'],$resultado['foto'],$resultado['anio'],$resultado['precio'],$resultado['urlCompra']);
                }
            }

            Persistence::desconectar($conexion);
            
            return $lista;
        }

        static function obtenerListaCanciones($idDisco){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT * FROM cancion WHERE `idDisco`='".$idDisco."'";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);

            $lista = array();

            if ($filas > 0) {
                for ($i=0; $i < $filas; $i++) {
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $lista[$i]=new Canciones($resultado['indice'],$resultado['titulo'],$resultado['duracion']);
                }
            }

            Persistence::desconectar($conexion);
            
            return $lista;
        }

        static function obtenerListaConciertos(){
            $resultado=0;

            $conexion=Persistence::conectar();
            
            $consultaSQL = "SELECT * FROM conciertos";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            $filas=mysqli_num_rows($sentenciaSQL);

            $lista = array();

            if ($filas > 0) {
                for ($i=0; $i < $filas; $i++) {
                    $resultado=mysqli_fetch_assoc($sentenciaSQL);
                    $lista[$i]=new Conciertos($resultado['fecha'],$resultado['hora'],$resultado['lugar'],$resultado['descripcion'],$resultado['urlCompra']);
                }
            }

            Persistence::desconectar($conexion);
            
            return $lista;
        }

        static function aniadirComponentes($nombre, $fecha, $lugarNacimiento, $foto, $bibliografia){
            $conexion=Persistence::conectar();
            
            $consultaSQL = "INSERT INTO `componentes`(`idComponentes`, `nombre`, `fecha`, `lugarNacimiento`, `foto`, `bibliografia`) VALUES (NULL, '$nombre','$fecha','$lugarNacimiento','$foto','$bibliografia')";
         
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            Persistence::desconectar($conexion);
        }

        static function editarComponenteS($nombre, $fecha, $lugarNacimiento, $foto, $bibliografia, $idComponentes){
            $conexion=Persistence::conectar();
            
            $consultaSQL = "UPDATE `componentes` SET `nombre`='$nombre',`fecha`='$fecha',`lugarNacimiento`='$lugarNacimiento',`foto`='$foto',`bibliografia`='$bibliografia' WHERE `idComponentes` = '$idComponentes'";
            
            $sentenciaSQL=mysqli_query($conexion, $consultaSQL);

            Persistence::desconectar($conexion);
        }
    }

?>        