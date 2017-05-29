<?php
// connexion bdd

 $db_hostname = "localhost";
 $db_user = "akhasanov";
 $db_password = "jamas003";
 $db_name = "dbNewWorld_v1";
 
 try{
  
  $db_con = new PDO("mysql:host={$db_hostname};dbname={$db_name}",$db_user,$db_password);
  
 }catch(PDOException $x){
  
  die($x->getMessage());
 }


$requete1="set names utf8;";
$res1=mysqli_query($requete1);

$requete ="select concat(utilisateur.ville,',France') as location, true as stopover from visite v inner join ControleProducteur cp on v.idVisite=cp.idVisite inner join utilisateur u on cp.idUtilisateur=u.idUtilisateur where v.idRole=".$_GET["idControleur"];";

$res=$db_con->prepare($requete);
$res->execute();

while($resultat=$res->fetch(PDO::FETCH_ASSOC))
{
  if($resultat["stopover"]==1) {
	$resultat["stopover"]=TRUE;
  }
   $tabRes[]=$resultat;
}
echo json_encode($tabRes);

?>
