<form method="post">
<!--Naked Form-->
<div class="card-block">

    <!--Header-->
    <div class="text-center">
        <h3><i class="fa fa-envelope"></i><?=$labelInscription?>:</h3>
        <hr class="mt-2 mb-2">
    </div>
    <!--Body-->
    <div class="md-form">
	<label for='lastName'><?=$labelLastName?>:*</label>
    	<input name='lastName' type="text" class="form-control">
    </div>
    <div class="md-form">
	<label for='firstName'><?=$labelFirstName?>:*</label>
    	<input name='firstName' type="text" class="form-control">
    </div>
    <div class="md-form">
	<label for='login'><?=$labelLogin?>:*</label>
    	<input name='login' type="text" class="form-control">
    </div>
    <div class="md-form">
	<label for='address'><?=$labelAddress?>:*</label>
    	<input name='address' type="text" class="form-control">
    </div>
    <div class="md-form">
	<label for='city'><?=$labelCity?>:*</label>
    	<input name='city' type="text" class="form-control">
    </div>
    <div class="md-form">
	<label for='zipCode'><?=$labelZipCode?>:*</label>
    	<input name='zipCode' type="text" class="form-control">
    </div>
   <div class="md-form">
	<label for='email'><?=$labelMail?>:*</label>
    	<input name='email' type="text" class="form-control">
    </div>
    <div class="md-form">
	<label for='phone_num'><?=$labelPhone?>:*</label>
    	<input name='phone_num' type="text" class="form-control">
    </div>
    <div class="md-form">
 	<input  type="radio" name="option_user" value="1"><?=$valueConsumer?>
   	<input  type="radio" name="option_user" value="2" ><?=$valueProducer?>
    	<input  type="radio" name="option_user" value="3" ><?=$valuePointSale?>
	</div> 
	<p id='requiredField' align='left'>*<?=$pRequiredField?></p>

    <div class="text-center">
        <button id="register" name="registration" type="submit" class="btn btn-default"><?=$valueRegister?></button>

      </div>

</div>
<!--Naked Form-->
</form>
