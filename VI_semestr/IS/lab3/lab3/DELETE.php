<?php
$servername = "localhost"; 
$username = "sakila2"; 
$password = "pass"; 
$database = "sakila"; 

// Tworzymy połączenie z bazą danych
$conn = new mysqli($servername, $username, $password, $dbname);

// Sprawdzamy połączenie
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Zakładam, że ID rekordu do usunięcia zostało przekazane jako parametr GET
$actor_id = $_GET['actor_id']; // Przykład: ?actor_id=123

// Zapytanie DELETE (usuwanie stworzonego rekordu)
$sql_delete = "DELETE FROM actor WHERE actor_id = $actor_id"; // Usuwamy rekord na podstawie ID

if ($conn->query($sql_delete) === TRUE) {
    echo "Record deleted successfully\n";
} else {
    echo "Error deleting record: " . $conn->error . "\n";
}

$conn->close();
?>
