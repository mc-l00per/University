-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1:3306
-- Tiempo de generación: 11-06-2018 a las 17:55:56
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
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
