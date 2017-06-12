<?php
echo "<div class='row'>";
echo "<div><h3>$labelBatchesProposed</h3>";
echo "</div>";


foreach ($lots as $lot) {
	$idLot = $lot['idLot'];
	$qte =$lot['quantite'];
	$nbJourConservation = $lot['nbJourConservation'];
	$uniteVente = $lot['uniteDeVente'];
	$modeProduction = $lot['modeProduction'];
	$ramassageManuel = $lot['ramassageManuel'];
	$libelle=$lot['libelle'];
	$prix = $lot['prixUnitaire'];
	$dateRecolte=$lot['dateRecolte'];
	$image= $lot['image'];
    $prix = number_format($prix,2,',',' ');
    if($ramassageManuel==1) {
    	$ramassageManuel="Yes";
   	} else { $ramassageManuel="Non";}
	?>
<!--Card-->
<div class="col-xs-3" id="<?=$idLot?>">
	<div class="pop-info" id="pop-info<?=$idLot?>" >
		<ul>
			<li><?="Batch id: ",$idLot?></li>
			<li><?=$labelNameProduct,": ",$libelle?></li>
			<li><?=$labelQuantity,": ",$qte?></li>
			<li><?=$labelDateHarvest,": ",$dateRecolte?></li>
			<li><?=$labelLengthPreservation,": ",$nbJourConservation?></li>
			<li><?=$labelUnitPrice,": ",$prix?></li>
			<li><?=$labelProductionMode,": ",$modeProduction?></li>
			<li><?=$labelManuelCollecting,": ",$ramassageManuel?></li>
		</ul>
	</div>

    <!--Card image-->
    <div class='thumbnail'>
    <div class="view overlay hm-white-slight">
        <img src="<?=$image?>" width="180px" height="148" alt="">
        <a href="#">
            <div class="mask waves-effect waves-light"></div>
        </a>
    </div>
    </div>
    <!--/.Card image-->

    <!--Card content-->
    <div class="card-block">
        <!--Title-->
        <h4 class="card-title"><?=$libelle?></h4>
        <!--Text-->
        <div class="row">
	        <div class="col-xs-12">
	        	<p class="lead"><strong><?=$labelUnitPrice,': </strong> ',$prix?></p>
	        </div>
        </div>
        <div class="row">
	        <div class="col-xs-12">
	        	<p><strong><?=$labelDateHarvest,': </strong> ',$dateRecolte?></p>
	        </div>
	        </div>
    </div>
    <!--/.Card content-->


</div>
<!--/.Card-->
<?php
}
echo "</div>";

?>
<script type="text/javascript">

		$(".pop-info").hide();


$(document).ready(function(){

  
    $(".col-xs-3").mouseover(function(){
        var idLot = $(this).attr("id");
    	$("#pop-info"+idLot+"").show();

    });
    $(".col-xs-3").hover(function(){
    	$(".pop-info").hide();
    });
});

</script>
