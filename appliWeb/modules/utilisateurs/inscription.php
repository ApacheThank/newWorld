<?php
// inscription d'un nouveau utilisateur

#connection à la base de données
include CHEMIN_LIB.'db.php';
$inscription_effectuee = false;
// check connection
if(!mysqli_connect_errno())
{
if(isset($_POST['registration']))
{      		
		
 $err = array();
 if(empty($_POST['lastName']))
 {$err[] = $errorLastName;}
	elseif(empty($_POST['firstName']))
	{$err[] = $errorFirstName;}	
	elseif(empty($_POST['login']))
	{$err[] = $errorLogin;}	
	# verification du login
	elseif(!preg_match("/^[a-zA-Z0-9]+$/",$_POST['login']))
	{$err[] = $errorLogin1;}
	elseif(strlen($_POST['login']) < 3 or strlen($_POST['login']) > 30)
	{$err[] = $errorLogin2;}
	elseif(empty($_POST['address']))
	{$err[] = $errorAddress;}
	#vérification de mail
	elseif(empty($_POST['email']))
	{$err[] = $errorMail1;}
	# vérification du format de mail
	elseif(!preg_match("/^[a-zA-Z0-9_\.\-]+@([a-zA-Z0-9\-]+\.)+[a-zA-Z]{2,6}$/", $_POST['email']))
	{$err[]= $errorMail2;}
	#vérification de ville
	elseif(empty($_POST['city']))
	{$err[] = $errorCity1;}
	elseif(!preg_match("/^[a-zA-Z0-9]+$/",$_POST['city']))
	{$err[] = $errorCity2;}	
	#vérification de code postale
	elseif(empty($_POST['zipCode']))
	{$err[] = $errorZipCode1;}
	elseif(preg_match("/^[0-9]{10,10}+$/",$_POST['zipCode']))
	{$err[] = $errorZipCode2;}		
	// Vérification de numéro de portable
	elseif(empty($_POST['phone_num']))
	{$err[] = $errorNumber1;}
	elseif(preg_match("/^[0-9]{12,14}+$/",$_POST['phone_num']))
	{$err[] = $errorNumber2;}
	elseif(!isset($_POST['option_user']))
	{$err[] = $errorTypeUser;}
	# vérification d'existance de l'utilisateur avec le mếme login
	$query =$db_con->query("SELECT COUNT(idUtilisateur) as loginExists FROM utilisateur WHERE login='".$_POST['login']."';");
	$resultat=$query->fetch(PDO::FETCH_ASSOC);
	# si login est déjà utilisé
	if($resultat['loginExists']!=0)
	{$err[] = $errorLogin3;}  
	# on regarde est-ce qu'il déjà existe dans notre base 
        $verif_mail = $db_con->query("SELECT count(idUtilisateur) as mailExists FROM utilisateur WHERE email='".$_POST['email']."';");
	$resultat=$query->fetch(PDO::FETCH_ASSOC);
	# si email déjà existe
	if($resultat['mailExists']!=0)
	{$err[] = $errorMail3;} 
	# si ne contient pas des erreurs, on ajoute à la base de données
	if(count($err) == 0 )
	{
	$firstName = $_POST['firstName'];
	$lastName = $_POST['lastName'];
	$login = $_POST['login'];
	$address = $_POST['address'];
	$city = $_POST['city'];
	$zipCode = $_POST['zipCode'];
	$mail = $_POST['email'];
	$phone = $_POST['phone_num'];
	$type_user = $_POST['option_user'];
	$resultat=$db_con->query("select ifnull(max(idUtilisateur),0)+1 as id from utilisateur;");
	$idmax =$resultat->fetch(PDO::FETCH_ASSOC);
	$id=$idmax['id'];
	$moment=date("Y-m-d");
	$password = generateCode(); 
	//envoi d'un e-mail pour inscription       
        $to=$mail;
        $sujet = 'Inscription';
		$message = $succesRegistration.'<br>';
		$message.= $yourLogin.$login.'<br>';
		$message.= $yourPassword.$password.'<br>';
        $message.= $confirmMessage;
        $entete = 'From: apachethank@gmail.com';
        $entete.= 'Return-Path: apachethank@gmail.com';
        $entete.= 'MIME-Version: 1.0'.'\n';
        $entete.= 'Content-Type: text/html; charset=UTF=8\r\n';
        $entete.= 'X-Mailer: PHP/' . phpversion();
		 //envoi de l'e-mail
        smtpmailer($to,$sujet,$message,$entete);
		
		
	$password = sha1($password); // chiffrement le mot de passe
	$requeteSql= ("INSERT INTO utilisateur SET idUtilisateur='".$id."', prenom='".$firstName."', nom='".$lastName."', 
	login='".$login."', adresse='".$address."', ville='".$city."', codePostal='".$zipCode."', 
	email='".$mail."', tel='".$phone."', mdp='".$password."', 
	dateInscription='".$moment."', typeUtilisateur='".$type_user."', cle=' ', active=0;");
	$res= $db_con->prepare($requeteSql);
	$res->execute();
	$inscription_effectuee=true;
	include CHEMIN_VUE.'inscription_effectuee.php';
	
	} else { 
	foreach($err AS $error)
    { echo "<div class='alert alert-info'>";
      echo "<strong>Info!</strong>".$error."</div>";}	  
    }
}
if ($inscription_effectuee!=1) {
	  // Affichage du formulaire inscription
	  include CHEMIN_VUE.'formulaire_inscription.php';
	}
}
else // we can't connect to database
{
	echo "Failed to connect to MySQL: " . mysqli_connect_errno();

}



?>
