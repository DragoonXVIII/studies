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
        <form method="post" action='index.php'>
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
                    <td>Mail</td>
                    <td><input type='text' name="mail"></td>
                </tr>
            </table>
            <h3>Zamawiam tutrial z jezyka:</h3>
            
            <?php
                $jezyki = ["CPP", "Java", "PHP"];

                foreach ($jezyki as $value)
                {
                    echo "<input type='checkbox' name='jezyki[]' value='$value'> $value";
                }
            ?>

            <h3>Sposob zaplaty</h3>
            Visa<input type="radio" name="zaplata" value="Visa">
            Master Card<input type="radio" name="zaplata" value="Master Card">
            Przelew<input type="radio" name="zaplata" value="Przelew">

            <br><br>
			<input type="submit" name ="submit" value="Pokaz">
            <input type="submit" name ="submit" value="Zapisz">
        </form>
    </body>
</html>

<?php

	include_once("funkcje.php");
	include_once "Baza.php";
    include_once "Baza1.php";
	$bd = new Baza("localhost", "root", "", "klienci");
    //Skrypt właściwy do obsługi akcji (żądań):
    if (filter_input(INPUT_POST,"submit")) 
    { //jeśli kliknięto przycisk o name=submit
        $akcja = filter_input(INPUT_POST, "submit"); //odczytaj jego value
        switch ($akcja) 
        {
           case "Zapisz":dodaj($bd);break;
		   case "Pokaz": echo $bd->select("select Nazwisko,Zamowienie from klienci", ["Nazwisko","Zamowienie"]); break;
        }
    }

?>
