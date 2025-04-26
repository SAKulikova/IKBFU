<?php
session_start();
?>

<!DOCTYPE html>
<html>
<head>
    <title>User Data</title>
</head>
<body>
<h1>Данные пользователя</h1>
<p>Фамилия: <?php echo $_SESSION["surname"]; ?></p>
<p>Имя: <?php echo $_SESSION["name"]; ?></p>
<p>Возраст: <?php echo $_SESSION["age"]; ?></p>
</body>
</html>