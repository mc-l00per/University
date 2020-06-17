
--este script nos genera todas las tablas que tenemos y sus relaciones

--creamos la tabla para los propietarios del bloque
	CREATE TABLE propietario (
		DNI INTEGER NOT NULL, 
		username VARCHAR2(20), 
		apellidos VARCHAR2(60),
		domicilio VARCHAR2(100),
		telefono VARCHAR2(9),

		PRIMARY KEY (DNI)
	);

--tabla para las zonas comunes
CREATE TABLE zonas_comunes (
  ID_ZONA INTEGER NOT NULL,

  PRIMARY KEY (ID_ZONA)
);

--crear tabla de los datos que contiene una empresa
CREATE TABLE empresa (
	ID_EMPRESA INTEGER GENERATED ALWAYS AS IDENTITY,
	nombre VARCHAR2(30),
	direccion VARCHAR2(100),
	descripcion VARCHAR2(300),		
	telefono VARCHAR2(9),
	mail VARCHAR2(100),

	PRIMARY KEY (ID_EMPRESA)
);

--tabla para registrar las insidencias
CREATE TABLE registrar (
	ID_INCIDENCIA INTEGER GENERATED ALWAYS AS IDENTITY,
	DNI INTEGER,

	FOREIGN KEY (DNI) REFERENCES propietario (DNI),
	PRIMARY KEY (ID_INCIDENCIA)
); 

--tabla para almacenar una incidencia
CREATE TABLE incidencias (
	ID_INCIDENCIA INTEGER,
	ID_ZONA INTEGER,
	ID_EMPRESA INTEGER,
	descripcion VARCHAR2(300),
	fecha_incidencia DATE,

	FOREIGN KEY (ID_ZONA) REFERENCES zonas_comunes (ID_ZONA),
	FOREIGN KEY (ID_EMPRESA) REFERENCES empresa (ID_EMPRESA),
	FOREIGN KEY (ID_INCIDENCIA) REFERENCES registrar (ID_INCIDENCIA),
	PRIMARY KEY (ID_INCIDENCIA)
);

--crea la tabla de la relacion genera Recibo Incidencia
CREATE TABLE generaReciboComunidad (
	ID_RECIBO INTEGER GENERATED ALWAYS AS IDENTITY,
  fecha_incidencia DATE,
  
 	PRIMARY KEY (ID_RECIBO)
);

--crea la tabla de la relacion genera Recibo Incidencia
CREATE TABLE generaReciboIncidencia (
	ID_RECIBO INTEGER GENERATED ALWAYS AS IDENTITY,
 	ID_INCIDENCIA INTEGER,

 	FOREIGN KEY (ID_INCIDENCIA) REFERENCES incidencias (ID_INCIDENCIA),
 	PRIMARY KEY (ID_RECIBO, ID_INCIDENCIA)
);

--creamos la tabla para los recibos
CREATE TABLE recibo (
	ID_RECIBO INTEGER,
	fecha DATE,
	cantidad BINARY_DOUBLE,

	FOREIGN KEY (ID_RECIBO) REFERENCES recibo (ID_RECIBO),
	PRIMARY KEY (ID_RECIBO)
);

--tabla de recibos para saber si esta pagado o no
CREATE TABLE paga (
	DNI INTEGER,
	ID_RECIBO INTEGER,
	
	FOREIGN KEY (DNI) REFERENCES propietario (DNI),
	FOREIGN KEY (ID_RECIBO) REFERENCES recibo (ID_RECIBO),
	PRIMARY KEY (DNI, ID_RECIBO)
);

--estos son los tres tipòs de recibos que tenemos simplemente ponemos un atributo que los identifique

	--tabla para los datos para general un recibo de tipo comunidad
	CREATE TABLE recibo_comunidad (
		ID_RECIBO_COMUNIDAD INTEGER GENERATED ALWAYS AS IDENTITY,
		ID_RECIBO INTEGER NOT NULL, 
		DNI INTEGER,
		direcion_completa VARCHAR2(100), 
		estado CHAR(1), 
		fecha DATE, 
		cantidad_dinero BINARY_DOUBLE,

		FOREIGN KEY (DNI) REFERENCES propietario (DNI),
		FOREIGN KEY (ID_RECIBO) REFERENCES recibo (ID_RECIBO),
		PRIMARY KEY (ID_RECIBO_COMUNIDAD, DNI, ID_RECIBO)
	);

	--tabla para los datos de almacenamiento deun resivo reserva
	CREATE TABLE recibo_reserva (
		ID_RECIBO_RESERVA INTEGER GENERATED ALWAYS AS IDENTITY,
		ID_RECIBO INTEGER NOT NULL,
		DNI INTEGER, 
		ID_ZONA INTEGER, 
		dia_mes_anio VARCHAR2(12), 
		estado CHAR(1), 
		hora TIMESTAMP, 
		cantidad_de_dinero_a_pagar BINARY_DOUBLE,

		FOREIGN KEY (ID_RECIBO) REFERENCES recibo (ID_RECIBO),
		FOREIGN KEY (ID_ZONA) REFERENCES zonas_comunes (ID_ZONA),
		FOREIGN KEY (DNI) REFERENCES propietario (DNI),
		PRIMARY KEY(ID_RECIBO, DNI, ID_ZONA)
	);

	--tabla para los datos de un recibo de mantenimiento
	CREATE TABLE recibo_mantenimiento (
		ID_RECIBO_INCIDENCIA INTEGER GENERATED ALWAYS AS IDENTITY,
		ID_RECIBO INTEGER NOT NULL,
		DNI INTEGER,
		ID_ZONA INTEGER,
		descripcion VARCHAR2(300),
		estado INTEGER,
		fecha_reparacion DATE,
		cantidad_dinero BINARY_DOUBLE,

		FOREIGN KEY (DNI) REFERENCES propietario (DNI),
		FOREIGN KEY (ID_ZONA) REFERENCES zonas_comunes (ID_ZONA),
		PRIMARY KEY(ID_RECIBO, DNI, ID_ZONA)
	);

 
--crea la tabla que almacena la relacion notificación
CREATE TABLE notificacion (
	ID_INCIDENCIA INTEGER,
	ID_EMPRESA INTEGER,

	FOREIGN KEY (ID_INCIDENCIA) REFERENCES incidencias  (ID_INCIDENCIA),
	FOREIGN KEY (ID_EMPRESA) REFERENCES empresa (ID_EMPRESA),
	PRIMARY KEY (ID_INCIDENCIA)  
);
 
--tabla para hacer las reservas
CREATE TABLE haceReserva (
	ID_RESERVA INTEGER GENERATED ALWAYS AS IDENTITY,
	DNI INTEGER,

	FOREIGN KEY (DNI) REFERENCES propietario (DNI),
	PRIMARY KEY (ID_RESERVA)
);

--tabla para almacenar las reservas
CREATE TABLE reservas (
	ID_RESERVA INTEGER,
	ID_ZONA INTEGER,
	DNI INTEGER,
	fecha DATE,
	hora TIMESTAMP,

	FOREIGN KEY (ID_RESERVA) REFERENCES haceReserva (ID_RESERVA),
	FOREIGN KEY (ID_ZONA) REFERENCES zonas_comunes (ID_ZONA),
	FOREIGN KEY (DNI) REFERENCES propietario (DNI),
	PRIMARY KEY (ID_RESERVA)
);

--tabla para ejecuta las insidencias
CREATE TABLE ejecutaReserva (
	ID_RESERVA INTEGER,
	DNI INTEGER,

	FOREIGN KEY (ID_RESERVA) REFERENCES haceReserva (ID_RESERVA),
	FOREIGN KEY (DNI) REFERENCES propietario (DNI),
	PRIMARY KEY (ID_RESERVA)	
);

--tabla para tiene recibo Reserva
CREATE TABLE tieneReciboReserva (
	ID_RESERVA INTEGER,
	ID_RECIBO INTEGER,

	FOREIGN KEY (ID_RESERVA) REFERENCES reservas (ID_RESERVA),
	FOREIGN KEY (ID_RECIBO) REFERENCES recibo (ID_RECIBO),
	PRIMARY KEY (ID_RESERVA)
);

--Inserción de propietarios inventados; Único propietario real Alejandro Durán Castro

INSERT INTO PROPIETARIO VALUES ('76644890', 'Alejandro', 'Duran Castro', 'Plaza de Gracia nº 1 Piso 602, Granada, 18002', '617094756');
INSERT INTO PROPIETARIO VALUES ('58431856', 'Pepito', 'García', 'Plaza de Gracia nº 1 Piso 101, Granada, 18002', '567894625');
INSERT INTO PROPIETARIO VALUES ('52186545', 'Juanito', 'González', 'Plaza de Gracia nº 1 Piso 102, Granada, 18002', '145878965');
INSERT INTO PROPIETARIO VALUES ('48596325', 'Miguelito', 'Casas', 'Plaza de Gracia nº 1 Piso 103, Granada, 18002', '123456789');
INSERT INTO PROPIETARIO VALUES ('66666666', 'La tetu (Carmen)', 'Pechotes', 'Plaza de Gracia nº 1 Piso 6 104, Granada, 18002', '145263987');
INSERT INTO PROPIETARIO VALUES ('56987456', 'Tete', 'Cani', 'Plaza de Gracia nº 1 Piso 105, Granada, 18002', '475689321');
INSERT INTO PROPIETARIO VALUES ('47568522', 'Daniel', 'Sidonio', 'Plaza de Gracia nº 1 Piso 106, Granada, 18002', '456893214');
INSERT INTO PROPIETARIO VALUES ('45588666', 'Aurelio', 'Fernández', 'Plaza de Gracia nº 1 Piso 107, Granada, 18002', '436897156');
INSERT INTO PROPIETARIO VALUES ('78134588', 'Jesús', 'de Dios', 'Plaza de Gracia nº 1 Piso 6 108, Granada, 18002', '423100589');
INSERT INTO PROPIETARIO VALUES ('14255523', 'Soraya', 'Arcos', 'Plaza de Gracia nº 1 Piso 6 109, Granada, 18002', '478963215');

























