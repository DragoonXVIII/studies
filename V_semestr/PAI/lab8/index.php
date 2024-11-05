<!DOCTYPE html>

<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
            include 'klasy/User.php';
			include_once('klasy/RegistartionForm.php');
			include_once "klasy/Baza.php";
			$bd = new Baza("localhost", "root", "", "klienci");

			$rf = new RegistartionForm();
			
			if(filter_input(INPUT_POST,'submit',FILTER_SANITIZE_FULL_SPECIAL_CHARS))
			{
				$user = $rf->checkUser();
				if($user==NULL)
				{
					echo '<p>Niepoprawne dane do rejestracji</p>';
				}
				else
				{
					echo '<p>Poprawne dane do rejestracji</p>';
                    $user->saveToDB($bd);
				}
			}
            if(filter_input(INPUT_POST,'show',FILTER_SANITIZE_FULL_SPECIAL_CHARS))
            {
                User::getAllUsersFromDB($bd);
            }
			
        ?>
    </body>
</html>
