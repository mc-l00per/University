<?php

	/**
	 * objeto para los discos
	 */
	class Disco	{
		public $idDisco;
		public $foto;
		public $anio;
		public $listaCanciones;
		public $precio;
		public $urlCompra;

		function Disco($idDisco, $foto, $anio, $precio, $urlCompra){
			$this->idDisco=$idDisco;
			$this->foto=$foto;
			$this->anio=$anio;
			$this->precio=$precio;
			$this->urlCompra=$urlCompra;
			$this->listaCanciones=Persistence::obtenerListaCanciones($idDisco);
		}
	}

	/**
	 * Objetos para las canciones
	 */
	class Canciones {
		public $indice;
		public $titulo;
		public $duracion;

		function Canciones($indice, $titulo, $duracion){
			$this->indice=$indice;
			$this->titulo=$titulo;
			$this->duracion=$duracion;
		}
	}

	/**
	 * Objetos de tipo concierto
	 */
	class Conciertos{
		public $fecha;
		public $hora;
		public $lugar;
		public $descripcion;
		public $urlCompra;

		function Conciertos($fecha, $hora, $lugar, $descripcion, $urlCompra){
			$this->fecha=$fecha;
			$this->hora=$hora;
			$this->lugar=$lugar;
			$this->descripcion=$descripcion;
			$this->urlCompra=$urlCompra;
		}
	}

	/**
	 * Objeto para los usuarios que interactuan con la web
	 */
	class Usuario {
		public $nombre;
		public $apellidos;
		public $telefono;
		public $email;
		public $login;

		function Usuario($nombre, $apellidos, $telefono, $email, $login) {
			$this->nombre=$nombre;
			$this->apellidos=$apellidos;
			$this->telefono=$telefono;
			$this->email=$email;
			$this->login=$login;
		}
	}

	/**
	 * objetos para poder editar y mostrar los apartados de la bibliografia 
	 */
	class Bibliografia {
		public $fecha;
		public $idBibliografia;
		public $texto;

		function Bibliografia($fecha, $idBibliografia, $texto) {
			$this->fecha=$fecha;
			$this->idBibliografia=$idBibliografia;
			$this->texto=$texto;
		}
	}

	/**
	 * Componente del grupo
	 */
	class Componente {
		public $nombre;
		public $fecha;
		public $lugarNacimiento;
		public $foto;
		public $bibliografia;
		public $idComponentes;

		function Componente($nombre,$fecha,$foto,$lugarNacimiento,$bibliografia,$idComponentes) {
			$this->nombre=$nombre;
			$this->fecha=$fecha;
			$this->lugarNacimiento=$lugarNacimiento;
			$this->foto=$foto;
			$this->bibliografia=$bibliografia;
			$this->idComponentes=$idComponentes;
		}
	}

?>