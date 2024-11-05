<?php
    include_once "klasy/User.php";

    echo "<h2>TEST 1</h2>";

    session_start();
    $_SESSION['username'] = 'kubus';
    $_SESSION['fullname'] = 'Kubus Puchatek';
    $_SESSION['email'] = 'kubus@stumilowylas.pl';
    $_SESSION['status'] = 'ADMIN';

    echo "<b>Dane uzytkownika:</b><br>";
    $user = new User("temp","Temp Test","email@temp.pl","temporary");
    $user->show();
    $_SESSION["u1"] = serialize($user); //do session

    echo "<hr>";
    echo "<b>Session ID: </b>".session_id();
    echo "<br><hr>";

    echo "<b>Dane sesji:</b><br>";
    $l = 0;
    foreach ($_SESSION as $key => $val)
    {
        echo $key.":".$val."<br>";
        $l++;
        if($l==4)
        {
            $l=0;
            echo "<br>";
        }
    }
    echo "<hr>";
    foreach ($_COOKIE as $i)
    {
        echo "<b>Cookie: </b>".$i;
    }
    echo "<br><hr>";
    echo "<a href='test2.php'>Idz do test2.php</a>";
?>