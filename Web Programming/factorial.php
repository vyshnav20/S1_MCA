<?php
$n=$_POST['num'];
$n=(int)$n;
$f=1;
for($i=1;$i<=$n;$i++)
    $f*=$i;
echo "Factorial of ".$n." = ".$f;
?>