<?php
$conn=mysqli_connect("localhost","root","cetmca","student");
$rno=$_POST['ktuid'];
$p=$_POST['pass'];
$phno = $_POST['phno'];
$result = mysqli_query($conn, "update `ktu` set Password='$p', Phno='$phno' WHERE ktuid='$rno'" );
if($result)
    echo "<script>alert('Successfully Updated');</script>";
else
echo "<script>alert('Not Updated');</script>";
?>