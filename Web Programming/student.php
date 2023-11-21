<html>
<head>
    <title>Student Registration</title>
</head>
<body>
    <center><h1>Register</h1>
    <form action="student.php" method="post">
        Name: <input type="text" placeholder="Enter your name" name="name"><br>
        Roll No:<input type="text" placeholder="Enter Roll Number" name="rno"><br>
        Age:<input type="text" placeholder="Enter your Age" name="age"><br>
        <input type="submit">
    </form>    
</center>
</body>
</html>
<?php
$conn=mysqli_connect("localhost","root","cetmca","mca_s1");
$name=$_POST['name'];
$rno=(int)$_POST['rno'];
$age=(int)$_POST['age'];
if(!$conn)
    echo mysqli_connect_error();
else
{
    echo "hi";
    $q="insert into student values($name,$rno,$age)";
    if(mysqli_query($conn,$q))
    {
        echo "Inserted";
    }
}
?>