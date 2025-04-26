<?php
//#1.a
$str = 'ahb acb aeb aeeb adcb axeb';
$regexp='/a[a-z]{2}b/ui';
$matches = array();
$count = preg_match_all($regexp, $str, $matches);
echo "Найдено строк: {$count}\n";
var_dump($matches);

//#1.b
$text = 'a1b2c3';
$change = '/[0-9]/ui';
function replaceWithCube($matches) {
    $number = (int)$matches[0];
    $cubedNumber = pow($number, 3);
    return $cubedNumber;
}
$result = preg_replace_callback($change, 'replaceWithCube', $text);
echo $result;
