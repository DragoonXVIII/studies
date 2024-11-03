<?php

class Baza {
	private $mysqli; //uchwyt do BD
	public function __construct($serwer, $user, $pass, $baza) 
	{
		$this->mysqli = new mysqli($serwer, $user, $pass, $baza);
		/* sprawdz połączenie */
		if ($this->mysqli->connect_errno) 
		{
			printf("Nie udało sie połączenie z serwerem: %s\n",
			$mysqli->connect_error);
			exit();
		}
		/* zmien kodowanie na utf8 */
		if ($this->mysqli->set_charset("utf8")) 
		{
			//udało sie zmienić kodowanie
		}
	} //koniec funkcji konstruktora
	
	function __destruct() 
	{
		$this->mysqli->close();
	}
	public function select($sql, $pola) 
	{
		//parametr $sql – łańcuch zapytania select
		//parametr $pola - tablica z nazwami pol w bazie
		//Wynik funkcji – kod HTML tabeli z rekordami (String)
		$tresc = "";
		
		if ($result = $this->mysqli->query($sql)) 
		{
			$ilepol = count($pola); //ile pól
			$ile = $result->num_rows; //ile wierszy
			// pętla po wyniku zapytania $results
			$tresc.="<table><tbody>";
			while ($row = $result->fetch_object()) 
			{
				$tresc.="<tr>";
				for ($i = 0; $i < $ilepol; $i++) 
				{
					$p = $pola[$i];
					$tresc.="<td>" . $row->$p . "</td>";
				}
				$tresc.="</tr>";
			}
			$tresc.="</table></tbody>";
			$result->close(); /* zwolnij pamięć */
		}
		return $tresc;
	}
	
	public function insert($sql) 
	{
		if( $this->mysqli->query($sql))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public function delete($sql) 
	{
		if( $this->mysqli->query($sql))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public function getMysqli() 
	{
		return $this->mysqli;
	}
} 

?>
