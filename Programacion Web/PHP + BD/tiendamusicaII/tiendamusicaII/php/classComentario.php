<?php 
    /**
    * clase para trabajar los comentario de los discos
    */
    class Comentario
    {
        public static $idDisco;
        public static $comentario;

        function __construct($idDiscoTMP, $comentarioTMP){
            $this->idDisco = $idDiscoTMP;
            $this->comentario = $comentarioTMP;
        }
        
} 
?>