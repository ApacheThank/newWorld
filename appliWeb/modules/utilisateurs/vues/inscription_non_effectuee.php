<?php

if (!empty($erreurs_inscription)) {

	echo '<ul>'."\n";
	
	foreach($erreurs_inscription as $e) {
	
		echo '	<li>'.$e.'</li>'."\n";
	}
	
	echo '</ul>';
//$form_inscription->fieldsets(array("Saisie de vos informations personnelles " => array('nom' ,'prenom','adresse', 'ville', 'codePostal', 'mdp','mdp_verif', 'email')));
//echo $form_inscription;