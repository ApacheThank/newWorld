<?php //include CHEMIN_LIB.'messages_en.php';?>
    <nav class="navbar navbar-inverse navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <a class="navbar-brand" href="index.php"><?=$aHome?></a>
						<!--<span class='lang-sm' lang='en'></span>-->

	

<?php

if(utilisateur_est_connecte())
{
	$id_utilisateur = $_SESSION['login'];
	if((compteActive($id_utilisateur)==1))
	{
$type_user = $_SESSION['typeUtilisateur'] ;
switch ($type_user) {
/*consommateur*/case 1 : 	
			echo 	"<a class='navbar-brand' href='index.php?module=utilisateurs&amp;action=afficher_profil&amp;id=$id_utilisateur'>$aAccount</a>
					<a class='navbar-brand' href='index.php?module=utilisateurs&amp;action=afficher_produits&amp;id=$id_utilisateur'>$aBuy</a>
				</div>
				<div id='navbar' class='navbar-collapse collapse'>
					<form class='navbar-form navbar-right'>
					<a href='index.php?module=utilisateurs&amp;action=afficher_panier'><img src='images/panier2.png'></a>
					<form class='form-inline waves-effect waves-light'>
						<input class='form-control' type='text' placeholder='Search'>     
						<a href='index.php?module=utilisateurs&amp;action=deconnexion' class='btn btn-primary'>$aLogOut</a>
					</form>
					</form> 
				</div>";
			break;

/*producteur*/   case 2 : 	
			echo 	"<a class='navbar-brand' href='index.php?module=utilisateurs&amp;action=afficher_profil&amp;id=$id_utilisateur'>$aAccount</a>
					<a class='navbar-brand' href='index.php?module=utilisateurs&amp;action=declaration_produit&amp;id=$id_utilisateur'>$aProduce</a>
					<a class='navbar-brand' href='index.php?module=utilisateurs&amp;action=lot_propose&amp;id=$id_utilisateur'>$aMyBatch</a>
				</div>
				<div id='navbar' class='navbar-collapse collapse'>
					<form class='navbar-form navbar-right'>
					<form class='form-inline waves-effect waves-light'>
						<input class='form-control' type='text' placeholder='Search'>     
						<a href='index.php?module=utilisateurs&amp;action=deconnexion' class='btn btn-primary'>$aLogOut</a>
					</form>
					</form> 
				</div>";
			break;
/*point de vente*/case 3 : 	
			echo 	"<a class='navbar-brand' href='index.php?module=utilisateurs&amp;action=afficher_profil&amp;id=$id_utilisateur'>$aAccount</a>
					<a class='navbar-brand' href='index.php?module=utilisateurs&amp;action=declarer_point_vente&amp;id=$id_utilisateur'>$aDeclarePoint</a>
				</div>
				<div id='navbar' class='navbar-collapse collapse'>
				<form class='navbar-form navbar-right'>
					<form class='form-inline waves-effect waves-light'>
						<input class='form-control' type='text' placeholder='Search'>     
						<a href='index.php?module=utilisateurs&amp;action=deconnexion' class='btn btn-primary'>$aLogOut</a>
					</form>
					</form> 
				</div>";
			break;
		} // fin du switch
	} // fin du if
	else {
				echo "</div><div id='navbar' class='navbar-collapse collapse'>
							<form class='navbar-form navbar-right'>
								<form class='form-inline waves-effect waves-light'>
									<input class='form-control' type='text' placeholder='Search'>     
									<a href='index.php?module=utilisateurs&amp;action=deconnexion' class='btn btn-primary'>$aLogOut</a>
								</form>
								</form> 
							</div>";
	} // fin du else 
} // fin du if 
else { // si l'utilisateur n'est pas connecté			
			echo "	<a class='navbar-brand' href='index.php?module=utilisateurs&amp;action=afficher_produits'>$aBuy</a>
					<a class='navbar-brand' href='index.php?module=utilisateurs&amp;action=declaration_produit'>$aProduce</a>
					<a class='navbar-brand' href='index.php?module=utilisateurs&amp;action=declarer_point_vente'>$aDistribute</a>
					<a class='navbar-brand' href='index.php?module=utilisateurs&amp;action=afficher_contact'>$aContact</a>
				</div>
				<div id='navbar' class='navbar-collapse collapse'>
					<form class='navbar-form navbar-right'>
					<a href='index.php?module=utilisateurs&amp;action=afficher_panier'><img src='images/panier2.png'></a>

					<form class='form-inline waves-effect waves-light'>
						<input class='form-control' type='text' placeholder='Search'>     
						<a href='index.php?module=utilisateurs&amp;action=connexion' class='btn btn-success'>$aLogIn</a>	
						<a href='index.php?module=utilisateurs&amp;action=inscription' class='btn btn-primary'>$aSignUp</a>
					</form>
					</form>
				</div>"; // fin navbar colapse
} // fin else
?>
  </div>
</nav>

<div class="container">


