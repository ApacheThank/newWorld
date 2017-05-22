<?php
// inscription d'un nouveau utilisateur

#connection à la base de données
$con=mysqli_connect("localhost", "akhasanov", "jamas003", "dbNewWorld_v1");

include CHEMIN_LIB.'messages_en.php';
$inscription_effectuee = false;
// check connection
if(!mysqli_connect_errno())
{
if(isset($_POST['registration']))
{
	function generateCode($length=6) {
		$chars = "aAbBcCdDeEfFgGhHjJiIkKlLmMnNoOpPqQrRsStTuUwWvVxXyYzZ0123456789";
		$code = "";
		$clen = strlen($chars) - 1;  
		while (strlen($code) < $length) {
			$code .= $chars[mt_rand(0,$clen)];  
		}
			return $code;
		}
	function mysqli_result($res, $row, $field=0) { 
		$res->data_seek($row); 
		$datarow = $res->fetch_array(); 
			return $datarow[$field]; 	
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
            $mail->Password='JaMaS003'; //ton mdp gmail
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
	elseif(preg_match("/^[0-9]{10,10}+$/",$_POST['phone_num']))
	{$err[] = $errorNumber2;}
	elseif(!isset($_POST['option_user']))
	{$err[] = $errorTypeUser;}
	# vérification d'existance de l'utilisateur avec le mếme login
	$resultat = mysqli_query($con,"SELECT COUNT(idUtilisateur) FROM utilisateur WHERE login='".mysqli_real_escape_string($con,$_POST['login'])."';");
	$query=mysqli_result($resultat,0,"COUNT(idUtilisateur)");
	# si login est déjà utilisé
	if($query)
	{$err[] = $errorLogin3;}  
	# on regarde est-ce qu'il déjà existe dans notre base 
	$resultat = mysqli_query($con,"SELECT count(idUtilisateur) FROM utilisateur WHERE email='".mysqli_real_escape_string($con, $_POST['email'])."';");
	$verif_mail = mysqli_result($resultat,0,"count(idUtilisateur)");
	# si email déjà existe
	if($verif_mail)
	{$err[] = $errorMail3;} 
	# si ne contient pas des erreurs, on ajoute à la base de données
	if(count($err) == 0 )
	{$firstName = $_POST['firstName'];
	$lastName = $_POST['lastName'];
	$login = $_POST['login'];
	$address = $_POST['address'];
	$city = $_POST['city'];
	$zipCode = $_POST['zipCode'];
	$mail = $_POST['email'];
	$phone = $_POST['phone_num'];
	$type_user = $_POST['option_user'];
	$requeteId="select max(idUtilisateur) from utilisateur;";
	$resultat = mysqli_query($con,$requeteId);
	$idmax = mysqli_result($resultat,0,"max(idUtilisateur)");
	$id = $idmax + 1; 
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
	$sql= ("INSERT INTO utilisateur SET idUtilisateur='".$id."', prenom='".$firstName."', nom='".$lastName."', 
	login='".$login."', adresse='".$address."', ville='".$city."', codePostal='".$zipCode."', 
	email='".$mail."', tel='".$phone."', mdp='".$password."', 
	dateInscription='".$moment."', typeUtilisateur='".$type_user."', cle=' ', verifie=0;");
	$requete0= mysqli_query($con,$sql);	
	// var_dump(mail);
	include CHEMIN_VUE.'inscription_effectuee.php';
	$inscription_effectuee=true;
	} else { 
	foreach($err AS $error)
    { echo "<div class='md-form'><p>" .$error."</p><br>";}	  
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
