// #1
<?php
/* Imagine a lot of code here */ 
 $very_bad_unclear_name = "15 chicken wings";

// Write your code here:

$order = &$very_bad_unclear_name;
$order .= "Hi";
  
 // Don't change the line below
 echo "\nYour order is: $very_bad_unclear_name.";

// #2
$number = 15;
echo $number;
$digit = 0x1B7;
echo "\n$digit";
$float = 1.56;
echo $float;
echo (10 + 2);
$last_month = 1187.23;
$this_month = 1089.98;
echo "\nРазница между расходами:",$last_month-$this_month;

//#11
$num_languages = 4;
$months = 11;
$days = $months * 16;
$days_per_language = $days/$num_languages;
echo $days_per_language;

// #12
echo 8**2;

// #13
$my_num = 93;
$answer = $my_num;
$answer += 2;
$answer *= 2;
$answer -= 2;
$answer /= 2;
$answer -= $my_num;
echo $answer;

//#14
$a = 10;
$b = 3;
echo $a%$b;
if ($a%$b==0){
    echo "\nДелится, результат деления: ",$a/$b;
}
else{
    echo "\nДелится с остатком ", $a%$b;
}
$st = pow(2,10);
$sqrtOne = sqrt(245);
$arr = [4, 2, 5, 19, 13, 0, 10];
$sumOfSquares = 0;
foreach ($arr as $i){
    $sumOfSquares += pow($i,2);
}
$sqrtSumOfSquares = sqrt($sumOfSquares);
$n = round(sqrt(379));
$k = round(sqrt(379),1);
$t = round(sqrt(379),2);
$varOne = ceil(sqrt(587));
$varTwo = floor(sqrt(587));
$arrRouding = ['ceil' => $varOne, 'floor' => $varTwo];
$maximum = max(4,-2, 5, 19, -130, 0, 10);
$minimum = min(4,-2, 5, 19, -130, 0, 10);
echo rand(1,100);
$i=0;
$massive = [];
while($i<10)
{
    $massive[$i] = rand(1,100);
    $i++;
}
$module =  abs($a-$b); //a и b уже заданы выше
$masOfNumbers = [1, 2, -1, -2, 3, -3];
foreach ($masOfNumbers as $key => $value) {
    if ($masOfNumbers[$key]<0){
        $masOfNumbers[$key] = abs($masOfNumbers[$key]);
    }
}
$num = 30;
$divider = [];
for ($i=1;$i<$num+1;$i++) {
    if ($num%$i == 0){
        $divider[]=$i;
    }
}
$arrTwo = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
for ($sum = 0, $i = 0; $sum <= 10; $i++) {
    $sum += $arrTwo[$i];
}

//#15
function printStringReturnNumber($stringOne)
{
    echo $stringOne;
    return rand(1,1000);
}
$my_num = printStringReturnNumber('blablabla');
echo $my_num;
