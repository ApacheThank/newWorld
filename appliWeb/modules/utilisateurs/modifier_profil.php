<?php
// Vérification des droits d'accès de la page
if (!utilisateur_est_connecte()) {
	// On affiche la page d'erreur : l'utilisateur doit être connecté pour accéder à la page
	include CHEMIN_VUE.'erreur_non_connecte.php';
} else {
	// Ne pas oublier d'inclure la librairie Form
	include CHEMIN_LIB.'form.php';
    # "form_modif_infos" est l'ID unique du formulaire
	$form_modif_infos_localisation = new Form("form_modif_infos_localisation");
	
	$form_modif_infos_localisation->method('POST');
	
	$form_modif_infos_localisation->add('Text', 'adresse')
                         ->label($labelAddress)
                         ->Required(true)
                         ->value($_SESSION['adresse']);
	
	$form_modif_infos_localisation->add('Text', 'codePostal')
                         ->label($labelZipCode)
                         ->Required(true)
                         ->value($_SESSION['codePostal']);
	
	$form_modif_infos_localisation->add('Text', 'ville')
                         ->label($labelCity)
                         ->Required(true)
                         ->value($_SESSION['ville']);


	$form_modif_infos_localisation->add('Submit', 'submit')
                         ->value($submitModify);			 

	// "form_modif_mdp" est l'ID unique du formulaire
	$form_modif_mdp = new Form("form_modif_mdp");
	
	$form_modif_mdp->method('POST');
	
	$form_modif_mdp->add('Password', 'mdp_ancien')
                       ->label( $labelOldPswd);
	
	$form_modif_mdp->add('Password', 'mdp')
                       ->label($labelNewPswd);
	
	$form_modif_mdp->add('Password', 'mdp_verif')
                       ->label($labelNewPswdVerif);
	
	$form_modif_mdp->add('Submit', 'submit')
					->value($submitModifyPswd);
	
	// Création des tableaux des erreurs (un par formulaire)
	$erreurs_form_modif_infos_localisation = array();
	$erreurs_form_modif_infos = array();
	$erreurs_form_modif_mdp   = array();
	
	// Et d'un tableau des messages de confirmation
	$msg_confirm = array();
	
	// Validation des champs suivant les règles en utilisant les données du tableau $_POST
	$form_modif_infos_localisation->is_valid($_POST);
	  if ($form_modif_infos_localisation->is_valid($_POST)) { 
		list($adresse, $codePostal, $ville) = $form_modif_infos_localisation->get_cleaned_data('adresse', 'codePostal', 'ville');
		// Si l'un des champs est vide 
		if ((     empty($adresse ) )||(empty($codePostal)) ||(empty($ville))    ) {
		   $erreurs_form_modif_infos_localisation[] = $labelErrorFillAllFields;
		}
		else{
		
			$testCP = strlen($codePostal ) ;;
			if ( $testCP != 5 ) 
			{
				$erreurs_form_modif_infos_localisation[] = $labelErrorZipCode;
			}
			
			if ( intval($codePostal) == FALSE )
			{
				$erreurs_form_modif_infos_localisation[] = $labelErrorInvalidZipCode;
			}
            
			if (empty($erreurs_form_modif_infos_localisation) ) { 	// cas OK  
			
				if(maj_infos_membre($_SESSION['login'],$adresse, $codePostal, $ville))
				{
					$_SESSION['adresse']=$adresse;
					$_SESSION['cp']=$codePostal;
					$_SESSION['ville']=$ville;
					$msg_confirm[] =$messageSuccesModifyAddress;
				}
				else {
				$erreurs_form_modif_infos_localisation[] = "Error code contact to administrator: AS005";
				}
			}
			
		}   
	}
	
	// Validation des champs suivant les règles en utilisant les données du tableau $_POST
		
	  if ($form_modif_mdp->is_valid($_POST)) {
		// On vérifie si les 2 mots de passe correspondent
		list($mdpNouveau,$mdp_verif,$mdp_ancien)= $form_modif_mdp->get_cleaned_data('mdp','mdp_verif','mdp_ancien');
		
		$vrif_mdp = verif_ancien_mdp($_SESSION['login']);
		 $mdp_ancien_cript = sha1($mdp_ancien);
		 $mdp_util_old =$vrif_mdp['mdp'];
		
		if ($mdpNouveau != $mdp_verif) {
				$erreurs_form_modif_mdp[] = $errorNewPassword ;
		
		}
		else if ($mdp_util_old != $mdp_ancien_cript){
		$erreurs_form_modif_mdp[] = $labelErrorCurrentPswd;
		} else{
			// C'est bon, on peut modifier la valeur dans la BDD
		    maj_mdp_membre($_SESSION['login'], sha1($mdpNouveau));
			$msg_confirm[] = $messageSuccesModifyPswd ;
		}
	}
}

// Affichage des formulaires de modification du profil
include CHEMIN_VUE.'formulaires_modifier_profil.php';
