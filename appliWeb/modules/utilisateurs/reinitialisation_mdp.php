<?php
// connexion premiere fois

#connection à la base de données
$con=mysqli_connect("localhost", "root", "ini01", "dbNewWorld");

include CHEMIN_LIB.'messages_en.php';
// include_once CHEMIN_VUE.'formulaire_reinitialisation_mdp.php';

// check connection
if(!mysqli_connect_errno())
{
if(isset($_POST['save']))
{
	$old_pswd = $_POST['old_pswd'];
	$new_pswd = $_POST['new_pswd'];
	$new_pswd_verif = $_POST['new_pswd_verif'];
	$verif_old_pswd = verif_ancien_mdp($_SESSION['login']);
	if(!($old_pswd == $verif_old_pswd)) {
		echo "Ancien mot de passe n'est pas correct";
	}
}
 else {
	 
 }
 
}
