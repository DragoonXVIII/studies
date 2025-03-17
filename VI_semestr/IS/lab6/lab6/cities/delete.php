<?php
header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");
header("Access-Control-Allow-Methods: DELETE");
include_once '../class/Citites.php';
include_once '../config/Database.php';

$database = new Database();
$db = $database->getConnection();
$cities = new Cities($db);

$cities->id = isset($_GET['id']) ? $_GET['id'] : die();

if ($cities->delete()) {
    http_response_code(200);
    echo json_encode(array("message" => "City deleted successfully."));
} else {
    http_response_code(503);
    echo json_encode(array("message" => "Unable to delete city."));
}
?>
