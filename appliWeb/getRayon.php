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

$requete="select idRayon,libelle from rayon";
$res=$db_con->prepare($requete);
$res->execute();
$tabResultat=array();

while($tabInfo=$res->fetch(PDO::FETCH_ASSOC))
{
$tabResultat['rayons'][]=$tabInfo;
}

$obj=json_encode($tabResultat);
echo $obj;
?>
