<?php
// connexion premiere fois
	#connection à la base de données
	include CHEMIN_LIB.'db.php';

	
	// check connection
	$connection=false;
	
	if(isset($_POST['save']))
	{
		$id_connexion=$_SESSION['login'];
		$old_pswd = $_POST['old_pswd'];
		$new_pswd = $_POST['new_pswd'];
		$new_pswd_verif = $_POST['new_pswd_verif'];
		$verif_old_pswd = verif_ancien_mdp($id_connexion);
		$old_pswd = sha1($old_pswd);
		if(!($old_pswd == $verif_old_pswd)) {
			include CHEMIN_VUE.'erreur_activation_compte.php';	
		} 
		else 
		{  
			if($new_pswd == $new_pswd_verif)
			{
				$connection = true;				
				maj_mdp_membre($id_connexion,$new_pswd);
				activationCompte($_SESSION['login']);
				include CHEMIN_VUE.'compte_valide.php';
			}else { echo $errorNewPassword; }
		
		}
	}

	if ($connection != 1)
	{
		include CHEMIN_VUE.'formulaire_reinitialisation_mdp.php';
	}

	
