<?php

function combinaison_connexion_valide($login, $mdp) {

	$pdo = PDO2::getInstance();

	$requete = $pdo->prepare("SELECT login FROM utilisateur
		WHERE
		login = :login AND 
		mdp = :mdp ");

	$requete->bindValue(':login', $login);
	$requete->bindValue(':mdp', $mdp);
	$requete->execute();
	
	if ($result = $requete->fetch(PDO::FETCH_ASSOC)) {
	
		$requete->closeCursor();
		return $result['login'];
	}
	return false;
}

function lire_infos_utilisateur($id_connexion) {

	$pdo = PDO2::getInstance();

	$requete = $pdo->prepare("SELECT nom, prenom, login, adresse, ville, codePostal, email, mdp, dateInscription,typeUtilisateur,tel
		FROM utilisateur
		WHERE
		login = :id_connexion");
    	$requete->bindValue(':id_connexion', $id_connexion);
	$requete->execute();
	
	if ($result = $requete->fetch(PDO::FETCH_ASSOC)) {
	    //    echo "=> $result[nom] <br />";
		$requete->closeCursor();
		return $result;
	}
	return false;
}
function maj_email_membre($id_utilisateur, $email)
{
     $pdo = PDO2::getInstance();

	$requete = $pdo->prepare("UPDATE utilisateur SET
		email = :email
		WHERE
		login = :id_connexion");

	$requete->bindValue(':id_connexion', $id_connexion);
	$requete->bindValue(':email',$email);

	return $requete->execute();
}
function maj_mdp_membre($id_connexion,$mdp)
{
     $pdo = PDO2::getInstance();

	$requete = $pdo->prepare("UPDATE utilisateur SET
		mdp = :mdp
		WHERE
		login= :id_connexion");

	$requete->bindValue(':id_connexion', $id_connexion);
	$requete->bindValue(':mdp',$mdp);

	return $requete->execute();
}

function maj_infos_membre($id_connexion,$rue,$codePostal,$ville)
{
   
   $pdo = PDO2::getInstance();

	$requete = $pdo->prepare("UPDATE utilisateur SET
		adresse = :rue,
		codePostal = :codePostal,
		ville = :ville
		WHERE
		login = :id_connexion");

	$requete->bindValue(':id_connexion', $id_connexion);
	$requete->bindValue(':rue',$rue);
	$requete->bindValue(':codePostal',$codePostal);
	$requete->bindValue(':ville',$ville);

	return $requete->execute();
}

function verif_ancien_mdp($id_connexion)
{
		$pdo = PDO2::getInstance();
	
	$requete = $pdo->prepare("SELECT mdp
		FROM utilisateur
		WHERE
		login = :id_connexion");
		$requete->bindValue(':id_connexion', $id_connexion);
		$requete->execute();
		
		if ($result = $requete->fetch(PDO::FETCH_ASSOC)) {
	    //   echo "=> $result[mdp] <br />";
		$requete->closeCursor();
	}
	return $result;
		
	
}

function connexion($login, $mdp) 
{
    $mdp = sha1($mdp); // chiffrement le mot de passe sur varchar(40)
    $pdo = PDO2::getInstance();
    $requete = $pdo->prepare("SELECT login FROM utilisateur
		WHERE login = :login
                AND  mdp = :mdp;");
	// Associe une valeur à un paramètre
	$requete->bindValue(':login', $login);
	$requete->bindValue(':mdp', $mdp);
	$requete->execute();
	
	if ($result = $requete->fetch(PDO::FETCH_ASSOC)) {
		$requete->closeCursor();
		return $result['login'];
	}
	return false;
}




?>