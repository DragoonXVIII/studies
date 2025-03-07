<?php
$servername = "localhost"; 
$username = "sakila1"; 
$password = "pass"; 
$database = "sakila"; 

// Tworzymy połączenie z bazą danych
$conn = new mysqli($servername, $username, $password, $dbname);

// Sprawdzamy połączenie
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Zapytanie CREATE
$sql = "INSERT INTO actor (first_name, last_name) VALUES ('John', 'Doe')"; // Przykładowe zapytanie INSERT

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error creating record: " . $conn->error;
}

$conn->close();
?>
