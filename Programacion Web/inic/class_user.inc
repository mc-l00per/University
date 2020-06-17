 <?php
	 class User{

	 	/*atributos*/
	 	private $IDuser
	 	private $nick
	 	private $key
	 	private $name
	 	private $apellidos
	 	private $direccion
	 	private $ciudad
	 	private $CP
	 	private $provincia
	 	private $email
	 	private $DNI
	 	private $credit
	 	private $observaciones
	 	private $envio

	 	/*Lista de metodos*/
	 	/*constructor por defecto*/
	 	function __construct(){
	 		$this->IDuser="";
	 		$this->nick="";
	 		$this->key="";
	 		$this->name="";
	 		$this->apellidos="";
	 		$this->direccion="";
	 		$this->ciudad="";
	 		$this->CP="";
	 		$this->provincia="";
	 		$this->email="";
	 		$this->credit="";
	 		$this->observaciones="";
	 		$this->envio="";
	 	}

	 	/*registrar un usuario*/
	 	function registrar($nick, $key, $name, $apellidos, $direccion, $ciudad, $CP, $provincia, $email, $envio){
	 		
	 	}
	 };
?>