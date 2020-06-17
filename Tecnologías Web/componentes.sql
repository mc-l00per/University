-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 11-06-2018 a las 17:55:18
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
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
