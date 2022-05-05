<?php
$dbFaculty = 'HDUTTON_cs120';
$dsn = 'mysql:host=webdb.uvm.edu;dbname='.$dbFaculty;
$username = 'hdutton_writer';
$password = 'am9YHGaOxrjq7OiH';

$pdo = new PDO($dsn, $username, $password);
?>