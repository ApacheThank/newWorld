-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Dim 21 Mai 2017 à 23:32
-- Version du serveur :  5.6.17
-- Version de PHP :  5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `dbnewworld_v1`
--

-- --------------------------------------------------------

--
-- Structure de la table `categorie`
--

CREATE TABLE IF NOT EXISTS `categorie` (
  `idCategorie` int(11) NOT NULL,
  `libelle` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `idRayon` int(11) NOT NULL,
  PRIMARY KEY (`idCategorie`),
  KEY `categorie_ibfk_1` (`idRayon`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Contenu de la table `categorie`
--

INSERT INTO `categorie` (`idCategorie`, `libelle`, `idRayon`) VALUES
(1, 'aides culinaires', 1),
(2, 'alimentation bebe', 1),
(3, 'biscuits, biscottes, chips', 1),
(4, '''laitages'' vegetaux', 1),
(5, 'eau, jus de fruits, sirops', 1),
(6, 'cafe, succedanes', 1),
(7, 'thes, tisanes', 1),
(8, 'cereales, pates', 1),
(9, 'desserts, chocolat, douceurs', 1),
(10, 'farines', 1),
(11, 'fruits secs', 1),
(12, 'huiles vegetales', 1),
(13, 'sucres, miel, produits sucrant', 1),
(14, 'fruits', 2),
(15, 'legumes', 2),
(16, 'pain, produits boulangers', 3),
(17, 'poisson, fruits de mer', 3),
(18, 'viande, charcuterie', 3),
(19, 'produits laiteirs', 3),
(20, 'autres produits frais', 3),
(21, 'produits de la ruche', 4),
(22, 'elixirs floraux et huiles essentielles', 4),
(23, 'jus, ampoules, sirops', 4),
(24, 'autres complements alimentaire', 4);

-- --------------------------------------------------------
--
-- Structure de la table `controleproducteur`
--

CREATE TABLE IF NOT EXISTS `controleproducteur` (
  `idUtilisateur` int(11) NOT NULL,
  `idVisite` int(11) NOT NULL,
  PRIMARY KEY (`idUtilisateur`),
  KEY `controleproducteur_ibfk_2` (`idVisite`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `lot`
--

CREATE TABLE IF NOT EXISTS `lot` (
  `idLot` int(11) NOT NULL,
  `quantite` float NOT NULL,
  `dateRecolte` date NOT NULL,
  `nbJourConservation` int(11) NOT NULL,
  `uniteDeVente` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `modeProduction` varchar(25) COLLATE utf8_unicode_ci NOT NULL,
  `ramassageManuel` tinyint(1) DEFAULT NULL,
  `prixUnitaire` float NOT NULL,
  `idProduit` int(11) NOT NULL,
  `idUtilisateur` int(11) NOT NULL,
  PRIMARY KEY (`idLot`),
  KEY `lot_ibfk_1` (`idProduit`),
  KEY `lot_ibfk_2` (`idUtilisateur`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `personnel`
--

CREATE TABLE IF NOT EXISTS `personnel` (
  `idPersonnel` int(11) NOT NULL,
  `nom` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `prenom` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `email` varchar(35) COLLATE utf8_unicode_ci NOT NULL,
  `typePersonnel` varchar(25) COLLATE utf8_unicode_ci NOT NULL,
  `ssNumber` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `mdp` varchar(60) COLLATE utf8_unicode_ci NOT NULL,
  `dateEmbauche` date NOT NULL,
  `supprimer` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`idPersonnel`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `pointvente`
--

CREATE TABLE IF NOT EXISTS `pointvente` (
  `idPV` int(11) NOT NULL,
  `adresse` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `codePostal` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `nom` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `activite` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `ville` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `tel` varchar(20) COLLATE utf8_unicode_ci DEFAULT NULL,
  `responsable` int(11) NOT NULL,
  PRIMARY KEY (`idPV`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `produit`
--

CREATE TABLE IF NOT EXISTS `produit` (
  `idProduit` int(11) NOT NULL,
  `libelle` varchar(100) COLLATE utf8_unicode_ci NOT NULL,
  `pU` float NOT NULL,
  `qte` int(11) NOT NULL,
  `idCategorie` int(11) NOT NULL,
  `accepte` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`idProduit`),
  KEY `produit_ibfk_1` (`idCategorie`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `proposera`
--

CREATE TABLE IF NOT EXISTS `proposera` (
  `idPV` int(11) NOT NULL,
  `idLot` int(11) NOT NULL,
  KEY `proposera_ibfk_1` (`idPV`),
  KEY `proposera_ibfk_2` (`idLot`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Structure de la table `rayon`
--

CREATE TABLE IF NOT EXISTS `rayon` (
  `idRayon` int(11) NOT NULL,
  `libelle` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`idRayon`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Contenu de la table `rayon`
--

INSERT INTO `rayon` (`idRayon`, `libelle`) VALUES
(1, 'Epicerie'),
(2, 'Fruits et Legumes'),
(3, 'Produits frais'),
(4, 'Complements alimentaires');

-- --------------------------------------------------------

--
-- Structure de la table `typeutilisateur`
--

CREATE TABLE IF NOT EXISTS `typeutilisateur` (
  `idTypeUtilisateur` int(1) NOT NULL,
  `libelle` varchar(32) COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Contenu de la table `typeutilisateur`
--

INSERT INTO `typeutilisateur` (`idTypeUtilisateur`, `libelle`) VALUES
(1, 'consommateur'),
(2, 'producteur'),
(3, 'pointDeVente');

-- --------------------------------------------------------

--
-- Structure de la table `utilisateur`
--

CREATE TABLE IF NOT EXISTS `utilisateur` (
  `idUtilisateur` int(11) NOT NULL,
  `nom` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `prenom` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `login` varchar(15) COLLATE utf8_unicode_ci NOT NULL,
  `mdp` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `adresse` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `ville` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `codePostal` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `email` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `tel` varchar(20) COLLATE utf8_unicode_ci DEFAULT NULL,
  `typeUtilisateur` int(10) unsigned NOT NULL,
  `cle` varchar(100) COLLATE utf8_unicode_ci NOT NULL,
  `dateInscription` date NOT NULL,
  `verifie` tinyint(1) NOT NULL,
  PRIMARY KEY (`idUtilisateur`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Contenu de la table `utilisateur`
--

INSERT INTO `utilisateur` (`idUtilisateur`, `nom`, `prenom`, `login`, `mdp`, `adresse`, `ville`, `codePostal`, `email`, `tel`, `typeUtilisateur`, `cle`, `dateInscription`, `verifie`) VALUES
(1, 'Khasanov', 'Apti', 'akhasanov', '9019f6cc666edb44cb65839867c3dc68f26534f4', '48 route Sainte Marguerite', 'Gap', '05000', 'apachethank@gmail.com', '753256227', 2, ' ', '2017-05-20', 0);

-- --------------------------------------------------------

--
-- Structure de la table `visite`
--

CREATE TABLE IF NOT EXISTS `visite` (
  `idVisite` int(11) NOT NULL,
  `libelle` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `dateVisite` date NOT NULL,
  `idRole` int(11) NOT NULL,
  PRIMARY KEY (`idVisite`),
  KEY `visite_ibfk_1` (`idRole`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `categorie`
--
ALTER TABLE `categorie`
  ADD CONSTRAINT `categorie_ibfk_1` FOREIGN KEY (`idRayon`) REFERENCES `rayon` (`idRayon`);

--
-- Contraintes pour la table `controleproducteur`
--
ALTER TABLE `controleproducteur`
  ADD CONSTRAINT `controleproducteur_ibfk_1` FOREIGN KEY (`idUtilisateur`) REFERENCES `utilisateur` (`idUtilisateur`),
  ADD CONSTRAINT `controleproducteur_ibfk_2` FOREIGN KEY (`idVisite`) REFERENCES `visite` (`idVisite`);

--
-- Contraintes pour la table `lot`
--
ALTER TABLE `lot`
  ADD CONSTRAINT `lot_ibfk_1` FOREIGN KEY (`idProduit`) REFERENCES `produit` (`idProduit`),
  ADD CONSTRAINT `lot_ibfk_2` FOREIGN KEY (`idUtilisateur`) REFERENCES `utilisateur` (`idUtilisateur`);

--
-- Contraintes pour la table `produit`
--
ALTER TABLE `produit`
  ADD CONSTRAINT `produit_ibfk_1` FOREIGN KEY (`idCategorie`) REFERENCES `categorie` (`idCategorie`);

--
-- Contraintes pour la table `proposera`
--
ALTER TABLE `proposera`
  ADD CONSTRAINT `proposera_ibfk_1` FOREIGN KEY (`idPV`) REFERENCES `pointvente` (`idPV`),
  ADD CONSTRAINT `proposera_ibfk_2` FOREIGN KEY (`idLot`) REFERENCES `lot` (`idLot`);

--
-- Contraintes pour la table `visite`
--
ALTER TABLE `visite`
  ADD CONSTRAINT `visite_ibfk_1` FOREIGN KEY (`idRole`) REFERENCES `personnel` (`idPersonnel`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
