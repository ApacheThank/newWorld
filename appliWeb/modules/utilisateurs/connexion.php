<?php
// Vérification des droits d'accès de la page

include CHEMIN_LIB.'db.php';
	echo "<div class='row'>";

$connected = false;
if(isset($_POST['connect']))
{	
	$login = $_POST['login'];
	$mdp = $_POST['pass_verif'];
	$id_connexion = connexion($login,$mdp );
	if (false !== $id_connexion) 
	{
		// si le compte de l'utilisateur est déjà activé 
		// On enregistre les informations dans la session
		$_SESSION['login'] = $id_connexion;
		$infos_utilisateur = lire_infos_utilisateur($id_connexion);
		$_SESSION['nom'] = $infos_utilisateur['nom'];
		$_SESSION['prenom'] = $infos_utilisateur['prenom'];
		$_SESSION['email']  = $infos_utilisateur['email'];
		$_SESSION['adresse'] = $infos_utilisateur['adresse'];
		$_SESSION['codePostal']  = $infos_utilisateur['codePostal'];
		$_SESSION['typeUtilisateur']  = $infos_utilisateur['typeUtilisateur'];
		$_SESSION['ville']  = $infos_utilisateur['ville'];
		$_SESSION['login'] = $infos_utilisateur['login'];
		$_SESSION['idUtilisateur'] = $infos_utilisateur['idUtilisateur'];
		$requeteMdp=$db_con->query("select active from utilisateur where login='".$login."';");
		$res=$requeteMdp->fetch(PDO::FETCH_ASSOC);
		// si uitilisateur se connecte la premiere fois on l'oblige de changer son mot de passe 
		if($res['active']=='0') { // changement de la mot de passe lors de la premiere connexion
			/// reinitialisation de la mot de passe 
			$connected=true;
			header('Location: index.php?module=utilisateurs&action=reinitialisation_mdp');
		} else 
		{
						
			$connected=true;
			include CHEMIN_VUE.'connexion_ok.php';
		}
	} else {
	print $labelErrorConnection;
	}
}
if ($connected != 1)
{
	
 include CHEMIN_VUE.'formulaire_connexion.php';
}

?>
