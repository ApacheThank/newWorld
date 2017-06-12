<?php

include_once CHEMIN_VUE.'formulaire_contact.php';

if(isset($_POST['submit']))
{
 $err = array();
if(empty($_POST['firstName']))
	{$err[] = $errorFirstName;}
	#vérification de mail
	elseif(empty($_POST['email']))
	{$err[] = $errorMail1;}
	# vérification du format de mail
	elseif(!preg_match("/^[a-zA-Z0-9_\.\-]+@([a-zA-Z0-9\-]+\.)+[a-zA-Z]{2,6}$/", $_POST['email']))
	{$err[]= $errorMail2;}
	elseif(empty($_POST['comment']))
	{$err[] = $errorComment;}
	if(count($err) == 0 ) {
	$firstName = $_POST['firstName'];
	$email = $_POST['email'];
	$comment= $_POST['comment'];
		$to = 'apachethank@gmail.com'; 
		// $from - de qui
		$from=$email; 
		$message = $comment;
		// fonction qui envoie le courier
		mail($to, $subjectMessage, $message, $from); 
	}
}
?>