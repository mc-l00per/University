CREATE or REPLACE PROCEDURE recibo_comuny (cantidad in BINARY_DOUBLE) AS

  CURSOR vecinos IS SELECT DNI FROM propietario;
  
  CANTIDAD_FINAL BINARY_DOUBLE;
  ent INTEGER;
  NUM_RECIBO INTEGER;
  fecha_a DATE;
  dni_u INTEGER;
  direccion varchar2(100);
  
BEGIN
  INSERT INTO generaReciboComunidad(fecha_incidencia) VALUES (sysdate());
  SELECT ID_RECIBO, fecha_INCIDENCIA INTO NUM_RECIBO, fecha_a FROM generaReciboComunidad;

  INSERT INTO RECIBO VALUES (NUM_RECIBO, fecha_a, cantidad);
  
  OPEN vecinos;
  
    LOOP
      FETCH vecinos INTO ent;
      EXIT WHEN vecinos%NOTFOUND;
      
      cantidad_FINAL := cantidad/ent;      
    END LOOP;
    
    LOOP
      FETCH vecinos INTO ent;
        SELECT DNI, domicilio INTO DNI_U, direccion FROM PROPIETARIO;
        INSERT INTO RECIBO_COMUNIDAD(ID_RECIBO, DNI, DIRECION_COMPLETA, FECHA, CANTIDAD_DINERO) VALUES (NUM_RECIBO, DNI_U, direccion, fecha_a, cantidad);
      EXIT WHEN vecinos%NOTFOUND;
          
    END LOOP;
CLOSE vecinos;
  
  
END recibo_comuny;