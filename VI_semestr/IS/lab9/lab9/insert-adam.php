<?php
$servername = "localhost";
$username = "sakila1";
$password = "pass";
$database = "sakila";

$conn = new mysqli($servername, $username, $password, $database);
if ($conn->connect_error) {
    die("Database connection failed: " . $conn->connect_error);
}

$conn->query("INSERT INTO actor (first_name, last_name) VALUES ('ADAM', 'NEWACTOR')");
echo "New ADAM added!";

$conn->close();
?>