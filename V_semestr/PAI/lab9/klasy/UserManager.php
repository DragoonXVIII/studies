<?php

class UserManager 
{
	function loginForm() 
	{
		?>
			<h3>Formularz logowania</h3><p>
			<form action="processLogin.php" method="post">
				<table>
				<tr>
					<td>Login</td><td><input type="text" name = "login"></td>
				</tr>
				<tr>
					<td>Haslo</td><td><input type="text" name = "passwd"></td>
				</tr>
				<table>
				<table>
					<td><input type="submit" value="Zaloguj" name="zaloguj"/></td>
					<td><input type="reset" value="Reset" name="reset" /></td>
					<td>
						<form>
			        		<button formaction="index.php">Zarejestruj sie</button>
			        		<button formaction="testLogin.php">testLogin</button>
			        	</form>
			        </td>
				</table>
			</form></p> 
		<?php
	}
	
	function login($db) 
	{

	 //funkcja sprawdza poprawność logowania
	 //wynik - id użytkownika zalogowanego lub -1
	 $args = [
				'login' => 521,
				'passwd' => 521
			];
	 //przefiltruj dane z GET (lub z POST) zgodnie z ustawionymi w $args filtrami:
	$dane = filter_input_array(INPUT_POST, $args);
	//sprawdź czy użytkownik o loginie istnieje w tabeli users i czy podane hasło jest poprawne
	$login = $dane["login"];
	$passwd = $dane["passwd"];
	$userId = $db->selectUser($login, $passwd, "users");
	if ($userId >= 0) 
		{ 
			//Poprawne dane
			//rozpocznij sesję zalogowanego użytkownika
			//usuń wszystkie wpisy historyczne dla użytkownika o $userId
			//ustaw datę - format("Y-m-d H:i:s");
			//pobierz id sesji i dodaj wpis do tabeli logged_in_users

			$sql = "DELETE from logged_in_users WHERE userId=$userId;";
			$db->delete($sql);
			session_start();
			$session_id = session_id();
			$lastUpdate = new DateTime();
			$lastUpdate = $lastUpdate->format("Y-m-d H:i:s");
			$sql = "INSERT INTO logged_in_users VALUES ('$session_id','$userId','$lastUpdate');";
			//echo $sql;
			$db->insert($sql);
			
			
		}
		return $userId;
	}
	
	function getLoggedInUser($db, $sessionId) 
	{
		$userID = $db->select("select sessionId from logged_in_users where sessionId = '$sessionId'", ["sessionId"]);

		if(str_contains($userID, $sessionId))
		{
			return $userID;
		}
		else
		{
			return -1;
		}
		
	}

	function logout($db) 
	{
		session_start();
		$session_id = session_id();
		if(isset($_COOKIE[session_name()]))
		{
			setcookie(session_name(),'',time()-4200,'/');
		}
		session_destroy();

		$sql = "DELETE from logged_in_users WHERE sessionId='$session_id';";
		//echo $sql;
		if($db->delete($sql))
		{
			echo "<h6>Uzytwkonik wylogowany</h6>";
		}
		//pobierz id bieżącej sesji (pamiętaj o session_start()
		//usuń sesję (łącznie z ciasteczkiem sesyjnym) //sesion_destroy;
		//usuń wpis z id bieżącej sesji z tabeli logged_in_users
	}
	
	
}

?>