<?php

function dodaj1()
{
    $dane = "";
    if(filter_input(INPUT_POST, "nazwisko"))
    {
        $dane=$dane."Nazwisko: ".htmlspecialchars($_REQUEST["nazwisko"])." ";
    }
    if(filter_input(INPUT_POST,"wiek"))
    {
        $dane=$dane."Wiek: ".htmlspecialchars($_REQUEST["wiek"])." ";
    }
    if(filter_input(INPUT_POST, "mail"))
    {
        $dane=$dane."Mail: ".htmlspecialchars($_REQUEST["mail"])." ";
    }
    if(filter_input(INPUT_POST,"kraj"))
    {
        $dane=$dane."Kraj: ".htmlspecialchars($_REQUEST["kraj"])." ";
    }
    
    if(filter_input(INPUT_POST, 'jezyki')) 
    {    
        $dane=$dane."Jezyki: ";
        foreach(filter_input(INPUT_POST, 'jezyki') as $value)
        {
            $dane=$dane." ".htmlspecialchars($value)." ";
        }
    }
    
    if(filter_input(INPUT_POST, 'zaplata')!="")
    {
        $dane=$dane."Zaplata: ".htmlspecialchars($_REQUEST["zaplata"])." ";
    }
	
	if($dane!="")
	{
		$dane=$dane."\n";
		$myfile = fopen("data2.txt", "a") or die("Nie mozna otworzyc pliku");
		fwrite($myfile, $dane);
		fclose($myfile);
	}
      
};

function pokaz()
{
	$d_root = $_SERVER['DOCUMENT_ROOT'];
	$myfile = fopen("data.txt", "r") or die("Nie mozna otworzyc pliku");
	echo nl2br(fread($myfile,filesize("data.txt")));
	fclose($myfile);
}

function pokaz_zamowienie($tut)
{
	//$d_root = $_SERVER['DOCUMENT_ROOT'];
	
	if ($file = fopen("data.txt", "r")) 
	{
		while(!feof($file)) 
		{
			$line = fgets($file);
			if(strstr($line,$tut))
			{
				print(nl2br($line));
			}
		}
		fclose($file);
	}
}

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
	//var_dump($dane);
	
	//echo $dane;
	$wstaw ="";
	if ($errors === "") 
	{
		foreach ($dane as $key => $val) 
		{
			if (is_array($val))
			{
				foreach ($val as $tmp)
				{
					$wstaw = $wstaw.$tmp." ";
				}
			}
			else
			{
				$wstaw=$wstaw.$val." ";
			}
		}
		dopliku("dane.txt", $wstaw);
	} 
	else 
	{
		echo "Bledne dane";
	}
}

//nowa postać funkcji dodaj():
function dodaj()
{
	echo "<h3>Dodawanie do pliku:</h3>";
	walidacja();
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
	echo "Liczba osob w wieku ponizej 18 lat: $licznik18m<br>";
	echo "Liczba osob w wieku powyzej lub rowna 50 lat: $licznik50w<br>";
}
?>