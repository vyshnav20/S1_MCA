<?php
$conn=mysqli_connect("localhost","root","cetmca","student");
$rno=$_POST['rno'];
$p=$_POST['pass'];
echo "<script>alert('Hello');</script>";
echo "HI";/*
$result = mysqli_query($conn, "update `ktu` set Password='$p' WHERE ktuid='$rno'" );
if($result)
    echo "<script>alert('Successfully Updated');</script>";
else
echo "<script>alert('Not Updated');</script>";*/
?>