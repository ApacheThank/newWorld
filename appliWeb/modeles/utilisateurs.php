<?php

function generateCode($length=8) {
		$chars = "aAbBcCdDeEfFgGhHjJiIkKlLmMnNoOpPqQrRsStTuUwWvVxXyYzZ0123456789";
		$code = "";
		$clen = strlen($chars) - 1;  
		while (strlen($code) < $length) {
			$code .= $chars[mt_rand(0,$clen)];  
		}
			return $code;
}
	   
//fonction e-mail
function smtpmailer($to,$sujet,$message,$entete){
	require_once("PHPMailer/class.phpmailer.php");
	require_once("PHPMailer/class.smtp.php");
	$mail = new PHPMailer();
	$mail->IsSMTP();
	$mail->IsHTML();    
	$mail->Host='localhost';
	$mail->SMTPDebug=0;
	$mail->SMTPAuth=true;
	$mail->SMTPSecure='ssl';
	$mail->Host='smtp.gmail.com';
	$mail->Port=465;
	$mail->Username='apachethank@gmail.com';
	$mail->Password='****'; //ton mdp gmail
	$mail->SetFrom('apachethank@gmail.com');
	$mail->AddReplyTo('apachethank@gmail.com');
	$mail->CharSet="utf-8";
	$mail->Subject = $sujet;
	$mail->Body = $message;
	$mail->AddAddress($to);
                 
	if(!$mail->Send()){
		echo 'E-mail non envoyé';
		echo 'Mailer error:'.$mail->Errorinfo;
	}else{
		echo 'Message envoyé';
	}
} //fin fonction e-mail

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

	$requete = $pdo->prepare("SELECT idUtilisateur, nom, prenom, login, adresse, ville, codePostal, email, mdp, dateInscription,typeUtilisateur,tel
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
	$mdp=sha1($mdp);
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
		return $result['mdp'];
	}
	return $result;
		
	
}

function connexion($login, $mdp) 
{
    $mdp = sha1($mdp);// chiffrement le mot de passe sur varchar(40)
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

function compteActive($login)
{
	$pdo = PDO2::getInstance();
	$requete = $pdo->prepare("select active from utilisateur	
					where login = :login;");
	$requete->bindValue(':login',$login);
	$requete->execute();
	if ($result = $requete->fetch(PDO::FETCH_ASSOC)) {
		$requete->closeCursor();
		return $result['active'];
	}
	return $result;
}

function activationCompte($login)
{
	$pdo = PDO2::getInstance();
	$requete = $pdo->prepare("update utilisateur
				set active=1
				where login = :login;");
	$requete->bindValue(':login',$login);
	$requete->execute();
}
// afficher les rayons
function afficher_rayons() {
	$tableau=array();
	$pdo=PDO2::getInstance();
	$requete=$pdo->prepare("select * from rayon;");
	$requete->execute();
	$i=0;
	while ($result = $requete->fetch(PDO::FETCH_ASSOC)) {
		$tableau[$i]=$result;
		$i++;
	}
	$requete->closeCursor();
	return $tableau;
}	
// afficher les catégories 
function afficher_categories($ray) {
	$tableau=array();
	$pdo=PDO2::getInstance();
	$requete=$pdo->prepare("select * from categorie where idRayon=:ray;");
	$requete->bindValue(':ray',$ray);
	$requete->execute();
	$i=0;
	while ($result = $requete->fetch(PDO::FETCH_ASSOC)) {
		$tableau[$i]=$result;
		$i++;
	}
	$requete->closeCursor();
	return $tableau;
}	

// Afficher les produits
function afficher_produits($cat){
	$tableau=array();
	$pdo=PDO2::getInstance();
	$requete=$pdo->prepare("select * from lot l inner join produit p on l.idProduit=p.idProduit where idCategorie=:cat;");
	$requete->bindValue(':cat',$cat);
	$requete->execute();
	$i=0;
	while ($result = $requete->fetch(PDO::FETCH_ASSOC)) {
		$tableau[$i]=$result;
		$i++;
	}
	$requete->closeCursor();
	return $tableau;
}


// Afficher les produits
function afficher_tous_les_produits($cat){
	$tableau=array();
	$pdo=PDO2::getInstance();
	$requete=$pdo->prepare("select * from produit where accepte=1 and idCategorie=:cat;");
	$requete->bindValue(':cat',$cat);
	$requete->execute();
	$i=0;
	while ($result = $requete->fetch(PDO::FETCH_ASSOC)) {
		$tableau[$i]=$result;
		$i++;
	}
	$requete->closeCursor();
	return $tableau;
}

function rechercher_categorie_rayon($idProduit){
	$tableau=array();
	$pdo=PDO2::getInstance();
	$requete=$pdo->prepare("select c.libelle as libCategorie, r.libelle
		from produit p 
		inner join categorie c on p.idCategorie=c.idCategorie 
		inner join rayon r on c.idRayon=r.idRayon
		where p.idProduit = :idProduit;");
	$requete->bindValue(':idProduit',$idProduit);
	$requete->execute();
	$i=0;
	while ($result = $requete->fetch(PDO::FETCH_ASSOC)) {
		$tableau[$i]=$result;
		$i++;
	}
	$requete->closeCursor();
	return $tableau;

}

?>
