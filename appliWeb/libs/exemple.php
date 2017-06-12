<?php
// Ne pas oublier d'inclure la libraire Form
include 'form.php';

// Création d'un objet Form.  // L'identifiant est obligatoire !
$mon_form = new Form('exemple', 'POST');

// Ajout d'un champ texte nommé "pseudo"
$mon_form->add('Text', 'pseudo')
               ->label('Votre pseudo SVP');

// Ajout d'une liste d'options pour choisir un pays
$mon_form->add('Select', 'pays')
         ->label('Quel est votre pays préféré')
         ->choices(array(
           'Europe' => array(
             'fr' => 'France',
             'de' => 'Allemagne'
           ),
           'Asie' => array(
             'cn' => 'Chine',
             'jp' => 'Japon'
           )
         ));

// Si le formulaire est valide avec les données issues du tableau $_POST
if ($mon_form->is_valid($_POST)) {

	// On récupère les valeurs
	list($pseudo, $pays) = $mon_form->get_cleaned_data('pseudo', 'pays');
	
	// Et on les affiche
	echo 'Vous êtes '.$pseudo.' et votre pays préféré est "'.$pays.'".';

} else {

	// Sinon on affichage le formulaire jusqu'à ce que ça soit valide
	echo $mon_form;
}