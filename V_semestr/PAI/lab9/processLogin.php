<?php
	include_once 'klasy/Baza.php';
	include_once 'klasy/User.php';
	include_once 'klasy/UserManager.php';
	$db = new Baza("localhost", "root", "", "klienci");
	
	$um = new UserManager();
	//parametr z GET – akcja = wyloguj
	if (filter_input(INPUT_GET, "akcja")=="wyloguj") 
	{
		$um->logout($db);
	}
	
	//kliknięto przycisk submit z name = zaloguj
	if (filter_input(INPUT_POST, "zaloguj")) 
	{
		 $userId=$um->login($db); //sprawdź parametry logowania
		 if ($userId > 0) 
		 {
			 echo "<p>Poprawne logowanie.<br />";
			 echo "Zalogowany użytkownik o id=$userId <br />";
			 //pokaż link wyloguj lub przekieruj
			 // użytkownika na inną stronę dla zalogowanych
			 echo "<a href='processLogin.php?akcja=wyloguj' >Wyloguj</a> </p>";
			 header("location:testLogin.php");
		}
		else 
		{
			echo "<p>Błędna nazwa użytkownika lub hasło</p>";
			$um->loginForm(); //Pokaż formularz logowania
		}
	} 
	else 
	{
		 //pierwsze uruchomienie skryptu processLogin
		 $um->loginForm();
	}
	
 ?>