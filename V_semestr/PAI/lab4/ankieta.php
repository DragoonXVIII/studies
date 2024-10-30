<html>
    <head>
        <title>Ankieta</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
		<h3>Ankieta</h3>
		<p>Jakie jezyki programowania znasz?</p>
		<form method="post" action='ankieta.php'>
			<?php
				$tech = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
				foreach ($tech as $x)
				{
					echo "<input type='checkbox' name='tech[]' value='$x'> $x<br>";
				}
			?>
			<input type="submit" name ="submit" value="Wyslij ankiete">
		</form>
		
	</body>
</html>

<?php

	if (filter_input(INPUT_POST,"submit")) 
		{
			zapiszwynik();
			pokaz();
		};
		
function zapiszwynik()
{
	$dane = "";
	  
		$args = ['tech' => ['filter' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,'flags' => FILTER_REQUIRE_ARRAY]];
		
		$dane = filter_input_array(INPUT_POST, $args);
		//var_dump($dane);
		
		$errors = "";
		foreach ($dane as $key => $val) 
		{
			if ($val === false or $val === NULL) 
			{
				$errors .= $key . " ";
			}
		}
		
////



$wyniki = array("C"=>0,"CPP"=>0,"Java"=>0,"C#"=>0,"HTML"=>0,"CSS"=>0,"XML"=>0,"PHP"=>0,"JavaScript"=>0);
//var_dump($wyniki);

//tablica wynikow pobrana z pliku	
	if ($file = fopen("ankieta.txt", "r")) 
	{
		while(!feof($file)) 
		{
			$line = fgets($file);
			if ($line!="")
			{
				$liczba="";
				$klucz = "";
				$i=0;
				$i=strpos($line, " ",0);

				for ($k=$i+1;$k<strlen($line);$k++)
				{
					$liczba=$liczba.$line[$k];
				}
				$w = intval($liczba);
				
				for ($k=0;$k<$i;$k++)
				{
					$klucz=$klucz.$line[$k];
				}
				$wyniki[$klucz]=$w;
			}
		}  	
	}
	
////////
		
		$wstaw ="";
		if ($errors === "") 
		{
			foreach ($dane as $key => $val)
			{
				if (is_array($val))
				{
					foreach ($val as $k => $v)
					{
						$wyniki[$v]++;
					}
				}
			}
		} 
		else 
		{
			echo "Nie uzupelniono ankiety!";
		}
		
		echo "<br>";
		//var_dump($wyniki);
		dopliku("ankieta.txt",$wyniki);
}

function dopliku($plik, $dane) 
{
	$myfile = fopen("ankieta.txt", "w") or die("Nie mozna otworzyc pliku");		
	foreach ($dane as $k=>$v)
	{
		$data=$k." ".$v."\n";
		fwrite($myfile, $data);
	}
	fclose($myfile);

}



function pokaz()
{
	echo "<p>Wyniki ankiety</p>";
	$d_root = $_SERVER['DOCUMENT_ROOT'];
	$myfile = fopen("ankieta.txt", "r") or die("Nie mozna otworzyc pliku");
	echo nl2br(fread($myfile,filesize("ankieta.txt")));
	fclose($myfile);
}

?>