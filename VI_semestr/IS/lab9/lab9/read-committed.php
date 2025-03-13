<?php

// example of READ COMMITTED transaction isolation level (default one) 

$servername = "localhost";
$username = "sakila1";
$password = "pass";
$database = "sakila";
$conn = new mysqli(
    $servername,
    $username,
    $password,
    $database
);
if ($conn->connect_error) {
    die("Database connection failed: " . $conn->connect_error);
}
echo "Databse connected successfully, username " .
    $username . "<br><br>";
// Change the default isolation level (default is 
// REPEATABLE READ) 
$conn->query("SET SESSION TRANSACTION ISOLATION LEVEL READ 
COMMITTED");
// Start transaction 
$conn->begin_transaction();
echo "Before sleep<br>";
$sql = "SELECT actor_id, first_name, last_name FROM actor 
WHERE first_name = 'ADAM'";
$result = $conn->query($sql);
if ($result->num_rows > 0) {
    // output data of each row 
    while ($row = $result->fetch_assoc()) {
        echo "id: " . $row["actor_id"] . " - Name: " .
            $row["first_name"] . " " . $row["last_name"] . "<br>";
    }
} else {
    echo "0 results<br>";
}
// To test how to isolation level works you should invoke 
// /update-adam.php from the second application in this moment, 
// that the database state will be changed 
sleep(20);
// You should see different result of the query even though 
// both queries are executed during one transaciton. 
// This is due to the altered level of isolation that 
// allows committed changes to be read from other transactions 
echo "After sleep<br>";
$sql = "SELECT actor_id, first_name, last_name FROM actor 
WHERE first_name = 'ADAM'";

$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // output data of each row 
    while ($row = $result->fetch_assoc()) {
        echo "id: " . $row["actor_id"] . " - Name: " .
            $row["first_name"] . " " . $row["last_name"] . "<br>";
    }
} else {
    echo "0 results<br>";
}

$conn->commit();
$conn->close();

?>