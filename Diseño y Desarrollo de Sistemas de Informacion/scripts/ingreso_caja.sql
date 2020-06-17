create or replace TRIGGER entrada
AFTER INSERT ON cobro 
FOR EACH ROW
DECLARE
  cant NUMERIC(7,2);
BEGIN
  SELECT precio_p INTO cant FROM plato
    WHERE nombre_p = :NEW.nombre_p;
    
    UPDATE caja SET cantidad = cantidad + cant;
END;  