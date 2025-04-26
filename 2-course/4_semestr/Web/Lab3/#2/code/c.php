<?php
session_start();
if (isset($_GET))
    $_SESSION['input'] = $_GET;
?>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
</head>
<body>
    <form method="get">
        <label>
            Фамилия <input type="text" name="surname"><br>
        </label>
        <label>
            Имя <input type="text" name="name"><br>
        </label>
        <label>
            Возраст <input type="text" name="age"><br>
        </label>
        <label>
            Зарплата <input type="text" name="salary"><br>
        </label>
        <input type="submit">
    </form>
</body>
</html>