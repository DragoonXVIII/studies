<?php

$servername = "localhost";
$username = "sakila1";
$password = "pass";
$database = "sakila";

$conn = new mysqli($servername, $username, $password, $database);
if ($conn->connect_error) {
    die("Database connection failed: " . $conn->connect_error);
}

echo "Database connected successfully, username: " . $username . "<br><br>";

$conn->query("SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE");

$conn->begin_transaction();

echo "Before sleep<br>";
$sql = "SELECT * FROM actor WHERE first_name = 'ADAM'";
$result = $conn->query($sql);
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "id: " . $row["actor_id"] . " - Name: " . $row["first_name"] . " " . $row["last_name"] . "<br>";
    }
} else {
    echo "0 results<br>";
}

sleep(20);

$conn->commit();
$conn->close();
?>