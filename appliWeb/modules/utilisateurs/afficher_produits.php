<?php
$cat = $_GET['idCategorie'];
$lesProduits= afficher_produits($cat);
include_once CHEMIN_VUE.'formulaire_charger_produits.php';

?>
<div class="col-md-8 col-xs-offset">
 <div class="well well-sm"> 
        <strong><?=$cat?></strong>
        <div class="btn-group">
            <a href="#" id="list" class="btn btn-default btn-sm"><span class="glyphicon glyphicon-th-list">
            </span>List</a> <a href="#" id="grid" class="btn btn-default btn-sm"><span
                class="glyphicon glyphicon-th"></span>Grid</a>
        </div>
    </div>

<?php


foreach ($lesProduits as $produit) {
	$libelle=$produit['libelle'];
	$prix = $produit['pU'];
	$dateRecolte=$produit['dateRecolte'];
	$uniteVente = $produit['uniteDeVente'];
	$image= $produit['image'];
	echo "<div class='item  col-xs-6 col-lg-6'>";
	echo    "<div class='thumbnail'>";
	echo    	"<img class='group list-group-image' width='328px' height='282' src='$image' alt='' />";
	echo    	"<div class='caption'>";
	echo    		"<h4 class='group inner list-group-item-heading'>$libelle</h4>";
	echo    		"<p class='group inner list-group-item-text'>$labelSalesUnit $uniteVente</p>";
	echo    		"<div class='row'>";
	echo    			"<div class='col-xs-12 col-md-6'>";
	echo    				"<p class='lead'>$prix</p>";
	echo    			"</div>";
	echo    			"<div class='col-xs-12 col-md-6'>";
	echo    			"<a class='btn btn-success btn-sm' href='http://www.jquery2dotnet.com'>Add to cart</a>";
	echo    			"</div>";
	echo        	"</div>";
	echo    	"</div>";
	echo    "</div>";
	echo  "</div>";
}

     
?>
</div>
</div>
<script LANGUAGE="JavaScript">

$(document).ready(function() {
    $('#list').click(function(event){event.preventDefault();$('#products .item').addClass('list-group-item');});
    $('#grid').click(function(event){event.preventDefault();$('#products .item').removeClass('list-group-item');$('#products .item').addClass('grid-group-item');});
});

</script>

<script type="text/javascript">
  var action = "<?= $action=substr($action,0,strlen($action)-4); ?>";
</script>
<script src="scripts/chargerLesProduits.js">
</script>
<style type="text/css">
	
.glyphicon { margin-right:5px; }
.thumbnail
{
    margin-bottom: 20px;
    padding: 0px;
    -webkit-border-radius: 0px;
    -moz-border-radius: 0px;
    border-radius: 0px;
}

.item.list-group-item
{
    float: none;
    width: 100%;
    background-color: #fff;
    margin-bottom: 10px;
}
.item.list-group-item:nth-of-type(odd):hover,.item.list-group-item:hover
{
    background: #428bca;
}

.item.list-group-item .list-group-image
{
    margin-right: 10px;
}
.item.list-group-item .thumbnail
{
    margin-bottom: 0px;
}
.item.list-group-item .caption
{
    padding: 9px 9px 0px 9px;
}
.item.list-group-item:nth-of-type(odd)
{
    background: #eeeeee;
}

.item.list-group-item:before, .item.list-group-item:after
{
    display: table;
    content: " ";
}

.item.list-group-item img
{
    float: left;
}
.item.list-group-item:after
{
    clear: both;
}
.list-group-item-text
{
    margin: 0 0 11px;
}



</style>
