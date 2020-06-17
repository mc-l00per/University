CREATE TABLE productos(
  id_producto INTEGER,
  categoria INTEGER NOT NULL,
  nombre_producto VARCHAR(30) NOT NULL,
  fecha_caducidad DATE NOT NULL,
  fecha_ingreso DATE NOT NULL,
  
  PRIMARY KEY(id_producto)
);

CREATE TABLE proveedores(
  id_proveedor INTEGER,
  tel NUMBER(9),
  direccion VARCHAR2(50),
  nombre VARCHAR2(30),
  
  PRIMARY KEY(id_proveedor)
);

CREATE TABLE pedidos(
  id_proveedor INTEGER,
  id_producto INTEGER,
  cantidad_ped INTEGER NOT NULL,
  fecha_pedido DATE NOT NULL,
	
  FOREIGN KEY (id_producto) REFERENCES productos (id_producto),
  FOREIGN KEY (id_proveedor) REFERENCES proveedores (id_proveedor),
  PRIMARY KEY (fecha_pedido,id_producto,id_proveedor)
);

CREATE TABLE suministros(
  id_producto INTEGER,
  id_proveedor INTEGER,
  cantidad_ped INTEGER,
  fecha_sumin DATE,

  FOREIGN KEY(id_producto) REFERENCES productos(id_producto),
  FOREIGN KEY(id_proveedor) REFERENCES proveedores(id_proveedor),
  PRIMARY KEY(id_producto,id_proveedor,fecha_sumin)
);

CREATE TABLE plato(
  nombre_p VARCHAR2(100),
  categoria VARCHAR2(30),
  tipo VARCHAR2(30),
  precio_p NUMERIC(5,2) CHECK(precio_p>=0.0),
  
  PRIMARY KEY(nombre_p)
);

CREATE TABLE mesa(
  id_mesa VARCHAR2(30) PRIMARY KEY 
);

CREATE TABLE menu(
  nombre_m VARCHAR2(100),
  precio_m NUMERIC(5,2) CHECK(precio_m>=0.0),
  
  PRIMARY KEY(nombre_m)
);

CREATE TABLE pedido_cliente(
  id_pedido VARCHAR2(30),
  id_mesa VARCHAR2(30),
  nombre_p VARCHAR2(30),

  FOREIGN KEY (id_mesa) REFERENCES mesa(id_mesa),
  FOREIGN KEY (nombre_p) REFERENCES plato(nombre_p),
  PRIMARY KEY (id_pedido,id_mesa,nombre_p)
);

CREATE TABLE tiene_plato(
  nombre_m VARCHAR2(100),
  nombre_p VARCHAR2(100),

  FOREIGN KEY(nombre_p) REFERENCES plato(nombre_p),
  FOREIGN KEY(nombre_m) REFERENCES menu(nombre_m),
  PRIMARY KEY (nombre_p,nombre_m) 
);

CREATE TABLE ingrediente(
  nombre_p VARCHAR2(100),
  id_producto INTEGER,
  cantidad INTEGER,

  FOREIGN KEY(nombre_p) REFERENCES plato(nombre_p),
  FOREIGN KEY(id_producto) REFERENCES productos(id_producto),
  PRIMARY KEY (nombre_p, id_producto)
);

CREATE TABLE caja(
  cantidad NUMERIC(8,2) CHECK(cantidad >=0.0),

  PRIMARY KEY (cantidad)
);

CREATE TABLE camarero(
  dni VARCHAR(9) PRIMARY KEY,
  nombre VARCHAR2(20)
);

CREATE TABLE atiende(
  fecha DATE,
  turno VARCHAR2(6) CHECK(turno='mañana' or turno='noche'),
  dni VARCHAR(9),
  nombre_p VARCHAR2(100),
  id_pedido VARCHAR2(30),
  id_mesa VARCHAR2(30),

  FOREIGN KEY(id_pedido,id_mesa,nombre_p) REFERENCES pedido_cliente(id_pedido,id_mesa,nombre_p),
  FOREIGN KEY(dni) REFERENCES camarero(dni),
  PRIMARY KEY (Nombre_P,Id_mesa,fecha,turno,dni)
);

CREATE TABLE pagos(
  fecha DATE,
  id_proveedor INTEGER,
  fecha_pedido DATE,
  id_producto INTEGER,
  cantidad NUMBER(7,2),

  FOREIGN KEY(id_producto,id_proveedor,fecha_pedido) REFERENCES pedidos(id_producto,id_proveedor,fecha_pedido),
  PRIMARY KEY(fecha,id_proveedor,fecha_pedido, id_producto)
);

CREATE TABLE cobro(
  fecha DATE,
	nombre_p VARCHAR2(100),
  id_pedido VARCHAR2(30),
	id_mesa VARCHAR2(30),

  FOREIGN KEY(nombre_p,id_pedido,id_mesa) REFERENCES pedido_cliente(nombre_p,id_pedido,id_mesa),
  PRIMARY KEY(fecha,nombre_p,id_pedido,id_mesa)
);

INSERT INTO productos VALUES(1,0,'aceite',to_DATE('20150212','YYYYMMDD'),to_DATE('20140910','YYYYMMDD'));
INSERT INTO productos VALUES(2,1,'tomate',to_DATE('20140920','YYYYMMDD'),to_DATE('20140910','YYYYMMDD'));
INSERT INTO productos VALUES(3,1,'berenjenas',to_DATE('20140819','YYYYMMDD'),to_DATE('20140910','YYYYMMDD'));
INSERT INTO productos VALUES(4,0,'harina',to_DATE('20200212','YYYYMMDD'),to_DATE('20140910','YYYYMMDD'));
INSERT INTO productos VALUES(5,0,'vinagre',to_DATE('20400212','YYYYMMDD'),to_DATE('20140910','YYYYMMDD'));

INSERT INTO proveedores VALUES(1,958457345,'severo_ochoa_3','prov1');
INSERT INTO proveedores VALUES(2,958433345,'carmen sanchez','prov2');
INSERT INTO proveedores VALUES(3,958457845,'av. andalucia 44','prov3');
INSERT INTO proveedores VALUES(4,953476345,'calle ancha','prov4');
INSERT INTO proveedores VALUES(5,958457845,'rio ebro','prov5');

INSERT INTO pedidos VALUES (1,1,22,'10/10/2014');
INSERT INTO pedidos VALUES (2,1,5,'11/10/2014');
INSERT INTO pedidos VALUES (3,5,55,'12/10/2014');
INSERT INTO pedidos VALUES (4,4,56,'13/10/2014');
INSERT INTO pedidos VALUES (5,4,24,'14/10/2014');

INSERT INTO suministros VALUES (1,1,20,SYSDATE);
INSERT INTO suministros VALUES (1,2,2,SYSDATE);
INSERT INTO suministros VALUES (1,3,12,SYSDATE);
INSERT INTO suministros VALUES (1,4,6,SYSDATE);
INSERT INTO suministros VALUES (1,5,90,SYSDATE);

INSERT INTO plato VALUES ('sopa de picadillo', 'primero', 'sopa', 4.5);
INSERT INTO plato VALUES ('crema de calabaza', 'primero', 'ensalada', 4.5);
INSERT INTO plato VALUES ('ensalada de la casa', 'primero', 'ensalada', 6.5);
INSERT INTO plato VALUES ('macarrones con tomate', 'primero', 'pasta', 7.5);
INSERT INTO plato VALUES ('paella', 'primero', 'arroz', 10.5);
INSERT INTO plato VALUES ('pollo en salsa', 'segundo', 'carne', 7.5);
INSERT INTO plato VALUES ('tortilla de patatas', 'segundo', 'tortilla', 9);
INSERT INTO plato VALUES ('pollo empanado con patatas fritas', 'segundo', 'carne', 7.5);
INSERT INTO plato VALUES ('berenjenas rellenas', 'segundo', 'verduras', 10.5);
INSERT INTO plato VALUES ('calamares fritos', 'segundo', 'pescado', 8.5);
INSERT INTO plato VALUES ('cuscus de verduras', 'segundo', 'tortilla', 9.5);
INSERT INTO plato VALUES ('natillas', 'postre', 'postre', 3.5);
INSERT INTO plato VALUES ('flan', 'postre', 'postre', 3.5);
INSERT INTO plato VALUES ('macedonia de frutas', 'postre', 'postre', 3.5);

INSERT INTO mesa VALUES ('mesa 1');
INSERT INTO mesa VALUES ('mesa 2');
INSERT INTO mesa VALUES ('mesa 3');
INSERT INTO mesa VALUES ('mesa 4');
INSERT INTO mesa VALUES ('mesa 5');

INSERT INTO menu VALUES ('menu del dia (1)', 8.5);
INSERT INTO menu VALUES ('menu del dia (2)', 8.5);
INSERT INTO menu VALUES ('menu del dia (3)', 8.5);
INSERT INTO menu VALUES ('menu vegetariano', 8.5);
INSERT INTO menu VALUES ('menu infantil', 7.5);

INSERT INTO tiene_plato VALUES ('menu del dia (1)','sopa de picadillo');
INSERT INTO tiene_plato VALUES ('menu del dia (1)','ensalada de la casa');
INSERT INTO tiene_plato VALUES ('menu del dia (1)','pollo en salsa');
INSERT INTO tiene_plato VALUES ('menu del dia (1)','tortilla de patatas');
INSERT INTO tiene_plato VALUES ('menu del dia (1)','natillas');
INSERT INTO tiene_plato VALUES ('menu del dia (1)','flan');
INSERT INTO tiene_plato VALUES ('menu del dia (2)','crema de calabaza');
INSERT INTO tiene_plato VALUES ('menu del dia (2)','macarrones con tomate');
INSERT INTO tiene_plato VALUES ('menu del dia (2)','berenjenas rellenas');
INSERT INTO tiene_plato VALUES ('menu del dia (2)','pollo en salsa');
INSERT INTO tiene_plato VALUES ('menu del dia (2)','natillas');
INSERT INTO tiene_plato VALUES ('menu del dia (2)','flan');
INSERT INTO tiene_plato VALUES ('menu del dia (3)','paella');
INSERT INTO tiene_plato VALUES ('menu del dia (3)','ensalada de la casa');
INSERT INTO tiene_plato VALUES ('menu del dia (3)','pollo empanado con patatas fritas');
INSERT INTO tiene_plato VALUES ('menu del dia (3)','calamares fritos');
INSERT INTO tiene_plato VALUES ('menu del dia (3)','natillas');
INSERT INTO tiene_plato VALUES ('menu del dia (3)','flan');
INSERT INTO tiene_plato VALUES ('menu vegetariano','crema de calabaza');
INSERT INTO tiene_plato VALUES ('menu vegetariano','ensalada de la casa');
INSERT INTO tiene_plato VALUES ('menu vegetariano','berenjenas rellenas');
INSERT INTO tiene_plato VALUES ('menu vegetariano','cuscus de verduras');
INSERT INTO tiene_plato VALUES ('menu vegetariano','macedonia de frutas');
INSERT INTO tiene_plato VALUES ('menu infantil','sopa de picadillo');
INSERT INTO tiene_plato VALUES ('menu infantil','macarrones con tomate');
INSERT INTO tiene_plato VALUES ('menu infantil','tortilla de patatas');
INSERT INTO tiene_plato VALUES ('menu infantil','pollo empanado con patatas fritas');
INSERT INTO tiene_plato VALUES ('menu infantil','natillas');
INSERT INTO tiene_plato VALUES ('menu infantil','flan');

INSERT INTO pedido_cliente VALUES ('p1','mesa 1','crema de calabaza');
INSERT INTO pedido_cliente VALUES ('p1','mesa 1','berenjenas rellenas');
INSERT INTO pedido_cliente VALUES ('p2','mesa 2','macarrones con tomate');
INSERT INTO pedido_cliente VALUES ('p3','mesa 3','pollo en salsa');
INSERT INTO pedido_cliente VALUES ('p3','mesa 3','crema de calabaza');
INSERT INTO pedido_cliente VALUES ('p3','mesa 3','macedonia de frutas');
INSERT INTO pedido_cliente VALUES ('p4','mesa 1','pollo en salsa');
INSERT INTO pedido_cliente VALUES ('p4','mesa 1','macedonia de frutas');
INSERT INTO pedido_cliente VALUES ('p5','mesa 5','pollo en salsa');

INSERT INTO ingrediente VALUES ('pollo en salsa',1, 1);
INSERT INTO ingrediente VALUES ('berenjenas rellenas',3, 3);
INSERT INTO ingrediente VALUES ('calamares fritos',3, 10);
INSERT INTO ingrediente VALUES ('pollo empanado con patatas fritas',1, 1);
INSERT INTO ingrediente VALUES ('tortilla de patatas',5, 4);

INSERT INTO caja VALUES(1000.00);
UPDATE caja SET cantidad = cantidad + 500;
UPDATE caja SET cantidad = cantidad - 100;
UPDATE caja SET cantidad = cantidad + 50;
UPDATE caja SET cantidad = cantidad + 50;

INSERT INTO camarero VALUES('75453551R','Antonio Flores');
INSERT INTO camarero VALUES('24457840T','Luis Ramirez');
INSERT INTO camarero VALUES('54478795V','Pedro Martin');
INSERT INTO camarero VALUES('32548754F','Carlos Lopez');
INSERT INTO camarero VALUES('74475789C','Francisco Ortega');

INSERT INTO atiende VALUES('10/10/2014','mañana','75453551R','crema de calabaza','p1','mesa 1');
INSERT INTO atiende VALUES('10/10/2014','mañana','75453551R','berenjenas rellenas','p1','mesa 1');
INSERT INTO atiende VALUES('10/10/2014','mañana','75453551R','macarrones con tomate','p2','mesa 2');
INSERT INTO atiende VALUES('10/10/2014','mañana','24457840T','pollo en salsa','p3','mesa 3');
INSERT INTO atiende VALUES('10/10/2014','mañana','24457840T','crema de calabaza','p3','mesa 3');
INSERT INTO atiende VALUES('10/10/2014','mañana','24457840T','macedonia de frutas','p3','mesa 3');
INSERT INTO atiende VALUES('10/10/2014','noche','54478795V','pollo en salsa','p4','mesa 1');
INSERT INTO atiende VALUES('10/10/2014','noche','54478795V','macedonia de frutas','p4','mesa 1');
INSERT INTO atiende VALUES('10/10/2014','noche','32548754F','pollo en salsa','p5','mesa 5');


INSERT INTO cobro VALUES('10/10/2014','crema de calabaza','p1','mesa 1');
INSERT INTO cobro VALUES('10/10/2014','berenjenas rellenas','p1','mesa 1');
INSERT INTO cobro VALUES('10/10/2014','macarrones con tomate','p2','mesa 2');
INSERT INTO cobro VALUES('10/10/2014','pollo en salsa','p3','mesa 3');
INSERT INTO cobro VALUES('10/10/2014','crema de calabaza','p3','mesa 3');
INSERT INTO cobro VALUES('10/10/2014','macedonia de frutas','p3','mesa 3');
INSERT INTO cobro VALUES('10/10/2014','pollo en salsa','p4','mesa 1');
INSERT INTO cobro VALUES('10/10/2014','macedonia de frutas','p4','mesa 1');
INSERT INTO cobro VALUES('10/10/2014','pollo en salsa','p5','mesa 5');

INSERT INTO pagos VALUES('10/10/2014',1,'10/10/2014',1,50);
INSERT INTO pagos VALUES('11/10/2014',2,'11/10/2014',1,80);
INSERT INTO pagos VALUES('12/10/2014',3,'12/10/2014',5,100);
INSERT INTO pagos VALUES('13/10/2014',4,'13/10/2014',4,100);
INSERT INTO pagos VALUES('14/10/2014',5,'14/10/2014',4,60);

/* inserciones para probar los triggers y 
   para comprobar que se muestran bien los movimientos diarios */
   
--INSERT INTO pedido_cliente VALUES ('p5','mesa 5','macedonia de frutas');
--INSERT INTO atiende VALUES('10/10/2014','noche','32548754F','macedonia de frutas','p5','mesa 5');
--INSERT INTO cobro VALUES('10/10/2014','macedonia de frutas','p5','mesa 5');

--INSERT INTO pedidos VALUES (1,1,60,'15/10/2014');
--INSERT INTO pagos VALUES('15/10/2014',1,'15/10/2014',1,60);
