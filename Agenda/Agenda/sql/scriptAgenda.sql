CREATE DATABASE `agenda2`;
USE agenda2;
CREATE TABLE `personas` 
(
  `idPersona` int(11) NOT NULL AUTO_INCREMENT,
  `Nombre` varchar(45) NOT NULL,
  `Telefono` varchar(20) NOT NULL,
  `Localidad` varchar(150) NOT NULL,
  PRIMARY KEY (`idPersona`)
);