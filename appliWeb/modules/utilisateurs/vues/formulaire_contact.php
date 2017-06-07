<form method="post">
<!--Naked Form-->
<div class="card-block">

    <!--Header-->
    <div class="text-center">
        <h3><i class="fa fa-envelope"></i><?=$labelWriteToUs?>:</h3>
        <hr class="mt-2 mb-2">
    </div>

    <!--Body-->
    <p><?=$labelContentMessage?></p>
    <br>

    <!--Body-->
    <div class="md-form">
        <i class="fa fa-user prefix"></i>
        <input type="text" id="firstName" class="form-control">
        <label for="firstName"><?=$labelYourName?></label>
    </div>

    <div class="md-form">
        <i class="fa fa-envelope prefix"></i>
        <input type="text" id="email" class="form-control">
        <label for="email"><?=$labelYourEmail?></label>
    </div>

    <div class="md-form">
        <i class="fa fa-tag prefix"></i>
        <input type="text" id="subject" class="form-control">
        <label for="subject"><?=$labelSubject?></label>
    </div>

    <div class="md-form">
        <i class="fa fa-pencil prefix"></i>
        <textarea type="text" id="message" class="md-textarea"></textarea>
        <label for="message"><?=$labelYourMessage?></label>
    </div>

    <div class="text-center">
        <button id="contact" type="submit" class="btn btn-default"><?=$valueSend?></button>
    </div>

</div>
<!--Naked Form-->

</form>
