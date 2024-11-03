<?php
include_once "Baza.php";
function walidacja()
{
	$min = 10;
	$max = 100;
	$args = [
				'nazwisko' => ['filter' => FILTER_VALIDATE_REGEXP,'options' => ['regexp' => '/^[A-Z]{1}[a-ząęłńśćźżó-]{1,25}$/']],
				'wiek' => ['filter' => FILTER_VALIDATE_INT, 'options' => array("options" => array("min_range"=>$min, "max_range"=>$max))],
				'kraj' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
				'jezyki' => ['filter' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,'flags' => FILTER_REQUIRE_ARRAY],
				'mail' => FILTER_VALIDATE_EMAIL,
				'zaplata' => FILTER_SANITIZE_FULL_SPECIAL_CHARS
			];
			
	
	
	$dane = filter_input_array(INPUT_POST, $args);
	
	$errors = "";
	foreach ($dane as $key => $val) 
	{
		if ($val === false or $val === NULL) 
		{
			$errors .= $key . " ";
		}
	}
	
	if ($errors === "") 
	{
		return $dane;
		return $sql;
	} 
	else 
	{
		echo "bledne dane";
		return false;
	}
}

//nowa postać funkcji dodaj():
function dodaj($bd)
{
	echo "<h3>Dodawanie do bazy:</h3>";
	$dane = walidacja();
	if($dane)
	{
		$j = implode(",",$dane['jezyki']);
		$sql = "INSERT INTO klienci VALUES (NULL, '{$dane['nazwisko']}','{$dane['wiek']}', '{$dane['kraj']}','{$dane['mail']}', '$j', '{$dane['zaplata']}');";
		if($bd->insert($sql))
		{
			echo "dodano";
		}
		else
		{
			echo "nie dodano";
		}
	}
}

function dodaj1($bd)
{
	echo "<h3>Dodawanie do bazy:</h3>";
	$dane = walidacja();
	if($dane)
	{
		$j = implode(",",$dane['jezyki']);
		$stmt = $bd->prepare("INSERT INTO klienci(nazwisko,wiek,panstwo,email,zamowienie,platnosc) VALUES (?,?,?,?,?,?)");
		$stmt->bindParam(1,$dane['nazwisko']);
		$stmt->bindParam(2,$dane['wiek']);
		$stmt->bindParam(3,$dane['nazwisko']);
		$stmt->bindParam(4,$dane['mail']);
		$stmt->bindParam(5,$j);
		$stmt->bindParam(6,$dane['zaplata']);
		echo $stmt;
		if($bd->insert($sql))
		{
			echo "dodano";
		}
		else
		{
			echo "nie dodano";
		}
	}
}

//nowa funkcja pomocnicza:
function dopliku($plik, $dane) 
{
	echo "<p>Zapisano: <br /> $dane</p>";
	$dane=$dane."\n";
	$myfile = fopen("data.txt", "a") or die("Nie mozna otworzyc pliku");		
	fwrite($myfile, $dane);
	fclose($myfile);
}


function statystyki()
{
	$licznik = 0;
	$licznik18m = 0;
	$licznik50w = 0;
	$w = 0;

	//sprawdzic czy zawiera minimum 1 linijke
	if ($file = fopen("data.txt", "r")) 
	{
		while(!feof($file)) 
		{
			$odczyt="";
			$i=0;
			$line = fgets($file);
			if ($line!="")
			{
				$licznik++;
				$i=strpos($line, " ");
				$j=strpos($line, " ",$i+1);
				//echo $line;
				//echo $i." ".$j;
				for ($k=$i+1;$k<$j;$k++)
				{
					$odczyt=$odczyt.$line[$k];
				}
				$w = intval($odczyt);
				//echo $w;
				
				if( $w<18)
				{
					$licznik18m++;
				}
				if( $w>=50)
				{
					$licznik50w++;
				}
			}
		}
		
	}
	fclose($file);
	echo "Liczba osob: $licznik<br>";
	echo "Liczba osob w wieku poniezej 18 lat: $licznik18m<br>";
	echo "Liczba osob w wieku powyzej lub rowna 50 lat: $licznik50w<br>";
}
?>