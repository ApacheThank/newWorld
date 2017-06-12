<?php

// on charge les rayons et leurs catégories 
include_once CHEMIN_VUE.'formulaire_charger_produits.php';
$formulaireLot = false;
if(utilisateur_est_connecte())
{
	// lors du click 
	if(isset($_POST['propose']))
	{

		$err = array();
		// traitement des champs saisies par l'utilisateur
		if(empty($_POST['quantity']))
			{$err[] = $errorQuantity1;}
		elseif(!preg_match("/^[0-9]+$/",$_POST['quantity']))
			{$err[] = $errorQuantity2;}	
		elseif(empty($_POST['harvestDate']))
			{$err[] = $errorHarvestDate1;}	
		elseif(!preg_match("/^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$/",$_POST['harvestDate']))
			{$err[] = $errorHarvestDate2;}	
		elseif(empty($_POST['lengthPreservation']))
			{$err[] = $errorPreservationLength1;}
		elseif(!preg_match("/^[0-9]+$/",$_POST['lengthPreservation']))
			{$err[] = $errorPreservationLength2;}				
		elseif(empty($_POST['salesUnit']))
			{$err[] = $errorSalesUnit1;}	
		elseif(!preg_match("/[a-zA-Z0-9]+/",$_POST['salesUnit']))
			{$err[] = $errorSalesUnit2;}	
		elseif(empty($_POST['productionMode']))
			{$err[] = $errorProductionMode1;}	
		elseif(!preg_match("/[a-zA-Z]+/",$_POST['productionMode']))
			{$err[] = $errorProductionMode2;}
		elseif(empty($_POST['unitPrice']))
			{$err[] = $errorUnitPrice1;}	
		elseif(!preg_match("/^[+-]?([0-9]*[.])?[0-9]{2}+$/",$_POST['unitPrice']))
			{$err[] = $errorUnitPrice2;}

		$resultat=$db_con->query("select IFNULL(MAX(idLot), 0) + 1 as id from lot;");
		$idmax =$resultat->fetch(PDO::FETCH_ASSOC);
		$idLot=$idmax['id'];

		$quantity=$_POST['quantity'];
		$harvestDate=$_POST['harvestDate'];
		$lengthPreservation=$_POST['lengthPreservation'];
		$salesUnit=$_POST['salesUnit'];
		$productionMode=$_POST['productionMode'];
		$unitPrice=$_POST['unitPrice'];
		$idProduit = $_POST['leProduit'];
		// si ramassageManuel n'est pas coché
		if(!(isset($_POST['manuelCollecting'])))
		{
			$manuelCollecting = 0;
		}
		else { 	$manuelCollecting=$_POST['manuelCollecting']; }
		$idUtilisateur = $_SESSION['idUtilisateur'];
		// s'il n'y a pas d'erreur on fait la requête
		if(count($err) == 0 )
		{
		$sql = "insert into lot(idLot,quantite,dateRecolte,nbJourConservation,uniteDeVente,modeProduction,prixUnitaire,ramassageManuel,idProduit,idUtilisateur)
		values ($idLot, $quantity, '$harvestDate',$lengthPreservation,'$salesUnit',
		'$productionMode',$unitPrice,$manuelCollecting,$idProduit,$idUtilisateur);";
		$res= $db_con->prepare($sql);
		$res->execute();
		$formulaireLot=true;
		echo "<div class='col-md-5 col-xs-offset'>";
		echo "<div class='alert alert-success'>";
		echo "$labelMessageSuccesfullyDeclaredBatch";
		echo "</div></div>";

		} else { // si non on affiche les erreurs
			foreach($err AS $error)
    		{ 	echo "<div class='col-md-5 col-xs-offset'><div class='alert alert-info'>";
     	 		echo "<strong>Info!</strong>".$error."</div></div>";
     	 	}
     	 	}	 
		} // fin if isset
		// si le bouton proposer mon propre produit était appuyé on affiche le formulaire
		if(isset($_POST['proposerNouveauProduit'])){
			// recupere la catégorie saisie
			$cat=$_GET['idCategorie'];
			$libelle = $_GET['libelle'];
			$libCat=strtoupper($libelle);
			$formulaireLot = true;
			header("Location: index.php?module=utilisateurs&action=ajout_nouveau_produit&libelle=$libelle&idCategorie=$cat");
			//include CHEMIN_CONTROLEUR.'ajout_nouveau_produit.php';	
		}
		// on affiche le formulaire après la saisie de catégorie
		if($formulaireLot != 1 && isset($_GET['idCategorie']))
		{
			// recupere la catégorie saisie
			$cat=$_GET['idCategorie'];
			$libCat=strtoupper($_GET['libelle']);
			// ensuite on charge les produits selon la catégorie saisie
			$lesProduits=afficher_tous_les_produits($cat);
			include CHEMIN_VUE.'formulaire_ajout_lot.php'; 
		} else {  if(!isset($_POST['proposerNouveauProduit'])) {echo "</div>";}} // pour normaliser la classe row


} else 
{  // si non on demande de se connecter
	echo "<div class='row'>";
	echo "<div class='col-md-5 col-xs-offset'>";
	echo "<div class='alert alert-info'>";	
	echo "<strong>Info!</strong>$labelMessageNecessaryConnection";
	echo "</div></div>";
	include CHEMIN_CONTROLEUR.'connexion.php';
}	




?>
<script type="text/javascript">
  var action = "<?= $action=substr($action,0,strlen($action)-4); ?>";
</script>
<script src="scripts/chargerLesProduits.js">
</script>