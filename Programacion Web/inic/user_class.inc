<?php
	class user{
		/*Lista de atributos*/
		private $_DNI;
		private $_name;
		private $_surname;
		private $_login;
		private $_key;
		private $_ID_user;

		/*Lista de metodos*/
		function __construct($DNI, $name, $surname, $login, $key){
			_setDNI($DNI);
			_setName($name);
			_setSurname($surname);
			_setLogin($login);
			_setKey($key);
			_setIDUser();
		}

		function _getDNI(){
			return $this->_DNI;
		}

		function _setDNI($DNI){
			$this->_DNI=$DNI;
		}

		function _getName(){
			return $this->_name;
		}

		function _setName($name){
			$this->_name=$name;
		}

		function _getSurname(){
			return $this->_surname;
		}

		function _setSurname($surname){
			$this->_surname=$surname;
		}

		function _getLogin(){
			return $this->_login;
		}

		function _setLogin($login){
			$this->_login=$login;
		}

		function _getKey(){
			return $this->_key;
		}

		function _setKey($key){
			$this->_key=$key;
		}

		function _getIDUser(){
			return $this->_ID_user;
		}

		function _setIDUser(){
			$ID_user;
			$this->_ID_user=$ID_user;
		}
	}
?>