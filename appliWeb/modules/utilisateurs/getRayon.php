<?php
// connexion bdd
$con=mysqli_connect("localhost", "akhasanov", "jamas003", "dbNewWorld_v1");

$requete="select libelle from rayon";
$res=mysqli_query($con,$requete);


while($tabInfo=mysqli_fetch_array($res))
{
$tabResultat[]=$tabInfo;
}
var_dump($tabResultat);

$tabResultat = array_map('encode_all_strings', $tabResultat);

function encode_all_strings($arr) {
    foreach($arr as $key => $value) {
        $arr[$key] = utf8_decode($value);
    }
    return $arr;
}
var_dump($tabResultat);
$obj=json_encode($tabResultat);
echo $obj;
mysqli_close($con);

?>
