<?php
class Cities
{
    private $citiesTable = "city";
    public $id;
    public $name;
    public $countryCode;
    public $district;
    public $population;

    public function __construct($db)
    {

        $this->conn = $db;
    }
    function read()
    {
        if ($this->id) {
            $stmt = $this->conn->prepare("SELECT * FROM " . $this->citiesTable . " WHERE ID = ?");
            $stmt->bind_param("i", $this->id);
        } else {
            $stmt = $this->conn->prepare("SELECT * FROM " . $this->citiesTable);
        }
        $stmt->execute();
        $result = $stmt->get_result();
        return $result;
    }
}