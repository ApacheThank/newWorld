<div class="col-md-7 col-xs-offset">
<div class="card-block">
<form method="POST" id="declaration-point-vente">
  <!--Header-->
    <div class="form-header">
        <h3><?=$labelDeclarationSalePoint?></h3>
    </div>
	<div class="md-form">
		<label for="companyName"><?=$labelCompanyName?>:</label>
        	<input type="text" class="form-control" name="companyName">
	</div>
	<div class="md-form">
		<label for="activity"><?=$labelActivity?>:</label>
        	<input type="text" class="form-control" name="activity">

	</div>
	<div class="md-form">
		<label for="address"><?=$labelAddress?>:</label>
        	<input type="text" class="form-control" name="address">
	</div>
	<div class="md-form">
		<label for="city"><?=$labelCity?>:</label>
        	<input type="text" class="form-control" name="city">
	</div>	
	<div class="md-form">
		<label for="zipCode"><?=$labelZipCode?>:</label>
        	<input type="text" class="form-control" name="zipCode">
	</div>
	<div class="md-form">
		<label for="phone_num"><?=$labelPhone?>:</label>
        	<input type="text" class="form-control" name="phone_num">
	</div>
	<div class="md-form">
	<input type="submit" class="btn btn-default btn-sm" name="declarePoint" value="<?=$aDeclarePoint?>">
	</div>
</form>
</div>
</div>
</div>