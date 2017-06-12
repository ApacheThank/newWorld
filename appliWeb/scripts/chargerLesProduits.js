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
  +"<a class='lienCategory' href='index.php?module=utilisateurs&action="+action+"&amp;libelle="+field.lib+"&amp;idCategorie="+field.idCategorie+"'>"+field.lib+"</a>"
  +"</li>" ;
  $(newLine).appendTo("#"+field.idRayon+libelleRayon+"");
  });
})
 .fail(function(){
  alert('raté');
 })