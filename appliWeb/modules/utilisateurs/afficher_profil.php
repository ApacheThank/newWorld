<?php
// Pas de v�rification de droits d'acc�s n�cessaire : tout le monde peut voir un profil utilisateur :)
// Si le param�tre id est manquant ou invalide
if (empty($_GET['id']) ) {

    	include CHEMIN_VUE.'erreur_parametre_profil.php';

} else {

	// On veut utiliser le mod�le des visiteurs (~/modeles/visiteurs.php)
	// include CHEMIN_MODELE.'visiteurs.php';
	// lire_infos_utilisateur() est d�fini dans ~/modeles/visiteurs.php
	// list($nom, $prenom, $mdp, $adresse, $cp, $ville ,$email, $avatar, $dateinscription, $hashvalidation) =$infos_utilisateur;
	// $form_inscription->get_cleaned_data('nom', 'prenom', 'mdp', 'adresse', 'codePostal', 'ville', 'email', 'avatar');
	// Probl�me list()   - remplac� par ci-dessous
	
	
	// lire_infos_utilisateur() est d�fini dans ~/modeles/visiteurs.php
	$infos_utilisateur = lire_infos_utilisateur($_GET['id']);
	
	if ($infos_utilisateur['typeUtilisateur'] == '1'){
	$fonction = "$valueConsumer";}
	else if ($infos_utilisateur['typeUtilisateur'] == '2'){
	$fonction ="$valueProducer";}
	else if ($infos_utilisateur['typeUtilisateur'] == '3'){
	$fonction = "$valuePointSale";}
	else{
	$fonction ="Error";}
	
	$login = $_GET['id'];
	$nom = $infos_utilisateur['nom'];
	$prenom = $infos_utilisateur['prenom'];
	$rue = $infos_utilisateur['adresse'];
	$codePostal = $infos_utilisateur['codePostal'];
	$ville = $infos_utilisateur['ville'];
	$email = $infos_utilisateur['email'];
	$num_tel = $infos_utilisateur['tel'];
    $dateinscription = $infos_utilisateur['dateInscription'];
	// Si le profil existe et que le compte est valid�
	 //if (false !== $infos_utilisateur && $infos_utilisateur['hashvalidation'] == 'OK' && $infos_utilisateur['hashvalidation'] == null) {
	
		include CHEMIN_VUE.'profil_infos_utilisateur.php';

	}


