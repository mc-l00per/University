create or replace PROCEDURE cajaDiaria(fecha_buscada in DATE) AS

  CURSOR salidas IS SELECT id_proveedor, id_producto, cantidad FROM pagos
    WHERE fecha=fecha_buscada;
      
  CURSOR entradas IS select id_pedido, precio_p from plato, cobro
  where cobro.fecha=fecha_buscada and plato.nombre_p = cobro.nombre_p;
    
  prov INTEGER;
  prod INTEGER;
  ped VARCHAR2(30);
  ent NUMERIC(7,2);
  sal NUMERIC(7,2);
  totalEntradas NUMERIC(7,2);
  totalSalidas NUMERIC(7,2);
  totalCaja NUMERIC(7,2);
BEGIN
  totalEntradas :=0;
  totalSalidas := 0;
  SELECT cantidad INTO totalCaja FROM caja;
  
  dbms_output.put_line('entradas de dinero el dia: ' || to_char(fecha_buscada));
  OPEN entradas;
  LOOP
  FETCH entradas INTO ped, ent;
  EXIT WHEN entradas%NOTFOUND;
    dbms_output.put_line('pedido de comida: ' || ped || ' ' || to_char(ent) || ' €');
    totalEntradas := totalEntradas + ent;
  END LOOP;
  
  dbms_output.put_line(' ');
  dbms_output.put_line('salidas de dinero el dia: ' || to_char(fecha_buscada));
  OPEN salidas;
  LOOP 
  FETCH salidas INTO prov, prod, sal;
  EXIT WHEN salidas%NOTFOUND;
    dbms_output.put_line('pago: proveedor-> ' || to_char(prov) || ', producto-> ' || to_char(prod) || ', ' || to_char(sal)|| ' €');
    totalSalidas := totalSalidas + sal;
  END LOOP;
  
  dbms_output.put_line(' ');
  dbms_output.put_line('movimientos totales el dia: ' || to_char(fecha_buscada) );
  dbms_output.put_line('total de entradas de dinero: ' || to_char(totalEntradas) || ' €');
  dbms_output.put_line('total de salidas de dinero: ' || to_char(totalSalidas) || ' €');
  dbms_output.put_line('total en la caja: ' || to_char(totalCaja) || ' €');
  
  CLOSE entradas;
  CLOSE salidas;
  
END cajaDiaria;