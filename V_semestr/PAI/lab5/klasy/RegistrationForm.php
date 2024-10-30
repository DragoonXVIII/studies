<?php
include_once 'User.php';

class RegistrationForm {
    protected $user;

    // Konstruktor wyświetlający formularz
    function __construct() {
        ?>
        <h3>Formularz rejestracji</h3>
        <form action="index.php" method="post">
            Nazwa użytkownika: <br/><input name="userName" required /><br/>
            Imię i nazwisko: <br/><input name="fullName" required /><br/>
            Email: <br/><input type="email" name="email" required /><br/>
            Hasło: <br/><input type="password" name="passwd" required /><br/>
            <input type="submit" name="submit" value="Zarejestruj" />
        </form>
        <?php
    }

    // Metoda do weryfikacji danych
    function checkUser() {
        $args = [
            'userName' => ['filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[0-9A-Za-ząęłńśćźżó_]{2,25}$/']],
            'fullName' => ['filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^[A-Za-ząęłńśćźżó\s]{2,50}$/']],
            'email' => FILTER_VALIDATE_EMAIL,
            'passwd' => ['filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/.{5,25}/']]
        ];

        // Przefiltrowanie danych wejściowych
        $dane = filter_input_array(INPUT_POST, $args);

        // Sprawdzenie błędów walidacji
        $errors = "";
        foreach ($dane as $key => $val) {
            if ($val === false || $val === NULL) {
                $errors .= "Błędne $key. ";
            }
        }

        if ($errors === "") {
            // Dane są poprawne - utworzenie obiektu User
            $this->user = new User($dane['userName'], $dane['fullName'], $dane['email'], $dane['passwd']);
        } else {
            echo "<p>Błędne dane: $errors</p>";
            $this->user = NULL;
        }
        return $this->user;
    }
}
?>
