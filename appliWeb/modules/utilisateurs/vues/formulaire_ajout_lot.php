<div class="col-md-5 col-xs-offset">
<div class="card-block">
<form method="POST" id="formulaire-produit">
	<div class="md-form">
	<h4><?=$labelProductionBatch?><?=$libCat?></h4>
	</div>
	<div class="md-form">
		<select class="form-control" name ="leProduit" id="listProduits"> 
		<?php foreach($lesProduits as $produit) {
			$idCat = $produit['idCategorie'];
			$idProduit = $produit['idProduit'];
			$libelle = $produit['libelle'];
			echo "<option name='$idCat' value='$idProduit'>$libelle</option>";
		} 
		?>
		</select>
    </div>
    <div class="md-form">
	<label for="quantity"><?=$labelQuantity?>:</label>
        <input type="text" class="form-control" name='quantity'>
    </div>
    		<label for="quantity"><?=$labelDateHarvest?>:</label>

	<div class="md-form">
   		<input type="date" min="2017-01-01" class="form-control" name="harvestDate">

	</div>
    <div class="md-form">
		<label for="lengthPreservation"><?=$labelLengthPreservation?>:</label>
        <input type="text" class="form-control" name="lengthPreservation">
    </div>
	<div class="md-form">
      <label for="salesUnit"><?=$labelSalesUnit?>:</label>
        <input type="text" class="form-control" name="salesUnit">
    </div>
	<div class="md-form">
      <label for="productionMode"><?=$labelProductionMode?>:</label>
        <input type="text" class="form-control" name="productionMode">
    </div>
	<div class="md-form">
      <label for="unitPrice"><?=$labelUnitPrice?>:</label>
        <input type="text" class="form-control" name="unitPrice">
    </div>
	    
<fieldset class="form-group">
    <input type="checkbox" name="manuelCollecting" id="manuelCollecting" value="1">
    <label for="manuelCollecting"><?=$labelManuelCollecting?></label>
</fieldset>
    <div class="md-form">
	<table>
	<tr><td>       
        <input type="submit" name="propose" id="propose" class="btn btn-default btn-sm" value="<?=$submitPropose?>">
	</td><td align="right"><input type="submit" id="proposerNouveauProduit" name="proposerNouveauProduit" class="btn btn-warning btn-sm" value="<?=$labelProposeMyOwnProduct?>"></td></tr>
	<tr><td colspan="2">
	<p><?=$labelIfYouNotFind?></p>
	</td></tr></table>
	</div>
</form>
</div>
</div>
</div>
