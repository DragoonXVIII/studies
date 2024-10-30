
<?php
/*
class User {
    // Stałe określające status użytkownika
    const STATUS_USER = 1;
    const STATUS_ADMIN = 2;

    // Pola klasy
    protected $userName;
    protected $passwd;
    protected $fullName;
    protected $email;
    protected $date;
    protected $status;

    public function __construct($userName, $fullName, $email, $passwd) {
        $this->userName = $userName;
        $this->fullName = $fullName;
        $this->email = $email;
        $this->passwd = password_hash($passwd, PASSWORD_DEFAULT); // Hashowanie hasła
        $this->status = self::STATUS_USER; // Ustawienie statusu na użytkownika
        $this->date = (new DateTime())->format('Y-m-d'); // Ustawienie bieżącej daty
    }

    // Metoda show - wyświetla informacje o użytkowniku
    public function show() {
        echo "Nazwa użytkownika: " . $this->userName . "<br>";
        echo "Imię i nazwisko: " . $this->fullName . "<br>";
        echo "Email: " . $this->email . "<br>";
        echo "Data utworzenia konta: " . $this->date . "<br>";
        echo "Status: " . ($this->status == self::STATUS_USER ? "User" : "Admin") . "<br>";
    }

    // Gettery i Settery
    public function setUserName($userName) {
        $this->userName = $userName;
    }

    public function getUserName() {
        return $this->userName;
    }

    public function setPasswd($passwd) {
        $this->passwd = password_hash($passwd, PASSWORD_DEFAULT);
    }

    public function getPasswd() {
        return $this->passwd;
    }

    public function setFullName($fullName) {
        $this->fullName = $fullName;
    }

    public function getFullName() {
        return $this->fullName;
    }

    public function setEmail($email) {
        $this->email = $email;
    }

    public function getEmail() {
        return $this->email;
    }

    public function setDate($date) {
        $this->date = $date;
    }

    public function getDate() {
        return $this->date;
    }

    public function setStatus($status) {
        $this->status = $status;
    }

    public function getStatus() {
        return $this->status;
    }
}
*/  
?>

<?php
class User {
    const STATUS_USER = 1;
    const STATUS_ADMIN = 2;

    protected $userName;
    protected $passwd;
    protected $fullName;
    protected $email;
    protected $date;
    protected $status;

    // Konstruktor
    function __construct($userName, $fullName, $email, $passwd) {
        $this->userName = $userName;
        $this->fullName = $fullName;
        $this->email = $email;
        $this->passwd = password_hash($passwd, PASSWORD_DEFAULT);
        $this->date = (new DateTime())->format('Y-m-d');
        $this->status = self::STATUS_USER;
    }

    // Metoda do wyświetlania danych użytkownika
    public function show() {
        echo "<p>Nazwa użytkownika: {$this->userName}</p>";
        echo "<p>Imię i nazwisko: {$this->fullName}</p>";
        echo "<p>Email: {$this->email}</p>";
        echo "<p>Data utworzenia konta: {$this->date}</p>";
        echo "<p>Status: " . ($this->status === self::STATUS_ADMIN ? "Admin" : "User") . "</p>";
    }

    // Statyczna metoda do odczytu wszystkich użytkowników z pliku JSON
    public static function getAllUsers($plik) {
        $tab = json_decode(file_get_contents($plik));
        foreach ($tab as $val) {
            echo "<p>{$val->userName} - {$val->fullName} - Data utworzenia: {$val->date}</p>";
        }
    }

    // Metoda konwertująca obiekt do tablicy
    public function toArray() {
        return [
            "userName" => $this->userName,
            "passwd" => $this->passwd,
            "fullName" => $this->fullName,
            "email" => $this->email,
            "date" => $this->date,
            "status" => $this->status
        ];
    }

    // Metoda zapisująca obiekt do pliku JSON
    public function save($plik) {
        $tab = json_decode(file_get_contents($plik), true);
        array_push($tab, $this->toArray());
        file_put_contents($plik, json_encode($tab, JSON_PRETTY_PRINT));
    }

    public function saveXML($plik) {
        $xml = simplexml_load_file($plik);

        $userNode = $xml->addChild("user");
        $userNode->addChild("userName", $this->userName);
        $userNode->addChild("passwd", $this->passwd);
        $userNode->addChild("fullName", $this->fullName);
        $userNode->addChild("email", $this->email);
        $userNode->addChild("date", $this->date);
        $userNode->addChild("status", $this->status);

        $dom = new DOMDocument("1.0");
        $dom->preserveWhiteSpace = false;  // Usuwa zbędne białe znaki
        $dom->formatOutput = true;         // Ustawia formatowanie na "ładne" wcięcia
        $dom->loadXML($xml->asXML());   

        $dom->save($plik);  // Zapis zmodyfikowanego XML do pliku
    }

    // Statyczna metoda do odczytu wszystkich użytkowników z pliku XML
    public static function getAllUsersFromXML($plik) {
        $xml = simplexml_load_file($plik);
        echo "<ul>";
        foreach ($xml->user as $user) {
            echo "<li>";
            echo "Nazwa użytkownika: {$user->userName}, ";
            echo "Imię i nazwisko: {$user->fullName}, ";
            echo "Email: {$user->email}, ";
            echo "Data utworzenia: {$user->date}, ";
            echo "Status: " . ($user->status == self::STATUS_ADMIN ? "Admin" : "User");
            echo "</li>";
        }
        echo "</ul>";
    }

    // Gettery i Settery
    public function setUserName($userName) {
        $this->userName = $userName;
    }

    public function getUserName() {
        return $this->userName;
    }

    public function setPasswd($passwd) {
        $this->passwd = password_hash($passwd, PASSWORD_DEFAULT);
    }

    public function getPasswd() {
        return $this->passwd;
    }

    public function setFullName($fullName) {
        $this->fullName = $fullName;
    }

    public function getFullName() {
        return $this->fullName;
    }

    public function setEmail($email) {
        $this->email = $email;
    }

    public function getEmail() {
        return $this->email;
    }

    public function setDate($date) {
        $this->date = $date;
    }

    public function getDate() {
        return $this->date;
    }

    public function setStatus($status) {
        $this->status = $status;
    }

    public function getStatus() {
        return $this->status;
    }
}
?>
