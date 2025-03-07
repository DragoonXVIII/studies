<?php
$servername = "localhost";  // Zmienna dla serwera
$username = "root";         // Nazwa użytkownika
$password = "";             // Hasło
$dbname = "sakila";         // Nazwa bazy danych

// Tworzymy połączenie z bazą danych
$conn = new mysqli($servername, $username, $password, $dbname);

// Sprawdzamy połączenie
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Zapytanie UPDATE
$sql = "UPDATE customer SET email = 'new_email@example.com' WHERE customer_id = 1"; // Możesz zmienić zapytanie

if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully";
} else {
    echo "Error updating record: " . $conn->error;
}

$conn->close();
?>
