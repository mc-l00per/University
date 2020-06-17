
<?php 
    /**
    * clase que contiene toda la informacion de la clase
    */
    class Disco
    {
        /*
        atributos privativos de la clase
         */
        public $idDisco;
        public $nombre;
        public $canciones;
        public $genero;
        public $fecha;
        public $valoracion;
        public $caratula;
        public $comentarios;
        public $url;

        /*
        constructor por defecto con parametros
         */
        function __construct($idDiscoTMP, $nombreTMP, $cancionesTMP, $generoTMP, $fechaTMP, $valoracionTMP, $caratulaTMP, $comentariosTMP, $urlTMP){
            $this->idDisco = $idDiscoTMP;
            $this->nombre = $nombreTMP;
            $this->canciones = $cancionesTMP;
            $this->genero = $generoTMP;
            $this->fecha = $fechaTMP;
            $this->valoracion = $valoracionTMP;
            $this->caratula = $caratulaTMP;
            $this->comentarios = $comentariosTMP;
            $this->url = $urlTMP;
        }

        function generarDiscoObjeto($disco){
            $actual = new Disco();
            $actual->idDisco = $disco->idDisco;
            $actual->nombre = $disco->nombre;
            $actual->canciones = $disco->canciones;
            $actual->genero = $disco->genero;
            $actual->fecha = $disco->fecha;
            $actual->valoracion = $disco->valoracion;
            $actual->caratula = $disco->caratula;
            $actual->comentarios = $disco->comentarios;
            $actual->url = $disco->url;
            return $actual;
        }

    }
?>