-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 11-06-2018 a las 17:54:11
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
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
