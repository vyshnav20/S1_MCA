<?php
session_start();
$u=$_SESSION['username'];
$con=mysqli_connect('localhost','root','password','student');
$s1=mysqli_query($con,"select * from book where username='$u'");
if(mysqli_num_rows($s1))
{
    echo "<table border='1'><tr><td>Book Name</td><td>Book Author</td><td>Number of copies</td></tr>";
    while($r=mysqli_fetch_array($s1))
    {
        echo "<tr><td>".$r['name']."</td><td>".$r['author']."</td><td>".$r['numcopies']."</td></tr>";
    }
    echo "</table>";
}
else
{
    echo "<h1>No orders yet!!!!</h1>";
}