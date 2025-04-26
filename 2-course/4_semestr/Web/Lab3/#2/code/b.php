<?php
session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $_SESSION["surname"] = $_POST["surname"];
    $_SESSION["name"] = $_POST["name"];
    $_SESSION["age"] = $_POST["age"];
    header("Location: b_1.php");
    exit;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>User Data</title>
</head>
<body>
<form method="post">
    Фамилия: <input type="text" name="surname"><br>
    Имя:     <input type="text" name="name"><br>
    Возраст: <input type="text" name="age"><br>
    <input type="submit" value="Показать данные">
</form>
</body>
</html>