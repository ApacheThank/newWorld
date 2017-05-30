<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.0/jquery.min.js">
</script>
<script LANGUAGE="JavaScript"> 
function getXhr(){
                                var xhr = null; 
				if(window.XMLHttpRequest) // Firefox et autres
				   xhr = new XMLHttpRequest(); 
				else if(window.ActiveXObject){ // Internet Explorer 
				   try {
			                xhr = new ActiveXObject("Msxml2.XMLHTTP");
			            } catch (e) {
			                xhr = new ActiveXObject("Microsoft.XMLHTTP");
			            }
				}
				else { // XMLHttpRequest non supporté par le navigateur 
				   alert("Votre navigateur ne supporte pas les objets XMLHTTPRequest..."); 
				   xhr = false; 
				} 
                                return xhr;
			}
 

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
  +"<a class='lienCategory' href='#'>"+field.lib+"</a>"
  +"</li>" ;
  $(newLine).appendTo("#"+field.idRayon+libelleRayon+"");
  });
  $(".lienCategory").click(function(){
 // quand l'utilisateur clique dans la case
$("#formulaire-produit").show(); 
    valeur = this.text;    
    var categorieSaisie= "<h3>"+valeur.toUpperCase()+"<h3>";
    $("#categorieChoisie").empty();
    $("#listProduits").empty();
    $(categorieSaisie).appendTo("#categorieChoisie");

				var xhr = getXhr();
				
 				// Ici on va voir comment faire du post
				xhr.open("POST","scripts/getProduit.php",true);
				// ne pas oublier ça pour le post
				xhr.setRequestHeader('Content-Type','application/x-www-form-urlencoded');
				// ne pas oublier de poster les arguments
				xhr.send("libelleCategorie="+valeur);
				// On défini ce qu'on va faire quand on aura la réponse
				xhr.onreadystatechange = function(){
					// On ne fait quelque chose que si on a tout reçu et que le serveur est ok
					if(xhr.readyState == 4 && xhr.status == 200){
						leselect = xhr.responseText;
						// On se sert de innerHTML pour rajouter les options a la liste
						$(leselect).appendTo("#listProduits");
					}
				}	

});
})
 .fail(function(){
  alert('raté');
 })

$(function(){
        $("#formulaire-produit").submit(function(){
            qty = $(this).find("input[name=quantity]").val();
			harvestDate = $(this).find("input[name=harvestDate]").val();
		    lengthPreservation = $(this).find("input[name=lengthPreservation]").val();
            salesUnit = $(this).find("input[name=salesUnit]").val();
			productionMode = $(this).find("input[name=productionMode]").val();
			unitPrice = $(this).find("input[name=unitPrice]").val();
		    manuelCollecting = $(this).find("input[name=manuelCollecting]").val(); 
        });

    });
var i=0;
$(function(){
		$("#ajoutProduit").click(function(){
			if(i==0) {
			var unProduit = "<label for='leProduit'>Nouveau produit:</label><input type='text' class='form-control' id='leProduit'>";
			$(unProduit).appendTo("#nouveauProduit");
			i=1;
		}
						
		});
});

</SCRIPT>
<div class="row">
<div class="col-xs-3">
<div class="panel-group" id="listRayons">
<!-- la il va s'executer le script ajax-->
</div><!-- fin panel-group -->
</div><!-- fin col-xs-5 -->

<div class="col-md-5 col-xs-offset">
<div class="col-xs-3" id="categorieChoisie" >
</div>
<div class="card-block">
<form method="POST" id="formulaire-produit">
	<div class="md-form" id="nouveauProduit">
		<input type="button" id="ajoutProduit" class="btn btn-primary btn-sm" value="<?=$labelAddProduct?>">
	</div>
	<div class="md-form">
		<select class="form-control" name ="idProduit" id="listProduits"> </select>
    </div>
    <div class="md-form">
	<label for="quantity"><?=$labelQuantity?>:</label>
        <input type="text" class="form-control" name="quantity">
    </div>
	<label><?=$labelDateHarvest?>:</label>
	<div class="md-form">
   		<input type="date" class="form-control" name="harvestDate">
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
		  <input type="checkbox" class="form-control" name="manuelCollecting" value="1">
    </div>
    <div class="md-form">        
        <input type="submit" name="propose" class="btn btn-default" value="<?=$submitPropose?>">
	</div>
</form>
</div>
</div>
</div>
