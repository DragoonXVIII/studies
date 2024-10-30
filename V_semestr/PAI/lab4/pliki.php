<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/ClientSide/html.html to edit this template
-->
<html>
    <head>
        <title>Formularz</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <form method="post" action='pliki.php'>
            <h2> Formularz zamowienia </h2>
            <table>
                <tr>
                    <td>Nazwisko</td>
                    <td><input type="text" name="nazwisko"></td>
                </tr>
                <tr>
                    <td>Wiek</td>
                    <td><input type="number" name="wiek"></td>
                </tr>
                <tr>
                    <td>Panstwo</td>
                    <td><select name="kraj" id="kraj">
                        <option value="Polska"> Polska</option>
                        <option value="Niemcy">Niemcy</option>
                        <option value="Wielka Brytania">Wielka Brytania</option>
                        <option value="Finlandia">Finlandia</option>
                     </select></td>
                </tr>
                <tr>
                    <td>Mail</td><!-- comment -->
                    <td><input type='text' name="mail"></td>
                </tr>
            </table>
            <h3>Zamawiam tutrial z jezyka:</h3><!-- comment -->
            
            <?php
                $jezyki = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];

                foreach ($jezyki as $value)
                {
                    echo "<input type='checkbox' name='jezyki[]' value='$value'> $value";
                }
            ?>

            <h3>Sposob zaplaty</h3><!-- comment -->
            BLIK<input type="radio" name="zaplata" value="blik"><!-- comment -->
            EuroCard<input type="radio" name="zaplata" value="eurocard">
            Przelew Balnkowy<input type="radio" name="zaplata" value="przelew">

            <br><br><!-- comment -->
            <input type="submit" name ="submit" value="Wyczysc">
            <input type="submit" name ="submit" value="Zapisz">
            <input type="submit" name ="submit" value="Pokaz"><!-- comment -->
            <input type="submit" name ="submit" value="PHP">
            <input type="submit" name ="submit" value="Java"><!-- comment -->
            <input type="submit" name ="submit" value="CPP">
			<input type="submit" name ="submit" value="Statystyki">
        </form>
    </body>
</html>

<?php

	include_once("funkcje.php");
    //Skrypt właściwy do obsługi akcji (żądań):
    if (filter_input(INPUT_POST,"submit")) 
    { //jeśli kliknięto przycisk o name=submit
        $akcja = filter_input(INPUT_POST, "submit"); //odczytaj jego value
        switch ($akcja) 
        {
           case "Zapisz":dodaj();break;
           case "Pokaz":pokaz();break;
           case "Java":pokaz_zamowienie("Java");break;
		   case "CPP":pokaz_zamowienie("CPP");break;
		   case "PHP":pokaz_zamowienie("PHP");break;
		   case "Statystyki":statystyki();break;
           //pozostałe przypadki
        }
    }
/*	
	foreach($_SERVER as $key => $value)
	{
		echo "$key $value<br>";
    }
 */  

?>
