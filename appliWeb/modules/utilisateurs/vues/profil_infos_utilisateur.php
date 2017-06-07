<?php include CHEMIN_LIB.'messages_en.php';?>
<h2><?=$labelYourProfil?></h2>
<p>
	<span class="label_profil"><br /><?=$labelLogin?></span> : <?php echo htmlspecialchars($login); ?><br />
	<span class="label_profil"><?=$labelLastName?></span> : <?php echo htmlspecialchars($nom); ?><br />
	<span class="label_profil"><?=$labelFirstName?></span> : <?php echo htmlspecialchars($prenom); ?><br />
	<span class="label_profil"><?=$labelMail?></span> : <?php echo htmlspecialchars($email); ?><br />
	<span class="label_profil"><?=$labelAddress?> </span> : <?php echo htmlspecialchars($rue); ?><br />
	<span class="label_profil"><?=$labelCity?></span> : <?php echo htmlspecialchars($ville); ?><br />
	<span class="label_profil"><?=$labelZipCode?></span> : <?php echo htmlspecialchars($codePostal); ?><br />
	<span class="label_profil"><?=$labelPhone?></span> : <?php echo $num_tel; ?><br />
	<span class="label_profil"><?=$labelRegistrationDate?></span> : <?php echo $dateinscription; ?><br />
	<span class="label_profil"><?=$labelTypeUser?></span> : <?php echo $fonction; ?>

</p>
	<h3><a href='index.php?module=utilisateurs&amp;action=modifier_profil&amp;id=$id_utilisateur'><?=$buttonModifyProfil?></a></h3>
