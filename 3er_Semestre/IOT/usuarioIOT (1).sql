-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 18-10-2020 a las 22:01:15
-- Versión del servidor: 10.4.14-MariaDB
-- Versión de PHP: 7.4.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `iot`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `aplicacion`
--

CREATE TABLE `aplicacion` (
  `id_aplicacion` int(11) NOT NULL,
  `descripcion` varchar(250) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `aplicacion`
--

INSERT INTO `aplicacion` (`id_aplicacion`, `descripcion`) VALUES
(1, 'Módulos de TEC SALUD');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `empleado_venta`
--

CREATE TABLE `empleado_venta` (
  `id_empleado_venta` int(20) NOT NULL,
  `nombres` varchar(100) NOT NULL,
  `apellido_paterno` varchar(100) NOT NULL,
  `apellido_materno` varchar(100) DEFAULT NULL,
  `numero_nomina` int(8) DEFAULT NULL,
  `id_unidad_organizacional_base` int(10) NOT NULL,
  `fecha_ingreso` date NOT NULL,
  `fecha_nacimiento` date NOT NULL,
  `cuenta_correo` varchar(250) DEFAULT NULL,
  `id_empleado_lider_inmediato` int(20) DEFAULT NULL,
  `id_puesto_empleado_venta` int(4) NOT NULL,
  `nombre_completo` varchar(250) DEFAULT NULL,
  `activo` int(1) NOT NULL,
  `es_externo` int(1) DEFAULT NULL,
  `fecha_baja` date DEFAULT NULL,
  `cuenta` varchar(64) DEFAULT NULL,
  `id_perfil` int(2) DEFAULT NULL,
  `numero_nomina_responsable` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `empleado_venta`
--

INSERT INTO `empleado_venta` (`id_empleado_venta`, `nombres`, `apellido_paterno`, `apellido_materno`, `numero_nomina`, `id_unidad_organizacional_base`, `fecha_ingreso`, `fecha_nacimiento`, `cuenta_correo`, `id_empleado_lider_inmediato`, `id_puesto_empleado_venta`, `nombre_completo`, `activo`, `es_externo`, `fecha_baja`, `cuenta`, `id_perfil`, `numero_nomina_responsable`) VALUES
(236751, 'Isaac', 'LUNA', 'Plascencia', 135439, 6, '1994-01-01', '1972-06-03', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564272, 8, NULL, 1, 0, NULL, 'isaac.ortiz', NULL, NULL),
(329609, 'Efren', 'LUNA', 'Flores', 136362, 10, '2009-01-06', '1960-04-09', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564339, 3, NULL, 0, 0, NULL, NULL, NULL, NULL),
(598924, 'Silvia Josefina', 'LUNA', 'Flores', 395347, 43, '1983-04-01', '1974-01-09', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564268, 14, NULL, 1, 0, NULL, 'josefina.gallegos', NULL, NULL),
(815752, 'Elsa', 'LUNA', 'Gonzalez', 393089, 43, '1994-04-01', '1972-11-10', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564268, 9, NULL, 1, 0, NULL, 'elsa.casas', NULL, NULL),
(1029004, 'Maria', 'LUNA', 'Sarabia', 92805, 60, '1984-07-07', '1958-04-29', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564305, 14, NULL, 1, 0, NULL, 'ejtel19', NULL, NULL),
(1262925, 'Daniel Heriberto', 'LUNA', 'Perales', 140326, 26, '2006-01-01', '1975-07-26', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564338, 3, NULL, 1, 0, NULL, 'daniel.flores.perales', NULL, NULL),
(1967204, 'Raul Abraham', 'LUNA', 'Rosas', 148746, 16, '2005-04-16', '1982-07-12', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564324, 8, NULL, 0, 0, NULL, 'ejser22', NULL, NULL),
(2056467, 'Kelvin', 'LUNA', 'Espinoza', 148457, 6, '1999-01-01', '1985-04-03', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564272, 14, NULL, 1, 0, NULL, 'kelvin.calderon', NULL, NULL),
(2102473, 'Rosalba', 'LUNA', 'Ulloa', 326380, 6, '1999-04-01', '1966-06-17', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564272, 14, NULL, 1, 0, NULL, 'rosalba.cardenas', NULL, NULL),
(2113870, 'Daniel', 'LUNA', 'Preciado', 66998, 44, '1995-10-01', '1957-05-12', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564269, 8, NULL, 1, 0, NULL, 'daniel.juarez', NULL, NULL),
(2142212, 'Luis Antonio', 'LUNA', 'Pat', 149353, 111, '2005-10-16', '1973-04-09', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564262, 8, NULL, 1, 0, NULL, 'luis.canul', NULL, NULL),
(2171531, 'Brian Alberto', 'LUNA', 'Ramirez', 142182, 43, '1999-04-01', '1979-08-05', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564268, 8, NULL, 1, 0, NULL, 'brian.gonzalez', NULL, NULL),
(2171535, 'Sergio Arturo', 'LUNA', 'Lopez', 130291, 43, '1993-04-01', '1972-11-27', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564268, 8, NULL, 1, 0, NULL, 'sergio.tovar', NULL, NULL),
(2223789, 'Maria de los Angeles', 'LUNA', 'Ramirez', 3021898, 64, '2000-07-23', '1963-10-24', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564344, 14, NULL, 1, 0, NULL, 'angeles.jimenez', NULL, NULL),
(2223820, 'Gloria Marcela', 'LUNA', 'Zamudio', 137511, 43, '2000-08-01', '1975-08-24', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564268, 14, NULL, 0, 0, NULL, NULL, NULL, NULL),
(2273500, 'Lizzy María de los Angele', 'LUNA', 'Sahagun', 3037085, 60, '2001-02-17', '1982-06-28', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564306, 14, NULL, 1, 0, NULL, 'ejtel44', NULL, NULL),
(2376821, 'Zulma', 'LUNA', 'Mercado', 3054678, 43, '2001-11-27', '1973-11-13', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564268, 14, NULL, 1, 0, NULL, 'zulma.toledo', NULL, NULL),
(2412449, 'Marco Antonio', 'LUNA', 'Montes', 3061437, 43, '2008-06-01', '1978-10-24', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564268, 8, NULL, 1, 0, NULL, 'marco.torres', NULL, NULL),
(2453125, 'Luis Anibal', 'LUNA', 'Cabrera', 3069165, 89, '2002-09-20', '1973-06-17', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564351, 14, NULL, 0, 0, NULL, NULL, NULL, NULL),
(2476816, 'Blanca Nayely', 'LUNA', 'Silva', 3071790, 43, '2003-01-03', '1988-07-10', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564268, 14, NULL, 1, 0, NULL, 'maria.antunez', NULL, NULL),
(2488868, 'Rosamaria', 'LUNA', 'De Hoyos', 3082628, 7, '2003-02-13', '1979-03-24', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564325, 14, NULL, 0, 0, NULL, NULL, NULL, NULL),
(2505499, 'Manuel Alejandro', 'LUNA', 'Gil', 3085724, 6, '2014-04-06', '1983-11-28', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564272, 3, NULL, 0, 0, NULL, NULL, NULL, NULL),
(2548888, 'Jairo Giovanny', 'LUNA', 'Naranjo', 3096820, 43, '2003-09-11', '1992-04-24', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564268, 14, NULL, 0, 0, NULL, NULL, NULL, NULL),
(2549311, 'Lucina Elizabeth', 'LUNA', 'Montoya', 3092693, 30, '2003-08-22', '1991-09-12', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564259, 14, NULL, 0, 0, NULL, NULL, NULL, NULL),
(2564291, 'Juan Carlos', 'LUNA', 'del Río', 3019187, 2, '2005-04-28', '1969-10-26', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564346, 9, NULL, 1, 0, NULL, 'juan.delrio', NULL, NULL),
(2564292, 'Guillermo', 'LUNA', 'Vazquez', 143217, 2, '1978-04-01', '1959-05-16', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564346, 20, NULL, 1, 0, NULL, 'eloisa.gallaga', NULL, NULL),
(2564293, 'Raul Arnoldo', 'LUNA', 'Treviño', 203, 2, '1997-04-01', '1972-01-22', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564346, 16, NULL, 1, 0, NULL, 'cesar.campos', NULL, NULL),
(2564294, 'Jorge Luis', 'LUNA', 'Arroyo', 208, 2, '2000-06-30', '1973-05-04', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564346, 16, NULL, 1, 0, NULL, 'liadm5', NULL, NULL),
(2564295, 'Martín Jaime', 'LUNA', 'Tamez', 329669, 2, '2006-09-29', '1968-04-04', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564346, 9, NULL, 1, 0, NULL, 'martin.tamezt', NULL, NULL),
(2564297, 'Irma Leticia', 'LUNA', 'Cepeda', 1382387, 2, '1981-07-01', '1973-08-04', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564327, 21, NULL, 1, 0, NULL, 'luis.palacios', NULL, NULL),
(2564298, 'Natalie Ruth', 'LUNA', 'Ortíz', 2001347, 2, '2001-07-01', '1987-08-31', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564334, 9, NULL, 0, 0, NULL, NULL, NULL, NULL),
(2564299, 'Hector Gabriel', 'LUNA', 'Hernandez', 148008, 2, '2003-07-01', '1973-09-27', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564334, 9, NULL, 1, 0, NULL, 'hector.gonzalezh', NULL, NULL),
(2564308, 'Martha Guadalupe', 'LUNA', 'Martinez', 419643, 2, '1989-01-06', '1973-05-15', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564341, 9, NULL, 1, 0, NULL, 'martha.castillo', NULL, NULL),
(2564309, 'Ana Isabel', 'LUNA', 'Diaz', 109721, 8, '1990-10-01', '1966-02-20', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564332, 9, NULL, 1, 0, NULL, 'ana.chavez.diaz', NULL, NULL),
(2564310, 'Armando', 'LUNA', 'Badillo', 329169, 5, '1983-06-10', '1965-10-22', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564338, 9, NULL, 1, 0, NULL, 'armando.ortiz', NULL, NULL),
(2564311, 'Perla Patricia', 'LUNA', 'Rodriguez', 134902, 5, '1992-09-01', '1980-01-17', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564338, 9, NULL, 1, 0, NULL, 'PROMOTORIAREY', NULL, NULL),
(2564312, 'Lorena', 'LUNA', 'Robledo', 346509, 20, '1984-01-06', '1965-10-10', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564342, 9, NULL, 1, 0, NULL, 'lorena.meza', NULL, NULL),
(2564313, 'Jorge Luis', 'LUNA', 'Mendoza', 3087896, 40, '2008-07-07', '1989-03-28', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564343, 9, NULL, 1, 0, NULL, 'jorge.castrom', NULL, NULL),
(2564315, 'Irene', 'LUNA', NULL, NULL, 3, '1983-05-07', '1967-03-11', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564280, 9, NULL, 1, 0, NULL, NULL, NULL, NULL),
(2564316, 'Alberto', 'LUNA', 'Garcia', 342087, 3, '1983-11-15', '1967-03-09', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564280, 9, NULL, 1, 0, NULL, 'alberto.martinez', NULL, NULL),
(2564319, 'Gabriela', 'LUNA', 'Zamora', 489595, 92, '1990-07-21', '1962-09-20', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564259, 9, NULL, 1, 0, NULL, 'PROMOTORIAZAM', NULL, NULL),
(2564320, 'Hector Raul', 'LUNA', 'Gonzalez', 3013685, 32, '2005-01-30', '1989-06-23', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564260, 9, NULL, 1, 0, NULL, 'hector.angeles', NULL, NULL),
(2564323, 'Moises', 'LUNA', 'Hernandez', 144296, 16, '2005-02-27', '1968-06-19', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564327, 9, NULL, 1, 0, NULL, 'gerardo.ossio', NULL, NULL),
(2564328, 'Armando', 'LUNA', 'Cano', 356803, 2, '1999-01-01', '1965-05-31', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564334, 9, NULL, 1, 0, NULL, 'armando.garcia', NULL, NULL),
(2564330, 'Zelene', 'LUNA', 'Borboa', 119602, 31, '1991-07-01', '1971-01-24', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564277, 9, NULL, 1, 0, NULL, 'zelene.rojas', NULL, NULL),
(2564336, 'Marivel Cristina', 'LUNA', 'Chavez', 379020, 9, '1988-04-01', '1966-12-17', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564273, 9, NULL, 1, 0, NULL, 'marivel.aguirre', NULL, NULL),
(2564347, 'Alfonso Alberto', 'LUNA', 'Delgado', 147699, 2, '2003-04-16', '1978-07-08', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564346, 9, NULL, 1, 0, NULL, 'alfonso.duran', NULL, NULL),
(2594804, 'Crisantos', 'LUNA', 'Martinez', 140451, 23, '2009-07-21', '1967-07-24', 'equipo.seit.sorteos@servicios.sorteostec.mx', 2564282, 8, NULL, 0, 0, NULL, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `modulo`
--

CREATE TABLE `modulo` (
  `id_modulo` int(11) NOT NULL,
  `descripcion` varchar(250) DEFAULT NULL,
  `id_aplicacion` int(11) DEFAULT NULL,
  `nombre_corto` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `modulo`
--

INSERT INTO `modulo` (`id_modulo`, `descripcion`, `id_aplicacion`, `nombre_corto`) VALUES
(1, 'Orden de PEDIDOS', 1, NULL),
(2, 'Cliente', 1, NULL),
(3, 'Indicadores TEC', 1, NULL),
(4, 'Indicadores TEC STORE', 1, NULL),
(5, 'Gestión Alumno', 1, NULL),
(6, 'Paciente', 1, NULL),
(7, 'Líder TEc', 1, 'Admon'),
(8, 'Campaña', 1, NULL),
(9, 'Egresos', 1, NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `modulo_puesto`
--

CREATE TABLE `modulo_puesto` (
  `id_modulo` int(11) NOT NULL,
  `id_puesto_empleado` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `modulo_puesto`
--

INSERT INTO `modulo_puesto` (`id_modulo`, `id_puesto_empleado`) VALUES
(1, 3),
(1, 16),
(1, 20),
(2, 9),
(2, 16),
(2, 20),
(3, 2),
(3, 6),
(3, 9),
(3, 16),
(3, 20),
(4, 3),
(4, 14),
(4, 20),
(5, 3),
(5, 20),
(6, 6),
(6, 12),
(6, 16),
(6, 17),
(6, 20),
(7, 20),
(8, 20),
(8, 21),
(9, 20),
(9, 23);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `puesto_empleado_venta`
--

CREATE TABLE `puesto_empleado_venta` (
  `id_puesto_empleado_venta` int(11) NOT NULL,
  `descripcion` varchar(250) NOT NULL,
  `descripcion_corta` varchar(15) DEFAULT NULL,
  `es_ejecutivo` int(1) DEFAULT 0,
  `es_lider_venta` int(1) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `puesto_empleado_venta`
--

INSERT INTO `puesto_empleado_venta` (`id_puesto_empleado_venta`, `descripcion`, `descripcion_corta`, `es_ejecutivo`, `es_lider_venta`) VALUES
(1, 'Director de México', 'DdM', 0, 0),
(2, 'Director de Zona', 'DdZ', 0, 1),
(3, 'Ejecutivo de Retención y Crecimiento Campo', 'EdRyCC', 1, 0),
(4, 'Ejecutivo de Cobranza', 'EdC', 0, 0),
(5, 'Ejecutivo de Punto de Venta', 'EdPdV', 1, 0),
(6, 'Líder de Mercado', 'LdM', 0, 1),
(7, 'Director de Ventas', 'DdV', 0, 0),
(8, 'Ejecutivo de Servicio', 'EdS', 1, 0),
(9, 'Líder de Ventas', 'LdV', 0, 1),
(10, 'Ejecutivo de Desarrollo Territorial', 'EdDT', 1, 0),
(11, 'Director de Estrategia Digital', 'DdED', 0, 0),
(12, 'Líder de CEDIS', 'LdC', 0, 1),
(13, 'Líder de EDT', 'LdE', 0, 1),
(14, 'Ejecutivo de Retención y Crecimiento Teléfono', 'EdRyCT', 1, 0),
(15, 'Líder de EPV', 'LdE', 0, 1),
(16, 'Administrador de oficina', 'Ado', 0, 0),
(17, 'Auxiliar', 'A', 0, 0),
(18, 'Supervisor administrativo', 'Sa', 0, 0),
(19, 'Puesto no identificado', 'Pni', 0, 0),
(20, 'Líder del Proceso de Atención', 'LdPdA', 0, 0),
(21, 'Especialista de Inteligencia de Negocios', 'EdIdN', 0, 0),
(22, 'Líder de Sub Proceso de Logística y Distribución de Atención', 'LdSPdLyDdA', 0, 0),
(23, 'Especialista de Ingresos', 'EdI', 0, 0),
(24, 'Especialista de Emision Y Control', 'EdEYC', 0, 0),
(25, 'Coordinador de Emision Y Control', 'CdEYC', 0, 0),
(26, 'Supervisor Administrativo', 'SA', 0, 0),
(27, 'Especialista de Egresos', 'EdE', 0, 0),
(28, 'Coordinador Administrativo Sorteos Instantáneos', 'CASI', 0, 0),
(29, 'Jefe de Egresos', 'JdE', 0, 0),
(30, 'Director de Administración y Finanzas', 'DdAyF', 0, 0),
(31, 'Supervisor Nacional de Cobranza', 'SNdC', 0, 0),
(32, 'Coordinador de Información Financiera', 'CdIF', 0, 0),
(33, 'Gerente de Premios', 'GdP', 0, 0),
(34, 'Especialista de Premios', 'EdP', 0, 0),
(35, 'Especialista Zona Monterrey', 'EZM', 0, 0),
(38, 'Ejecutivo de Reactivación y Venta Telefónica', 'EdRyVT', 1, 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `sub_modulo`
--

CREATE TABLE `sub_modulo` (
  `id_sub_modulo` int(11) NOT NULL,
  `descripcion` varchar(250) NOT NULL,
  `id_modulo` int(11) NOT NULL,
  `url` varchar(250) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `sub_modulo`
--

INSERT INTO `sub_modulo` (`id_sub_modulo`, `descripcion`, `id_modulo`, `url`) VALUES
(1, 'Consulta', 1, 'view/holamundo'),
(2, 'Alta', 1, 'view/holamundo'),
(3, 'Solicitud', 1, 'view/holamundo'),
(4, 'Traspaso', 1, 'view/holamundo'),
(5, 'Reportes', 1, 'view/holamundo'),
(6, 'Reporte Balance Boletos', 1, 'view/holamundo'),
(7, 'Consulta', 2, 'view/holamundo'),
(8, 'Alta', 2, 'view/holamundo'),
(9, 'Unificaci�n', 2, 'view/holamundo'),
(10, 'Traspaso de Colaboradores', 2, 'view/holamundo'),
(11, 'IBase Forecast', 3, 'view/holamundo'),
(12, 'Campa�as', 3, 'view/holamundo'),
(13, 'Base Meta-Sorteo', 3, 'view/holamundo'),
(14, 'Monitoreo Retenci�n', 3, 'view/holamundo'),
(15, 'Monitoreo Retenci�n por Sorteo', 3, 'view/holamundo'),
(16, 'Resumen Ventas', 3, 'view/holamundo'),
(17, 'Resumen Ventas por Sorteo', 3, 'view/holamundo'),
(18, 'Orden Visita d�a anterior', 3, 'view/holamundo'),
(19, 'Orden Visita siguiente d�a', 3, 'view/holamundo'),
(20, 'Orden Visita ejecutivo', 3, 'view/holamundo'),
(21, 'Orden Visita realizadas Base real', 3, 'view/holamundo'),
(22, 'Orden Visita programadas', 3, 'view/holamundo'),
(23, 'Tiempos ', 3, 'view/holamundo'),
(24, 'Reporte de premios', 3, 'view/holamundo'),
(25, 'Ejecutivo - Mi compromiso de Venta total', 3, 'view/holamundo'),
(26, 'Mi compromiso de venta total', 4, 'view/holamundo'),
(27, 'Comportamiento de venta', 4, 'view/holamundo'),
(28, 'Cero Movimientos', 4, 'view/holamundo'),
(29, 'Resumen de Venta', 4, 'view/holamundo'),
(30, 'Premios', 4, 'view/holamundo'),
(31, 'Prospectos', 4, 'view/holamundo'),
(32, 'Tiempo Contacto', 4, 'view/holamundo'),
(33, 'Meta del d�a', 4, 'view/holamundo'),
(34, 'Visitas', 4, 'view/holamundo'),
(35, 'Monitoreo retenci�n', 4, 'view/holamundo'),
(36, 'Monitoreo retenci�n por Sorteo', 4, 'view/holamundo'),
(37, 'Buscar Cliente', 5, 'view/holamundo'),
(38, 'Armado de Paquetes', 6, 'view/holamundo'),
(39, 'Solicitud Venta Directa', 1, 'view/holamundo'),
(40, 'Alta Empleado', 7, 'view/holamundo'),
(41, 'Alta Ejecutivo Externo', 7, 'view/holamundo'),
(42, 'Consulta Zona', 7, 'view/holamundo'),
(43, 'Alta Zona', 7, 'view/holamundo'),
(44, 'Activar Zona', 7, 'view/holamundo'),
(45, 'SeguimientoBaseColaborador', 3, 'view/holamundo'),
(46, 'Seguimiento a EDTs', 3, 'view/holamundo'),
(47, 'Venta Directa', 4, 'view/holamundo'),
(48, 'Venta Directa', 3, 'view/holamundo'),
(49, 'Cierre Retenci�n Colaboradores', 3, 'view/holamundo'),
(50, 'Cierre Retenci�n Colaboradores', 4, 'view/holamundo'),
(51, 'Cierre Retenci�n Colaboradores', 4, 'view/holamundo'),
(52, 'Consulta', 8, 'view/holamundo'),
(53, 'Alta', 8, 'view/holamundo'),
(54, 'Clientes Traspaso pendiente llamada Bienvenida', 3, 'view/holamundo'),
(55, 'Colaboradores Por Reactivar', 3, 'view/holamundo'),
(56, 'Base Multiproducto', 3, 'view/holamundo'),
(57, 'Alta de Promoci�n', 9, 'view/holamundo'),
(58, 'Compradores De Colaboradores Inactivos', 3, 'view/holamundo');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `sub_modulo_puesto`
--

CREATE TABLE `sub_modulo_puesto` (
  `id_sub_modulo` int(11) NOT NULL,
  `id_puesto_empleado` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `sub_modulo_puesto`
--

INSERT INTO `sub_modulo_puesto` (`id_sub_modulo`, `id_puesto_empleado`) VALUES
(1, 3),
(1, 16),
(1, 20),
(2, 3),
(2, 16),
(2, 20),
(3, 16),
(3, 20),
(4, 16),
(4, 20),
(5, 16),
(5, 20),
(6, 16),
(6, 20),
(7, 16),
(7, 20),
(8, 16),
(8, 20),
(9, 16),
(9, 20),
(10, 9),
(10, 16),
(10, 20),
(11, 16),
(11, 20),
(12, 16),
(12, 20),
(13, 16),
(13, 20),
(14, 16),
(14, 20),
(15, 16),
(15, 20),
(16, 16),
(16, 20),
(17, 16),
(17, 20),
(18, 16),
(18, 20),
(19, 16),
(19, 20),
(20, 16),
(20, 20),
(21, 16),
(21, 20),
(22, 16),
(22, 20),
(23, 16),
(23, 20),
(24, 16),
(24, 20),
(25, 16),
(25, 20),
(26, 14),
(26, 20),
(27, 14),
(27, 20),
(28, 14),
(28, 20),
(29, 14),
(29, 20),
(30, 14),
(30, 20),
(31, 14),
(31, 20),
(32, 14),
(32, 20),
(33, 14),
(33, 20),
(34, 14),
(34, 20),
(35, 3),
(35, 14),
(35, 20),
(36, 3),
(36, 14),
(36, 20),
(37, 3),
(37, 20),
(38, 6),
(38, 12),
(38, 16),
(38, 17),
(38, 20),
(39, 16),
(39, 20),
(40, 20),
(41, 20),
(42, 20),
(43, 20),
(44, 20),
(45, 2),
(45, 6),
(45, 9),
(45, 16),
(45, 20),
(46, 14),
(46, 16),
(46, 20),
(47, 14),
(47, 20),
(48, 16),
(48, 20),
(49, 2),
(49, 6),
(49, 9),
(49, 14),
(49, 16),
(49, 20),
(50, 3),
(52, 20),
(52, 21),
(53, 20),
(53, 21),
(54, 9),
(55, 2),
(55, 6),
(55, 9),
(55, 16),
(55, 20),
(56, 2),
(56, 6),
(56, 9),
(56, 16),
(56, 20),
(57, 20),
(57, 23),
(58, 2),
(58, 6),
(58, 9),
(58, 16),
(58, 20);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `unidad_organizacional`
--

CREATE TABLE `unidad_organizacional` (
  `id_unidad_organizacional` int(11) NOT NULL,
  `nombre` varchar(45) DEFAULT NULL,
  `activa` int(1) NOT NULL,
  `id_tipo_unidad_organizacional` int(1) NOT NULL,
  `id_unidad_banner` varchar(15) DEFAULT NULL,
  `id_unidad_organiza_superior` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `unidad_organizacional`
--

INSERT INTO `unidad_organizacional` (`id_unidad_organizacional`, `nombre`, `activa`, `id_tipo_unidad_organizacional`, `id_unidad_banner`, `id_unidad_organiza_superior`) VALUES
(1, 'Oficinas Centrales', 1, 1, NULL, NULL),
(2, 'Monterrey', 1, 3, '340324', 107),
(3, 'Cd. Victoria', 1, 3, '344501', 103),
(4, 'Matamoros', 1, 3, '345301', 100),
(5, 'Reynosa', 1, 3, '346301', 107),
(6, 'Nuevo Laredo', 1, 3, '345901', 100),
(7, 'Piedras Negras', 1, 3, '346001', 100),
(8, 'Monclova', 1, 3, '345701', 100),
(9, 'Chihuahua', 1, 3, '344601', 100),
(10, 'San Luis Potosí', 1, 3, '346401', 102),
(11, 'Zacatecas', 1, 3, '344302', 100),
(12, 'Aguascalientes', 1, 3, '344301', 105),
(13, 'León', 1, 3, '345201', 102),
(14, 'Durango', 1, 3, '345001', 100),
(15, 'Cd. Juárez', 1, 3, '344401', 100),
(16, 'Querétaro', 1, 3, '346201', 102),
(17, 'Mexicali', 1, 3, '345601', 104),
(18, 'Tampico', 1, 3, '346601', 103),
(19, 'Córdoba', 1, 3, '347101', 103),
(20, 'Culiacán', 1, 3, '344901', 104),
(21, 'Hermosillo', 1, 3, '345101', 104),
(22, 'Puebla', 1, 3, '346101', 103),
(23, 'Coatzacoalcos', 1, 3, '344701', 103),
(24, 'Villahermosa', 1, 3, '347201', 103),
(25, 'Toluca', 1, 3, '346801', 102),
(26, 'Saltillo', 1, 3, '346501', 107),
(27, 'Tijuana', 1, 3, '346701', 104),
(28, 'Acapulco', 1, 3, '347511', 102),
(29, 'Mazatlán', 1, 3, '345401', 104),
(30, 'Morelia', 1, 3, '345801', 102),
(31, 'Cd. Obregón', 1, 3, '345102', 104),
(32, 'Irapuato', 1, 3, '347506', 102),
(33, 'Celaya', 1, 3, '347505', 102),
(34, 'Oficina Virtual', 1, 3, '347513', 69),
(35, 'Los Mochis', 1, 3, '344902', 104),
(36, 'Mérida', 1, 3, '345501', 103),
(37, 'Cuernavaca', 1, 3, '344801', 102),
(38, 'Delicias', 1, 3, '347801', 100),
(40, 'La Paz', 1, 3, '348201', 104),
(41, 'Chiapas', 1, 3, '347001', 103),
(42, 'Torreón', 1, 3, '346901', 107),
(43, 'Tepic', 1, 3, '347701', 105),
(44, 'Colima', 1, 3, '347601', 105),
(48, 'Uruapan', 1, 3, '345802', 102),
(50, 'Oficina Central', 1, 3, '346602', 2841893),
(51, 'Ensenada', 1, 3, '348101', 104),
(52, 'Xalapa', 1, 3, '348501', 103),
(53, 'Nogales', 1, 3, '345104', 104),
(54, 'Hidalgo', 1, 3, '347401', 103),
(58, 'Cast Mexico CEM', 0, 3, '347560', 106),
(60, 'Guadalajara', 1, 3, '348001', 105),
(61, 'Tapachula', 0, 4, NULL, 103),
(62, 'Orizaba', 0, 4, '347103', 103),
(63, 'Cast Monterrey', 0, 3, NULL, 107),
(64, 'Veracruz', 1, 3, '348401', 103),
(65, 'Oaxaca', 1, 3, '347901', 103),
(66, 'Stock 66', 1, 3, NULL, 1),
(67, 'Dirección de Ventas México', 1, 7, NULL, NULL),
(68, 'Campeche', 0, 4, NULL, 103),
(69, 'Dirección de Estrategia Digital', 1, 7, NULL, 1),
(70, 'Contact Center', 1, 5, NULL, NULL),
(71, 'OFICINA MAD', 1, 3, NULL, 109),
(75, 'OFICINA MERCADEO', 1, 3, NULL, 66),
(84, 'Cd.Valles', 0, 4, NULL, 101),
(85, 'Cast Guadalajara', 0, 3, NULL, 105),
(86, 'Cast Mercado Abierto', 0, 3, NULL, 106),
(87, 'Cast Mercado Abierto Gdl', 0, 3, '348042', 105),
(89, 'México', 1, 3, '347301', 106),
(90, 'Ventas Proyecto BMX', 1, 3, NULL, 109),
(91, 'Ventas Proyecto STD', 1, 3, NULL, 109),
(92, 'Zamora', 1, 3, '345803', 102),
(94, 'Navojoa', 0, 4, '345105', 104),
(95, 'Puerto Vallarta', 1, 3, '347703', 105),
(96, 'Manzanillo', 1, 3, '347602', 105),
(97, 'México Reforma', 1, 3, '347003', 106),
(99, 'Sorteos Instantáneos', 1, 3, NULL, 109),
(100, 'Zona NIC', 1, 2, NULL, 66),
(101, 'Noreste', 0, 2, NULL, NULL),
(102, 'Zona PONIENTE', 1, 2, NULL, 66),
(103, 'Zona TEC', 1, 2, NULL, 66),
(104, 'Zona ExATec', 1, 2, NULL, 66),
(105, 'Zona OLMECA', 1, 2, NULL, 66),
(106, 'Zona MMM', 1, 2, NULL, 66),
(107, 'Zona Sorteos', 1, 2, NULL, 66),
(109, 'Zona Promociones', 1, 2, NULL, NULL),
(111, 'Cancún', 1, 3, '345502', 103),
(112, 'San Juan del Río', 0, 4, NULL, 102),
(113, 'Promotoría 113', 1, 8, NULL, 205),
(122, 'Promotoría 122', 1, 8, NULL, 32),
(137, 'Promotoría 137', 1, 8, NULL, 9),
(138, 'Promotoría 138', 1, 8, NULL, 9),
(144, 'Promotoría 144', 1, 8, NULL, 5),
(145, 'Promotoría 145', 1, 8, NULL, 5),
(160, 'Promotoría 160', 1, 8, NULL, 3),
(180, 'Promotoría 180', 1, 8, NULL, 4),
(181, 'Gerencia Fresnillo', 1, 9, NULL, 11),
(183, 'Promotoria 183', 1, 8, NULL, 181),
(192, 'Promotoría 192', 1, 8, NULL, 20),
(200, 'Promotoría 200', 1, 8, NULL, 8),
(201, 'Equipo desarrollo Territorial', 1, 9, NULL, NULL),
(202, 'Gerencia Oriente', 1, 9, NULL, NULL),
(203, 'Gerencia Campo Monterrey', 1, 9, NULL, 2),
(204, 'Gerencia Telemarketing', 1, 9, NULL, 2),
(205, 'Gerencia Institucional', 1, 9, NULL, 2),
(207, 'Promotoría 207', 1, 8, NULL, 203),
(209, 'Promotoría 209', 1, 8, NULL, 203),
(211, 'Promotoría 211', 1, 8, NULL, 203),
(214, 'Promotoría 214', 1, 8, NULL, 203),
(218, 'Promotoría 218', 1, 8, NULL, 203),
(223, 'Promotoría 223', 1, 8, NULL, 203),
(229, 'Promotoría 229', 1, 8, NULL, 2),
(231, 'Promotoría 231', 1, 8, NULL, 205),
(237, 'Promotoría 237', 1, 8, NULL, 203),
(238, 'Promotoría 238', 1, 8, NULL, 204),
(253, 'Promotoría 253', 1, 8, NULL, 205),
(965, 'Gerencia Ventas por Internet', 1, 9, NULL, NULL),
(1692, 'Promotoría 1692', 1, 8, NULL, 40),
(246986, 'Promotoría 246986', 1, 8, NULL, 3),
(538898, 'Promotoría 538898', 1, 8, NULL, 21),
(564923, 'Promotoría 564923', 1, 8, NULL, 17),
(769485, 'Promotoría 769485', 1, 8, NULL, 23),
(851255, 'Gerencia Campo', 1, 9, NULL, 89),
(851256, 'Gerencia Institucional', 1, 9, NULL, 89),
(1045365, 'Promotoría 1045365', 1, 8, NULL, 31),
(1104912, 'Promotoría 1104912', 1, 8, NULL, 1104927),
(1104916, 'Promotoría 1104916', 1, 8, NULL, 1104927),
(1104918, 'Promotoría 1104918', 1, 8, NULL, 60),
(1104927, 'Gerencia de Campo', 1, 9, NULL, 60),
(1104931, 'Gerencia de Puntos de Venta', 1, 9, NULL, NULL),
(1104932, 'Gerencia de Telemarketing', 1, 9, NULL, NULL),
(1324687, 'Promotoría 1324687', 1, 8, NULL, 24),
(1392030, 'Promotoría 1392030', 1, 8, NULL, 92),
(1579180, 'Promotoría 1579180', 1, 8, NULL, 205),
(1698513, 'Emisión y Control', 1, 5, NULL, NULL),
(1832681, 'Promotoría 1832681', 1, 8, NULL, 204),
(1863911, 'Promotoría 1863911', 1, 8, NULL, 16),
(1870472, 'Promotoría 1870472', 1, 8, NULL, 851256),
(1870792, 'Promotoría 1870792', 1, 8, NULL, 851255),
(1926659, 'Promotoría 1926659', 1, 8, NULL, 204),
(1988979, 'Promotoría 1988979', 1, 8, NULL, 851256),
(2152769, 'Promotoría 2152769', 1, 8, NULL, 1104927),
(2230454, 'Promotoría 2230454', 1, 8, NULL, 60),
(2250475, 'Promotoría 2250475', 1, 8, NULL, 851255),
(2344559, 'Zona SUR', 0, 2, NULL, NULL),
(2367239, 'Promotoría 2367239', 1, 8, NULL, 851255),
(2430346, 'Promotoría 2430346', 1, 8, NULL, 60),
(2527366, 'Promotoría 2527366', 1, 8, NULL, 22),
(2660353, 'EGADE', 1, 2, NULL, 1),
(2841893, 'Operación Central', 1, 2, NULL, 1);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `aplicacion`
--
ALTER TABLE `aplicacion`
  ADD PRIMARY KEY (`id_aplicacion`);

--
-- Indices de la tabla `empleado_venta`
--
ALTER TABLE `empleado_venta`
  ADD PRIMARY KEY (`id_empleado_venta`),
  ADD KEY `id_empleado_lider_inmediato` (`id_empleado_lider_inmediato`),
  ADD KEY `id_unidad_organizacional_base` (`id_unidad_organizacional_base`),
  ADD KEY `id_puesto_empleado_venta` (`id_puesto_empleado_venta`);

--
-- Indices de la tabla `modulo`
--
ALTER TABLE `modulo`
  ADD PRIMARY KEY (`id_modulo`),
  ADD KEY `id_aplicacion` (`id_aplicacion`);

--
-- Indices de la tabla `modulo_puesto`
--
ALTER TABLE `modulo_puesto`
  ADD PRIMARY KEY (`id_modulo`,`id_puesto_empleado`),
  ADD KEY `id_puesto_empleado` (`id_puesto_empleado`);

--
-- Indices de la tabla `puesto_empleado_venta`
--
ALTER TABLE `puesto_empleado_venta`
  ADD PRIMARY KEY (`id_puesto_empleado_venta`);

--
-- Indices de la tabla `sub_modulo`
--
ALTER TABLE `sub_modulo`
  ADD PRIMARY KEY (`id_sub_modulo`),
  ADD KEY `id_modulo` (`id_modulo`);

--
-- Indices de la tabla `sub_modulo_puesto`
--
ALTER TABLE `sub_modulo_puesto`
  ADD PRIMARY KEY (`id_sub_modulo`,`id_puesto_empleado`),
  ADD KEY `id_puesto_empleado` (`id_puesto_empleado`);

--
-- Indices de la tabla `unidad_organizacional`
--
ALTER TABLE `unidad_organizacional`
  ADD PRIMARY KEY (`id_unidad_organizacional`),
  ADD KEY `id_unidad_organiza_superior` (`id_unidad_organiza_superior`);

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `empleado_venta`
--
ALTER TABLE `empleado_venta`
  ADD CONSTRAINT `sf_empleado_venta_ibfk_3` FOREIGN KEY (`id_unidad_organizacional_base`) REFERENCES `unidad_organizacional` (`id_unidad_organizacional`),
  ADD CONSTRAINT `sf_empleado_venta_ibfk_4` FOREIGN KEY (`id_puesto_empleado_venta`) REFERENCES `puesto_empleado_venta` (`id_puesto_empleado_venta`);

--
-- Filtros para la tabla `modulo`
--
ALTER TABLE `modulo`
  ADD CONSTRAINT `as_modulo_ibfk_1` FOREIGN KEY (`id_aplicacion`) REFERENCES `aplicacion` (`id_aplicacion`);

--
-- Filtros para la tabla `modulo_puesto`
--
ALTER TABLE `modulo_puesto`
  ADD CONSTRAINT `as_modulo_puesto_ibfk_1` FOREIGN KEY (`id_modulo`) REFERENCES `modulo` (`id_modulo`),
  ADD CONSTRAINT `as_modulo_puesto_ibfk_2` FOREIGN KEY (`id_puesto_empleado`) REFERENCES `puesto_empleado_venta` (`id_puesto_empleado_venta`);

--
-- Filtros para la tabla `sub_modulo`
--
ALTER TABLE `sub_modulo`
  ADD CONSTRAINT `as_sub_modulo_ibfk_1` FOREIGN KEY (`id_modulo`) REFERENCES `modulo` (`id_modulo`);

--
-- Filtros para la tabla `sub_modulo_puesto`
--
ALTER TABLE `sub_modulo_puesto`
  ADD CONSTRAINT `as_sub_modulo_puesto_ibfk_1` FOREIGN KEY (`id_puesto_empleado`) REFERENCES `puesto_empleado_venta` (`id_puesto_empleado_venta`),
  ADD CONSTRAINT `as_sub_modulo_puesto_ibfk_2` FOREIGN KEY (`id_sub_modulo`) REFERENCES `sub_modulo` (`id_sub_modulo`);

--
-- Filtros para la tabla `unidad_organizacional`
--
ALTER TABLE `unidad_organizacional`
  ADD CONSTRAINT `uo_unidad_organizacional_ibfk_1` FOREIGN KEY (`id_unidad_organiza_superior`) REFERENCES `unidad_organizacional` (`id_unidad_organizacional`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
