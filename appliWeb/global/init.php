<?php
// Inclusion du fichier de configuration (qui définit des constantes)
include 'global/config.php';
include 'libs/messages_en.php';
// Désactivation des guillemets magiques
ini_set('magic_quotes_runtime', 0);
// set_magic_quotes_runtime(0);

if (1 == get_magic_quotes_gpc())
{
	function remove_magic_quotes_gpc(&$value) {
	
		$value = stripslashes($value);
	}
	array_walk_recursive($_GET, 'remove_magic_quotes_gpc');
	array_walk_recursive($_POST, 'remove_magic_quotes_gpc');
	array_walk_recursive($_COOKIE, 'remove_magic_quotes_gpc');
}

// Inclusion de Pdo2, potentiellement utile partout
include CHEMIN_LIB.'pdo2.php';

// Vérifie si l'utilisateur est connecté   
function utilisateur_est_connecte() {
 
	return !empty($_SESSION['login']);
}
// -------version 2 ---------------------------------------------------

// Vérifications pour la connexion automatique

// On a besoin du modèle des visiteurs
include CHEMIN_MODELE.'utilisateurs.php';       // Pour la fonction connexion()
// L'utilisateur n'est pas connecté mais les cookies sont présents
if (!utilisateur_est_connecte() && !empty($_COOKIE['login']) && !empty($_COOKIE['connexion_auto']))
{
	$infos_utilisateur = lire_infos_utilisateur($_COOKIE['login']);
	
	if (false !== $infos_utilisateur)
	{
		$navigateur = (!empty($_SERVER['HTTP_USER_AGENT'])) ? $_SERVER['HTTP_USER_AGENT'] : '';
		$hash = sha1('aaa'.$infos_utilisateur['nom'].'bbb'.$infos_utilisateur['mdp'].'ccc'.$navigateur.'ddd');
		
		if ($_COOKIE['connexion_auto'] == $hash)
		{
			// On enregistre les informations dans la session
			$_SESSION['login']     = $_COOKIE['login'];
			$_SESSION['nom'] = $infos_utilisateur['nom'];
			$_SESSION['email']  = $infos_utilisateur['email'];
			$_SESSION['login']  = $infos_utilisateur['login'];
			$_SESSION['type_user']  = $infos_utilisateur['type_user'];

		}
	}
}
?>
