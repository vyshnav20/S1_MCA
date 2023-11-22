<?php
$conn=mysqli_connect("localhost","root","cetmca","student");
$name=$_POST['name'];
$rno=$_POST['rno'];
if(!$conn)
    echo mysqli_connect_error();
else
{
    $q= "insert into stud values(12,".$name.",75)";
    $p= mysqli_query($conn,$q);
    if($p)
    {
        echo "Inserted";
    }
    else
    {
        echo mysqli_error($conn);
    }
    
}

?>