CREATE TABLE IF NOT EXISTS rayon
(
idRayon int(11) NOT NULL PRIMARY KEY,
libelle varchar(30) NOT NULL
);

CREATE TABLE IF NOT EXISTS categorie
(idCategorie int(11) NOT NULL,
libelle varchar(30) NOT NULL,
idRayon int(11) NOT NULL,
PRIMARY KEY(idCategorie),
FOREIGN KEY (idRayon) REFERENCES rayon(idRayon)
);

CREATE TABLE IF NOT EXISTS utilisateur
(
idUtilisateur int(11) NOT NULL PRIMARY KEY,
nom varchar(30) NOT NULL,
prenom varchar(30) NOT NULL,
dateNaissance varchar(30) NOT NULL,
login varchar(15) NOT NULL,
mdp varchar(30) NOT NULL,
adresse varchar(50) NOT NULL,
ville varchar(30) NOT NULL,
codePostal varchar(10) NOT NULL,
email varchar(50) NOT NULL,
tel varchar(20) NOT NULL,
typeUtilisateur tinyint(4) NOT NULL,
cle varchar(100) NOT NULL,
dateInscription date NOT NULL,
verifie tinyint(1) NOT NULL
);


CREATE TABLE IF NOT EXISTS produit
(
idProduit int(11) NOT NULL,
libelle varchar(100) NOT NULL,
pU float NOT NULL,
qte int(11) NOT NULL,
idCategorie int(11) NOT NULL,
PRIMARY KEY(idProduit),
FOREIGN KEY (idCategorie) REFERENCES categorie(idCategorie)
);

CREATE TABLE IF NOT EXISTS lot
(
idLot int(11) NOT NULL PRIMARY KEY,
quantite float NOT NULL,
dateRecolte date NOT NULL,
nbJourConservation int(11) NOT NULL,
uniteDeVente varchar(50) NOT NULL,
modeProduction varchar(25) NOT NULL,
ramassageManuel tinyint(1) NOT NULL,
prixUnitaire float NOT NULL,
idProduit int(11) NOT NULL,
idUtilisateur int(11) NOT NULL,
FOREIGN KEY (idProduit) REFERENCES produit(idProduit),
FOREIGN KEY (idUtilisateur) REFERENCES utilisateur(idUtilisateur)
);

CREATE TABLE IF NOT EXISTS pointVente
(
idPV int(11) NOT NULL PRIMARY KEY,
adresse varchar(50) NOT NULL,
codePostal varchar(10) NOT NULL,
nom varchar(50) NOT NULL,
activite varchar(50) NOT NULL,
ville varchar(30) NOT NULL,
tel varchar(20) NOT NULL,
responsable int(11) NOT NULL
);


CREATE TABLE IF NOT EXISTS personnel
(
idPersonnel integer NOT NULL PRIMARY KEY,
nom varchar(30) NOT NULL,
prenom varchar(30) NOT NULL,
adresse varchar(30) NOT NULL,
ville varchar(30) NOT NULL,
codePostal varchar(10) NOT NULL,
email varchar(35) NOT NULL,
typePersonnel varchar(25) NOT NULL,
ssNumber varchar(30) NOT NULL,
mdp varchar(60) NOT NULL,
dateEmbauche date NOT NULL,
supprimer boolean NOT NULL DEFAULT FALSE
);

CREATE TABLE IF NOT EXISTS visite
(
idVisite int(11) NOT NULL PRIMARY KEY,
libelle varchar(30) NOT NULL,
dateVisite date NOT NULL,
idRole int(11) NOT NULL,
FOREIGN KEY (idRole) REFERENCES personnel(idPersonnel)
);

CREATE TABLE IF NOT EXISTS proposerA(
idPV int(11) NOT NULL,
idLot int(11) NOT NULL,
FOREIGN KEY (idPV) REFERENCES pointVente(idPV),
FOREIGN KEY (idLot) REFERENCES lot(idLot)
);


CREATE TABLE IF NOT EXISTS ControleProducteur 
(
idUtilisateur int(11) NOT NULL PRIMARY KEY,
idVisite int(11) NOT NULL,
FOREIGN KEY (idUtilisateur) REFERENCES utilisateur(idUtilisateur),
FOREIGN KEY (idVisite) REFERENCES visite(idVisite)
);



alter table personnel add column login varchar(32) NOT NULL;
alter table utilisateur add foreign key (typeUtilisateur) references typeUtilisateur(idTypeUtilisateur);
alter table personnel add column adresse varchar(50) NOT NULL;
alter table personnel add column ville varchar(30) NOT NULL;
alter table personnel add column codePostal varchar(10) NOT NULL;
alter table personnel add column tel varchar(20) NOT NULL;

insert into personnel 
values (1,"Dupond", "Jean","jdupond@mail.fr","gestion","1788952415474","123","2017-04-01",0,"gestion","6 rue Cadet de Charance","Gap","05000","0753256227");
insert into personnel 
values (3,"Jean","Michel","jmichel@mail.fr","control","178522141574","123","2017-04-11",0,"control"," rue Capitaine de Bresson","Gap","05000","0778254558");


insert into utilisateur 
values (1,"Khasanov","Apti","akhasanov","jamas","6 rue","Gap","05000","apachethank@gmail.com","07532256227",
2,"cle a savoir","2017-04-20",1);
insert into utilisateur 
values (2,"Jimmy","Las","las","123","1 rue","Marseille","13000","jimlas@gmail.com","0755556227",
1,"cle a savoir","2017-02-01",0);
insert into utilisateur 
values (3,"Lafleur","Jessica","jesica","12345","charance de fleur","Monaco","98000","jassicafleur@gmail.com","065879927",3,"cle a savoir","2015-07-11",1);
insert into utilisateur 
values (4,"Bernard","jax","bjax","12345","capitaine bresson","Nice","06000","bernardjax@gmail.com","077852556227",2,"cle a savoir","2017-01-31",0);
insert into utilisateur 
values (5,"Jean","Michel","jmichel","michem","rue de paris","Manosque","04006","jeanmichel@gmail.com","04589366",
2,"cle a savoir","2017-03-20",1);



insert into typeUtilisateur
values (1,"consommateur");
insert into typeUtilisateur
values (2,"producteur");
insert into typeUtilisateur
values (3,"pointDeVente");

select libelle, nom,prenom from utilisateur u inner join typeUtilisateur t on u.typeUtilisateur=t.idTypeUtilisateur where typeUtilisateur=2;


alter table produit add column accepte boolean NOT NULL default false;



insert into lot values (1,25,"2017-05-05",14,"5","hors sol",1,2.4,10,1);
