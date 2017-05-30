<?php

include CHEMIN_LIB.'messages_en.php';
include CHEMIN_LIB.'db.php';

extract($_POST);

if(utilisateur_est_connecte())
{

	$produitDeclare=false;
	if($produitDeclare!=1)
	{
		include CHEMIN_VUE.'formulaire_declaration_produit.php';
	}
	
	if(isset($_POST['propose']))
	{
		$err = array();
		if(empty($_POST['quantity']))
			{$err[] = $errorQuantity1;}
		elseif(!preg_match("/^[0-9]+$/",$_POST['quantity']))
			{$err[] = $errorQuantity2;}	
		elseif(empty($_POST['harvestDate']))
			{$err[] = $errorHarvestDate1;}	
		elseif(!preg_match("/^[0-9]+$/",$_POST['harvestDate']))
			{$err[] = $errorHarvestDate2;}	
		elseif(empty($_POST['lengthPreservation']))
			{$err[] = $errorPreservationLength1;}
		elseif(!preg_match("/^[0-9]+$/",$_POST['lengthPreservation']))
			{$err[] = $errorPreservationLength2;}				
		elseif(empty($_POST['salesUnit']))
			{$err[] = $errorSalesUnit1;}	
		elseif(!preg_match("/^[0-9]+$/",$_POST['salesUnit']))
			{$err[] = $errorSalesUnit2;}	
		elseif(empty($_POST['productionMode']))
			{$err[] = $errorProductionMode1;}	
		elseif(!preg_match("/^[a-zA-Z]+$/",$_POST['productionMode']))
			{$err[] = $errorProductionMode2;}
		elseif(empty($_POST['unitPrice']))
			{$err[] = $errorUnitPrice1;}	
		elseif(!preg_match("/^[0-9]+$/",$_POST['unitPrice']))
			{$err[] = $errorUnitPrice2;}
		$resultat=$db_con->query("select IFNULL(MAX(idLot), 0) + 1 as id from lot;");
		$idmax =$resultat->fetch(PDO::FETCH_ASSOC);
		$idLot=$idmax['id'];
		// si ramassageManuel n'est pas coché
		if(!(isset($_POST['manuelCollecting'])))
		{
			$manuelCollecting = 0;
		}
		$idUtilisateur = $_SESSION['idUtilisateur'];
	    $sql = "insert into lot(idLot,quantite,dateRecolte,nbJourConservation,uniteDeVente,modeProduction,prixUnitaire,ramassageManuel,idProduit,idUtilisateur)
		values ($idLot, $quantity, '$harvestDate',$lengthPreservation,'$salesUnit',
		'$productionMode',$unitPrice,$manuelCollecting,$idProduit,$idUtilisateur);";
		$res= $db_con->prepare($sql);
		$res->execute();

	}

} else 
{
	echo "<div class='alert alert-info'>";
	echo "<strong>Info!</striong>$labelMessageNecessaryInscription";
	echo "</div>";
	include CHEMIN_CONTROLEUR.'inscription.php';
}	




?>