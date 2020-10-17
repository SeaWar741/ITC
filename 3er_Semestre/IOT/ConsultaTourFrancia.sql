CREATE TABLE `ciclista` (
  `IDCiclista` int(12) NOT NULL,
  `Nombre` varchar(256) NOT NULL,
  `IDEquipo` int(5) NOT NULL,
  `IDLider` int(8) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `ciclista`
--

INSERT INTO `ciclista` (`IDCiclista`, `Nombre`, `IDEquipo`, `IDLider`) VALUES
(1, 'JOSE', 60, NULL),
(2, 'LANCE', 60, 1),
(3, 'MIGUEL', 60, 1),
(4, 'MICHAEL', 60, 1),
(5, 'KARIN', 60, 1),
(6, 'SAMUEL', 60, 1),
(7, 'ALBERTO', 60, 1),
(8, 'JULIO', 61, NULL),
(9, 'RAUL', 61, 8),
(10, 'OSCAR', 61, 8),
(11, 'FERNANDO', 61, 8),
(12, 'RAMON', 61, 8),
(13, 'DAVID', 61, 8),
(14, 'ARTURO', 61, 8),
(15, 'LUIS', 62, NULL),
(16, 'JUAN CARLOS', 62, 16),
(17, 'JESUS ANTONIO', 62, 16),
(18, 'CESAR', 62, 16),
(19, 'ALFONSO', 62, 16),
(20, 'JOSE CARLOS', 62, 16),
(21, 'JOSE', 1, NULL),
(22, 'LANCE', 1, 22),
(23, 'MIGUEL', 1, 22),
(24, 'MICHAEL', 1, 22),
(25, 'KARIN', 1, 22),
(26, 'SAMUEL', 2, NULL),
(27, 'ALBERTO', 2, 26),
(28, 'JULIO', 2, 26),
(29, 'RAUL', 2, 26),
(30, 'OSCAR', 3, NULL),
(31, 'FERNANDO', 3, 30),
(32, 'RAMON', 3, 30),
(33, 'DAVID', 3, 30),
(34, 'ARTURO', 3, 30),
(35, 'LUIS', 4, NULL),
(36, 'JUAN CARLOS', 4, 35),
(37, 'JESUS ANTONIO', 4, 35),
(38, 'CESAR', 4, 35),
(39, 'ALFONSO', 4, 35),
(40, 'JOSE CARLOS', 4, 35);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `equipo`
--

CREATE TABLE `equipo` (
  `ID` int(5) NOT NULL,
  `PAIS` varchar(256) NOT NULL,
  `Nombre` varchar(256) NOT NULL,
  `EdicionTour` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `equipo`
--

INSERT INTO `equipo` (`ID`, `PAIS`, `Nombre`, `EdicionTour`) VALUES
(1, 'REINO UNIDO', 'Team Ineos', 1),
(2, 'PAISES BAJOS', 'Team Jumbo', 1),
(3, 'ALEMANIA', 'Bora', 1),
(4, 'FRANCIA', 'AG2R', 1),
(5, 'BELGICA', 'Deceuninck', 1),
(6, 'FRANCIA', 'Groupama', 1),
(7, 'BAHREIN', 'Bahrain-MCLAREN', 1),
(8, 'ESTADOS UNIDOS', 'EF Education', 1),
(9, 'FRANCIA', 'Arkéa', 1),
(10, 'ESPAÑA', 'Movistar', 1),
(11, 'ESTADOS UNIDOS', 'Trek', 1),
(12, 'POLONIA', 'CCC', 1),
(13, 'FRANCIA', 'Cofidis', 1),
(14, 'EMIRATOS ARABES UNIDOS', 'UAE Team', 1),
(15, 'KAZAJISTAN', 'Astana Pro', 1),
(16, 'BELGICA', 'Lotto', 1),
(17, 'AUSTRALIA', 'Mitchelton', 1),
(18, 'ISRAEL', 'Israel Start-up', 1),
(19, 'FRANCIA', 'Direct Energie', 1),
(20, 'SUDAFRICA', 'NTT Procycling', 1),
(21, 'ALEMANIA', 'Team Sunweb', 1),
(22, 'FRANCIA', 'Vital Concept', 1),
(23, 'FRANCIA', 'AG2R LA Mondiale', 117),
(24, 'ESTADOS UNIDOS', 'Trek-segafredo', 117),
(25, 'FRANCIA', 'Groupama-FDJ', 117),
(26, 'KAZAJISTAN', 'Astana Pro', 117),
(27, 'BELGICA', 'Deceuninck-Quick Step', 117),
(28, 'PAISES BAJOS', 'Jumbo-Visma', 117),
(29, 'ESPAÑA', 'Movistar', 117),
(30, 'SUDAFRICA', 'Dimension Data', 117),
(31, 'SUIZA', ' Katusha-Alpecin', 117),
(32, 'REINO UNIDO', 'Team Ineos', 117),
(33, 'ALEMANIA', 'Bora-hansgrohe', 117),
(34, 'ESTADOS UNIDOS', 'EF Education First', 117),
(35, 'BELGICA', 'Lotto Soudal', 117),
(36, 'ALEMANIA', 'Team Sunweb', 117),
(37, 'ESTADOS UNIDOS', 'Trek', 116),
(38, 'POLONIA', 'CCC', 116),
(39, 'FRANCIA', 'Cofidis', 116),
(40, 'EMIRATOS ARABES UNIDOS', 'UAE Team', 116),
(41, 'KAZAJISTAN', 'Astana Pro', 116),
(42, 'BELGICA', 'Lotto', 116),
(43, 'AUSTRALIA', 'Mitchelton', 116),
(44, 'ISRAEL', 'Israel Start-up', 116),
(45, 'FRANCIA', 'Direct Energie', 116),
(46, 'SUDAFRICA', 'NTT Procycling', 116),
(47, 'ALEMANIA', 'Team Sunweb', 116),
(48, 'FRANCIA', 'Vital Concept', 116),
(49, 'PAISES BAJOS', 'Jumbo-Visma', 115),
(50, 'ESPAÑA', 'Movistar', 115),
(51, 'SUDAFRICA', 'Dimension Data', 115),
(52, 'SUIZA', ' Katusha-Alpecin', 115),
(53, 'REINO UNIDO', 'Team Ineos', 115),
(54, 'ALEMANIA', 'Bora-hansgrohe', 115),
(55, 'ESTADOS UNIDOS', 'EF Education First', 115),
(56, 'BELGICA', 'Lotto Soudal', 115),
(57, 'REINO UNIDO', 'Team Ineos', 114),
(58, 'PAISES BAJOS', 'Team Jumbo', 114),
(59, 'ALEMANIA', 'Bora', 114),
(60, 'FRANCIA', 'AG2R', 114),
(61, 'BELGICA', 'Deceuninck', 114),
(62, 'FRANCIA', 'Groupama', 114),
(63, 'BAHREIN', 'Bahrain-MCLAREN', 114),
(64, 'ESTADOS UNIDOS', 'EF Education', 114),
(65, 'FRANCIA', 'Arkéa', 114),
(66, 'ESPAÑA', 'Movistar', 114),
(67, 'ESTADOS UNIDOS', 'Trek', 114),
(68, 'POLONIA', 'CCC', 114);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `etapa`
--

CREATE TABLE `etapa` (
  `Inicio` varchar(256) NOT NULL,
  `Meta` varchar(256) NOT NULL,
  `IDCiclista` int(8) DEFAULT NULL,
  `EdicionTour` int(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `etapa`
--

INSERT INTO `etapa` (`Inicio`, `Meta`, `IDCiclista`, `EdicionTour`) VALUES
('Lille', 'Niza', 19, 114),
('Lyon', 'Paris', 10, 116),
('Marsella', 'Niza', 11, 116),
('Marsella', 'Paris', 10, 116),
('Niza', 'Nantes', 18, 114),
('Paris', 'Nantes', 18, 114),
('Toulouse', 'Marsella', 11, 116);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `nacionalidad`
--

CREATE TABLE `nacionalidad` (
  `IDCiclista` int(8) NOT NULL,
  `Nacionalidad` varchar(256) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `nacionalidad`
--

INSERT INTO `nacionalidad` (`IDCiclista`, `Nacionalidad`) VALUES
(1, 'Mexicana'),
(2, 'Española'),
(3, 'Norteamericana'),
(4, 'Sueca'),
(5, 'Irlandesa'),
(6, 'alemana'),
(7, 'boliviano'),
(8, 'Chino'),
(9, 'Colombiano'),
(10, 'coreano'),
(11, 'cubano'),
(12, 'danés'),
(13, 'ecuatoriano'),
(14, 'Mexicana'),
(15, 'Española'),
(16, 'Norteamericana'),
(17, 'Sueca'),
(18, 'Irlandesa'),
(19, 'alemana'),
(20, 'boliviano'),
(21, 'Chino'),
(22, 'Colombiano'),
(23, 'coreano'),
(24, 'cubano'),
(25, 'danés'),
(26, 'ecuatoriano'),
(27, 'Mexicana'),
(28, 'Mexicana'),
(29, 'Mexicana'),
(30, 'Mexicana'),
(31, 'Mexicana'),
(32, 'Mexicana'),
(33, 'Española'),
(34, 'Española'),
(35, 'Española'),
(36, 'Española'),
(37, 'Española'),
(38, 'Española'),
(39, 'Mexicana'),
(40, 'Mexicana');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tourfrancia`
--

CREATE TABLE `tourfrancia` (
  `Edicion` int(5) NOT NULL COMMENT 'Numero de edición del tour',
  `Inicio` date NOT NULL COMMENT 'Fecha de inicio del tour',
  `FIN` date NOT NULL COMMENT 'Fecha de fin del tour'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `tourfrancia`
--

INSERT INTO `tourfrancia` (`Edicion`, `Inicio`, `FIN`) VALUES
(1, '1903-07-04', '1903-08-01'),
(2, '1904-07-04', '1904-08-01'),
(3, '1905-07-04', '1905-08-01'),
(4, '1906-07-04', '1906-08-01'),
(5, '1907-07-04', '1907-08-01'),
(6, '1908-07-04', '1908-08-01'),
(7, '1909-07-04', '1909-08-01'),
(8, '1910-07-04', '1910-08-01'),
(9, '1911-07-04', '1911-08-01'),
(10, '1912-07-04', '1912-08-01'),
(11, '1913-07-04', '1913-08-01'),
(12, '1914-07-04', '1914-08-01'),
(13, '1915-07-04', '1915-08-01'),
(14, '1916-07-04', '1916-08-01'),
(15, '1917-07-04', '1917-08-01'),
(16, '1918-07-04', '1918-08-01'),
(17, '1919-07-04', '1919-08-01'),
(18, '1920-07-04', '1920-08-01'),
(19, '1921-07-04', '1921-08-01'),
(20, '1922-07-04', '1922-08-01'),
(21, '1923-07-04', '1923-08-01'),
(22, '1924-07-04', '1924-08-01'),
(23, '1925-07-04', '1925-08-01'),
(24, '1926-07-04', '1926-08-01'),
(25, '1927-07-04', '1927-08-01'),
(26, '1928-07-04', '1928-08-01'),
(27, '1929-07-04', '1929-08-01'),
(28, '1930-07-04', '1930-08-01'),
(29, '1931-07-04', '1931-08-01'),
(30, '1932-07-04', '1932-08-01'),
(31, '1933-07-04', '1933-08-01'),
(32, '1934-07-04', '1934-08-01'),
(33, '1935-07-04', '1935-08-01'),
(34, '1936-07-04', '1936-08-01'),
(35, '1937-07-04', '1937-08-01'),
(36, '1938-07-04', '1938-08-01'),
(37, '1939-07-04', '1939-08-01'),
(38, '1940-07-04', '1940-08-01'),
(39, '1941-07-04', '1941-08-01'),
(40, '1942-07-04', '1942-08-01'),
(41, '1943-07-04', '1943-08-01'),
(42, '1944-07-04', '1944-08-01'),
(43, '1945-07-04', '1945-08-01'),
(44, '1946-07-04', '1946-08-01'),
(45, '1947-07-04', '1947-08-01'),
(46, '1948-07-04', '1948-08-01'),
(47, '1949-07-04', '1949-08-01'),
(48, '1950-07-04', '1950-08-01'),
(49, '1951-07-04', '1951-08-01'),
(50, '1952-07-04', '1952-08-01'),
(51, '1953-07-04', '1953-08-01'),
(52, '1954-07-04', '1954-08-01'),
(53, '1955-07-04', '1955-08-01'),
(54, '1956-07-04', '1956-08-01'),
(55, '1957-07-04', '1957-08-01'),
(56, '1958-07-04', '1958-08-01'),
(57, '1959-07-04', '1959-08-01'),
(58, '1960-07-04', '1960-08-01'),
(59, '1961-07-04', '1961-08-01'),
(60, '1962-07-04', '1962-08-01'),
(61, '1963-07-04', '1963-08-01'),
(62, '1964-07-04', '1964-08-01'),
(63, '1965-07-04', '1965-08-01'),
(64, '1966-07-04', '1966-08-01'),
(65, '1967-07-04', '1967-08-01'),
(66, '1968-07-04', '1968-08-01'),
(67, '1969-07-04', '1969-08-01'),
(68, '1970-07-04', '1970-08-01'),
(69, '1971-07-04', '1971-08-01'),
(70, '1972-07-04', '1972-08-01'),
(71, '1973-07-04', '1973-08-01'),
(72, '1974-07-04', '1974-08-01'),
(73, '1975-07-04', '1975-08-01'),
(74, '1976-07-04', '1976-08-01'),
(75, '1977-07-04', '1977-08-01'),
(76, '1978-07-04', '1978-08-01'),
(77, '1979-07-04', '1979-08-01'),
(78, '1980-07-04', '1980-08-01'),
(79, '1981-07-04', '1981-08-01'),
(80, '1982-07-04', '1982-08-01'),
(81, '1983-07-04', '1983-08-01'),
(82, '1984-07-04', '1984-08-01'),
(83, '1985-07-04', '1985-08-01'),
(84, '1986-07-04', '1986-08-01'),
(85, '1987-07-04', '1987-08-01'),
(86, '1988-07-04', '1988-08-01'),
(87, '1989-07-04', '1989-08-01'),
(88, '1990-07-04', '1990-08-01'),
(89, '1991-07-04', '1991-08-01'),
(90, '1992-07-04', '1992-08-01'),
(91, '1993-07-04', '1993-08-01'),
(92, '1994-07-04', '1994-08-01'),
(93, '1995-07-04', '1995-08-01'),
(94, '1996-07-04', '1996-08-01'),
(95, '1997-07-04', '1997-08-01'),
(96, '1998-07-04', '1998-08-01'),
(97, '1999-07-04', '1999-08-01'),
(98, '2000-07-04', '2000-08-01'),
(99, '2001-07-04', '2001-08-01'),
(100, '2002-07-04', '2002-08-01'),
(101, '2003-07-04', '2003-08-01'),
(102, '2004-07-04', '2004-08-01'),
(103, '2005-07-04', '2005-08-01'),
(104, '2006-07-04', '2006-08-01'),
(105, '2007-07-04', '2007-08-01'),
(106, '2008-07-04', '2008-08-01'),
(107, '2009-07-04', '2009-08-01'),
(108, '2010-07-04', '2010-08-01'),
(109, '2011-07-04', '2011-08-01'),
(110, '2012-07-04', '2012-08-01'),
(111, '2013-07-04', '2013-08-01'),
(112, '2014-07-04', '2014-08-01'),
(113, '2015-07-04', '2015-08-01'),
(114, '2016-07-04', '2016-08-01'),
(115, '2017-07-04', '2017-08-01'),
(116, '2018-07-04', '2018-08-01'),
(117, '2019-07-04', '2019-08-01'),
(118, '2020-07-04', '2020-08-01');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `ciclista`
--
ALTER TABLE `ciclista`
  ADD PRIMARY KEY (`IDCiclista`),
  ADD KEY `IDEquipo` (`IDEquipo`),
  ADD KEY `IDLider` (`IDLider`);

--
-- Indices de la tabla `equipo`
--
ALTER TABLE `equipo`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `EdicionTour` (`EdicionTour`);

--
-- Indices de la tabla `etapa`
--
ALTER TABLE `etapa`
  ADD PRIMARY KEY (`Inicio`,`Meta`),
  ADD KEY `IDCiclista` (`IDCiclista`),
  ADD KEY `EdicionTour` (`EdicionTour`);

--
-- Indices de la tabla `nacionalidad`
--
ALTER TABLE `nacionalidad`
  ADD PRIMARY KEY (`IDCiclista`,`Nacionalidad`);

--
-- Indices de la tabla `tourfrancia`
--
ALTER TABLE `tourfrancia`
  ADD PRIMARY KEY (`Edicion`);

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `ciclista`
--
ALTER TABLE `ciclista`
  ADD CONSTRAINT `ciclista_ibfk_1` FOREIGN KEY (`IDEquipo`) REFERENCES `equipo` (`ID`),
  ADD CONSTRAINT `ciclista_ibfk_2` FOREIGN KEY (`IDLider`) REFERENCES `ciclista` (`IDCiclista`);

--
-- Filtros para la tabla `equipo`
--
ALTER TABLE `equipo`
  ADD CONSTRAINT `equipo_ibfk_1` FOREIGN KEY (`EdicionTour`) REFERENCES `tourfrancia` (`Edicion`);

--
-- Filtros para la tabla `etapa`
--
ALTER TABLE `etapa`
  ADD CONSTRAINT `etapa_ibfk_1` FOREIGN KEY (`IDCiclista`) REFERENCES `ciclista` (`IDCiclista`),
  ADD CONSTRAINT `etapa_ibfk_2` FOREIGN KEY (`EdicionTour`) REFERENCES `tourfrancia` (`Edicion`);

--
-- Filtros para la tabla `nacionalidad`
--
ALTER TABLE `nacionalidad`
  ADD CONSTRAINT `nacionalidad_ibfk_1` FOREIGN KEY (`IDCiclista`) REFERENCES `ciclista` (`IDCiclista`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
