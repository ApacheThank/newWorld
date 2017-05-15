CREATE TABLE IF NOT EXISTS utilisateur (
  id varchar(30) NOT NULL,
  nom char(30) NOT NULL,
  prenom char(30) not NULL,
  login char(20) not NULL,
  mdp char(40) not NULL,
  adresse char(30) not NULL,
  cp char(5) not NULL,
  ville char(30) not NULL,
  email varchar(128) not NULL,
  tel int(15) NOT NULL,
  dateinscription date not null,
  type_user varchar(10) NOT NULL,
  PRIMARY KEY (id),
  UNIQUE KEY adresse_email (email),
  KEY mot_de_passe (mdp)
) ENGINE=InnoDB not null CHARSET=utf8;


INSERT INTO utilisateur values (2, 'Khasanov', 'Apti', 'khasanov', '12345', '6 rue cadet', '05000', 'Gap','apache@gmail.com',0753256227,'2017-02-18','control');

INSERT INTO utilisateur values (1, 'Khasanov', 'Apti', 'khasanov', '123', '6 rue cadet', '05000', 'Gap','apachethank@gmail.com',0753256227,'12/02/2017','gestion');




/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */

CREATE TABLE IF NOT EXISTS producteur (
  id varchar(30) NOT NULL,
  nom char(30) NOT NULL,
  prenom char(30) not NULL,
  denom_soc char(30) DEFAULT NULL,
  login char(20) not NULL,
  mdp char(40) not NULL,
  adresse char(30) not NULL,
  cp char(5) not NULL  references villes_france_free(ville_code_commune),
  ville char(30) not NULL,
  email varchar(128) not NULL,
  tel int(15) NOT NULL,
  dateEmbauche date not null,
  vis_prevue date DEFAULT NULL,
  der_vis date DEFAULT NULL,
  valid boolean default false,
  PRIMARY KEY (id),
  UNIQUE KEY adresse_email (email),
  KEY mot_de_passe (mdp)
) ;

INSERT INTO producteur values (1, 'Khasanov', 'Apti', 'Alpagel','khasanov', '123', '6 rue cadet', '05000', 'Gap','apachethank@gmail.com',0753256227,'2017-01-01','2017-02-01','2017-27-01',true);

INSERT INTO producteur values (2, 'Khasanov', 'Apti', 'Gimo','khasanov', '123', '6 rue cadet', '04400', 'Manosque','thankyou@gmail.com',0753256227,'2017-01-02','0','0',false);

INSERT INTO producteur values (3, 'Dupond', 'Jean', 'Jak','hasanov', '123', 'cadet', '08930', 'Moiliseres','kiloa@lialo.fr',0753256227,'2017-01-02','0','2017-03-17',false);




CREATE TABLE IF NOT EXISTS visite (
idVisite int NOT NULL,
type_user varchar(10) NOT NULL REFERENCES utilisateur(id), 
libelleVisite varchar(25) NOT NULL,
dateVisite date NOT NULL,
PRIMARY KEY(idVisite)
);
