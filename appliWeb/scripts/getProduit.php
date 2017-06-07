<?php
// connexion bdd
include '../libs/db.php';

		
		$query = "SELECT p.idProduit, p.libelle,p.idCategorie FROM produit p inner join categorie c on p.idCategorie=c.idCategorie WHERE p.accepte=1 and c.libelle like '".$_POST["libelleCategorie"]."';";
		$res=$db_con->prepare($query);
		$res->execute();
		while($row = $res->fetch(PDO::FETCH_ASSOC)){
			echo "<option name='".$row["idCategorie"]."' value='".$row["idProduit"]."'>".$row["libelle"]."</option>";
		}

?>
