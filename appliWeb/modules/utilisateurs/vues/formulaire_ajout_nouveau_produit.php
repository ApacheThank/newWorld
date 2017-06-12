<div class="col-md-5 col-xs-offset">
<div class="card-block">
<form method="POST" enctype='multipart/form-data' id="proposition-produit">
	<div class="md-form">
	<h4><?=$labelAddProductIn?><?=$libCat?></h4>
	</div>
	<div class="md-form">
		<label for="productName"><?=$labelNameProduct?>:</label>
        	<input type="text" class="form-control" name="productName">
	</div>
	<div class="md-form">
		<label for="unitPriceNewProduct"><?=$labelAverageUnitPrice?>:</label>
        	<input type="text" class="form-control" name="unitPriceNewProduct">

	</div>
	<div class="md-form">
		<label for="quantityNewProduct"><?=$labelQuantity?>:</label>
        	<input type="text" class="form-control" name="quantityNewProduct">
	</div>

	<div class="md-form">	
     	<!-- On limite le fichier à 100Ko -->
    	  <input type="hidden" name="MAX_FILE_SIZE" value="100000">
     	File : <input type="file" name="imageProduit" id="imageProduit" accept="images/*">
	</div>
	<input type="submit" name="ajoutProduit" class="btn btn-default btn-sm" value="<?=$submitPropose?>">
</form>
</div>
</div>
</div><!-- class row est fermé -->