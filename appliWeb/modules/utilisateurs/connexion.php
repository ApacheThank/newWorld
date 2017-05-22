<?php
// Vérification des droits d'accès de la page
if (utilisateur_est_connecte()) {
	// On affiche la page d'erreur comme quoi l'utilisateur est déjà connecté   
	include CHEMIN_VUE.'erreur_deja_connecte.php';
	
} else {

include CHEMIN_LIB.'form.php';
include CHEMIN_LIB.'messages_en.php';
$con=mysqli_connect("localhost", "akhasanov", "jamas003", "dbNewWorld_v1");
function mysqli_result($res, $row, $field=0) { 
		$res->data_seek($row); 
		$datarow = $res->fetch_array(); 
			return $datarow[$field]; 
		
		}
$connected = false;
if(isset($_POST['connect']))
{	
	$login = $_POST['login'];
	$mdp = $_POST['pass_verif'];
	$id_connexion = connexion($login,$mdp );
	if (false !== $id_connexion) 
	{
	    	// On enregistre les informations dans la session
		$_SESSION['login'] = $login;
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
		
		//$requeteMdp="select activeMdp from utilisateur where login='".$login."'";
		//$resultat = mysqli_query($con,$requeteMdp);
		//$res = mysqli_result($resultat,0,"activeMdp");
		/*// si uitilisateur se connecte premiere fois on l'oblige de changer son mot de passe 
		if(!($resultat=='1')) { // changement de la mot de passe lors de la premiere connexion
			/// reinitialisation de la mot de passe 
			// "form_modif_mdp" est l'ID unique du formulaire
			include_once CHEMIN_VUE.'formulaire_reinitialisation_mdp.php';
			
		} else 
		{
			include CHEMIN_VUE.'connexion_ok.php';
		}*/
		//$url="location:".CHEMIN_VUE.'connexion_ok.php';
		//header($url);
		include CHEMIN_VUE.'connexion_ok.php';
		$connected=true;
		
	} else {
	print $labelErrorConnection;
	
	}


}
if ($connected != 1)
{
 include CHEMIN_VUE.'formulaire_connexion.php';
}
}
?>
