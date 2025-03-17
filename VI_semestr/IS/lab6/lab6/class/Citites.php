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

    // POST
    public function create() {
        $stmt = $this->conn->prepare("INSERT INTO " . $this->citiesTable . " (Name, CountryCode, District, Population) VALUES (?, ?, ?, ?)");
        $stmt->bind_param("sssi", $this->name, $this->countryCode, $this->district, $this->population);
        return $stmt->execute();
    }

    // PUT 
    public function update() {
        $stmt = $this->conn->prepare("UPDATE " . $this->citiesTable . " SET Name=?, CountryCode=?, District=?, Population=? WHERE ID=?");
        $stmt->bind_param("sssii", $this->name, $this->countryCode, $this->district, $this->population, $this->id);
        return $stmt->execute();
    }

    // DELETE 
    public function delete() {
        $stmt = $this->conn->prepare("DELETE FROM " . $this->citiesTable . " WHERE ID = ?");
        $stmt->bind_param("i", $this->id);
        return $stmt->execute();
    }
}