<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width-device-width, user-scalable-no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0"
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>
    <div id="form">
        <form action="hm.php" method="post">
            <label for="email">Email</label>
            <input type="email" name="email" required><br>

            <label for="category">Category</label>

            <?php
            $categories = scandir('categories');
            echo '<select name="category" required>';

                foreach ($categories as $category) {
                    if (is_dir("categories/$category") && $category != '.' && $category != '..') {
                        echo "<option value='$category'>$category</option>";
                    }
                }

                echo '</select>';
                ?>
            <br>
            <label for="title">Title</label>
            <input type="text" name="title" required>
            <br>
            <label for="description">Description</label>
            <textarea rows="2" name="description" required></textarea>
            <br>
            <input type="submit" value="Save">
        </form>
    </div>
    <div id="table">
        <table>
            <thead>
            <th style="width: 10%;">Category</th>
            <th style="width: 15%;">Title</th>
            <th style="width: 75%;">Description</th>
            </thead>

            <tbody>
            <?php
            $categ = opendir('categories');

            while ($file = readdir($categ))
            {
                if (is_dir('categories/'.$file) && $file != '.' && $file != '..')
                {
                    $subdir = opendir('categories/'.$file);
                    while ($ad = readdir($subdir))
                    {
                        if ($ad != '.' && $ad != '..')
                        {
                            $fp = fopen('categories/'.$file.'/'.$ad, 'r');
                            $descrb = "";
                            while ($line = fgets($fp))
                            {
                                $descrb .= $line;
                            }
                            fclose($fp);
                            echo '<tr>';
                            echo "<td>$file</td>";
                            echo "<td>".substr($ad, 0, strlen($ad) - 4)."</td>";
                            echo "<td>$descrb</td>";
                            echo '</tr>';
                        }
                    }
                }
            }
            ?>
            </tbody>
        </table>
    </div>
</body>
</html>