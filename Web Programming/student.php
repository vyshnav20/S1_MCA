<html>
<head>
    <title>Student Registration</title>
</head>
<body>
    <center><h1>Register</h1>
    <form action="student.php" method="post">
        Name: <input type="text" placeholder="Enter your name" name="name"><br>
        Roll No:<input type="text" placeholder="Enter Roll Number" name="rno"><br>
        Marks: <input type="text" placeholder="Enter marks" name="mark"><br>
        <input type="submit" name="insert" value="Submit">
        <input type="submit" name="display" value="Display">
    </form>    

<?php
if (array_key_exists('display',$_POST))
{
    display();
}
else if (array_key_exists('insert',$_POST))
{
    insert();
}
function insert()
{
    $conn=mysqli_connect("localhost","root","cetmca","student");
    $name=$_POST['name'];
    $rno=$_POST['rno'];
    $mark=$_POST['mark'];
    if(!$conn)
        echo mysqli_connect_error();
    else
    {
        $q= "insert into stud values('$rno','$name','$mark')";
        $p= mysqli_query($conn,$q);
        if($p)
        {
            echo "<script>alert('Inserted details to database');</script>";
        }
        else
        {
            $s="Duplicate";
            if(strpos(mysqli_error($conn),$s)==false)
            {
                echo "<script>alert('Cannot insert student with Duplicate Roll Number');</script>";
            }
        }
    }
}
    


function display()
{
    $conn=mysqli_connect("localhost","root","cetmca","student");
    echo "<table border='1'><tr><td>Roll Number</td><td>Name</td><td>Marks</td></tr>";
    $result = mysqli_query($conn, "SELECT * FROM stud" );
    while ($row = mysqli_fetch_assoc($result)) {

        echo "<tr><td>".$row{'RollNo'}."</td><td>".$row{'Name'}."</td><td> ". $row{'Mark'}."</td></tr>";
        
        }

}
?>
</center>
</body>
</html>