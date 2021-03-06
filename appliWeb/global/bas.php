<!--Footer-->
<footer class="page-footer center-on-small-only">

    <!--Footer Links-->
    <div class="container-fluid">
        <div class="row">

            <!--First column-->
            <div class="col-md-3 offset-md-1">
                <h5 class="title">Footer Content</h5>
                <p>Here you can use rows and columns here to organize your footer content.</p>
            </div>
            <!--/.First column-->

            <hr class="hidden-md-up">

            <!--Second column-->
            <div class="col-md-2 offset-md-1">
                <h5 class="title"><?=$aParticipate?></h5>
                <ul>
                    <li><a id='offerProducts' href=""><?=$aOfferProducts?></a></li>
                    <li><a id="transformate" href=""><?=$aTransformate?></a></li>
                    <li><a id="becomeCustomer" href=""><?=$aBecomeCustomer?></a></li>
                    <li><a id="distribute" href=""><?=$aDistribute ?></a></li>
                </ul>
            </div>
            <!--/.Second column-->

            <hr class="hidden-md-up">

            <!--Third column-->
            <div class="col-md-2">
                <h5 class="title"><?=$aUnderstand ?></h5>
                <ul>
                    <li><a id="" href=""><?=$aKnowDo ?></a></li>
                    <li><a id="" href=""><?=$aReduceTransport ?></a></li>
                    <li><a id="" href=""><?=$aFreshProducts?></a></li>
                    <li><a id="" href=""><?=$aQuality?></a></li>
                </ul>
            </div>
            <!--/.Third column-->

            <hr class="hidden-md-up">

            <!--Fourth column-->
            <div class="col-md-2">
                <h5 class="title"><?=$aCommunicate?></h5>
                <ul>
                    <li><a id="" href=""><?=$aSecretProducers?></a></li>
                    <li><a id="" href=""><?=$aKnowledgeArtisans?></a></li>
                    <li><a id="" href=""><?=$aReceptesGrandmother?></a></li>
                    <li><a id="" href=""><?=$aFoodPreservation?></a></li>
                </ul>
            </div>
            <!--/.Fourth column-->

        </div>
    </div>
    <!--/.Footer Links-->

<?php if(!utilisateur_est_connecte()){
    ?>
    <hr>
    <!--Call to action-->
    <div class="call-to-action">
        <ul>
            <li>
                <h5>Register for free</h5></li>
            <li><a href="index.php?module=utilisateurs&amp;action=inscription" class="btn btn-danger"><?=$aSignUp?></a></li>
        </ul>
    </div>
    <!--/.Call to action-->
    <hr>
    <?php } ?>

    <!--Social buttons-->
    <div class="social-section">
        <ul>
            <li><a class="btn-floating btn-small btn-fb"><i class="fa fa-facebook"> </i></a></li>
            <li><a class="btn-floating btn-small btn-tw"><i class="fa fa-twitter"> </i></a></li>
            <li><a class="btn-floating btn-small btn-gplus"><i class="fa fa-google-plus"> </i></a></li>
            <li><a class="btn-floating btn-small btn-li"><i class="fa fa-linkedin"> </i></a></li>
            <li><a class="btn-floating btn-small btn-git"><i class="fa fa-github"> </i></a></li>
            <li><a class="btn-floating btn-small btn-pin"><i class="fa fa-pinterest"> </i></a></li>
            <li><a class="btn-floating btn-small btn-ins"><i class="fa fa-instagram"> </i></a></li>
        </ul>
    </div>
    <!--/.Social buttons-->

    <!--Copyright-->
    <div class="footer-copyright">
        <div class="container-fluid">
            © 2017 Copyright: <a href="https://www.MDBootstrap.com"> MDBootstrap.com </a>

        </div>
    </div>
    <!--/.Copyright-->
<!--/.Footer-->
      </footer>

    </div><!--/.container-->

    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->  
    <!-- JQuery -->
    <script type="text/javascript" src="dist/js/jquery-3.1.1.min.js"></script>
    <!-- Bootstrap tooltips -->
    <script type="text/javascript" src="dist/js/tether.min.js"></script>
    <script type="text/javascript" src="dist/js/bootstrap.min.js"></script>
    <script type="text/javascript" src="dist/js/offcanvas.js"></script>
    <!-- MDB core JavaScript -->
    <script type="text/javascript" src="dist/js/mdb.min.js"></script>

  </body>
</html>
