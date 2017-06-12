<?php
$idProducteur = $_SESSION['idUtilisateur'];
$lots = requeteSql("select * from lot l inner join produit p on l.idProduit=p.idProduit where idUtilisateur=".$idProducteur.";");

include CHEMIN_VUE.'formulaire_lot_propose.php';

?>