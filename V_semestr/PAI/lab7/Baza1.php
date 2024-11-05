<?php

class BazaPDO {
    private $pdo; // PDO instancja

    public function __construct($serwer, $user, $pass, $baza) 
    {
        $dsn = "mysql:host=$serwer;dbname=$baza;charset=utf8";
        try {
            $this->pdo = new PDO($dsn, $user, $pass);
            // ustawiamy PDO error mode na wyjątki
            $this->pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        } catch (PDOException $e) {
            printf("Nie udało sie połączenie z serwerem: %s\n", $e->getMessage());
            exit();
        }
    }

    function __destruct() 
    {
        $this->pdo = null;
    }

    public function select($sql, $pola) 
    {
        //parametr $sql – łańcuch zapytania select
        //parametr $pola - tablica z nazwami pol w bazie
        //Wynik funkcji – kod HTML tabeli z rekordami (String)
        $tresc = "";
        
        try {
            $stmt = $this->pdo->query($sql);
            $ilepol = count($pola); //ile pól
            $ile = $stmt->rowCount(); //ile wierszy
            // pętla po wyniku zapytania $results
            $tresc .= "<table><tbody>";
            while ($row = $stmt->fetch(PDO::FETCH_OBJ)) 
            {
                $tresc .= "<tr>";
                for ($i = 0; $i < $ilepol; $i++) 
                {
                    $p = $pola[$i];
                    $tresc .= "<td>" . $row->$p . "</td>";
                }
                $tresc .= "</tr>";
            }
            $tresc .= "</table></tbody>";
        } catch (PDOException $e) {
            printf("Błąd zapytania: %s\n", $e->getMessage());
        }
        return $tresc;
    }

    public function insert($sql) 
    {
        try {
            $this->pdo->exec($sql);
            return true;
        } catch (PDOException $e) {
            printf("Błąd zapytania: %s\n", $e->getMessage());
            return false;
        }
    }

    public function delete($sql) 
    {
        try {
            $this->pdo->exec($sql);
            return true;
        } catch (PDOException $e) {
            printf("Błąd zapytania: %s\n", $e->getMessage());
            return false;
        }
    }

    public function getPdo() 
    {
        return $this->pdo;
    }
}

?>