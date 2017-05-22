<?php

include CHEMIN_LIB.'messages_en.php';
if(utilisateur_est_connecte())
{

	$produitDeclare=false;
	if($produitDeclare!=1)
	{
		include CHEMIN_VUE.'formulaire_declaration_produit.php';
	}

} else 
{
	echo "<div class='alert alert-info'>";
	echo "<strong>Info!</striong>$labelMessageNecessaryInscription";
	echo "</div>";
	include CHEMIN_CONTROLEUR.'inscription.php';
}	




?>