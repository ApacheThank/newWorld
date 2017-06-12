<?php
// connexion bdd
$host="localhost";
$user="akhasanov";
$password="jamas003";

mysqli_connect($host,$user,$password);
mysqli_select_db("dbNewWorld_v1");

$requete="select libelle from rayon";
$res=mysql_query($requete);
while($tabInfo=mysql_fetch_array($res))
{
$tabResultat['rayons'][]=$tabInfo;
}
$obj=json_encode($tabResultat);

echo $obj; 
?>
