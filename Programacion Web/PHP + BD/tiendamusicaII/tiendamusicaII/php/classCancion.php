
<?php 
    /**
    * clase que contiene toda la informacion de la clase
    */
    class Cancion
    {
        /*
        atributos privativos de la clase
         */
        public $idCancion;
        public $pista;
        public $nombre;
        public $url;

        /*
        constructor por defecto con parametros
         */
        function __construct($idCancioneTMP, $idDiscoTMP, $pistaTMP, $nombreTMP, $urlTMP){
            $this->idCanciones = $idCancioneTMP;
            $this->pista = $pistaTMP;
            $this->nombre = $nombreTMP;
            $this->url = $urlTMP;
        }

    }
?>