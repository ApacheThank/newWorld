<?php 
// Suppression de toutes les variables et destruction de la session
$_SESSION = array();
session_destroy();

// Suppression des cookies de connexion automatique
//setcookie('id', '');
//setcookie('connexion_auto', '');

include CHEMIN_VUE.'deconnexion_ok.php';

