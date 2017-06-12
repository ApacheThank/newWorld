<form method="POST">
<table id="reinit_pswd">
<tr>
	<td><label for='pswd_old' size='30'><?=$labelOldPswd?>:*</label></td>
	<td><input name="old_pswd" type="password"></td>
</tr>
<tr>
	<td><label for='new_pswd'><?=$labelNewPswd?>:*</label></td>
	<td><input name="new_pswd" type="password"></td>
</tr>
<tr>
	<td><label for='new_pswd_verif'><?=$labelNewPswdVerif?>:*</label></td>
	<td><input name="new_pswd_verif" type="password"></td>
</tr>
<tr>
<td><input id='save' type="submit" name="save" value="<?=$buttonSave?>"></td>
</tr>
</table>
</form>