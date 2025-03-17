<?php
header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");
header("Access-Control-Allow-Methods: POST");
include_once '../class/Citites.php';
include_once '../config/Database.php';

$database = new Database();
$db = $database->getConnection();
$cities = new Cities($db);

$data = json_decode(file_get_contents("php://input"));

if (!empty($data->Name) && !empty($data->CountryCode) && !empty($data->District) && !empty($data->Population)) {
    $cities->name = $data->Name;
    $cities->countryCode = $data->CountryCode;
    $cities->district = $data->District;
    $cities->population = $data->Population;

    if ($cities->create()) {
        http_response_code(201);
        echo json_encode(array("message" => "City added successfully."));
    } else {
        http_response_code(503);
        echo json_encode(array("message" => "Unable to add city."));
    }
} else {
    http_response_code(400);
    echo json_encode(array("message" => "Incomplete data."));
}
?>
