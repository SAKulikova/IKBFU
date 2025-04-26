<?php
session_start();
if (isset($_SESSION['input']))
{
    foreach ($_SESSION['input'] as $value)
        echo "<ul><li>$value</li></ul>";
}