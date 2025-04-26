
<?php
$container = 'db';
$useruser = 'root';
$password = '1234';
$database = 'MySQL';
$port = 3306;

// Подключение к базе данных
$mysqli = new mysqli($container, $useruser, $password, $database, $port);
if ($mysqli->connect_error) {
    die("Ошибка подключения к базе данных: " . $mysqli->connect_error);
}

// Получение данных из формы
$email = $_POST['email'];
$category = $_POST['category'];
$title = $_POST['title'];
$description = $_POST['description'];

// Сохранение данных в базе данных
$stmt = $mysqli->prepare("INSERT INTO MySQL.ad (email, category, title, description) VALUES (?, ?, ?, ?)");
$stmt->bind_param("ssss", $email, $category, $title, $description);
$stmt->execute();

$stmt->close();
$mysqli->close();

header("Location: index.php");
exit;
