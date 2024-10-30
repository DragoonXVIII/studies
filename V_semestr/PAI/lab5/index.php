
<?php
include_once 'klasy/User.php';


$user1 = new User('kp', 'Kubus Puchatek', 'kubus@stumilowylas.pl', 'nielubietygryska');
echo "<h2>Informacje o użytkowniku 1:</h2>";
$user1->show();


$user2 = new User('tygrysek', 'Tygrysek', 'tygrysek@stumilowylas.pl', 'hopsasa');
echo "<h2>Informacje o użytkowniku 2:</h2>";
$user2->show(); 

// Modyfikacja userName oraz statusu dla użytkownika 1
$user1->setUserName('admin');
$user1->setStatus(User::STATUS_ADMIN);

// Ponowne wyświetlenie informacji o zmodyfikowanym użytkowniku 1
echo "<h2>Zmodyfikowane informacje o użytkowniku 1:</h2>";
$user1->show();
?>

<?php
/*
include_once('klasy/User.php');
include_once('klasy/RegistrationForm.php');

$rf = new RegistrationForm(); // Wyświetla formularz rejestracji

// Sprawdza, czy formularz został przesłany
if (filter_input(INPUT_POST, 'submit', FILTER_SANITIZE_FULL_SPECIAL_CHARS)) {
    $user = $rf->checkUser(); // Sprawdza poprawność danych
    if ($user === NULL) {
        echo "<p>Niepoprawne dane rejestracji.</p>";
    } else {
        echo "<p>Poprawne dane rejestracji:</p>";
        $user->show();
    }
}
*/
?>
<?php
include_once('klasy/User.php');
include_once('klasy/RegistrationForm.php');

$rf = new RegistrationForm(); // Wyświetla formularz rejestracji

// Sprawdza, czy formularz został przesłany
if (filter_input(INPUT_POST, 'submit', FILTER_SANITIZE_FULL_SPECIAL_CHARS)) {
    $user = $rf->checkUser(); // Sprawdza poprawność danych
    if ($user === NULL) {
        echo "<p>Niepoprawne dane rejestracji.</p>";
    } else {
        echo "<p>Poprawne dane rejestracji:</p>";
        $user->show();
        $user->save("users.json"); // Zapisuje użytkownika do pliku JSON
        $user->saveXML("users.xml"); // Zapisuje użytkownika do pliku XML
    }
}

// Wywołanie metody statycznej do wyświetlania wszystkich użytkowników
echo "<h3>Lista wszystkich użytkowników JSON:</h3>";
User::getAllUsers("users.json");

//$user = new User("janek", "Jan Kowalski", "janek@example.com", "haslo123");
//$user->show();  // Wyświetla informacje o nowym użytkowniku
//$user->saveXML("users.xml");  // Zapisuje nowego użytkownika do pliku XML

// Wyświetlamy listę wszystkich użytkowników zapisanych w pliku XML
echo "<h3>Lista wszystkich użytkowników XML:</h3>";
User::getAllUsersFromXML("users.xml");
?>
