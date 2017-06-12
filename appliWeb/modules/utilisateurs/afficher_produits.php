<?php

include_once CHEMIN_VUE.'formulaire_charger_produits.php';
//include_once CHEMIN_CONTROLEUR.'panier.php';
if(isset($_GET['idCategorie'])){
    $cat = $_GET['idCategorie'];
    $lesProduits= afficher_produits($cat);

?>
<div class="col-md-8 col-xs-offset">

<?php

foreach ($lesProduits as $produit) {
    $idProduit =$produit['idProduit'];
    $idProducteur = $produit['idUtilisateur'];
	$libelle=$produit['libelle'];
	$prix = $produit['prixUnitaire'];
	$dateRecolte=$produit['dateRecolte'];
	$uniteVente = $produit['uniteDeVente'];
	$image= $produit['image'];
    $prix = number_format($prix,2,',',' ');
    echo "<form method='post'>";
	echo "<div class='item  col-xs-6 col-lg-6'>";
	echo    "<div class='thumbnail'>";
	echo    	"<img class='group list-group-image' width='328px' height='282' src='$image' alt='' />";
	echo    	"<div class='caption'>";
	echo    		"<h4 class='group inner list-group-item-heading'>$libelle</h4>";
	echo    		"<p class='group inner list-group-item-text'>$labelSalesUnit $uniteVente</p>";
	echo    		"<div class='row'>";
	echo    			"<div class='col-xs-12 col-md-6'>";
	echo    				"<p class='lead'>$prix</p>";
	echo    			"</div>";
	echo    			"<div class='col-xs-12 col-md-6'>";
	echo    			"<a class='btn btn-success btn-sm' href='index.php?module=utilisateurs&amp;action=panier&amp;id=$idProducteur&amp;idproduit=$idProduit'>Add to cart</a>";
	echo    			"</div>";
	echo        	"</div>";
	echo    	"</div>";
	echo    "</div>";
	echo  "</div>";
}

?>
</div>
</div><!-- fin class row -->
<?php } else { echo "</div>";}?>


<script type="text/javascript">
  var action = "<?= $action=substr($action,0,strlen($action)-4); ?>";
</script>
<script src="scripts/chargerLesProduits.js">
</script>
