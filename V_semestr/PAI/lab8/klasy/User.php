<?php


class User {
    const STATUS_USER = 1;
    const STATUS_ADMIN = 2;
    protected $userName;
    protected $password;
    protected $fullName;
    protected $email;
    protected $date;
    protected $status;

    /**
     * @return mixed
     */
    public function getUserName()
    {
        return $this->userName;
    }

    /**
     * @param mixed $userName
     */
    public function setUserName($userName)
    {
        $this->userName = $userName;
    }

    /**
     * @return false|string|null
     */
    public function getPassword()
    {
        return $this->password;
    }

    /**
     * @param false|string|null $password
     */
    public function setPassword($password)
    {
        $this->password = $password;
    }

    /**
     * @return mixed
     */
    public function getFullName()
    {
        return $this->fullName;
    }

    /**
     * @param mixed $fullName
     */
    public function setFullName($fullName)
    {
        $this->fullName = $fullName;
    }

    /**
     * @return mixed
     */
    public function getEmail()
    {
        return $this->email;
    }

    /**
     * @param mixed $email
     */
    public function setEmail($email)
    {
        $this->email = $email;
    }

    /**
     * @return DateTime
     */
    public function getDate()
    {
        return $this->date;
    }

    /**
     * @param DateTime $date
     */
    public function setDate($date)
    {
        $this->date = $date;
    }

    /**
     * @return int
     */
    public function getStatus()
    {
        return $this->status;
    }

    /**
     * @param int $status
     */
    public function setStatus($status)
    {
        $this->status = $status;
    }



    
    function __construct($userName, $fullName,$email,$password) 
    {
        $this->userName=$userName;
        $this->fullName=$fullName;
        $this->email=$email;
        $this->password= password_hash($password, PASSWORD_DEFAULT);
        $this->status=User::STATUS_USER;
        $this->date= new DateTime();
    }
    
    Public function show()
    {
        echo "User name: ".$this->userName."<br>";
        echo "Password: ".$this->password."<br>";
        echo "FullName: ".$this->fullName."<br>";
        echo "Email: ".$this->email."<br>";
        echo "Data: ".$this->date->format("d-m-Y")."<br>";
        echo "Status: ".$this->status."<br>";
    }

    //nowa
    public function saveToDB($bd)
    {
        $sql = "INSERT INTO users VALUES (NULL, '".$this->getUserName()."','".$this->getFullName()."','".$this->getEmail()."','".$this->getPassword()."', '1', '".$this->getDate()->format("Y-m-d")."');";
        echo $sql;
        $bd->insert($sql);
    }
    
    //nowa
    static public function getAllUsersFromDB($db)
    {
        $sql = "SELECT * FROM `users`";
        $pola = ["id","fullName","userName", "email","passwd","status","date"];
        $res = $db->select($sql,$pola);
        echo $res;
    }

	static public function getAllUsers($plik)
	{
		$tab = json_decode(file_get_contents($plik));
		foreach($tab as $val)
		{
			echo "<p>".$val->userName." ".$val->fullName." ".$val->date."</p>";
		}
	}
	public function toArray()
	{
		$arr=[
				"userName" => $this->userName,
				"fullName" => $this->fullName,
				"passwd" => $this->password,
				"email" => $this->email,
				"date" => $this->date->format("Y-m-d"),
				"status" => $this->status
			];
		return $arr;
	}
	public function save($plik)
	{
		$tab = json_decode(file_get_contents($plik),true);
		array_push($tab,$this->toArray());
		file_put_contents($plik, json_encode($tab));
	}
	
	static public function getAllUsersFromXML($plik)
	{
		 $allUsers = simplexml_load_file($plik);
		 echo "<ul>";
		 foreach ($allUsers as $user):
		 $userName=$user->userName;
		 $date=$user->date;
		 $fullName = $user->fullName;
		 echo "<li>userName: $userName | fullName: $fullName | data: $date </li>";
		 endforeach;
		 echo "</ul>";
	}
	public function saveXML($plik)
	{
		$xml = simplexml_load_file($plik);
		$xmlCopy=$xml->addChild("user");
		$xmlCopy->addChild("userName", $this->userName);
		$xmlCopy -> addChild("fullName",$this->fullName);
		$xmlCopy -> addChild("passwd",$this->password);
		$xmlCopy -> addChild("email",$this->email);
		$xmlCopy -> addChild("date",$this->date->format("d-m-Y"));
		$xmlCopy -> addChild("status",$this->status);
		$xml->asXML('users.xml');
		$allUsers = simplexml_load_file($plik);		
	}
}
