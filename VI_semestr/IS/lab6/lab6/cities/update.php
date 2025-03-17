<?php
header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");
header("Access-Control-Allow-Methods: PUT");
include_once '../class/Citites.php';
include_once '../config/Database.php';

$database = new Database();
$db = $database->getConnection();
$cities = new Cities($db);

$data = json_decode(file_get_contents("php://input"));
$cities->id = isset($_GET['id']) ? $_GET['id'] : die();

if (!empty($data->Name) && !empty($data->CountryCode) && !empty($data->District) && !empty($data->Population)) {
    $cities->name = $data->Name;
    $cities->countryCode = $data->CountryCode;
    $cities->district = $data->District;
    $cities->population = $data->Population;

    if ($cities->update()) {
        http_response_code(200);
        echo json_encode(array("message" => "City updated successfully."));
    } else {
        http_response_code(503);
        echo json_encode(array("message" => "Unable to update city."));
    }
} else {
    http_response_code(400);
    echo json_encode(array("message" => "Incomplete data."));
}
?>
