<?php

if(isset($_GET['idproduit'])){
   $produit  = requeteSql('select sum(quantite),p.libelle,l.idProduit,prixUnitaire from lot l inner join produit p on l.idProduit=p.idProduit where idUtilisateur=:idUtilisateur and l.idProduit=:idProduit',  array('idProduit' => $_GET['idproduit'], 'idUtilisateur' => $_GET['id']));
   if(empty($produit)){
      die("Product doesn't exist");
   }
   creationPanier();
   $l = $produit['0']['idProduit'];
   $pU =$produit['0']['prixUnitaire'];
   $qte = 1; // on peut pas choisir directement la quantite
   ajouterArticle($l,$qte,$pU);
   header('Location: index.php?module=utilisateurs&action=afficher_panier');

} else {
   die("You didn't select the product!");
}

?>