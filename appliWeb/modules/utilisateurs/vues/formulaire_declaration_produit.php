<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js">
</script>
<script LANGUAGE="JavaScript"> 
 $.ajax({
  url: 'scripts/getRayon.php',
  dataType: 'json',
 })
 .done(function(data){
  console.log(data);
  $.each(data.rayons, function(i,post){
  var libelle = post.libelle.replace(/ /g, ""); // pour supprimer des espaces
  var newRow =
  "<div class='panel panel-default' id='"+post.idRayon+"'>"
  	+"<div class='panel-heading'>"
	  +"<h4 class='panel-title'>"
  		+"<a data-toggle='collapse' href='#"+libelle+post.idRayon+"'>"+post.libelle+"</a>"
  	  +"</h4>"
  	+"</div>"
	+"<div id='"+libelle+post.idRayon+"' class='panel-collapse collapse'>"
  		+"<ul class='list-group' id='"+post.idRayon+libelle+"'>"
		+"</ul>"
	+"</div>"

 +"</div>" ;
  $(newRow).appendTo(".panel-group");
  });
$("#formulaire-produit").hide(); // à améliorer 

 })
 .fail(function(){
  alert('raté');
 })

 $.ajax({
  url: 'scripts/getCategorie.php',
  dataType: 'json',
 })
 .done(function(donnee){
  console.log(donnee);
  $.each(donnee.categories, function(a,field){
  var libelleRayon = field.libelle.replace(/ /g, ""); 
  var newLine =
  "<li class='list-group-item'>"
  +"<a id='lienCateg' class='lienCategory' href='#'>"+field.lib+"</a>"
  +"</li>" ;
  $(newLine).appendTo("#"+field.idRayon+libelleRayon+"");
  });
  $(".lienCategory").click(function(){
 // quand l'utilisateur clique dans la case
$("#formulaire-produit").show(); 
    valeur = this.text;    
    var produitSaisi= "<h3>"+valeur.toUpperCase()+"<h3>";
    $("#test").empty();
    $(produitSaisi).appendTo("#test");
});
})
 .fail(function(){
  alert('raté');
 })



</SCRIPT>
<div class="row">
<div class="col-xs-3">
<div class="panel-group" id="listRayons">
<!-- la il va s'executer le script ajax-->
</div><!-- fin panel-group -->
</div><!-- fin col-xs-5 -->

<div class="col-md-5 col-xs-offset">
<div id="test"></div>

<div class="card-block">
<form method="POST" id="formulaire-produit">
    <div class="md-form">
	<label for="quantity"><?=$labelQuantity?>:</label>
        <input type="text" class="form-control" name="quantity">
    </div>
	<div class="md-form">
	    <label><?=$labelDateHarvest?>:</label>
        <input type="text" class="form-control" name="harvestDate">
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
    <div class="md-form">        
          <label for="manuelCollecting"><?=$labelManuelCollecting?></label>
		  <input type="checkbox" class="form-control" §name="manuelCollecting" value="1">
    </div>
    <div class="md-form">        
        <input type="submit" class="btn btn-default" value="<?=$submitPropose?>">
	</div>
</form>
</div>
</div>
</div>
