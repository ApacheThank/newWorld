<?php
include_once CHEMIN_VUE.'formulaire_charger_produits.php';

$libCat=strtoupper($_GET['libelle']);
if(utilisateur_est_connecte())
{

	$formulaire_ajout = false;
	if(isset($_POST['ajoutProduit']))
	{
		$err = array();
		$productName = $_POST['productName'];
		$unitPrice = $_POST['unitPriceNewProduct'];
		$quantity = $_POST['quantityNewProduct'];
		if(empty($productName))
		{$err[]=$errorProductName1;}
		elseif(!preg_match("/[a-zA-Z]+/", $productName ))
		{$err[]=$errorProductName2;}
		// on vérifie si le produit rentré n'existe pas par hasard dans notre base(utilisateur est dans la mouvaise catégorie ou quelque chose autre)
		$query =$db_con->query("select idProduit,libelle, idCategorie from produit where libelle='".$productName."' and accepte=1");
		$produitExists =$query->fetch(PDO::FETCH_ASSOC);
		$produitExists = $produitExists['idProduit'];
		// si ce produit existe on recherche son rayon et sa catégorie
		if($produitExists!=0){ 
			$produitExistant = rechercher_categorie_rayon($produitExists);
			$libCategorie = $produitExistant[0]['libCategorie'];
			$libRayon = $produitExistant[0]['libelle'];
			$err[] = $product."<strong>".$productName."</strong>".$errorProductExists1."<strong>".$libCategorie."</strong>".$errorProductExists2."<strong>".$libRayon."</strong>";
		} 
					
		if(count($err)==0) {
			$resultat=$db_con->query("select ifnull(max(idProduit),0)+1 as id from produit;");
			$idmax =$resultat->fetch(PDO::FETCH_ASSOC);
			$idProduit=$idmax['id'];
			include CHEMIN_LIB.'uploadImage.php';
			$image = $dossier."/".$fichier;
			$idCategorie = $_GET['idCategorie'];
			$sql = "insert into produit values ($idProduit,'$productName',$unitPrice,$quantity,$idCategorie,0,'$image');";
			$res = $db_con->prepare($sql);
			$res->execute();
			$formulaire_ajout = true;
				echo "<div class='col-md-5 col-xs-offset'><div class='alert alert-success'>";
			echo $labelProducAdded;
			echo "</div>";
			echo "</div>";
			echo "</div>";


		} else { // si non on affiche les erreurs
			foreach($err AS $error)
    		{ 	echo "<div class='col-md-5 col-xs-offset'><div class='alert alert-info'>";
     	 		echo $error."</div></div>";
     	 	}
     	}
	

	}
	if($formulaire_ajout!=1){
			include CHEMIN_VUE.'formulaire_ajout_nouveau_produit.php';
	}


} else 
{
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