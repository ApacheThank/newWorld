<?php
include CHEMIN_LIB.'db.php';
$declaration_point_effectue = false;
if(!mysqli_connect_errno())
{
  if(utilisateur_est_connecte())
  {


	if(isset($_POST['declarePoint'])) 
	{
		
		$err = array();
		// vérification le nom social
		if(empty($_POST['companyName']))
		{$err[] = $errorCompanyName1;}
		elseif(!preg_match("/[a-zA-Z0-9]+/",$_POST['companyName']))
		{$err[] = $errorCompanyName2;}
		// vérification du champs activité s'il est vide
		elseif(empty($_POST['activity']))
		{$err[] = $errorActivity1;}
		elseif(!preg_match("/[a-zA-Z0-9]+/",$_POST['activity']))
		{$err[] = $errorActivity2;}	
		elseif(empty($_POST['address']))
		{$err[] = $errorAddress;}
		#vérification de ville
		elseif(empty($_POST['city']))
		{$err[] = $errorCity1;}
		elseif(!preg_match("/[a-zA-Z]+/",$_POST['city']))
		{$err[] = $errorCity2;}	
		#vérification de code postale
		elseif(empty($_POST['zipCode']))
		{$err[] = $errorZipCode1;}
		elseif(preg_match("/^[0-9]{10,10}+$/",$_POST['zipCode']))
		{$err[] = $errorZipCode2;}		
		// Vérification de numéro de portable
		elseif(empty($_POST['phone_num']))
		{$err[] = $errorNumber1;}
		elseif(preg_match("/^[0-9]{12,14}+$/",$_POST['phone_num']))
		{$err[] = $errorNumber2;}
		# vérification d'existance du point de vente dans le même lieu
		$query =$db_con->query("select count(idPV) as pointExists from pointVente where   adresse='".$_POST['address']."' and codePostal='".$_POST['zipCode']."';");
		$resultat=$query->fetch(PDO::FETCH_ASSOC);
		# si login est déjà utilisé
		if($resultat['pointExists']!=0)
		{$err[] = $errorPointAddressExists;}  

		if(count($err) == 0 )
		{
			$companyName = $_POST['companyName'];
			$activity= $_POST['activity'];
			$address = $_POST['address'];
			$city = $_POST['city'];
			$zipCode = $_POST['zipCode'];
			$phone = $_POST['phone_num'];
			$resultat=$db_con->query("select ifnull(max(idPV),0)+1 as idPV from pointVente;");
			$idmax =$resultat->fetch(PDO::FETCH_ASSOC);
			$idPV=$idmax['idPV'];
			$responsable = $_SESSION['idUtilisateur'];
			$query = "insert into pointVente(idPV,activite,adresse,ville,codePostal,nom,tel,responsable) 
						values($idPV,'$activity','$address','$city','$zipCode','$companyName','$phone',$responsable);";
			$res= $db_con->prepare($query);
			$res->execute();
			if($res=true){ 
			$declaration_point_effectue = true;
				echo "Félicitations! Votre declaration de point de vente se déroulée avec succès";
			} else { echo "Une erreur est survenue lors de la rentrée des données! ";}

		}else 
		{ 
			foreach($err AS $error)
		    { echo "<div class='alert alert-info'>";
		      echo "<strong>Info!</strong>".$error."</div>";
		  	}	  
	    }
	}

	if($declaration_point_effectue!=1){
		include CHEMIN_VUE.'formulaire_declarer_point.php';

	}

  } else 
  {
	echo "<div class='col-md-5 col-xs-offset'>";
	echo "<div class='alert alert-info'>";
	echo "<strong>Info!</strong>$labelMessageNecessaryConnection";
	echo "</div></div>";
	include CHEMIN_CONTROLEUR.'connexion.php';
  }	

}
else // we can't connect to database
{
	echo "Failed to connect to MySQL: " . mysqli_connect_errno();

}
?>