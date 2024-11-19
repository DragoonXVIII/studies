<?php

	include_once 'klasy/Baza.php';
	include_once 'klasy/User.php';
	include_once 'klasy/UserManager.php';


	session_start();
	$db = new Baza("localhost", "root", "", "klienci");
	$um = new UserManager();

	$sessionId = session_id();
	$userID = $um->getLoggedInUser($db, $sessionId);
	
	if($userID<0)
	{
		echo "<h2>Brak dostepu</h2>";
	}
	else
	{
		echo "<h2>Masz dostep do danych </h2>";
		echo $userID;
		echo "<br>";
		$IDU = $userID = $db->select("select userId from logged_in_users where sessionId = '$sessionId'", ["userId"]);
		$IDU2 = preg_replace('/[^0-9.]+/', '', $IDU);
		$dane = $db->select("select userName,fullName,email,passwd,status,date from users where id = '$IDU2'", ["userName","fullName","email","passwd","status","date"]);
		echo "<h3>Twoje dane</h3>";
		echo $dane."<br>";

		echo "<a href='processLogin.php?akcja=wyloguj' >Wyloguj</a> </p>";
	}


?>