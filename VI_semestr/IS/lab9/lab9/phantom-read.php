<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

$servername = "localhost";
$username = "sakila1";
$password = "pass";
$database = "sakila";

$conn = new mysqli($servername, $username, $password, $database);
if ($conn->connect_error) {
    die("Database connection failed: " . $conn->connect_error);
}

echo "Database connected successfully, username " . $username . "<br><br>";

$conn->query("SET SESSION TRANSACTION ISOLATION LEVEL READ COMMITTED");

$conn->begin_transaction();

echo "Before sleep<br>";
$sql = "SELECT actor_id, first_name, last_name FROM actor WHERE first_name = 'ADAM' ORDER BY actor_id ASC";
$result = $conn->query($sql);

$actors_before = [];
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "id: " . $row["actor_id"] . " - Name: " . $row["first_name"] . " " . $row["last_name"] . "<br>";
        $actors_before[] = $row;
    }
} else {
    echo "0 results<br>";
}

flush(); 
sleep(20); 

echo "After sleep<br>";
$sql = "SELECT actor_id, first_name, last_name FROM actor WHERE first_name = 'ADAM' ORDER BY actor_id ASC";
$result = $conn->query($sql);

$actors_after = [];
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "id: " . $row["actor_id"] . " - Name: " . $row["first_name"] . " " . $row["last_name"] . "<br>";
        $actors_after[] = $row;
    }
} else {
    echo "0 results<br>";
}

$conn->commit();
$conn->close();

if (count($actors_after) > count($actors_before)) {
    echo "<br><strong> Phantom Read detected! Now there are more records than before.</strong>";
} else {
    echo "<br><strong> No Phantom Read detected.</strong>";
}
?>
