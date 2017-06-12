  <?php //var_dump($_SESSION);
  if(!empty($_SESSION['panier'])){
    $ids=$_SESSION['panier']['idProduit'];
    $produits = requeteSql('select l.idProduit,p.libelle, l.prixUnitaire, p.image,concat(u.nom,u.prenom) as producteur from lot l inner join utilisateur u on l.idUtilisateur=u.idUtilisateur left join produit p on l.idProduit=p.idProduit where p.idProduit in('.implode(',', $ids).')');
}

    if (empty($ids)){
        echo "<div class='row'>";
        echo "<div class='col-md-5 col-xs-offset'>";
        echo "<div class='alert alert-warning'>";
        echo $labelEmptyCart;
        echo "</div>";
        echo "</div>";
        echo "</div>";
    }
    else
    {
?>
<div class="container">
    <div class="row">
        <div class="col-sm-12 col-md-10 col-md-offset-1">
            <table class="table table-hover">
                <thead>
                    <tr>
                        <th><?=$product?></th>
                        <th><?=$labelQuantity?></th>
                        <th class="text-center"><?=$labelUnitPrice?></th>
                        <th class="text-center"><?=$total?></th>
                        <th> </th>
                    </tr>
                </thead>
                <tbody>
              <?php
            include CHEMIN_LIB.'db.php';


              
					$i=0;
					foreach ($produits as $produit)
					{ 
				   /*if (creationPanier())
					{
					$nbArticles=count($_SESSION['panier']['libelleProduit']);
					//if ($nbArticles <= 0)
					//echo "Votre panier est vide";
					//else
					//{
					for ($i=0 ;$i < $nbArticles ; $i++)
					{*/
					?>
                    <tr>
                        <td class="col-sm-8 col-md-6">
                        <div class="media">
                            <a class="thumbnail pull-left" href="#"> <img src="<?=$produit['image'];?>" style="width: 72px; height: 72px;"> </a>
                            <div class="media-body">
                                <h4 class="media-heading"><a href="#"><?=$produit['libelle'];?></a></h4>
                                <h5 class="media-heading"> by <a href="#"><?=$produit['producteur'];?></a></h5>
                            </div>
                        </div></td>
                        <td class="col-sm-2" style="text-align: center">
                        <input type="text" class="form-control" id="qteProduit" value='<?=$_SESSION['panier']['qteProduit'][$i];?>'>
                        <input type="button" id="subtract" name="subtract" value="-" onclick="//<?php //ajouterArticle($_SESSION['panier']['idProduit'][$i], $_SESSION['panier']['qteProduit'][$i],1); ?>" />
                        <input type="button" id="add" name="add" value="+" onclick="addNombre(1)" />
                        </td>
                        <td class="col-sm-1 col-md-1 text-center"><strong><?=$produit['prixUnitaire'];?></strong></td>
                      
                        <td class="col-sm-1 col-md-1 text-center">
                           <span class="action"><a href="index.php?module=utilisateurs&action=afficher_panier&amp;del=<?=$produit['idProduit'];?>" onclick="<?php
if(isset($_GET['del'])){
	supprimerArticle($_GET['del']);

	}
?>"><img src="images/panier_sup.jpg">
                            </a></span>
                            </td>
                    </tr>
                    <?php
                    	$i++;
                    	}
                    //}
                    
                    ?>
                    <tr>
                        <td>   </td>
                        <td>   </td>
                        <td><h3><?=$total?></h3></td>
                        <td class="text-right"><h3><strong><?= MontantGlobal();?></strong></h3></td>
                    </tr>
                    <tr>
                        <td>   </td>
                        <td>   </td>
                        <td>
                            <span class="action"><a href="index.php?module=utilisateurs&action=afficher_produits" class='btn btn-primary'> <?=$labelContinueShopping?></a></span>
                        </td>
                        <td>
                        <button type="button" class="btn btn-success">
                            Checkout <span class="glyphicon glyphicon-play"></span>
                        </button></td>
                    </tr>
                </tbody>
            </table>
        </div>
    </div>
</div>
<?php
   }         
?>