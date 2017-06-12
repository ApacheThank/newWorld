<?php
define('CHEMIN_VUE_GLOBALE', 'vues_globales/');
// Identifiants pour la base de données. Nécessaires a PDO2.
define('SQL_DSN','mysql:dbname=dbNewWorld_v1;host=localhost');

define('SQL_USERNAME', 'akhasanov');
define('SQL_PASSWORD', 'jamas003');
// Chemins à utiliser pour accéder aux vues/modeles/librairies
$module = empty($module) ? !empty($_GET['module']) ? $_GET['module'] : 'index' : $module;
define('CHEMIN_VUE',    'modules/'.$module.'/vues/');
define('CHEMIN_MODELE', 'modeles/');
define('CHEMIN_LIB',    'libs/');
define('CHEMIN_CONTROLEUR', 'modules/'.$module.'/');

