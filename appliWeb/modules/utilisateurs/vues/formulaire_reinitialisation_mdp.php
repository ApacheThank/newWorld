<div class="row">
<div class="col-xs-5">
<div class="card-block">
<form method="POST">
<table id="reinit_pswd">
<!--Header-->
    <div class="text-center">
        <h3><?=$labelDemandeAccountActivation?></h3>
        <hr class="mt-2 mb-2">
    </div>
	<div class="md-form">
        <input type="password" name="old_pswd" class="form-control">
        <label for="old_pswd"><?=$labelOldPswd?></label>
    </div>
	<div class="md-form">
        <input type="password" name="new_pswd" class="form-control">
        <label for="new_pswd"><?=$labelNewPswd?></label>
    </div>
	<div class="md-form">
        <input type="password" name="new_pswd_verif" class="form-control">
        <label for="new_pswd_verif"><?=$labelNewPswdVerif?></label>
    </div>
<tr><td><p id='requiredField' align='left'>*<?=$pRequiredField?>
</p></td>
<td><div class="text-center">
        <input type="submit" class="btn btn-primary waves-effect waves-light" name="save" value="<?=$buttonSave?>">
    </div>
</td></tr>
</table>
</form>
</div>
</div>
</div>