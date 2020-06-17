
<?php

    /**
    * clase que se encargara de las consultas a la base de datos
    */
    class Persistence{
        
        private function conectar(){
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

        private function desconectar($conexion){
            mysqli_close($conexion);
        }

        static function desconectarUser($conexion){
            $conexion=NULL;
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
                    return $result["usuario"];
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

        static function obtenerTipoUsuario(){
            
        }
    }

?>        