-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 11-06-2018 a las 01:20:29
-- Versión del servidor: 5.7.21
-- Versión de PHP: 5.6.35

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `aralaminos1718`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `bibliografia`
--

DROP TABLE IF EXISTS `bibliografia`;
CREATE TABLE IF NOT EXISTS `bibliografia` (
  `fecha` date NOT NULL,
  `idBibliografia` int(11) NOT NULL AUTO_INCREMENT,
  `texto` varchar(3000) NOT NULL,
  PRIMARY KEY (`idBibliografia`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `bibliografia`
--

INSERT INTO `bibliografia` (`fecha`, `idBibliografia`, `texto`) VALUES
('2018-06-11', 1, 'JosÃ© (izquierda) y David (derecha), Estopa, en sus comienzos Los hermanos David y JosÃ© nacieron en el barrio de San Ildefonso de CornellÃ¡ de Llobregat, un municipio a escasos kilÃ³metros de Barcelona. Sus padres habÃ­an llegado desde Zarza Capilla (Badajoz), en la comarca de la Serena, y regentaban el bar La EspaÃ±ola, enfrente de la comisarÃ­a de policÃ­a de CornellÃ¡. Los Chichos, Los Chunguitos, BordÃ¡n 4 o Los Amaya, entre otros, era la mÃºsica que oÃ­an ya desde la infancia David y JosÃ©, que pronto comenzaron a aficionarse a la guitarra, antes de abandonar el instituto y empezar a buscarse la vida en varios trabajos, el Ãºltimo en Novel Lahnwerk, una fÃ¡brica filial de la SEAT produciendo piezas para automÃ³viles. La historia dice que del grito \"Â¡Dale estopa!\" que utilizaba el encargado de la fÃ¡brica para que no cesaran en su trabajo, surgiÃ³ el nombre de una de las bandas mÃ¡s importantes de la mÃºsica espÃ±ola de la Ãºltima dÃ©cada.'),
('2018-06-06', 2, 'En aquella fÃ¡brica, se comenzÃ³ a gestar Estopa, la letra de su primer Ã©xito, \"La raja de tu falda\" (â€œPor la raja de tu falda yo tuve un piÃ±azo con un Seat Pandaâ€), las primeras canciones y las primeras actuaciones en garitos del barrio. En 1998, David y JosÃ© se presentaron al concurso de cantautores del barrio de Horta-GuinardÃ³. Ganaron el primer premio y algo mÃ¡s de 2000 euros.'),
('2018-06-07', 3, 'Estopa es un dÃºo espaÃ±ol de mÃºsica creado el 19 de octubre de 1999, formado por los hermanos David y JosÃ© Manuel MuÃ±oz. El grupo es oriundo de la ciudad del Baix Llobregat (provincia de Barcelona) de CornellÃ¡ de Llobregat (barrio de San Ildefonso). '),
('2018-06-04', 4, 'Con su primer disco consiguieron unas ventas superiores a 1.000.000 de copias, logrando asÃ­ el reconocimiento en su paÃ­s natal y despuÃ©s en paÃ­ses americanos como Cuba, Colombia y Venezuela. Sus otros siete discos han seguido la fÃ³rmula que tanto Ã©xito les ha dado: estilo flamenco y rumbas urbanas. Son grandes admiradores de JoaquÃ­n Sabina, Joan Manuel Serrat, Robe Iniesta y de Pancho Varona. Han vendido mÃ¡s de 4 millones de discos a en el Ã¡mbito nacional e internacional. '),
('2018-06-04', 5, 'Con su primer disco consiguieron unas ventas superiores a 1.000.000 de copias, logrando asÃ­ el reconocimiento en su paÃ­s natal y despuÃ©s en paÃ­ses americanos como Cuba, Colombia y Venezuela. Sus otros siete discos han seguido la fÃ³rmula que tanto Ã©xito les ha dado: estilo flamenco y rumbas urbanas. Son grandes admiradores de JoaquÃ­n Sabina, Joan Manuel Serrat, Robe Iniesta y de Pancho Varona. Han vendido mÃ¡s de 4 millones de discos a en el Ã¡mbito nacional e internacional. ');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cancion`
--

DROP TABLE IF EXISTS `cancion`;
CREATE TABLE IF NOT EXISTS `cancion` (
  `idDisco` int(11) NOT NULL,
  `indice` int(11) NOT NULL,
  `titulo` varchar(300) NOT NULL,
  `duracion` time NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `cancion`
--

INSERT INTO `cancion` (`idDisco`, `indice`, `titulo`, `duracion`) VALUES
(24, 1, 'Vino Tinto', '03:18:00');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `componentes`
--

DROP TABLE IF EXISTS `componentes`;
CREATE TABLE IF NOT EXISTS `componentes` (
  `idComponentes` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(300) NOT NULL,
  `fecha` date NOT NULL,
  `lugarNacimiento` varchar(300) NOT NULL,
  `foto` varchar(300) NOT NULL,
  `bibliografia` varchar(8000) NOT NULL,
  UNIQUE KEY `componentes` (`idComponentes`)
) ENGINE=MyISAM AUTO_INCREMENT=18 DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `componentes`
--

INSERT INTO `componentes` (`idComponentes`, `nombre`, `fecha`, `lugarNacimiento`, `foto`, `bibliografia`) VALUES
(1, 'JosÃ© Manuel MuÃ±oz Calvo', '1978-11-13', 'image/jose.png', 'CornellÃ¡ de Llobregat, Barcelona', 'Es el guitarrista junto a su hermano David, cantante, del dÃºo espaÃ±ol de mÃºsica rock y pop rock con toques de rumba catalana Estopa, creado en 1999.\r\n\r\nEl dÃºo es oriundo de CornellÃ¡ de Llobregat, barrio de San Ildefonso, Barcelona, aunque su familia procede de Extremadura, mÃ¡s concretamente del pueblo de Zarza Capilla. Con su primer disco consiguieron unas ventas cercanas a 1.100.000 copias, logrando asÃ­ el reconocimiento en su paÃ­s natal y despuÃ©s en paÃ­ses tales como MÃ©xico y Chile, merced a gran campaÃ±a de prensa por medio de las empresas transnacionales espaÃ±olas en LatinoamÃ©rica. Sus siguientes discos han seguido la fÃ³rmula que tanto Ã©xito les ha dado, rumbas canallas y urbanas. Son grandes admiradores de LucÃ­a Folino.[cita requerida].A esto hay que aÃ±adir que todos sus disco hasta estopa 2.0 han sido discos de platino.'),
(2, 'David MuÃ±oz Calvo', '1976-01-10', 'image/david.jpg', 'CornellÃ¡ de Llobregat', 'Hijo de extremeÃ±os, David MuÃ±oz naciÃ³ en el barrio de San Ildefonso de CornellÃ¡ de Llobregat, un municipio a escasos diez kilÃ³metros de Barcelona. Sus padres habÃ­an llegado desde Zarza Capilla (Badajoz), en la comarca de la Serena, y regentaban el bar La EspaÃ±ola, enfrente de la comisarÃ­a de policÃ­a de CornellÃ¡. Al lado del colegio donde estudiaron, el Jaime I.[cita requerida] Pronto, Ã©l y su hermano JosÃ©, comenzaron a aficionarse a la guitarra,antes de abandonar el instituto y empezar a buscarse la vida en varios trabajos, el Ãºltimo en Novel Lanhwerk, una fÃ¡brica filial de la Seat produciendo piezas para automÃ³viles. La historia dice que del grito \"Â¡Dale estopa!\" que utilizaba el encargado de la fÃ¡brica para que no cesaran en su trabajo, surgiÃ³ el nombre de una de las bandas fundamentales de la mÃºsica espaÃ±ola de la Ãºltima dÃ©cada.1â€‹ Tras circular por varios caminos y lograr cierta popularidad en circuitos alternativos, una maqueta con casi 40 canciones grabadas en un cuatro pistas en casa de un amigo llegÃ³ a Sony Music (entonces BMG), que inmediatamente invitÃ³ a David y JosÃ© a Madrid para una audiciÃ³n. En esa maqueta estaban canciones como \"La raja de tu falda\", \"Poquito a poco\", \"El del medio de Los Chichos\", \"Como CamarÃ³n\", \"Cacho a cacho\", \"Hemicraneal\", \"Exilado en el lavabo\", \"Me falta el aliento\"â€¦ Comenzaba la carrera de Estopa con buena parte del repertorio hecho.');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `conciertos`
--

DROP TABLE IF EXISTS `conciertos`;
CREATE TABLE IF NOT EXISTS `conciertos` (
  `idConcierto` int(11) NOT NULL AUTO_INCREMENT,
  `fecha` date NOT NULL,
  `hora` time NOT NULL,
  `lugar` varchar(300) NOT NULL,
  `descripcion` varchar(3000) NOT NULL,
  `urlCompra` varchar(1000) NOT NULL,
  PRIMARY KEY (`idConcierto`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `conciertos`
--

INSERT INTO `conciertos` (`idConcierto`, `fecha`, `hora`, `lugar`, `descripcion`, `urlCompra`) VALUES
(1, '2018-08-21', '22:30:00', 'Starlite Auditorio, Marbella, EspaÃ±a ', 'Â¿Quieres formar parte de un concierto de Estopa? \r\n\r\nSi eres fan de Estopa y has llegado hasta aquÃ­ en busca de conciertos con los que disfrutar de su mÃºsica, has elegido bien. En StubHub encontrarÃ¡s las fechas y los eventos previstos para las giras de Estopa para que puedas elegir los que mÃ¡s te gusten y bailar junto al dÃºo catalÃ¡n sus ritmos pegadizos de rumba. Lo Ãºnico que tendrÃ¡s que hacer es buscar las entradas de Estopa que quieres comprar y darle al botÃ³n. Del resto, nos encargaremos nosotros para que las entradas lleguen a tus manos con total comodidad para el dÃ­a del evento. No te lo pienses dos veces y confÃ­a en StubHub para tus experiencias. ', 'https://www.stubhub.es/entradas-estopa/ca241?afl=5D9MWTTURH&gclid=CjwKCAjwo87YBRBgEiwAI1LkqXUUsPqN9cJtaSwxpwVTAHUyPLrdwvyLdwT0Vg-PY6L0R9ZG0eiziRoCGeMQAvD_BwE&gclsrc=aw.ds&dclid=CKjKi6LYuNsCFUlnGwodac8NiQ');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `disco`
--

DROP TABLE IF EXISTS `disco`;
CREATE TABLE IF NOT EXISTS `disco` (
  `idDisco` int(11) NOT NULL AUTO_INCREMENT,
  `foto` varchar(300) NOT NULL,
  `anio` date NOT NULL,
  `precio` double NOT NULL,
  PRIMARY KEY (`idDisco`)
) ENGINE=MyISAM AUTO_INCREMENT=25 DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `disco`
--

INSERT INTO `disco` (`idDisco`, `foto`, `anio`, `precio`) VALUES
(24, 'image/image10.png', '2018-06-12', 10.99);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `user`
--

DROP TABLE IF EXISTS `user`;
CREATE TABLE IF NOT EXISTS `user` (
  `idUser` int(11) NOT NULL AUTO_INCREMENT,
  `usuario` varchar(300) NOT NULL,
  `apellidos` varchar(1000) NOT NULL,
  `email` varchar(2000) NOT NULL,
  `key` varchar(3000) NOT NULL,
  `tipo` varchar(200) NOT NULL,
  `telefono` int(12) NOT NULL,
  PRIMARY KEY (`idUser`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `user`
--

INSERT INTO `user` (`idUser`, `usuario`, `apellidos`, `email`, `key`, `tipo`, `telefono`) VALUES
(2, 'admin', 'admin', 'admin@admin.es', '0000', 'admin', 111111111),
(4, 'compra', 'compra', 'compra@compra.es', '0000', 'compra', 222222222);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
