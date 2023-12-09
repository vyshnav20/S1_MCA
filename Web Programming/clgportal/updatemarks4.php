<?php
$id=$_POST['id'];
$sem=$_POST['sem'];
$sub=$_POST['sub'];
$s1=$_POST['s1'];
$s2=$_POST['s2'];
$a1=$_POST['a1'];
$a2=$_POST['a2'];
$att=$_POST['att'];
$internal=(($s1+$s2)*0.2)+(($a1+$a2)/2.0);
if($att>90)
    $internal+=8;
elseif($att>80)
    $internal+=7;
elseif($att>70)
    $internal+=6;
else
    $internal+=0;
$conn=mysqli_connect("localhost","root","cetmca","student");
$s="update marks set s1='$s1',s2='$s2',a1='$a1',a2='$a2',att='$att',internal='$internal' where ID='$id' and subject='$sub'";
if(mysqli_query($conn,$s))
    echo "<script>alert('Marks Updated');</script>";  
else
echo $s."\n";
echo mysqli_error($conn);  
?>