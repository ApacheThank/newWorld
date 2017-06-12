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
  +"<a class='lienCategory' href='index.php?module=utilisateurs&action=declaration_produit&amp;libelle="+field.lib+"&amp;idCategorie="+field.idCategorie+"'>"+field.lib+"</a>"
  +"</li>" ;
  $(newLine).appendTo("#"+field.idRayon+libelleRayon+"");
  });
  /*$(".lienCategory").click(function(){
 // quand l'utilisateur clique dans la case
$("#proposition-produit").hide();
$("#formulaire-produit").show(); 
    valeur = this.text;    
    var categorieSaisie= "<h3 name='categorie'>"+valeur.toUpperCase()+"</h3>";
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

});*/
})
 .fail(function(){
  alert('raté');
 })


/*$(function(){
        $("#propose").click(function(){
            qty = $(this).find("input[name=quantity]").val();
			harvestDate = $(this).find("input[name=harvestDate]").val();
		    lengthPreservation = $(this).find("input[name=lengthPreservation]").val();
            salesUnit = $(this).find("input[name=salesUnit]").val();
			productionMode = $(this).find("input[name=productionMode]").val();
			unitPrice = $(this).find("input[name=unitPrice]").val();
		    manuelCollecting = $(this).find("input[name=manuelCollecting]").val(); 

					/*
					$.ajax({
    				type: 'POST',
    				url: 'modules/utilisateurs/declaration_produit.php',
    				data: jQuery.param({propose: $("quantity").val()}),
    				// ...
    				contentType: 'application/x-www-form-urlencoded; charset=UTF-8',
			    	success: function (response) {
			        alert(propose);
			    	},
			   	 	error: function () {
			        alert("error");
			    	}
					}); 

        });

    });*/
/*$(function(){
		$("#ajoutProduit").click(function(){
			$("#formulaire-produit").hide(); // à améliorer 
			$("#proposition-produit").show();

		});
});
*/