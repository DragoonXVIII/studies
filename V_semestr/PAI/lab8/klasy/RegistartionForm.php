<?php


class RegistartionForm {
    
    protected $user;
    
    public function __construct()
    {
       ?>
        <h3>Formularz rejestracji</h3>
        <form action="index.php" method="post">
			<table>
			<tr>
				<td>Nazwa uzytwkonika:</td> <td><input name="userName"></td>
			</tr>
			<tr>
				<td>Imie i nazwisko:</td> <td><input name='fullName'></td>
			</tr>
			<tr>
				<td>Haslo:</td><td> <input name="passwd"></td>
			</tr>
			<tr>
				<td>Email:</td><td><input name="email"></td> 
			</tr>
			</table>
            <br>
			<input type="submit" name="submit" value="Rejestruj">
			<input type="submit" name="show" value="Pokaz">
			<input type="reset" name="reset" value="Anuluj">
        </form>
        <?php
    }
    
    public function checkUser()
    {
        $args = 
        [
            'userName' => ['filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp'=>'/^[0-9A-Za-ząęłńśćźżó_-]{2,25}$/']],
            'fullName' => ['filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp'=>'/^[A-Za-ząęłńśćźżó]{2,}\s[A-Za-ząęłńśćźżó]{2,}/']],
			'passwd' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
			'email' => FILTER_VALIDATE_EMAIL
        ];
		$dane = filter_input_array(INPUT_POST, $args);
		//var_dump($dane);
		
		$errors = "";
		foreach ($dane as $key => $val) 
		{
			if ($val === false or $val === NULL) 
			{
				$errors .= $key . " ";
			}
		}
		
		if ($errors === "")
		{
			$this->user=new User($dane['userName'], $dane['fullName'], $dane['email'],$dane['passwd']);
		}
		else
		{
			echo "<p>Błędne dane: <br>$errors</p>";
			$this->user = NULL;
		}
		return $this->user;
    }
}
