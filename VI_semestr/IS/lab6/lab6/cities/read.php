<?php
header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");
include_once '../class/Citites.php';
include_once '../config/Database.php';

$database = new Database();
$db = $database->getConnection();
$cities = new Cities($db);
$cities->id = (isset($_GET['id']) && $_GET['id']) ? $_GET['id'] : '0';
$result = $cities->read();

if ($result->num_rows > 0) {
    $cityRecords = array();
    $cityRecords["cities"] = array();
    while ($city = $result->fetch_assoc()) {
        extract($city);
        $cityDetails = array(

            "ID" => $ID,
            "Name" => $Name,
            "CountryCode" => $CountryCode,
            "District" => $District,
            "Population" => $Population
        );
        array_push($cityRecords["cities"], $cityDetails);
    }
    http_response_code(200);
    echo json_encode($cityRecords);
} else {
    http_response_code(404);
    echo json_encode(
        array("message" => "No item found.")
    );
}
?>