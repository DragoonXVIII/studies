<?php
    include_once "klasy/User.php";

    echo "<h2>TEST 2</h2>";

    session_start();


    $l = 0;
	if(!empty($_SESSION))
	{
		if(isset($_SESSION['u1']))
		{
			echo "<b>Dane uzytkownika:</b><br>";
			$u1 = unserialize($_SESSION['u1']);
			$u1->show();
		}
		echo "<hr>";
		echo "<b>Session ID: </b>".session_id();
		echo "<br><hr>";
		echo "<b>Dane sesji:</b><br>";
		foreach ($_SESSION as $key => $val)
		{
			echo $key.":".$val."<br>";
			$l++;
			if($l==4)
			{
				$l=0; //zeby formatowac tekst, 4 pierwsze dane i reszta potemxd
				echo "<br>";
				# echo "NOWAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAALININAAAA";
			}
		}
	}
	else
	{
		echo "BRAK";
	}
    
    echo "<hr>";
    foreach ($_COOKIE as $i)
    {
        echo "<b>Cookie: </b>".$i;
    }
    echo "<br><hr>";
    echo "<a href='test1.php'>Idz do test1.php</a>";
	session_destroy();
?>