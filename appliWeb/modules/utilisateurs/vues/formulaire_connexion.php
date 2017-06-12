<div class="col-xs-3">
</div>
<div class="col-md-5 col-xs-offset">
<!--Naked Form-->
<div class="card-block">
<form method="POST">
    <!--Header-->
    <div class="text-center">
        <h3><i class="fa fa-lock"></i><?=$aLogIn?></h3>
        <hr class="mt-2 mb-2">
    </div>

    <!--Body-->
    <div class="md-form">
        <i class="fa fa-user"></i>
        <input type="text" name="login" class="form-control">
        <label for="login"><?=$labelLogin?></label>
    </div>

    <div class="md-form">
        <i class="fa fa-lock"></i>
        <input type="password" name="pass_verif" class="form-control">
        <label for="pass_verif"><?=$labelPswd?></label>
    </div>

    <div class="text-center">
        <input id="logIn" type="submit" class="btn btn-primary btn-lg" name="connect" value="<?=$aLogIn?>">
    </div>

</div>

<!--Footer-->
<div class="modal-footer">
    <div class="options">
        <p>Not a member? <a href="index.php?module=utilisateurs&amp;action=inscription"><?=$aSignUp?></a></p>
        <p>Forgot <a href="#">Password?</a></p>
    </div>
</form>
</div>
<!--Naked Form-->
</div>
</div>
