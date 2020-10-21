/*Juan Carlos Garfias Tovar, A01652138 */

SELECT COUNT(*) FROM empleado_venta

SELECT MIN(numero_nomina) FROM empleado_venta

SELECT MIN(fecha_ingreso) FROM empleado_venta

Select count (distinct id_tipo_unidad_organizacional) from id_tipo_unidad_organizacional

insert into aplicacion
values(2,'“Aplicación IoT para conocer la geolocalización de
las herramientas móviles del equipo de ventas')

create table tipo_unidad_organizacional(
    id_tipo_unidad_organizacional int(100) NOT NULL,
    id_unidad_organizacional int(100) NOT NULL,
        primary key(id_tipo_unidad_organizacional),
        foreign key(id_tipo_unidad_organizacional) references unidad_organizacional(id_unidad_organizacional)
)

select descripcion 
from modulo 
where modulo.id_modulo in(
    select id_modulo 
    from modulo_puesto 
    where modulo_puesto.id_puesto_empleado in( 
        select id_puesto_empleado_venta 
        from puesto_empleado_venta 
        where puesto_empleado_venta.descripcion = "Especialista de Ingresos" 
    ) 
)

select count(id_sub_modulo)
from sub_modulo_puesto
where sub_modulo_puesto.id_puesto_empleado in (
    select id_puesto_empleado_venta
    from puesto_empleado_venta
     where puesto_empleado_venta.descripcion = "Líder EDT"
)

select nombres, apellido_paterno, apellido_materno, descripcion, fecha_nacimiento,
from empleado_venta emp
inner join puesto_empleado_venta pv on pv.id_puesto_empleado_venta = emp.id_puesto_empleado_venta
where emp.fecha_nacimiento = (select max(fecha_nacimiento) from empleado_venta)