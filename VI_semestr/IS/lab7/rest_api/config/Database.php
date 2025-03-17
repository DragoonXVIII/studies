<?php
class Database
{
    /*
    // Basic connection
    private $host = 'db';
    private $user = 'root';
    private $password = "elozelo2137";
    private $database = "world";
    */

    // Advanced connection
    private $host = 'db';
    private $user = 'newuser';
    private $password = 'newpassword'; 
    private $database = "world";

    public function getConnection()
    {
        $conn = new mysqli($this->host, $this->user, $this->password, $this->database);
        if ($conn->connect_error) {
            die("Error failed to connect to MySQL: " .
                $conn->connect_error);
        } else {
            return $conn;
        }
    }
}