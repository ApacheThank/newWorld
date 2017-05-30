<?php include CHEMIN_LIB.'messages_en.php';?>
<h2><?=$labelTitleModification?></h2>
<?php
if (!empty($msg_confirm))
 {
	echo '<ul>'."\n";
	foreach($msg_confirm as $m) {
		echo '	<li>'.$m.'</li>'."\n";
	}
	echo '</ul>';
}

if (!empty($erreurs_form_modif_infos_localisation))
 {
	echo '<ul>'."\n";
	foreach($erreurs_form_modif_infos_localisation as $e) {
		echo '	<li>'.$e.'</li>'."\n";
	}
	echo '</ul>';
}


$form_modif_infos_localisation->fieldsets(array($labelModificationInfosLocalisation => array('adresse', 'codePostal', 'ville')));
echo $form_modif_infos_localisation;

if (!empty($erreurs_form_modif_mdp)) {
	echo '<ul>'."\n";
	foreach($erreurs_form_modif_mdp as $e) {
		echo '	<li>'.$e.'</li>'."\n";
	}
	echo '</ul>';
}


// $form_modif_mdp->fieldsets("Modification du mot de passe", array('mdp_ancien', 'mdp', 'mdp_verif'));
$form_modif_mdp->fieldsets(array($labelModificationPswd => array('mdp_ancien', 'mdp', 'mdp_verif')));
echo $form_modif_mdp;


