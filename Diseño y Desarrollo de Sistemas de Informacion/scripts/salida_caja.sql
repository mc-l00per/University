create or replace TRIGGER salida
AFTER INSERT ON pagos 
FOR EACH ROW
BEGIN
 	UPDATE caja SET cantidad = cantidad - :new.cantidad;
END;