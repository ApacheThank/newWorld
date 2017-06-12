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
	
?>